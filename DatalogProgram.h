#ifndef DATALOGPROGRAM_H
#define DATALOGPROGRAM_H
#include "Parameter.h"
#include "Predicate.h"
#include "Rule.h"
#include <string>
#include <vector>


class DatalogProgram {
private:
    std::vector<Predicate*> schemes;
    std::vector<Predicate*> facts;
    std::vector<Predicate*> queries;
    std::vector<Rule*> rules;
    std::vector<std::string> domain;

public:
    DatalogProgram();
    ~DatalogProgram();

    void toString();
    void addPredicateSchemes(std::string, std::vector<Parameter*>);
    void addPredicateFacts(std::string, std::vector<Parameter*>);
    void addPredicateQueries(std::string, std::vector<Parameter*>);
    void addRuleRules(Predicate*, std::vector<Predicate*>);

    void setDomain(std::vector<std::string>);

    std::vector<Predicate*> getSchemes();
    std::vector<Predicate*> getFacts();
    std::vector<Predicate*> getQueries();
    std::vector<Rule*> getRules();
};


#endif //DATALOGPROGRAM_H
