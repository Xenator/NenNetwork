//
// Created by Xen on 09.05.2023.
//

#ifndef FNN_NNPARAMETERSERVICE_H
#define FNN_NNPARAMETERSERVICE_H


#include "../function/error/interface/ErrorFunction.h"

class NNParameterService {
protected:

public:

    virtual int getBatchSize()=0;
    virtual double getLearningRate()=0;
    virtual int getIterations()=0;
    virtual ErrorFunction* getErrorFunction()=0;
};


#endif //FNN_NNPARAMETERSERVICE_H
