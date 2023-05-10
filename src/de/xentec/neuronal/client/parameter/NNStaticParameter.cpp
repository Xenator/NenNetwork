//
// Created by Xen on 09.05.2023.
//

#include "NNStaticParameter.h"

void NNStaticParameter::setBatchSize(int batchSize) {
    this->batchSize = batchSize;
}

void NNStaticParameter::setIteration(int iterations) {
    this->iterations = iterations;
}

void NNStaticParameter::setLearningRate(double learningRate) {
    this->learningRate = learningRate;
}

void NNStaticParameter::setLossFunction(ErrorFunction *errorFunction) {
    this->errorFunction = errorFunction;
}

int NNStaticParameter::getBatchSize() {
    return batchSize;
}

double NNStaticParameter::getLearningRate() {
    return learningRate;
}

int NNStaticParameter::getIterations() {
    return iterations;
}

ErrorFunction* NNStaticParameter::getErrorFunction() {
    return errorFunction;
}

