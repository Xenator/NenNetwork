//
// Created by Xen on 09.05.2023.
//

#include <iostream>
#include "NeuronalNetworkService.h"

void NeuronalNetworkService::setWeights(const std::vector<std::vector<std::vector<double>>> &weights) {
    this->weights = weights;
}

void NeuronalNetworkService::setBias(const std::vector<double> &bias) {
    this->bias = bias;
}
void NeuronalNetworkService::setBatchSize(int batchSize) {
    this->batchSize = batchSize;
}

void NeuronalNetworkService::setIterations(int iterations) {
   this->iterations = iterations;
}

int NeuronalNetworkService::getBatchSize() {
    return this->batchSize;
}

void NeuronalNetworkService::setErrorFunction( ErrorFunction *errorFunction) {
    this->errorFunction = errorFunction;
}

void NeuronalNetworkService::setNn(const std::vector<NeuronalNetwork> &nn) {
    this->nn = nn;
}

void NeuronalNetworkService::setInput(int index, std::vector<double>& input) {
    nn[index].setInput(input);
}

void NeuronalNetworkService::setOutput(int index, std::vector<double>& ouput) {
    nn[index].setOutput(ouput);
}

void NeuronalNetworkService::setLearningRate(double learningRate) {
    this->learningRate = learningRate;
}

int NeuronalNetworkService::getIterations() {
    return iterations;
}

void NeuronalNetworkService::swapWeights() {

    for (int batch = 0; batch < batchSize; batch++) {
        std::vector<std::vector<std::vector<double>>> backWeights = nn[batch].getBackPropWeights();

        for (int matID = 0; matID < weights.size(); matID++) {
            for (int colID = 0; colID < weights[matID].size(); colID++) {
                for(int rowID  =0 ; rowID < weights[matID][colID].size();rowID++){
                    weights[matID][colID][rowID] -= (learningRate*(backWeights[matID][colID][rowID]/batchSize));
                    backWeights[matID][colID][rowID] = 0;
                }
            }
        }
    }
}

void NeuronalNetworkService::calculateSystemError(int index) {
    nn[index].setSystemError(errorFunction->calcSystemError(nn[index]));
}

void NeuronalNetworkService::printSystemError() {

    double error =  0;

    for(int i = 0 ; i< nn.size();i++){
        error+= nn[i].getSystemError();
    }

    std::cout<<"Systemerror: " << error<< std::endl;
}





