//
// Created by Xen on 09.05.2023.
//

#ifndef FNN_CASESERVICE_H
#define FNN_CASESERVICE_H

#include "../../network/fullconntected/interface/NeuronalNetworkService.h"
#include "../../../client/input/interface/InputService.h"
#include "../../../client/output/interface/OutputService.h"

class CaseService {

protected:

    NeuronalNetworkService* nnService;
    InputService *inputService;
    OutputService *outputService;

public:

    CaseService(NeuronalNetworkService *nnService, InputService *inputService, OutputService *outputService);
     virtual void start()=0;
};


#endif //FNN_CASESERVICE_H
