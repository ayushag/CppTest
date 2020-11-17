/*
 * ParseStates.hpp
 *
 *  Created on: Nov 11, 2020
 *      Author: root
 */

#ifndef PARSESTATES_HPP_
#define PARSESTATES_HPP_

#include "State.hpp"
#include <iostream>
#include "UrlParserStateMachine.hpp"

using namespace std;

class StartState: public State<class UrlParserStateMachine>
{
    void Enter(UrlParserStateMachine *pOwner)
    {
        cout << "Enter Start State\n";
    }
    void Execute(UrlParserStateMachine *pOwner);
    void Exit(UrlParserStateMachine *pOwner)
    {
        cout << "Exit from Start State\n";
    }
};
class State1: public State<class UrlParserStateMachine>
{
    void Enter(UrlParserStateMachine *pOwner)
    {
        cout << "Enter State1\n";
    }
    void Execute(UrlParserStateMachine *pOwner);
    void Exit(UrlParserStateMachine *pOwner)
    {
        cout << "Exit from State1\n";

    }
};

class State2: public State<class UrlParserStateMachine>
{
    void Enter(UrlParserStateMachine *pOwner)
    {
        cout << "Enter State2\n";
    }
    void Execute(UrlParserStateMachine *pOwner);
    void Exit(UrlParserStateMachine *pOwner)
    {
        cout << "Exit from State2\n";

    }
};

class State3: public State<class UrlParserStateMachine>
{
    void Enter(UrlParserStateMachine *pOwner)
    {
        cout << "Enter State3\n";
    }
    void Execute(UrlParserStateMachine *pOwner);
    void Exit(UrlParserStateMachine *pOwner)
    {
        cout << "Exit from State3\n";

    }
};

class StateN: public State<class UrlParserStateMachine>
{
    void Enter(UrlParserStateMachine *pOwner)
    {
        cout << "Enter StateN\n";
    }
    void Execute(UrlParserStateMachine *pOwner);
    void Exit(UrlParserStateMachine *pOwner)
    {
        cout << "Exit from StateN\n";

    }
};

#endif /* PARSESTATES_HPP_ */
