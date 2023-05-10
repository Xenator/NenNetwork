//
// Created by Xen on 09.05.2023.
//

#ifndef FNN_NNLOADCONFIGURATION_H
#define FNN_NNLOADCONFIGURATION_H


#include "interface/NNConfigurationService.h"

class NNLoadConfiguration : public NNConfigurationService{

public:
    NNLoadConfiguration();
    std::vector<double> loadBias() override;
    std::vector<std::vector<std::vector<double>>> loadWeights() override;

    void setWeightFile(const char *filePath);
    void setBiasFile(const char *filePath);

private:

    const char *weightFilePath{};
    const char *biasFilePath{};
};


#endif //FNN_NNLOADCONFIGURATION_H
