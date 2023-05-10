//
// Created by Xen on 09.05.2023.
//

#ifndef FNN_NNSTATICPARAMETER_H
#define FNN_NNSTATICPARAMETER_H


#include "interface/NNParameterService.h"

class NNStaticParameter: public NNParameterService {


public:
    void setBatchSize(int batchSize);
    void setIteration(int iterations);
    void setLearningRate(double learningRate);
    void setLossFunction(ErrorFunction* errorFunction) ;


     int getBatchSize() override;
     double getLearningRate()override;
     int getIterations() override;
     ErrorFunction* getErrorFunction()override;

private:
    ErrorFunction *errorFunction;
    double learningRate;
    int iterations;
    int batchSize;
};


#endif //FNN_NNSTATICPARAMETER_H
