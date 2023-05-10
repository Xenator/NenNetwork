//
// Created by Xen on 09.05.2023.
//

#include "CaseService.h"

CaseService::CaseService(NeuronalNetworkService *nnService, InputService *inputService, OutputService *outputService)
        : nnService(nnService), inputService(inputService), outputService(outputService) {

}

