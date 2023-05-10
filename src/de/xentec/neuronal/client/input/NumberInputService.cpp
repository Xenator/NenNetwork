//
// Created by Xen on 09.05.2023.
//

#include "NumberInputService.h"

void NumberInputService::setInputNumber(double *input, int size) {

    this->input= input;
    this->inputSize = size;
}

void NumberInputService::setLabelNumber(double *label, int size) {
    this->label= label;
    this->labelSize = size;
}

std::vector<std::vector<double>> NumberInputService::loadInput() {

    std::vector<std::vector<double>> tempInput;
    tempInput.emplace_back();

    for(int i = 0; i < inputSize;i++){
        tempInput[0].push_back(this->input[i]);
    }

    return tempInput;
}

std::vector<std::vector<double>> NumberInputService::loadOutput() {

    std::vector<std::vector<double>> tempLabel;
    tempLabel.emplace_back();

    for(int i = 0; i < labelSize;i++){
        tempLabel[0].push_back(this->label[i]);
    }

    return tempLabel;
}
