#include "Lexer.h"
#include "Parser.h"
#include "Interpreter.h"
#include <string>
#include <fstream>
#include <iostream>


using namespace std;

int main(int argc, char* argv[]) {

    // check command line arguments
    if (argc != 2) {
        std::cout << "usage: " << argv[0] << " input_file" << endl;
        return 1;
    }

    string fileName = argv[1];
    ifstream input(fileName);
    if (!input.is_open()) {
        cout << "File " << fileName << " could not be found or opened." << endl;
        return 1;
    }

    ifstream inputFile;
    inputFile.open(argv[1]);
    string inputString;

    while (input.peek() != EOF) {
        char addC = input.get();
        inputString = inputString + addC;
    }

    auto* lexer = new Lexer();
    lexer->Run(inputString);
    auto* parser = new Parser(lexer->returnTokens());
    parser->Parse();
    auto interpreter = new Interpreter(*parser->returnProgram());
    interpreter->InterpretSchemes();
    interpreter->InterpretFacts();
    interpreter->InterpretQueries();
    delete parser;
    delete lexer;
    delete interpreter;

    return 0;
}