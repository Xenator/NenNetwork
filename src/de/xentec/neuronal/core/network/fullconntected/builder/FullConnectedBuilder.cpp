//
// Created by Xen on 09.05.2023.
//

#include "FullConnectedBuilder.h"
#include "../FullConnectedService.h"

FullConnectedBuilder::FullConnectedBuilder(NNParameterService*  parameterService, NNConfigurationService*  configService)
{

    this->parameterService = parameterService;
    this->configService = configService;
}

NeuronalNetworkService *FullConnectedBuilder::build() {

    auto* service = new FullConnectedService();

    service->setBatchSize(parameterService->getBatchSize());
    service->setLearningRate(parameterService->getLearningRate());
    service->setIterations(parameterService->getIterations());
    service->setErrorFunction(parameterService->getErrorFunction());

    auto weights = configService->loadWeights();
    service->setWeights(weights);
    service->setBias(configService->loadBias());

    std::vector<NeuronalNetwork> list = std::vector<NeuronalNetwork>(service->getBatchSize());

    for(int i = 0; i < service->getBatchSize();i++){
        list[i] = NeuronalNetwork();
        list[i].setActivationFunction(configService->getActivationFunction());
        list[i].generateNeurons(weights);
    }

    service->setNn(list);

    return service;
}
