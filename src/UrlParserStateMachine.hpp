/*
 * UrlParserStateMachine.hpp
 *
 *  Created on: Nov 11, 2020
 *      Author: root
 */

#ifndef URLPARSERSTATEMACHINE_HPP_
#define URLPARSERSTATEMACHINE_HPP_

#include "StateMachine.hpp"

class UrlParserStateMachine: public StateMachine<UrlParserStateMachine>
{
    State<UrlParserStateMachine> *m_startState;
    State<UrlParserStateMachine> *m_state1;
    State<UrlParserStateMachine> *m_state2;
    State<UrlParserStateMachine> *m_state3;
    State<UrlParserStateMachine> *m_stateN;
    bool m_done;
    char m_url[256];
    char *m_pLabel;
public:
    UrlParserStateMachine();
    ~UrlParserStateMachine();
    void Update();
    void Done()
    {
        m_done = true;
    }
    bool isDone()
    {
        return m_done;
    }
    friend class StartState;
    friend class State1;
    friend class State2;
    friend class State3;
    friend class StateN;
};

#endif /* URLPARSERSTATEMACHINE_HPP_ */
