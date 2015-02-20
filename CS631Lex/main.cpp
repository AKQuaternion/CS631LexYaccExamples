//
//  main.cpp
//  CS631Lex
//
//  Created by Chris Hartman on 2/19/15.
//  Copyright (c) 2015 Chris Hartman. All rights reserved.
//

#include <iostream>
using std::cout;
#include <memory>
using std::unique_ptr;
using std::make_unique;
#include <FlexLexer.h>
#include <fstream>
using std::ifstream;
#include <cassert>

int yylex();

extern "C" int yywrap()
{
    cout << "End of input\n";
    return 1;
}

int main(int argc, const char * argv[]) {
    
    ifstream infile("/usr/share/dict/words");
    assert(infile);
    
    unique_ptr<FlexLexer> lexer{make_unique<yyFlexLexer>()};
    
    lexer->yylex(&infile);
}
