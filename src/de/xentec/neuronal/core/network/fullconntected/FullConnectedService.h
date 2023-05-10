//
// Created by Xen on 09.05.2023.
//

#ifndef FNN_FULLCONNECTEDSERVICE_H
#define FNN_FULLCONNECTEDSERVICE_H


#include "interface/NeuronalNetworkService.h"
#include "../../../client/input/interface/InputService.h"
#include "../../../client/output/interface/OutputService.h"
#include "../../../client/parameter/interface/NNParameterService.h"
#include "../../../client/configuration/interface/NNConfigurationService.h"

class FullConnectedService : public  NeuronalNetworkService{

public:
    FullConnectedService();
    void feedForeward(int index) override;
    void backPropagation(int index) override;
    void backPack(int neuron, int layer, int index) override;

private:


};


#endif //FNN_FULLCONNECTEDSERVICE_H
