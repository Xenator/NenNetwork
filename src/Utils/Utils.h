//
// Created by Xen on 08.04.2023.
//

#ifndef FNN_UTILS_H
#define FNN_UTILS_H


#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

class Utils {
public:
    static std::string readFile(const char* path);

    static void  parseMatrices(const std::string &text, std::vector<std::vector<std::vector<double>>> &matrices );
    static void  parseMatrices2D(const std::string &text, std::vector<std::vector<double>> &matrices );
    static void  parseMatrices1D(const std::string &text, std::vector<double> &matrices );

    static void safeWeights(const char *path, std::vector<std::vector<std::vector<double>>> weights);

    static void safeBias(const char *string, std::vector<double> vector1);
};


#endif //FNN_UTILS_H
