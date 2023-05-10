cmake_minimum_required(VERSION 3.25)
project(NenNetwork)

set(CMAKE_CXX_STANDARD 17)

set(HEADER_FILES

        src/de/xentec/neuronal/client/input/FileInputService.cpp
        src/de/xentec/neuronal/client/input/FileInputService.h
        src/Utils/Utils.h
        src/Utils/Utils.cpp
        )

set(SOURCE_FILES

        src/de/xentec/neuronal/client/input/interface/InputService.cpp
        src/de/xentec/neuronal/client/input/interface/InputService.h
        src/de/xentec/neuronal/client/input/NumberInputService.cpp
        src/de/xentec/neuronal/client/input/NumberInputService.h
        src/de/xentec/neuronal/client/output/interface/OutputService.cpp
        src/de/xentec/neuronal/client/output/interface/OutputService.h
        src/de/xentec/neuronal/client/output/FileOutputService.cpp
        src/de/xentec/neuronal/client/output/FileOutputService.h
        src/de/xentec/neuronal/client/parameter/interface/NNParameterService.cpp
        src/de/xentec/neuronal/client/parameter/interface/NNParameterService.h
        src/de/xentec/neuronal/client/parameter/NNStaticParameter.cpp
        src/de/xentec/neuronal/client/parameter/NNStaticParameter.h
        src/de/xentec/neuronal/client/parameter/function/error/QuadraticFunction.cpp
        src/de/xentec/neuronal/client/parameter/function/error/QuadraticFunction.h
        src/de/xentec/neuronal/client/parameter/function/error/interface/ErrorFunction.cpp
        src/de/xentec/neuronal/client/parameter/function/error/interface/ErrorFunction.h
        src/de/xentec/neuronal/client/parameter/function/activation/interface/ActivationFunction.cpp
        src/de/xentec/neuronal/client/parameter/function/activation/interface/ActivationFunction.h
        src/de/xentec/neuronal/client/parameter/function/activation/SigmoidFunction.cpp
        src/de/xentec/neuronal/client/parameter/function/activation/SigmoidFunction.h
        src/de/xentec/neuronal/client/configuration/interface/NNConfigurationService.cpp
        src/de/xentec/neuronal/client/configuration/interface/NNConfigurationService.h
        src/de/xentec/neuronal/client/configuration/NNCreateConfiguration.cpp
        src/de/xentec/neuronal/client/configuration/NNCreateConfiguration.h
        src/de/xentec/neuronal/client/configuration/NNLoadConfiguration.cpp
        src/de/xentec/neuronal/client/configuration/NNLoadConfiguration.h
        src/de/xentec/neuronal/core/network/fullconntected/FullConnectedService.cpp
        src/de/xentec/neuronal/core/network/fullconntected/FullConnectedService.h
        src/de/xentec/neuronal/core/network/fullconntected/interface/NeuronalNetworkService.cpp
        src/de/xentec/neuronal/core/network/fullconntected/interface/NeuronalNetworkService.h

        src/de/xentec/neuronal/core/case/base/CaseService.cpp
        src/de/xentec/neuronal/core/case/base/CaseService.h
        src/de/xentec/neuronal/core/case/NNTrainCase.cpp
        src/de/xentec/neuronal/core/case/NNTrainCase.h
        src/de/xentec/neuronal/core/case/NNPredictCase.cpp
        src/de/xentec/neuronal/core/case/NNPredictCase.h

        src/de/xentec/neuronal/core/network/model/NeuronalNetwork.cpp
        src/de/xentec/neuronal/core/network/model/NeuronalNetwork.h
        src/de/xentec/neuronal/core/network/fullconntected/builder/FullConnectedBuilder.cpp
        src/de/xentec/neuronal/core/network/fullconntected/builder/FullConnectedBuilder.h
        src/de/xentec/neuronal/client/input/decoder/base/DecoderInterface.h
        src/de/xentec/neuronal/client/input/decoder/FileTextDecoder.h
        src/de/xentec/neuronal/client/input/decoder/MNISTDecoder.h
        src/de/xentec/neuronal/client/input/decoder/MNISTDecoder.cpp
        src/de/xentec/neuronal/client/input/decoder/FileTextDecoder.cpp

        src/de/xentec/neuronal/client/input/ImageInputService.cpp
        src/de/xentec/neuronal/client/input/ImageInputService.h
        src/de/xentec/neuronal/client/input/model/image/Image.h
        src/de/xentec/neuronal/client/input/model/image/Image.cpp

        )


add_library(FNN_LIB STATIC  ${HEADER_FILES}  ${SOURCE_FILES} )

add_executable(NenNetwork main.cpp)

target_link_libraries(NenNetwork FNN_LIB)

file(COPY ${CMAKE_SOURCE_DIR}/res DESTINATION ${CMAKE_BINARY_DIR})
