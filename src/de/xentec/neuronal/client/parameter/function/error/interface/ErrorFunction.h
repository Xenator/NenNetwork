//
// Created by Xen on 09.05.2023.
//

#ifndef FNN_ERRORFUNCTION_H
#define FNN_ERRORFUNCTION_H


#include "../../../../../core/network/model/NeuronalNetwork.h"
#include <vector>

class ErrorFunction {
public:
    virtual double calc(std::vector<double> output, double preValue, int outNeuron) = 0;
    virtual double calcSystemError(NeuronalNetwork nn) = 0;
};


#endif //FNN_ERRORFUNCTION_H
