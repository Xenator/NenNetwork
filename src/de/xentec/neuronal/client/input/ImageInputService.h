//
// Created by Xentex on 10.05.2023.
//

#ifndef NENNETWORK_IMAGEINPUTSERVICE_H
#define NENNETWORK_IMAGEINPUTSERVICE_H


#include "interface/InputService.h"
#include "model/image/Image.h"

class ImageInputService : public InputService{

public:
    void loadInput(std::vector<std::vector<double>>& input) override;
    void loadOutput(std::vector<std::vector<double>>& output)  override;

    void setInputPath(const char *filePath);

    void setLabelPath(const char *filePath);

private:

    std::vector<Image> images;
    const char *labelFilePath;
    const char *imageFilePath;
};


#endif //NENNETWORK_IMAGEINPUTSERVICE_H
