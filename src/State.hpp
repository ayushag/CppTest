/*
 * state.hpp
 *
 *  Created on: Nov 10, 2020
 *      Author: root
 */

#ifndef STATE_HPP_
#define STATE_HPP_

template <class T>
class State{
public:
    virtual ~State(){};
    virtual void Enter(T *pOwner) = 0;
    virtual void Execute(T *pOwner) = 0;
    virtual void Exit(T *pOwner) = 0;
};

#endif /* STATE_HPP_ */
