//
// Created by Xen on 09.05.2023.
//

#include <random>
#include "NNCreateConfiguration.h"

void NNCreateConfiguration::setNeurons(int *neurons, int size) {
    this->neurons = neurons;
    this->size = size;
}

std::vector<std::vector<std::vector<double>>> NNCreateConfiguration::loadWeights() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1.0, 1.0);

    weights.resize(size - 1);
    for (int i = 0; i < size - 1; i++) {
        weights[i].resize(neurons[i]);
        for (int j = 0; j < neurons[i]; j++) {
            weights[i][j].resize(neurons[i + 1]);
            for (int k = 0; k < neurons[i + 1]; k++) {
                weights[i][j][k] = dis(gen);
            }
        }
    }

    return weights;
}

std::vector<double> NNCreateConfiguration::loadBias() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1.0, 1.0);

    bias.resize(size - 1);
    for (int i = 0; i < size- 1; i++) {
        bias[i] = dis(gen);
    }
    return bias;
}

NNCreateConfiguration::NNCreateConfiguration() {

}


