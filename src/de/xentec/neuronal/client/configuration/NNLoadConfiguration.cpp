//
// Created by Xen on 09.05.2023.
//

#include "NNLoadConfiguration.h"
#include "../../../../../Utils/Utils.h"

void NNLoadConfiguration::setWeightFile(const char *filePath) {
    this->weightFilePath= filePath;
}

void NNLoadConfiguration::setBiasFile(const char *filePath) {
    this->biasFilePath= filePath;
}

std::vector<double> NNLoadConfiguration::loadBias() {

    std::string text= Utils::readFile(biasFilePath);
    Utils::parseMatrices1D(text, bias);
    return bias;
}

std::vector<std::vector<std::vector<double>>> NNLoadConfiguration::loadWeights() {

    std::string text= Utils::readFile(weightFilePath);
    Utils::parseMatrices(text, weights);
    return weights;
}

NNLoadConfiguration::NNLoadConfiguration() {

}
