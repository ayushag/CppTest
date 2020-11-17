//============================================================================
// Name        : urlParser.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "UrlParserStateMachine.hpp"
#include<ctime>
using namespace std;

int main()
{
    srand(time(0));
    cout << "!!!URL Parser State Machine!!!" << endl;
    UrlParserStateMachine stateMachine;

    while (!stateMachine.isDone())
    {
        stateMachine.Update();
    }

    return 0;
}
