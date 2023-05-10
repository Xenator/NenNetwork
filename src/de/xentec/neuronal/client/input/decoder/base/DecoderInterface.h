//
// Created by Xen on 01.05.2023.
//

#ifndef FNN_DECODERINTERFACE_H
#define FNN_DECODERINTERFACE_H

#include <vector>

class DecoderInterface{

public:
    virtual std::vector<std::vector<double>> loadInput(const char*inputPath, const char* labelPath) = 0;

};

#endif //FNN_DECODERINTERFACE_H
