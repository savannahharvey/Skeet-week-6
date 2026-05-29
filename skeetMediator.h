#pragma once
#include "event.h"

class EffectColleague;
class PointColleague;
class BulletColleague;
class BirdColleague;

class SkeetMediator
{
private:
   BirdColleague* birdColleague;
   BulletColleague* bulletColleague;
   EffectColleague* effectColleague;
   PointColleague* pointColleague;

public:
   SkeetMediator()
      : birdColleague(nullptr), bulletColleague(nullptr), effectColleague(nullptr), pointColleague(nullptr) {}

   SkeetMediator(BirdColleague* birdColleague, BulletColleague* bulletColleague, EffectColleague* effectColleague, PointColleague* pointColleague)
      : birdColleague(birdColleague), bulletColleague(bulletColleague), effectColleague(effectColleague), pointColleague(pointColleague) {}

   void setColleagues(BirdColleague* b, BulletColleague* bl, EffectColleague* e, PointColleague* p)
   {
      birdColleague = b;
      bulletColleague = bl;
      effectColleague = e;
      pointColleague = p;
   }

   void notify(const Event& event);
};
