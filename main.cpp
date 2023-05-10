

#include "src/de/xentec/neuronal/client/input/FileInputService.h"
#include "src/de/xentec/neuronal/client/input/NumberInputService.h"
#include "src/de/xentec/neuronal/client/output/FileOutputService.h"
#include "src/de/xentec/neuronal/client/parameter/NNStaticParameter.h"
#include "src/de/xentec/neuronal/client/parameter/function/error/QuadraticFunction.h"
#include "src/de/xentec/neuronal/client/configuration/NNLoadConfiguration.h"
#include "src/de/xentec/neuronal/client/parameter/function/activation/SigmoidFunction.h"
#include "src/de/xentec/neuronal/client/configuration/NNCreateConfiguration.h"
#include "src/de/xentec/neuronal/core/network/fullconntected/builder/FullConnectedBuilder.h"
#include "src/de/xentec/neuronal/core/case/NNTrainCase.h"

int main() {

///*******************************      INPUT        ***************************************************************
    auto* fInputService = new FileInputService();
    fInputService->setInputPath("/youtube/input.txt");
    fInputService->setLabelPath("/youtube/output.txt");

    auto* nInputService = new NumberInputService();
    nInputService->setInputNumber(new double[]{0.2 , 0.1, }, 2);
    nInputService->setLabelNumber(new double[]{0.4,0.9},2);

    InputService*  inputService= fInputService;

///*******************************      OUTPUT        **************************************************************
    auto*output = new FileOutputService();
    output->setWeightFile("weights_new.txt");
    output->setBiasFile("bias_new.txt");

    OutputService*   outputService= output;

///*******************************      PARAMETER        **********************************************************
    auto*parameter = new NNStaticParameter();
    parameter->setBatchSize(1);
    parameter->setIteration(10000);
    parameter->setLearningRate(0.5);
    parameter->setLossFunction(new QuadraticFunction());

    NNParameterService*  parameterService = parameter;

///*******************************    NN CONFIG        ************************************************************
    NNLoadConfiguration *config = new NNLoadConfiguration();
    config->setWeightFile("/youtube/weights.txt");
    config->setBiasFile("/youtube/bias.txt");
    config->setActivationFunction(SigmoidFunction::create());

    NNCreateConfiguration *configs = new NNCreateConfiguration();
    configs->setNeurons(new int[]{2,2,2},3);
    configs->setActivationFunction(SigmoidFunction::create());

    NNConfigurationService* configService = config;

///*******************************    NN  Service        ************************************************************
    auto* builder= new FullConnectedBuilder(parameterService,configService);
    auto* nnSerivce = builder->build();

///*******************************    NN Case Service        ************************************************************
    CaseService* caseService = new NNTrainCase(nnSerivce, inputService, outputService);
    caseService->start();

    return 0;
}
