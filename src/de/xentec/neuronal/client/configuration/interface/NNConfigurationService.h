//
// Created by Xen on 09.05.2023.
//

#ifndef FNN_NNCONFIGURATIONSERVICE_H
#define FNN_NNCONFIGURATIONSERVICE_H


#include <vector>
#include "../../parameter/function/activation/interface/ActivationFunction.h"

class NNConfigurationService {
protected:

    std::vector<double> bias;
    std::vector<std::vector<std::vector<double>>> weights;
    ActivationFunction* activationFunction;

public:

    virtual std::vector<double> loadBias()=0;
    virtual std::vector<std::vector<std::vector<double>>> loadWeights()=0;


    ActivationFunction * getActivationFunction() ;
    void setActivationFunction(ActivationFunction* activationFunction);
};


#endif //FNN_NNCONFIGURATIONSERVICE_H
