//
//  main.cpp
//  CS631Lex
//
//  Created by Chris Hartman on 2/19/15.
//  Copyright (c) 2015 Chris Hartman. All rights reserved.
//

#include <iostream>
using std::cout;

int yylex();

extern "C" int yywrap()
{
    cout << "End of input\n";
    return 1;
}

int main(int argc, const char * argv[]) {
    yylex();
    return 0;
}
