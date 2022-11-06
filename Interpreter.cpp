#include "Interpreter.h"
#include "Predicate.h"
#include "Parameter.h"
#include <map>
#include <iostream>

Interpreter::Interpreter(DatalogProgram inProgram) {
    program = inProgram;
}

Interpreter::~Interpreter() = default;

void Interpreter::InterpretSchemes() {
    schemes = program.getSchemes();
    for (unsigned int i = 0; i < schemes.size(); i++) {
        std::string schemeName = schemes.at(i)->returnId();
        std::vector<Parameter*> schemePredicates = schemes.at(i)->returnParams();
        std::vector<std::string> translatedPreds;
        for (unsigned int j = 0; j < schemePredicates.size(); j++) {
            translatedPreds.push_back(schemePredicates.at(j)->returnContent());
        }
        Header newHeader(translatedPreds);
        Relation newRelation(schemeName, newHeader);
        dBase.AddRelation(newRelation);
    }
}

void Interpreter::InterpretFacts() {
    facts = program.getFacts();
    for (unsigned int i = 0; i < facts.size(); i++) {
        std::string factName = facts.at(i)->returnId();
        std::vector<Parameter*> factValues = facts.at(i)->returnParams();
        Tuple newTuple;
        for ( unsigned int j = 0; j < factValues.size(); j++) {
            newTuple.addValue(factValues.at(j)->returnContent());
        }
        //dBase.GetRelation(factName)->AddTuple(newTuple);
        dBase.addTupleToRel(factName,newTuple);
    }
}

Relation Interpreter::evaluatePredicate(Predicate* p) {
    std::string qName = p->returnId();
    std::map<std::string,int> usedVariables;
    std::vector<std::string> names;
    std::vector<Parameter*> qParams = p->returnParams();
    Relation returnR = dBase.GetRelationCopy(qName);
    for (unsigned int i = 0; i < qParams.size(); i++) {
        if (qParams.at(i)->returnIsConstant()) {
            //Select 1 function
            returnR = returnR.select1(i,qParams.at(i)->returnContent());
        }
        else {
            if (usedVariables.empty()) {
                usedVariables[qParams.at(i)->returnContent()] = i;
                names.push_back(qParams.at(i)->returnContent());
            }
            else if (usedVariables.find(qParams.at(i)->returnContent()) == usedVariables.end()) {
                usedVariables[qParams.at(i)->returnContent()] = i;
                names.push_back(qParams.at(i)->returnContent());
            }
            else {
                //Select 2 function
                returnR = returnR.select2(usedVariables[qParams.at(i)->returnContent()],i);
            }
        }
    }
    std::vector<int> colsToProject;
    for(unsigned int i = 0; i < names.size(); i++) {
        colsToProject.push_back(usedVariables[names.at(i)]);
    }
    returnR = returnR.project(colsToProject);
    returnR = returnR.rename(names);
    return returnR;
}

void Interpreter::InterpretQueries() {
    queries = program.getQueries();
    for (unsigned int i = 0; i < queries.size(); i++) {
        Predicate* evalP = queries.at(i);
        Relation returnedRel = evaluatePredicate(evalP);
        Relation returnSelect = selectPredicate(evalP);
        evalP->toString();
        std::string isEmpty;
        if (std::stoi(returnSelect.countTuples()) > 0) {
            isEmpty = "Yes";
        }
        else {
            isEmpty = "No";
        }
        std::cout << "? " << isEmpty;
        if (isEmpty == "Yes") {
           std::cout << "(" << returnSelect.countTuples() << ")";
        }
        std::cout << std::endl;
        returnedRel.toString();
    }
}

Relation Interpreter::selectPredicate(Predicate* p) {
    std::string qName = p->returnId();
    std::map<std::string,int> usedVariables;
    std::vector<std::string> names;
    std::vector<Parameter*> qParams = p->returnParams();
    Relation returnR = dBase.GetRelationCopy(qName);
    for (unsigned int i = 0; i < qParams.size(); i++) {
        if (qParams.at(i)->returnIsConstant()) {
            //Select 1 function
            returnR = returnR.select1(i,qParams.at(i)->returnContent());
        }
        else {
            if (usedVariables.empty()) {
                usedVariables[qParams.at(i)->returnContent()] = i;
                names.push_back(qParams.at(i)->returnContent());
            }
            else if (usedVariables.find(qParams.at(i)->returnContent()) == usedVariables.end()) {
                usedVariables[qParams.at(i)->returnContent()] = i;
                names.push_back(qParams.at(i)->returnContent());
            }
            else {
                //Select 2 function
                returnR = returnR.select2(usedVariables[qParams.at(i)->returnContent()],i);
            }
        }
    }
    return returnR;
}


