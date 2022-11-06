#ifndef PREDICATE_H
#define PREDICATE_H
#include "Parameter.h"
#include <vector>
#include <string>


class Predicate {
private:
    std::string id;
    std::vector<Parameter*> parameters;

public:
    Predicate(std::string, std::vector<Parameter*>);
    ~Predicate();

    void toString();
    std::string returnId();
    std::vector<Parameter*> returnParams();
};


#endif //PREDICATE_H
