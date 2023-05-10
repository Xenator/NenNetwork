//
// Created by Xen on 09.05.2023.
//

#include "NNConfigurationService.h"


void NNConfigurationService::setActivationFunction(ActivationFunction *activationFunction) {
    this->activationFunction = activationFunction;
}

ActivationFunction* NNConfigurationService::getActivationFunction() {
    return activationFunction;
}
