//
// Created by Xen on 01.05.2023.
//

#ifndef FNN_FILETEXTDECODER_H
#define FNN_FILETEXTDECODER_H


#include "base/DecoderInterface.h"
#include "../../../../../../Utils/Utils.h"

class FileTextDecoder : public DecoderInterface {
public:
    std::vector<std::vector<double>> loadInput(const char*inputPath, const char* labelPath) override ;
};


#endif //FNN_FILETEXTDECODER_H
