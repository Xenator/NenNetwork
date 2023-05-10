//
// Created by Xen on 09.05.2023.
//

#ifndef FNN_INPUTSERVICE_H
#define FNN_INPUTSERVICE_H


#include <vector>

class InputService {

public:
    virtual std::vector<std::vector<double>>loadInput() =0;
    virtual std::vector<std::vector<double>>loadOutput() =0;
};


#endif //FNN_INPUTSERVICE_H
