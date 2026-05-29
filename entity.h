/***********************************************************************
 * Header File:
 *    Entity : Abstract element for the Visitor pattern
 * Summary:
 *    Provides a common accept() interface for all game entities.
 ************************************************************************/

#pragma once

class Message;

/**********************
 * ENTITY
 * Abstract element visited by Message objects.
 **********************/
class Entity
{
public:
   virtual ~Entity() {}
   virtual void accept(Message& message) = 0;
};
