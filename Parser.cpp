#include "Parser.h"
#include "Token.h"
#include "Parameter.h"
#include "DatalogProgram.h"
#include "Rule.h"
#include <string>
#include <iostream>

Parser::Parser(std::vector<Token*> tokenList) {
    tokens = tokenList;
}

Parser::~Parser() {
//    for (unsigned int i = 0; i < parameters.size(); ++i ) {
//        delete parameters.at(i);
//    }
//    parameters.clear();
//    for (unsigned int i = 0; i < bodyPredicates.size(); ++i ) {
//        delete bodyPredicates.at(i);
//    }
//    bodyPredicates.clear();
//    delete headPredicate;
//    delete myProgram;
}

void Parser::Parse() {
    try {
        parseDatalogProgram();
        //std::cout << "Success!\n";
        myProgram->setDomain(domain);
        domain.clear();
    }
    catch(Token* errToken) {
        std::string errorMsg = errToken->toString();
        std::cout << "Failure!\n  " << errorMsg;
        //delete errToken;
    }
}

void Parser::parseDatalogProgram() {
    if (tokens.at(tokenCount)->returnToken() == TokenType::SCHEMES) {
        tokenCount += 1;
        if (tokens.at(tokenCount)->returnToken() == TokenType::COLON) {
            tokenCount += 1;
            parseScheme();
            parseSchemeList();
            if (tokens.at(tokenCount)->returnToken() == TokenType::FACTS) {
                tokenCount += 1;
                if (tokens.at(tokenCount)->returnToken() == TokenType::COLON) {
                    parameters.clear();
                    tokenCount += 1;
                    parseFactList();
                    if (tokens.at(tokenCount)->returnToken() == TokenType::RULES) {
                        tokenCount += 1;
                        if (tokens.at(tokenCount)->returnToken() == TokenType::COLON) {
                            parameters.clear();
                            tokenCount += 1;
                            parseRuleList();
                            if (tokens.at(tokenCount)->returnToken() == TokenType::QUERIES) {
                                tokenCount += 1;
                                if (tokens.at(tokenCount)->returnToken() == TokenType::COLON) {
                                    parameters.clear();
                                    tokenCount += 1;
                                    parseQuery();
                                    parseQueryList();
                                    if (tokens.at(tokenCount)->returnToken() == TokenType::E0F) {
                                        return;
                                    }
                                    else {
                                        throw tokens.at(tokenCount);
                                    }
                                }
                                else {
                                    throw tokens.at(tokenCount);
                                }
                            }
                            else {
                                throw tokens.at(tokenCount);
                            }
                        }
                        else {
                            throw tokens.at(tokenCount);
                        }
                    }
                    else {
                        throw tokens.at(tokenCount);
                    }
                }
                else {
                    throw tokens.at(tokenCount);
                }
            }
            else {
                throw tokens.at(tokenCount);
            }
        }
        else {
            tokens.at(tokenCount);
        }
    }
    else {
        tokens.at(tokenCount);
    }
}

void Parser::parseScheme() {
    std::string id;
    if (tokens.at(tokenCount)->returnToken() == TokenType::ID) {
        id = tokens.at(tokenCount)->returnDescription();
        tokenCount += 1;
        if (tokens.at(tokenCount)->returnToken() == TokenType::LEFT_PAREN) {
            tokenCount += 1;
            if (tokens.at(tokenCount)->returnToken() == TokenType::ID) {
                parameters.push_back(new Parameter(tokens.at(tokenCount)->returnDescription()));
                tokenCount += 1;
                parseIDList();
                if (tokens.at(tokenCount)->returnToken() == TokenType::RIGHT_PAREN) {
                    tokenCount += 1;
                    myProgram->addPredicateSchemes(id, parameters);
//                    for (unsigned int i = 0; i < parameters.size(); i++) {
//                        delete parameters.at(i);
//                    }
                    parameters.clear();
                    return;
                }
                else {
                    throw tokens.at(tokenCount);
                }
            }
            else {
                throw tokens.at(tokenCount);
            }
        }
        else {
            throw tokens.at(tokenCount);
        }
    }
    else {
        throw tokens.at(tokenCount);
    }
}

