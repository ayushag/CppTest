/*
 * StateMachine.hpp
 *
 *  Created on: Nov 11, 2020
 *      Author: root
 */

#ifndef STATEMACHINE_HPP_
#define STATEMACHINE_HPP_
# include "State.hpp"
# include <iostream>

using namespace std;

template<class T>
class StateMachine
{
    T *m_pOwner;
    State<T> *m_pCurrentState;
    bool m_firstRun = true;

public:
    StateMachine()
    {
        cout << "State Machine Created\n";
    }
    ~StateMachine()
    {
        cout << "State Machine Destroyed\n";
    }

    void Init(T *pOwner, State<T> *initialState);
    void Update();
    void ChangeState(State<T> *newState);
};

template<class T>
inline void StateMachine<T>::Init(T *pOwner, State<T> *initialState)
{
    m_pCurrentState = initialState;
    m_pOwner = pOwner;
    cout << "State Machine Ready\n";
}

template<class T>
inline void StateMachine<T>::Update()
{
    if (m_firstRun)
    {
        m_firstRun = false;
        m_pCurrentState->Enter(m_pOwner);
    }
    m_pCurrentState->Execute(m_pOwner);
}

template<class T>
inline void StateMachine<T>::ChangeState(State<T> *newState)
{
    m_pCurrentState->Exit(m_pOwner);
    m_pCurrentState = newState;
    m_pCurrentState->Enter(m_pOwner);
}

#endif /* STATEMACHINE_HPP_ */
