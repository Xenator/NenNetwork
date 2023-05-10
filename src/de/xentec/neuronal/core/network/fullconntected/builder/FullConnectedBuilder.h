//
// Created by Xen on 09.05.2023.
//

#ifndef FNN_FULLCONNECTEDBUILDER_H
#define FNN_FULLCONNECTEDBUILDER_H


#include "../../../../client/input/interface/InputService.h"
#include "../../../../client/parameter/interface/NNParameterService.h"
#include "../../../../client/output/interface/OutputService.h"
#include "../../../../client/configuration/interface/NNConfigurationService.h"
#include "../interface/NeuronalNetworkService.h"

class FullConnectedBuilder {

private:

    NNParameterService*  parameterService;
    NNConfigurationService*  configService;

public:

    FullConnectedBuilder(NNParameterService *parameterService,
                         NNConfigurationService *configService);

    NeuronalNetworkService *build();
};


#endif //FNN_FULLCONNECTEDBUILDER_H
