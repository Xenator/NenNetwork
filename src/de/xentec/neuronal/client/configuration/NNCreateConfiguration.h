//
// Created by Xen on 09.05.2023.
//

#ifndef FNN_NNCREATECONFIGURATION_H
#define FNN_NNCREATECONFIGURATION_H


#include "interface/NNConfigurationService.h"

class NNCreateConfiguration : public NNConfigurationService{

private:
    int *neurons;
    int size;

public:
    NNCreateConfiguration();
    void setNeurons(int *neurons, int size);

    std::vector<double> loadBias() override;
    std::vector<std::vector<std::vector<double>>> loadWeights() override;

};


#endif //FNN_NNCREATECONFIGURATION_H
