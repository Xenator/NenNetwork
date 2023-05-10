//
// Created by Xen on 09.05.2023.
//

#ifndef FNN_NNPREDICTCASE_H
#define FNN_NNPREDICTCASE_H


#include "base/CaseService.h"

class NNPredictCase : public CaseService{

public:
    NNPredictCase(NeuronalNetworkService *service, InputService *inputService, OutputService *outputService);
    void start() override;
};


#endif //FNN_NNPREDICTCASE_H