void Parser::parseSchemeList() {
    if (tokens.at(tokenCount)->returnToken() == TokenType::FACTS) {
        return;
    }
    else {
        parseScheme();
        parseSchemeList();
    }
}

void Parser::parseFactList() {
    if (tokens.at(tokenCount)->returnToken() == TokenType::RULES) {
        return;
    }
    else {
        parseFact();
        parseFactList();
    }
}

void Parser::parseRuleList() {
    if (tokens.at(tokenCount)->returnToken() == TokenType::QUERIES) {
        return;
    }
    else {
        parseRule();
        parseRuleList();
    }
}

void Parser::parseQueryList() {
    if (tokens.at(tokenCount)->returnToken() == TokenType::E0F) {
        return;
    }
    else {
        parseQuery();
        parseQueryList();
    }
}

void Parser::parseFact() {
    std::string id;
    if (tokens.at(tokenCount)->returnToken() == TokenType::ID) {
        id = tokens.at(tokenCount)->returnDescription();
        tokenCount += 1;
        if (tokens.at(tokenCount)->returnToken() == TokenType::LEFT_PAREN) {
            tokenCount += 1;
            if (tokens.at(tokenCount)->returnToken() == TokenType::STRING) {
                parameters.push_back(new Parameter(tokens.at(tokenCount)->returnDescription()));
                tokenCount += 1;
                parseStringList();
                if (tokens.at(tokenCount)->returnToken() == TokenType::RIGHT_PAREN) {
                    tokenCount += 1;
                    if (tokens.at(tokenCount)->returnToken() == TokenType::PERIOD) {
                        myProgram->addPredicateFacts(id, parameters);
                        for (unsigned int i = 0; i < parameters.size(); i++) {
                            bool pushParam = true;
                            if (domain.empty()) {
                                domain.push_back(parameters.at(i)->returnContent());
                            }
                            else {
                                for (unsigned int j = 0; j < domain.size(); j++) {
                                    if (parameters.at(i)->returnContent() == domain.at(j)) {
                                        pushParam = false;
                                        break;
                                    }
                                }
                                if (pushParam) {
                                    domain.push_back(parameters.at(i)->returnContent());
                                }
                            }
                        }
                        myProgram->setDomain(domain);
                        tokenCount += 1;
                        parameters.clear();
                        return;
                    }
                    else {
                        throw tokens.at(tokenCount);
                    }
                }
                else {
                    throw tokens.at(tokenCount);
                }
            }
            else {
                throw tokens.at(tokenCount);
            }
        }
        else {
            throw tokens.at(tokenCount);
        }
    }
    else {
        throw tokens.at(tokenCount);
    }
}

void Parser::parseRule() {
    bodyPredicates.clear();
    parseHeadPredicate();
    if (tokens.at(tokenCount)->returnToken() == TokenType::COLON_DASH) {
        tokenCount += 1;
        parsePredicate();
        parsePredicateList();
        if (tokens.at(tokenCount)->returnToken() == TokenType::PERIOD) {
            myProgram->addRuleRules(headPredicate, bodyPredicates);
            bodyPredicates.clear();
            tokenCount += 1;
            return;
        }
        else {
            throw tokens.at(tokenCount);
        }
    }
    else {
        throw tokens.at(tokenCount);
    }
}

void Parser::parseQuery() {
    parsePredicate();
    if (tokens.at(tokenCount)->returnToken() == TokenType::Q_MARK) {
        tokenCount += 1;
        myProgram->addPredicateQueries(predID, parameters);
        parameters.clear();
        return;
    }
    else {
        throw tokens.at(tokenCount);
    }
}

