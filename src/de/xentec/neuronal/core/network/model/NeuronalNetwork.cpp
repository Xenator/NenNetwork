//
// Created by Xen on 09.05.2023.
//

#include "NeuronalNetwork.h"

ActivationFunction* NeuronalNetwork::getActivationFunction() {
    return activationFunction;
}

void NeuronalNetwork::setActivationFunction(ActivationFunction *activationFunction) {
    this->activationFunction = activationFunction;
}

void NeuronalNetwork::setInput(const std::vector<double> &input) {
    this->input = input;
    neurons[0] = input;
}


void NeuronalNetwork::setOutput(const std::vector<double> &output) {
    this->output = output;
}

std::vector<std::vector<std::vector<double>>> &NeuronalNetwork::getBackPropWeights() {
    return backPropWeights;
}

void NeuronalNetwork::generateBackPropWeights(std::vector<std::vector<std::vector<double>>> weights) {

    backPropWeights.resize(weights.size());
    for(int i = 0 ; i< weights.size();i++){

        backPropWeights[i].resize(weights[i].size());
        for(int j = 0 ; j< weights[i].size();j++){
            backPropWeights[i][j].resize(weights[i][j].size());
            for(int k = 0 ; k< weights[i][j].size();k++) {
                backPropWeights[i][j][k] =0;
            }
        }
    }

}


void NeuronalNetwork::generateNeurons(std::vector<std::vector<std::vector<double>>> weights) {

    neurons.resize(weights.size()+1);
    backProValues.resize(weights.size()+1);

    neurons[0].resize(weights[0].size());
    backProValues[0].resize(weights[0].size());
    for (int i = 0; i < neurons.size()-1; i++) {
        neurons[i+1].resize(weights[i][0].size());
        backProValues[i+1].resize(weights[i][0].size());
    }

    generateBackPropWeights(weights);
}

std::vector<std::vector<double>>& NeuronalNetwork::getNeurons() {
    return neurons;
}

std::vector<double> NeuronalNetwork::getOutput() {
    return output;
}

std::vector<std::vector<double>> NeuronalNetwork::getBackPropValue() {
    return backProValues;
}

void NeuronalNetwork::setBackPropValue(int layer, int neuron, double value) {
    backProValues[layer][neuron] = value;
}

void NeuronalNetwork::setSystemError(double systemError) {
    this->systemError = systemError;
}

double NeuronalNetwork::getSystemError() {
    return systemError;
}

