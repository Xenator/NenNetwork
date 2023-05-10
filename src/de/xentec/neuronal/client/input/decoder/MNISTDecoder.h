//
// Created by Xen on 01.05.2023.
//

#ifndef FNN_MNISTDECODER_H
#define FNN_MNISTDECODER_H


#include "base/DecoderInterface.h"

class MNISTDecoder : public DecoderInterface {

public:

    std::vector<std::vector<double>> loadInput(const char*inputPath, const char* labelPath) override;


};


#endif //FNN_MNISTDECODER_H
