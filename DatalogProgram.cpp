#include "DatalogProgram.h"
#include <iostream>
#include <algorithm>

DatalogProgram::DatalogProgram() {

}

DatalogProgram::~DatalogProgram() {
//    for (unsigned int i = 0; i < schemes.size(); i++) {
//        delete schemes.at(i);
//    }
//    schemes.clear();
//    for (unsigned int i = 0; i < facts.size(); i++) {
//        delete facts.at(i);
//    }
//    facts.clear();
//    for (unsigned int i = 0; i < queries.size(); i++) {
//        delete queries.at(i);
//    }
//    queries.clear();
//    for (unsigned int i = 0; i < rules.size(); i++) {
//        delete rules.at(i);
//    }
//    rules.clear();
}

void DatalogProgram::toString() {
    std::cout << "Schemes(" << std::to_string(schemes.size()) << "):\n";
    if (!schemes.empty()) {
        for (unsigned int i = 0; i < schemes.size(); i++) {
            std::cout << "  ";
            schemes.at(i)->toString();
            std::cout << "\n";
        }
    }
    std::cout << "Facts(" << std::to_string(facts.size()) << "):\n";
    if (!facts.empty()) {
        for (unsigned int i = 0; i < facts.size(); i++) {
            std::cout << "  ";
            facts.at(i)->toString();
            std::cout << ".\n";
        }
    }
    std::cout << "Rules(" << std::to_string(rules.size()) << "):\n";
    if (!rules.empty()) {
        for (unsigned int i = 0; i < rules.size(); i++) {
            std::cout << "  ";
            rules.at(i)->toString();
            std::cout << ".\n";
        }
    }
    std::cout << "Queries(" << std::to_string(queries.size()) << "):\n";
    if (!queries.empty()) {
        for (unsigned int i = 0; i < queries.size(); i++) {
            std::cout << "  ";
            queries.at(i)->toString();
            std::cout << "?\n";
        }
    }
    std::cout << "Domain(" << std::to_string(domain.size()) << "):";
    if (!domain.empty()) {
        std::sort(domain.begin(), domain.end());
        for (unsigned int i = 0; i < domain.size(); i++) {
            std::cout << "\n  " << domain.at(i);
        }
    }
}

void DatalogProgram::addPredicateSchemes(std::string id, std::vector<Parameter*> parameters) {
    Predicate* inPredicate = new Predicate(id, parameters);
    schemes.push_back(inPredicate);
}

void DatalogProgram::setDomain(std::vector<std::string> inputDomain) {
    domain = inputDomain;
}

void DatalogProgram::addPredicateFacts(std::string id, std::vector<Parameter*> parameters) {
    Predicate* inPredicate = new Predicate(id, parameters);
    facts.push_back(inPredicate);
}

void DatalogProgram::addPredicateQueries(std::string id, std::vector<Parameter*> parameters) {
    Predicate* inPredicate = new Predicate(id, parameters);
    queries.push_back(inPredicate);
}

void DatalogProgram::addRuleRules(Predicate* hPredicate, std::vector<Predicate*>bPredicates) {
    Rule* inRule = new Rule(hPredicate, bPredicates);
    rules.push_back(inRule);
}

std::vector<Predicate *> DatalogProgram::getSchemes() {
    return schemes;
}

std::vector<Predicate *> DatalogProgram::getFacts() {
    return facts;
}

std::vector<Predicate *> DatalogProgram::getQueries() {
    return queries;
}

std::vector<Rule *> DatalogProgram::getRules() {
    return rules;
}
