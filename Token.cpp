#include "Token.h"
#include "iostream"

Token::Token(TokenType type, std::string description, int line) {
    this->type = type;
    this->description = description;
    this->lineNum = line;
}

std::string Token::toString() {
    return "(" + enumToString(type) + ",\"" + description + "\"," + std::to_string(lineNum) + ")\n";
}

std::string Token::enumToString(TokenType) {
    std::string returnString = "";
    switch (type) {
        case TokenType::COMMA: returnString = "COMMA"; break;
        case TokenType::PERIOD: returnString = "PERIOD"; break;
        case TokenType::Q_MARK: returnString = "Q_MARK"; break;
        case TokenType::LEFT_PAREN: returnString = "LEFT_PAREN"; break;
        case TokenType::RIGHT_PAREN: returnString = "RIGHT_PAREN"; break;
        case TokenType::COLON: returnString = "COLON"; break;
        case TokenType::COLON_DASH: returnString = "COLON_DASH"; break;
        case TokenType::MULTIPLY: returnString = "MULTIPLY"; break;
        case TokenType::ADD: returnString = "ADD"; break;
        case TokenType::SCHEMES: returnString = "SCHEMES"; break;
        case TokenType::FACTS: returnString = "FACTS"; break;
        case TokenType::RULES: returnString = "RULES"; break;
        case TokenType::QUERIES: returnString = "QUERIES"; break;
        case TokenType::ID: returnString = "ID"; break;
        case TokenType::STRING: returnString = "STRING"; break;
        case TokenType::COMMENT: returnString = "COMMENT"; break;
        case TokenType::LINE_COMMENT: returnString = "COMMENT"; break;
        case TokenType::UNDEFINED: returnString = "UNDEFINED"; break;
        case TokenType::E0F: returnString = "EOF"; break;
    }
    return returnString;
}

TokenType Token::returnToken() {
    return type;
}

std::string Token::returnDescription() {
    return description;
}


