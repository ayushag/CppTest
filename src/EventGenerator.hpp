/*
 * EventGenerator.hpp
 *
 *  Created on: Nov 11, 2020
 *      Author: root
 */

#ifndef EVENTGENERATOR_HPP_
#define EVENTGENERATOR_HPP_

# include <iostream>
#define MAX_COUNT 5

class EventGenerator
{
    int m_counter;
    EventGenerator()
    {
        m_counter = rand() % MAX_COUNT + 1;
    }
public:
    static EventGenerator* GetInstance();
    void cleanup();
    int Generate(int eventNum);
};

#endif /* EVENTGENERATOR_HPP_ */
