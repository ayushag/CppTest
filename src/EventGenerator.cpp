/*
 * EventGenerator.cpp
 *
 *  Created on: Nov 11, 2020
 *      Author: root
 */

#include "EventGenerator.hpp"

EventGenerator* EventGenerator::GetInstance()
{
    static EventGenerator s_instance;
    return &s_instance;
}

int EventGenerator::Generate(int eventNum)
{
    if (m_counter == 0)
    {
        m_counter = rand() % MAX_COUNT + 1;
        if (eventNum > 1)
            return rand() % eventNum + 1;
        return 1;
    }
    else
    {
        m_counter--;
    }
    return 0;
}
