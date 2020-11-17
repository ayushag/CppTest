/*
 * UrlParserStateMachine.cpp
 *
 *  Created on: Nov 11, 2020
 *      Author: root
 */

#include "UrlParserStateMachine.hpp"
#include "ParseStates.hpp"

UrlParserStateMachine::UrlParserStateMachine()
{
    m_startState = new StartState();
    m_state1 = new State1();
    m_state2 = new State2();
    m_state3 = new State3();
    m_stateN = new StateN();
    m_done = false;
    m_pLabel = NULL;
    StateMachine<UrlParserStateMachine>::Init(this, m_startState);
}

UrlParserStateMachine::~UrlParserStateMachine()
{
    delete m_startState;
    delete m_state1;
    delete m_state2;
    delete m_state3;
    delete m_stateN;
}

void UrlParserStateMachine::Update()
{
    StateMachine<UrlParserStateMachine>::Update();
}
