//
// Created by Xen on 09.05.2023.
//

#include "NNPredictCase.h"

void NNPredictCase::start() {

}

NNPredictCase::NNPredictCase(NeuronalNetworkService *service, InputService *inputService, OutputService *outputService)
        : CaseService(service, inputService, outputService) {

}
