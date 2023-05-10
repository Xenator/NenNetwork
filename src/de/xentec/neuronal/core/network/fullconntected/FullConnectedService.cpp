//
// Created by Xen on 09.05.2023.
//

#include <iostream>
#include "FullConnectedService.h"



FullConnectedService::FullConnectedService() {

}

void FullConnectedService::backPropagation(int index) {
    auto neurons = nn[index].getNeurons();
    for(int layer =  neurons.size()-1; layer > 0 ; layer--){
        for(int neuron =0 ; neuron < neurons[layer].size();neuron++){
            backPack(neuron, layer, index);
        }
    }
}


void FullConnectedService::backPack(int neuron, int layer, int index) {

    double v1 = 0;
    if(layer < weights.size() ){

        for(int layNeuron = 0  ;layNeuron<  nn[index].getBackPropValue()[layer + 1].size(); layNeuron++){
            v1 += weights[layer][neuron][layNeuron] * nn[index].getBackPropValue()[layer + 1][layNeuron];
        }
    }else{
        v1 = this->errorFunction->calc(nn[index].getOutput(), nn[index].getNeurons()[layer][neuron], neuron );
    }

    double v2 =  nn[index].getActivationFunction()->nCalc(nn[index].getNeurons()[layer][neuron]);

    for(int i = 0; i < weights[layer - 1].size() ; i++){
        nn[index].getBackPropWeights()[layer - 1][i][neuron] = v1 * v2 * nn[index].getNeurons()[layer - 1][i];
        nn[index].getNeurons()[layer][neuron] =0;
    }

    nn[index].setBackPropValue(layer, neuron, v1 * v2);
}


void FullConnectedService::feedForeward(int index) {

    auto& neurons = nn[index].getNeurons();
    for (int layerIdx = 0; layerIdx < neurons.size() - 1; layerIdx++) {

         ActivationFunction* activeFunction = nn[index].getActivationFunction();
        for (int nextLayerNeuron = 0; nextLayerNeuron < neurons[layerIdx + 1].size(); nextLayerNeuron++) {

            double& neuron =  neurons[layerIdx+1][nextLayerNeuron];

            for (int currentLayerNeuron = 0; currentLayerNeuron < neurons[layerIdx].size(); currentLayerNeuron++) {

                neuron += neurons[layerIdx][currentLayerNeuron] *
                          weights[layerIdx][currentLayerNeuron][nextLayerNeuron];
            }
            neuron += bias[layerIdx];
            neuron = activeFunction->calc(neuron);
        }
    }

    calculateSystemError(index);
}