void Parser::parseHeadPredicate() {
    if (tokens.at(tokenCount)->returnToken() == TokenType::ID) {
        predID = tokens.at(tokenCount)->returnDescription();
        parameters.clear();
        tokenCount += 1;
        if (tokens.at(tokenCount)->returnToken() == TokenType::LEFT_PAREN) {
            tokenCount += 1;
            if (tokens.at(tokenCount)->returnToken() == TokenType::ID) {
                parameters.push_back(new Parameter(tokens.at(tokenCount)->returnDescription()));
                tokenCount += 1;
                parseIDList();
                if (tokens.at(tokenCount)->returnToken() == TokenType::RIGHT_PAREN) {
                    headPredicate = new Predicate(predID, parameters);
                    tokenCount += 1;
                    return;
                }
                else {
                    throw tokens.at(tokenCount);
                }
            }
            else {
                throw tokens.at(tokenCount);
            }
        }
        else {
            throw tokens.at(tokenCount);
        }
    }
    else {
        throw tokens.at(tokenCount);
    }
}

void Parser::parsePredicate() {
    if (tokens.at(tokenCount)->returnToken() == TokenType::ID) {
        parameters.clear();
        predID = tokens.at(tokenCount)->returnDescription();
        tokenCount += 1;
        if (tokens.at(tokenCount)->returnToken() == TokenType::LEFT_PAREN) {
            tokenCount += 1;
            parseParameter();
            parseParameterList();
            if (tokens.at(tokenCount)->returnToken() == TokenType::RIGHT_PAREN) {
                bodyPredicates.push_back(new Predicate(predID, parameters));
                tokenCount += 1;
                return;
            }
            else {
                throw tokens.at(tokenCount);
            }
        }
        else {
            throw tokens.at(tokenCount);
        }
    }
    else {
        throw tokens.at(tokenCount);
    }
}

void Parser::parsePredicateList() {
    if (tokens.at(tokenCount)->returnToken() == TokenType::PERIOD) {
        return;
    }
    else if (tokens.at(tokenCount)->returnToken() == TokenType::COMMA) {
        tokenCount += 1;
        parsePredicate();
        parsePredicateList();
    }
    else {
        throw tokens.at(tokenCount);
    }
}

void Parser::parseParameterList() {
    if (tokens.at(tokenCount)->returnToken() == TokenType::RIGHT_PAREN) {
        return;
    }
    else if (tokens.at(tokenCount)->returnToken() == TokenType::COMMA) {
        tokenCount += 1;
        parseParameter();
        parseParameterList();
    }
    else {
        throw tokens.at(tokenCount);
    }
}

void Parser::parseStringList() {
    if (tokens.at(tokenCount)->returnToken() == TokenType::RIGHT_PAREN) {
        return;
    }
    else if (tokens.at(tokenCount)->returnToken() == TokenType::COMMA) {
        tokenCount += 1;
        if (tokens.at(tokenCount)->returnToken() == TokenType::STRING) {
            parameters.push_back(new Parameter(tokens.at(tokenCount)->returnDescription()));
            tokenCount += 1;
            parseStringList();
        }
        else {
            throw tokens.at(tokenCount);
        }
    }
    else {
        throw tokens.at(tokenCount);
    }
}

void Parser::parseIDList() {
    if (tokens.at(tokenCount)->returnToken() == TokenType::COMMA) {
        tokenCount += 1;
        if (tokens.at(tokenCount)->returnToken() == TokenType::ID) {
            parameters.push_back(new Parameter(tokens.at(tokenCount)->returnDescription()));
            tokenCount += 1;
            parseIDList();
        }
        else {
            throw tokens.at(tokenCount);
        }
    }
    else if (tokens.at(tokenCount)->returnToken() == TokenType::RIGHT_PAREN) {
        return;
    }
    else {
        throw tokens.at(tokenCount);
    }
}

void Parser::parseParameter() {
    if (tokens.at(tokenCount)->returnToken() == TokenType::ID) {
        parameters.push_back(new Parameter(tokens.at(tokenCount)->returnDescription()));
        tokenCount += 1;
        return;
    }
    else if (tokens.at(tokenCount)->returnToken() == TokenType::STRING) {
        parameters.push_back(new Parameter(tokens.at(tokenCount)->returnDescription()));
        tokenCount += 1;
        return;
    }
    else {
        throw tokens.at(tokenCount);
    }
}

DatalogProgram *Parser::returnProgram() {
    return myProgram;
}



