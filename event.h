#pragma once
# include "position.h"

enum EventType
{
   COLLISION
};

struct Event
{
   EventType type;
   Position position;
   Velocity velocity;
   int pointValue;
};
