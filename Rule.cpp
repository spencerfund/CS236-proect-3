#include "Rule.h"
#include <iostream>

Rule::Rule(Predicate* hPredicate, std::vector<Predicate*> bPredicates) {
    headPredicate = hPredicate;
    bodyPredicates = bPredicates;
}

Rule::~Rule() {
//    delete headPredicate;
//    for (unsigned int i = 0; i < bodyPredicates.size(); i++) {
//        delete bodyPredicates.at(i);
//    }
//    bodyPredicates.clear();
}

void Rule::toString() {
    headPredicate->toString();
    std::cout << " :- ";
    for (unsigned int i = 0; i < bodyPredicates.size() - 1; i++) {
        bodyPredicates.at(i)->toString();
        std::cout << ",";
    }
    bodyPredicates.at(bodyPredicates.size()-1)->toString();
}
