//
// Created by Xen on 09.05.2023.
//

#ifndef FNN_FILEOUTPUTSERVICE_H
#define FNN_FILEOUTPUTSERVICE_H


#include "interface/OutputService.h"

class FileOutputService : public OutputService{

public:
    void setWeightFile(const char *filePath);

    void setBiasFile(const char *filePath);
};


#endif //FNN_FILEOUTPUTSERVICE_H
