//
// Created by Xen on 09.05.2023.
//

#include "FileInputService.h"
#include "../../../../../Utils/Utils.h"

void FileInputService::setInputPath(const char *filePath) {
    this->inputFilePath = filePath;
}

void FileInputService::setLabelPath(const char *filePath) {
    this->labelFilePath = filePath;
}

std::vector<std::vector<double>> FileInputService::loadInput() {

    std::vector<std::vector<double>> input;

    std::string text= Utils::readFile(inputFilePath);
    Utils::parseMatrices2D(text, input);

    return input;
}

std::vector<std::vector<double>> FileInputService::loadOutput() {

    std::vector<std::vector<double>> label;

    std::string text= Utils::readFile(labelFilePath);
    Utils::parseMatrices2D(text, label);

    return label;
}
