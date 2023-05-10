//
// Created by Xentex on 14.04.2023.
//

#ifndef FNN_IMAGE_H
#define FNN_IMAGE_H

#include <vector>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <iterator>
#include <iostream>

class Image {
    double label;
    std::vector<double> pixels;

public:

    std::vector< double> getPixels(){
        return this->pixels;
    }
    double getLabel(){
        return label;
    }

    static void encodeMNIST(const std::string& imagesFilename, const std::string& labelsFilename, const std::vector<Image>& images) {
        std::ofstream imagesFile(imagesFilename, std::ios::binary);
        std::ofstream labelsFile(labelsFilename, std::ios::binary);

        int magicNumber = 2051;
        int numImages = images.size();
        int numRows = 28;
        int numCols = 28;

        imagesFile.write((char*)&magicNumber, sizeof(magicNumber));
        imagesFile.write((char*)&numImages, sizeof(numImages));
        imagesFile.write((char*)&numRows, sizeof(numRows));
        imagesFile.write((char*)&numCols, sizeof(numCols));

        for (const auto& image : images) {
            imagesFile.write((char*)&image.label, sizeof(image.label));
            imagesFile.write((char*)image.pixels.data(), image.pixels.size());
        }

        magicNumber = 2049;

        labelsFile.write((char*)&magicNumber, sizeof(magicNumber));
        labelsFile.write((char*)&numImages, sizeof(numImages));

        for (const auto& image : images) {
            labelsFile.write((char*)&image.label, sizeof(image.label));
        }

        imagesFile.close();
        labelsFile.close();
    }

    static int convertEndian(int value) {
        unsigned char* bytes = (unsigned char*)&value;
        std::reverse(bytes, bytes + sizeof(int));
        return *((int*)bytes);
    }


    static std::vector<Image> decodeMNIST(const std::string& imagesFilename, const std::string& labelsFilename) {
        std::vector<Image> images;

        std::string pathImages = std::filesystem::current_path().string() +"/res/"+ imagesFilename;
        std::string pathLabel = std::filesystem::current_path().string() +"/res/"+ labelsFilename;

        std::ifstream imagesFile(pathImages, std::ios::binary);
        std::ifstream labelsFile(pathLabel, std::ios::binary);

        int magicNumber;
        int numImages;
        int numRows;
        int numCols;

        imagesFile.read((char*)&magicNumber, sizeof(magicNumber));
        imagesFile.read((char*)&numImages, sizeof(numImages));
        imagesFile.read((char*)&numRows, sizeof(numRows));
        imagesFile.read((char*)&numCols, sizeof(numCols));

        magicNumber = convertEndian(magicNumber);
        numImages = convertEndian(numImages);
        numRows = convertEndian(numRows);
        numCols = convertEndian(numCols);

        if (magicNumber != 2051) {
            throw std::runtime_error("Invalid magic number for images file");
        }

        if (numImages <= 0) {
            throw std::runtime_error("Invalid number of images");
        }

        if (numRows <= 0 || numCols <= 0) {
            throw std::runtime_error("Invalid image dimensions");
        }

        for (int i = 0; i < numImages; i++) {
            Image image;
            image.label = -1;

            std::vector<unsigned char> pixels(numRows * numCols);
            imagesFile.read((char*)pixels.data(), pixels.size());

            std::vector<double> pixelsdouble(numRows * numCols);
            std::transform(pixels.begin(), pixels.end(), pixelsdouble.begin(), [](unsigned char p){ return p / 255.0; });

            if (imagesFile.gcount() != pixels.size()) {
                throw std::runtime_error("Error reading image pixels");
            }

            image.pixels = std::move(pixelsdouble);

            images.push_back(std::move(image));
        }

        int magicNumberLabels;
        int numLabels;

        labelsFile.read((char*)&magicNumberLabels, sizeof(magicNumberLabels));
        labelsFile.read((char*)&numLabels, sizeof(numLabels));

        magicNumberLabels = convertEndian(magicNumberLabels);
        numLabels = convertEndian(numLabels);

        if (magicNumberLabels != 2049) {
            throw std::runtime_error("Invalid magic number for labels file");
        }

        if (numLabels != images.size() ) {
            //std::cout<< ("Number of labels does not match number of images warnign muss weggemacht werden") <<std::endl;
            throw std::runtime_error("Number of labels does not match number of images");

        }

        for (int i = 0; i < numLabels; i++) {
            char label = -1;
            labelsFile.read(&label, sizeof(label));

            if (labelsFile.gcount() != sizeof(label)) {
                throw std::runtime_error("Error reading label");
            }

            images[i].label = label;
        }

        imagesFile.close();
        labelsFile.close();

        return images;
    }


};


#endif //FNN_IMAGE_H
