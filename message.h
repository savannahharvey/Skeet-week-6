/***********************************************************************
 * Header File:
 *    Message : Abstract visitor for the Visitor pattern
 * Summary:
 *    Provides one visit method for each concrete entity type.
 ************************************************************************/

#pragma once

#include <list>

class Bird;
class Bullet;
class Effect;
class Points;
class Entity;
class Score;
class HitRatio;

/**********************
 * MESSAGE
 * Abstract visitor.
 **********************/
class Message
{
public:
   virtual ~Message() {}
   virtual void visitBird(Bird* bird) = 0;
   virtual void visitBullet(Bullet* bullet) = 0;
   virtual void visitEffect(Effect* effect) = 0;
   virtual void visitPoints(Points* points) = 0;
};

/**********************
 * DRAW ENTITY
 * Concrete visitor that draws all entities.
 **********************/
class DrawEntity : public Message
{
public:
   void visitBird(Bird* bird);
   void visitBullet(Bullet* bullet);
   void visitEffect(Effect* effect);
   void visitPoints(Points* points);
};

/**********************
 * MOVE ENTITY
 * Concrete visitor that moves all entities.
 **********************/
class MoveEntity : public Message
{
public:
   MoveEntity(std::list<Entity*>& entities, HitRatio& hitRatio) :
      entities(entities), hitRatio(hitRatio) {}

   void visitBird(Bird* bird);
   void visitBullet(Bullet* bullet);
   void visitEffect(Effect* effect);
   void visitPoints(Points* points);

private:
   std::list<Entity*>& entities;
   HitRatio& hitRatio;
};

/**********************
 * REMOVE ZOMBIE ENTITY
 * Concrete visitor that determines whether an entity should be removed.
 **********************/
class RemoveZombieEntity : public Message
{
public:
   RemoveZombieEntity(std::list<Entity*>& entities, Score& score) :
      entities(entities), score(score), remove(false) {}

   void reset() { remove = false; }
   bool shouldRemove() const { return remove; }

   void visitBird(Bird* bird);
   void visitBullet(Bullet* bullet);
   void visitEffect(Effect* effect);
   void visitPoints(Points* points);

private:
   std::list<Entity*>& entities;
   Score& score;
   bool remove;
};
