#ifndef RULE_H
#define RULE_H
#include "Predicate.h"
#include <vector>


class Rule {
private:
    Predicate* headPredicate;
    std::vector<Predicate*> bodyPredicates;

public:
    Rule(Predicate*, std::vector<Predicate*>);
    ~Rule();

    void toString();
};


#endif //RULE_H
