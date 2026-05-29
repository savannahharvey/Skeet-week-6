#include "skeetMediator.h"
#include "skeetColleague.h"

void SkeetMediator::notify(const Event& event)
{
   if (event.type == COLLISION)
   {
      if (effectColleague)
         effectColleague->processMessage(event);
      if (pointColleague)
         pointColleague->processMessage(event);
   }
}