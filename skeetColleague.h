#pragma once
#include "skeetMediator.h"
#include "score.h"
#include <list>

struct Event;

class SkeetColleague
{
protected:
   SkeetMediator* mediator;

public:
   SkeetColleague(SkeetMediator* mediator)
      : mediator(mediator) {}

   // default behavior: forward to mediator
   virtual void notify(const Event& event)
   {
      if (mediator)
         mediator->notify(event);
   }

   virtual void processMessage(const Event& event) = 0;
};

// ---- BirdColleague ----
class Bird;

class BirdColleague : public SkeetColleague
{
private:
   std::list<Bird*>& birds;

public:
   // take birds by reference so we operate on the live collection
   BirdColleague(std::list<Bird*>& birds, SkeetMediator* mediator)
      : SkeetColleague(mediator), birds(birds) {}

   void processMessage(const Event&) override;
};

// ---- BulletColleague ----
class Bullet;

class BulletColleague : public SkeetColleague
{
private:
   std::list<Bullet*>& bullets;

public:
   BulletColleague(std::list<Bullet*>& bullets, SkeetMediator* mediator)
      : SkeetColleague(mediator), bullets(bullets) {}

   void processMessage(const Event& event) override;
};

// ---- EffectColleague ----
class Effect;
class Fragment;

class EffectColleague : public SkeetColleague
{
private:
   std::list<Effect*> effects;

public:
   EffectColleague(std::list<Effect*>& effects, SkeetMediator* mediator)
      : SkeetColleague(mediator), effects(effects) {}

   void processMessage(const Event& event) override;
};

// ---- PointColleague ----
class Points;

class PointColleague : public SkeetColleague
{
private:
   std::list<Points>& points;
   Score* score;

public:
   PointColleague(std::list<Points>& points, Score* score, SkeetMediator* mediator)
      : SkeetColleague(mediator), points(points), score(score) {}
   void processMessage(const Event& event) override;
};
