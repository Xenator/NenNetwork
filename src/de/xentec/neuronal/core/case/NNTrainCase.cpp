//
// Created by Xen on 09.05.2023.
//

#include <thread>
#include <iostream>
#include "NNTrainCase.h"

NNTrainCase::NNTrainCase(NeuronalNetworkService *nnService, InputService *inputService, OutputService *outputService)
        : CaseService(nnService, inputService, outputService) {

}

void NNTrainCase::run(int batchIndex,int inputIndex) {

    nnService->setInput(batchIndex,inputs[inputIndex]);
    nnService->setOutput(batchIndex, outputs[inputIndex]);
    nnService->feedForeward(batchIndex);
    nnService->backPropagation(batchIndex);
}

void NNTrainCase::start() {
    inputService->loadInput(inputs);
    inputService->loadOutput(outputs);

    std::vector<std::thread> threads;
    threads.reserve(nnService->getBatchSize());

    for(int i = 0 ; i < nnService->getIterations();i++){
        for(int index = 0 ; index< inputs.size();index= index+nnService->getBatchSize()){

            for(int batch = 0 ; batch < nnService->getBatchSize() && (batch+index) < inputs.size() ;batch++){
                 threads.emplace_back(&NNTrainCase::run, this, batch, index+batch);
            }

            for (auto &thread: threads) {
                thread.join();
            }

            nnService->printSystemError();
            nnService->swapWeights();
            threads.clear();
        }
    }

}
