//
// Created by Xentex on 10.05.2023.
//

#include "ImageInputService.h"

void ImageInputService::loadInput(std::vector<std::vector<double>>& input) {

    if(images.empty()){
        images = Image::decodeMNIST(imageFilePath,labelFilePath);
    }

    input.reserve(images.size());
    for ( auto& image : images) {
        input.emplace_back(image.getPixels());
    }
}

void ImageInputService::loadOutput(std::vector<std::vector<double>> & output) {


    if(images.empty()){
        images = Image::decodeMNIST(imageFilePath,labelFilePath);
    }

    output.resize(images.size());
    for(int i = 0 ; i < images.size();i++){
        output[i].resize(10);
        for(int j =0 ; j <10 ;j++){

            if(((int)images[i].getLabel()) == j){
                output[i][j] = 0.99;
            }else{
                output[i][j] = 0.01;
            }
        }
    }
}

void ImageInputService::setInputPath(const char *filePath) {
    this->imageFilePath = filePath;
}

void ImageInputService::setLabelPath(const char *filePath) {
    this->labelFilePath = filePath;
}
