//
// Created by Xen on 09.05.2023.
//

#ifndef FNN_INPUTSERVICE_H
#define FNN_INPUTSERVICE_H


#include <vector>

class InputService {

public:
    virtual void loadInput(std::vector<std::vector<double>>& input) = 0;
    virtual void loadOutput(std::vector<std::vector<double>>& output) = 0 ;
};


#endif //FNN_INPUTSERVICE_H
