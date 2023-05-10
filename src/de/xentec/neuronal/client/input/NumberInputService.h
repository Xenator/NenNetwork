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


    void loadInput(std::vector<std::vector<double>>& input) override;
    void loadOutput(std::vector<std::vector<double>>& output)  override;
private:

    double *label;
    int labelSize;
    double *input;
    int inputSize;
};


#endif //FNN_NUMBERINPUTSERVICE_H
