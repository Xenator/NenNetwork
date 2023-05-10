//
// Created by Xen on 09.05.2023.
//

#ifndef FNN_FILEINPUTSERVICE_H
#define FNN_FILEINPUTSERVICE_H


#include "interface/InputService.h"
#include "decoder/base/DecoderInterface.h"

class FileInputService : public  InputService{

public:

    void setInputPath(const char *filePath);
    void setLabelPath(const char *filePath);

     std::vector<std::vector<double>>loadInput() override;
     std::vector<std::vector<double>>loadOutput() override;

private:

    const char *inputFilePath;
    const char *labelFilePath;
};


#endif //FNN_FILEINPUTSERVICE_H
