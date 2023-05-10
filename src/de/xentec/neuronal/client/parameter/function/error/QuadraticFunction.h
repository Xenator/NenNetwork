//
// Created by Xen on 09.05.2023.
//

#ifndef FNN_QUADRATICFUNCTION_H
#define FNN_QUADRATICFUNCTION_H


#include "interface/ErrorFunction.h"

class QuadraticFunction: public ErrorFunction{
public:
    double calc(std::vector<double> output, double preValue, int outNeuron) override;
    double calcSystemError(NeuronalNetwork nn) override;
};


#endif //FNN_QUADRATICFUNCTION_H
