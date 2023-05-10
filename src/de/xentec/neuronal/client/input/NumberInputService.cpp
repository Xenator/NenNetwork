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

void NumberInputService::loadInput(std::vector<std::vector<double>>& input) {

    input.emplace_back();
    for(int i = 0; i < inputSize;i++){
        input[0].push_back(this->input[i]);
    }
}

void NumberInputService::loadOutput(std::vector<std::vector<double>>& output) {

    output.emplace_back();
    for(int i = 0; i < labelSize;i++){
        output[0].push_back(this->label[i]);
    }
}
