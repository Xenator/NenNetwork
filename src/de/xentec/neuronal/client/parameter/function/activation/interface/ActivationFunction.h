//
// Created by Xen on 09.05.2023.
//

#ifndef FNN_ACTIVATIONFUNCTION_H
#define FNN_ACTIVATIONFUNCTION_H


class ActivationFunction {

public:
    virtual double calc(double value)=0 ;
    virtual double nCalc(double value)=0;
};


#endif //FNN_ACTIVATIONFUNCTION_H
