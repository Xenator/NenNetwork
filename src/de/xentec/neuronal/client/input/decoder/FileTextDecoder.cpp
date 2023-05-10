//
// Created by Xen on 01.05.2023.
//

#include "FileTextDecoder.h"

std::vector<std::vector<double>> FileTextDecoder::loadInput(const char *inputPath, const char *labelPath) {

    std::vector<std::vector<double>> input;

    std::string text= Utils::readFile(inputPath);
    Utils::parseMatrices2D(text, input);


    return input;
}
