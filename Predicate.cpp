#include "Predicate.h"
#include <iostream>

Predicate::Predicate(std::string inputString, std::vector<Parameter*> inputParameters) {
    id = inputString;
    parameters = inputParameters;
}

Predicate::~Predicate() {
// for (unsigned int i = 0; i < parameters.size(); i++) {
//     delete parameters.at(i);
// }
// parameters.clear();
}

void Predicate::toString() {
    std::cout << id << "(";
    for (unsigned int i = 0; i < parameters.size()-1; i++) {
        parameters.at(i)->toString();
        std::cout << ",";
    }
    parameters.at(parameters.size()-1)->toString();
    std::cout << ")";
}

std::string Predicate::returnId() {
    return id;
}

std::vector<Parameter *> Predicate::returnParams() {
    return parameters;
}




