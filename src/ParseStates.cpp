/*
 * ParseStates.cpp
 *
 *  Created on: Nov 11, 2020
 *      Author: root
 */

#include "ParseStates.hpp"
#include "EventGenerator.hpp"
#include "UrlParserStateMachine.hpp"
#include <string>

void StartState::Execute(UrlParserStateMachine *pOwner)
{
    cout << "StartState : Enter URL:\n";
    cin >> pOwner->m_url;
    cout << pOwner->m_url << endl;
    pOwner->ChangeState(pOwner->m_state1);
}

void State1::Execute(UrlParserStateMachine *pOwner)
{
    cout << "State1 : Validating Hostname...\n";
    string url(pOwner->m_url);
    string hostname("www");
    size_t firstPeriodLoc = url.find_first_of(".");
    size_t found = url.find(hostname);
    if ((found != string::npos) && (found == 0))
    {
        cout << "State1 : Hostname Validation Successful!\n";
        pOwner->m_pLabel = &pOwner->m_url[firstPeriodLoc + 1];
        cout << "State1 : " << pOwner->m_pLabel << endl;
        pOwner->ChangeState(pOwner->m_state2);
    }
    else
    {
        cout << "State1 : Hostname Validation Failed!\n";
        pOwner->ChangeState(pOwner->m_stateN);
    }
}

void State2::Execute(UrlParserStateMachine *pOwner)
{
    cout << "State2 : Validating Labels...\n";
    cout << pOwner->m_pLabel << endl;
    string url(pOwner->m_pLabel);
    size_t firstPeriodLoc = url.find_first_of(".");
    size_t lastPeriodLoc = url.find_last_of(".");
    string label = url.substr(0, firstPeriodLoc);

    if (firstPeriodLoc <= lastPeriodLoc)
    {
        cout << "label : " << label << endl;
        //validate label

        //label must contain characters only in range a-z, A-Z, 0-9 and a hyphen
        if (label.find_first_not_of(
//                "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890-")
                "abcdefghijklmnopqrstuvwxyz01234567890-") != std::string::npos)
        {
            //label must not begin with hyphen
            cout << "State2 : Label Validation Failed!\n";
            pOwner->ChangeState(pOwner->m_stateN);
        }
        else if (label[0] == '-')
        {
            cout << "State2 : Label Validation Failed!\n";
            pOwner->ChangeState(pOwner->m_stateN);
        }
        else
        {
            cout << "State2 : Label Validation Successful!\n";
            if (firstPeriodLoc == lastPeriodLoc)
            {
                pOwner->ChangeState(pOwner->m_state3);
            }
            else
            {
                pOwner->m_pLabel += firstPeriodLoc + 1;
                pOwner->ChangeState(pOwner->m_state2);
            }
        }
    }
}

void State3::Execute(UrlParserStateMachine *pOwner)
{
    cout << "State3 : Validating Top Level Domain Name...\n";
    string url(pOwner->m_url);
    string hostname("com");
    size_t lastPeriodLoc = url.find_last_of(".");
    size_t found = url.find(hostname);
    if ((found != string::npos) && (found == lastPeriodLoc + 1))
    {
        cout << "State3 : Top Level Domain Name Validation Successful!\n";
        pOwner->ChangeState(pOwner->m_stateN);
    }
    else
    {
        cout << "State3 : Top Level Domain Name Validation Failed!\n";
        pOwner->ChangeState(pOwner->m_stateN);
    }
}

void StateN::Execute(UrlParserStateMachine *pOwner)
{
    pOwner->Done();
    cout << "StateN : Terminated\n";
}

