/***********************************************************************
 * Header File:
 *    GUN
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The gun at the bottom of the screen
 ************************************************************************/

#pragma once
#include "position.h"
#include "uiInteract.h"

/*********************************************
 * GUN
 * The gun at the bottom of the screen
 *********************************************/
class Gun : public InteractObserver
{
public:
   Gun(const Position & pt) : angle(0.78 /* 45 degrees */), pt(pt), isClockwise(false), isCounterclockwise(false)
   {
      UserInput::subscribe(this);
   }
   ~Gun()
   {
      UserInput::unsubscribe(this);
   }

   void display() const;
   void interact(int clockwise, int counterclockwise);
   void update(const InteractMessage& message) override;
   void animate();
   double getAngle() const { return angle; }
   
private:
   double angle;
   Position pt;
   bool isClockwise;
   bool isCounterclockwise;
};
