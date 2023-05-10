//
// Created by Xen on 08.04.2023.
//

#include "Utils.h"

std::string Utils::readFile(const char *path) {

    std::string filename = std::filesystem::current_path().string() +"/res/"+ path;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "Fehler beim Öffnen der Datei! " << filename << std::endl;
        return "";
    }

    std::string text;
    std::string line;
    const int reserve_size = 10000;  // Reserve 10.000 Zeichen im Voraus
    text.reserve(reserve_size);
    while (std::getline(file, line)) {
        text += line+"\n";
    }

    file.close();
    return text;
}

void  Utils::parseMatrices2D(const std::string &text, std::vector<std::vector<double>> &matrices ) {

    std::istringstream stream(text);
    std::string line;


    while (std::getline(stream, line)) {

        size_t start_pos = line.find_first_of('[');
        while (start_pos != std::string::npos) {
            line = line.substr(start_pos + 1);
            start_pos = line.find_first_of('[');
        }

        std::vector<double> row;
        std::istringstream line_stream(line);
        double value;

        while (line_stream >> value) {
            row.push_back(value);
            if (line_stream.peek() == ',' || line_stream.peek() == ' ') {
                line_stream.ignore();
            }
        }
        matrices.push_back(row);
    }
}



void  Utils::parseMatrices1D(const std::string &text, std::vector<double> &matrices ) {

    std::istringstream stream(text);
    std::string line;


    while (std::getline(stream, line)) {

       size_t start_pos = line.find_first_of('[');
        while (start_pos != std::string::npos) {
            line = line.substr(start_pos + 1);
            start_pos = line.find_first_of('[');
        }

        std::vector<double> row;
        std::istringstream line_stream(line);
        double value;

        while (line_stream >> value) {
            matrices.push_back(value);
            if (line_stream.peek() == ',' || line_stream.peek() == ' ') {
                line_stream.ignore();
            }
        }
    }
}




void  Utils::parseMatrices(const std::string &text, std::vector<std::vector<std::vector<double>>> &matrices ) {

    std::istringstream stream(text);
    std::string line;

    std::vector<std::vector<double>> matrix;

    while (std::getline(stream, line)) {
        if (line.empty()) {
            if (!matrix.empty()) {
                matrices.push_back(matrix);
                matrix.clear();
            }
            continue;
        }

        size_t start_pos = line.find_first_of('[');
        while (start_pos != std::string::npos) {
            line = line.substr(start_pos + 1);
            start_pos = line.find_first_of('[');
        }

        std::vector<double> row;
        std::istringstream line_stream(line);
        double value;

        while (line_stream >> value) {
            row.push_back(value);
            if (line_stream.peek() == ',' || line_stream.peek() == ' ') {
                line_stream.ignore();
            }
        }

        if (!row.empty()) {
            matrix.push_back(row);
        }
    }

    // Füge die letzte Matrix hinzu, wenn sie nicht leer ist
    if (!matrix.empty()) {
        matrices.push_back(matrix);
    }
}

void Utils::safeWeights(const char *path, std::vector<std::vector<std::vector<double>>> weights) {

    std::string filename = std::filesystem::current_path().string() +"/res/"+ path;
    std::ofstream myfile(filename);

    // Check if the file was successfully opened
    if (myfile.is_open()) {
        // Write some data into the file


        for(int i = 0;i< weights.size();i++){

            myfile << "[";
            for(int j = 0;j< weights[i].size();j++){
                myfile << "[";
                for(int k = 0; k<weights[i][j].size();k++){

                    myfile<< weights[i][j][k];
                    if(k +1 != weights[i][j].size()){
                        myfile << ", ";
                    }
                }
                if(j+1 == weights[i].size()){
                    myfile << "]";
                }else {
                    myfile << "],\n";
                }

            }
            myfile << "]\n\n";
        }

        // Close the file
        myfile.close();
    } else {
        std::cout << "Unable to open file.\n";
    }

}

void Utils::safeBias(const char *path, std::vector<double> bias) {
    std::string filename = std::filesystem::current_path().string() +"/res/"+ path;
    std::ofstream myfile(filename);

    // Check if the file was successfully opened
    if (myfile.is_open()) {
        // Write some data into the file

        myfile << "[[";
        for(int i = 0;i< bias.size();i++){
            myfile<< bias[i] ;

            if(i+1 != bias.size()){
                myfile<< ", ";
            }
        }
        myfile << "]]\n";
        // Close the file
        myfile.close();
    } else {
        std::cout << "Unable to open file.\n";
    }
}
