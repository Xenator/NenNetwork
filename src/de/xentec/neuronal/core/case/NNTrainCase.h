//
// Created by Xen on 09.05.2023.
//

#ifndef FNN_NNTRAINCASE_H
#define FNN_NNTRAINCASE_H


#include "base/CaseService.h"
#include "../network/fullconntected/interface/NeuronalNetworkService.h"
#include "../../client/input/interface/InputService.h"
#include "../../client/output/interface/OutputService.h"

class NNTrainCase : public  CaseService{

private:
    std::vector<std::vector<double>> inputs;
    std::vector<std::vector<double>> outputs;
    void run(int batchIndex, int inputIndex);

public:

    NNTrainCase(NeuronalNetworkService *service, InputService *inputService, OutputService *outputService);
    void start() override;
};


#endif //FNN_NNTRAINCASE_H
