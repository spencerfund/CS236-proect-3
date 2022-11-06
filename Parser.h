#ifndef INC_236_PROJECT_1_PARSER_H
#define INC_236_PROJECT_1_PARSER_H
#include <vector>
#include "Token.h"
#include "DatalogProgram.h"
#include "Parameter.h"
#include "Predicate.h"
#include "Rule.h"

class Parser {
private:
    unsigned int tokenCount = 0;
    std::vector<Token*> tokens;
    DatalogProgram* myProgram = new DatalogProgram;
    std::vector<Parameter*> parameters;
    std::vector<std::string> domain;
    std::string predID = "";
    Predicate* headPredicate;
    std::vector<Predicate*> bodyPredicates;


public:
    Parser(std::vector<Token*>);
    ~Parser();

    void Parse();
    void parseDatalogProgram();
    void parseSchemeList();
    void parseFactList();
    void parseRuleList();
    void parseQueryList();
    void parseScheme();
    void parseFact();
    void parseRule();
    void parseQuery();
    void parseHeadPredicate();
    void parsePredicate();
    void parsePredicateList();
    void parseParameterList();
    void parseStringList();
    void parseIDList();
    void parseParameter();
    DatalogProgram* returnProgram();
};


#endif //INC_236_PROJECT_1_PARSER_H
