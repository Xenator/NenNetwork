//
// Created by Xen on 09.05.2023.
//

#include <cmath>
#include <vector>
#include "QuadraticFunction.h"

double QuadraticFunction::calc(std::vector<double> output, double preValue, int outNeuron) {

    return -2 * (1 / (double) output.size()) * (output[outNeuron] - preValue);

}

double QuadraticFunction::calcSystemError(NeuronalNetwork nn) {

    double systemError = 0;

    auto neurons = nn.getNeurons();
    auto output = nn.getOutput();
    for (int j = 0; j < output.size(); j++) {
        systemError += (1 / (double) output.size()) * (output[j] - neurons[neurons.size() - 1][j]) *
                       (output[j] - neurons[neurons.size() - 1][j]);
    }

    return systemError;
}
