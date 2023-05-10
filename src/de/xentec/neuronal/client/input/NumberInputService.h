//
// Created by Xen on 09.05.2023.
//

#ifndef FNN_NUMBERINPUTSERVICE_H
#define FNN_NUMBERINPUTSERVICE_H


#include "interface/InputService.h"

class NumberInputService : public InputService{

public:
    void setInputNumber(double *input, int size);
    void setLabelNumber(double *label, int size);


    std::vector<std::vector<double>>loadInput() override;
    std::vector<std::vector<double>>loadOutput() override;
private:

    double *label;
    int labelSize;
    double *input;
    int inputSize;
};


#endif //FNN_NUMBERINPUTSERVICE_H
