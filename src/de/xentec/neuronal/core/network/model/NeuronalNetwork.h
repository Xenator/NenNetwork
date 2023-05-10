//
// Created by Xen on 09.05.2023.
//

#ifndef FNN_NEURONALNETWORK_H
#define FNN_NEURONALNETWORK_H


#include <vector>
#include <functional>
#include "../../../client/parameter/function/activation/interface/ActivationFunction.h"

class NeuronalNetwork {
public:

    void setInput(const std::vector<double> &input);
    void setOutput(const std::vector<double> &output);


    ActivationFunction* getActivationFunction();
    void setActivationFunction(ActivationFunction *activationFunction);
    std::vector<std::vector<std::vector<double>>> &getBackPropWeights();

    void generateNeurons(std::vector<std::vector<std::vector<double>>> weights);
    std::vector<std::vector<double>> & getNeurons();

    std::vector<double> getOutput();

    std::vector<std::vector<double>>  getBackPropValue();

    void setBackPropValue(int layer, int neuron, double value);

    void setSystemError(double systemError);

    double getSystemError();

private:

    std::vector<double> input;
    std::vector<double> output;

    std::vector<std::vector<double>> neurons;
    std::vector<std::vector<double>> backProValues;

    ActivationFunction *activationFunction;

    std::vector<std::vector<std::vector<double>>> backPropWeights;
    void generateBackPropWeights(std::vector<std::vector<std::vector<double>>> weights);

    double systemError;
};


#endif //FNN_NEURONALNETWORK_H
