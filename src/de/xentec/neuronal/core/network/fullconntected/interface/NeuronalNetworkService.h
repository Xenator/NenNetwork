//
// Created by Xen on 09.05.2023.
//

#ifndef FNN_NEURONALNETWORKSERVICE_H
#define FNN_NEURONALNETWORKSERVICE_H


#include "../../model/NeuronalNetwork.h"
#include "../../../../client/parameter/function/error/interface/ErrorFunction.h"

class NeuronalNetworkService {
public:

    void setWeights(const std::vector<std::vector<std::vector<double>>> &weights);
    void setBias(const std::vector<double> &bias);
    void setNn(const std::vector<NeuronalNetwork>& nn);
    void setErrorFunction( ErrorFunction *errorFunction);

    void setBatchSize(int batchSize);
    int getBatchSize();
    void setIterations(int iterations);
    void setLearningRate(double learningRate);

    void setInput(int index, std::vector<double>& input);
    void setOutput(int index, std::vector<double>& ouput);

    virtual void feedForeward(int index) =0;
    virtual  void backPropagation(int index) =0;
    virtual  void backPack(int run, int layerRun, int inputRun) =0;


    void swapWeights();

    int getIterations();


    void printSystemError();

protected:

    int batchSize;
    int iterations;
    double learningRate;
    ErrorFunction* errorFunction;

    std::vector<std::vector<std::vector<double>>> weights;
    std::vector<double> bias;

    std::vector<NeuronalNetwork> nn;

    void calculateSystemError(int index);
};


#endif //FNN_NEURONALNETWORKSERVICE_H
