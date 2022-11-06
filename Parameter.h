#ifndef PARAMETER_H
#define PARAMETER_H
#include <string>


class Parameter {
private:
    std::string content = "";
    bool isConstant;
public:
    Parameter(std::string);
    ~Parameter();

    void toString();

    std::string returnContent();
    bool returnIsConstant();
};


#endif //PARAMETER_H
