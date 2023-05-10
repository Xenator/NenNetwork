//
// Created by Xen on 09.05.2023.
//

#ifndef FNN_SIGMOIDFUNCTION_H
#define FNN_SIGMOIDFUNCTION_H

#include <cmath>
#include "interface/ActivationFunction.h"

class SigmoidFunction : public ActivationFunction{
private:

    static SigmoidFunction* instance;

    SigmoidFunction();

public:
    double calc(double value) override;
    double nCalc(double value) override;

    static ActivationFunction * create();
};


#endif //FNN_SIGMOIDFUNCTION_H
