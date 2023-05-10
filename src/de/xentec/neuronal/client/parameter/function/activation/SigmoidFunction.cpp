//
// Created by Xen on 09.05.2023.
//

#include "SigmoidFunction.h"

SigmoidFunction* SigmoidFunction::instance = nullptr;

ActivationFunction * SigmoidFunction::create() {

    if(instance == nullptr){
        instance = new SigmoidFunction();
    }
    return instance;
}

double SigmoidFunction::calc(double value) {

    return 1 /( 1 +exp(-value));
}

double SigmoidFunction::nCalc(double value) {
    return value*(1-value);
}

SigmoidFunction::SigmoidFunction() = default;