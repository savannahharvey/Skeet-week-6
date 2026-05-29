/***********************************************************************
 * Source File:
 *    Message : Visitors used to communicate with game entities
 ************************************************************************/

#include "message.h"
#include "entity.h"
#include "bird.h"
#include "bullet.h"
#include "effect.h"
#include "points.h"
#include "score.h"

 /************************
  * DRAW ENTITY
  ************************/
void DrawEntity::visitBird(Bird* bird)
{
   bird->draw();
}

void DrawEntity::visitBullet(Bullet* bullet)
{
   bullet->output();
}

void DrawEntity::visitEffect(Effect* effect)
{
   effect->render();
}

void DrawEntity::visitPoints(Points* points)
{
   points->show();
}

/************************
 * MOVE ENTITY
 ************************/
void MoveEntity::visitBird(Bird* bird)
{
   bird->advance();
   hitRatio.adjust(bird->isDead() ? -1 : 0);
}

void MoveEntity::visitBullet(Bullet* bullet)
{
   bullet->move(entities);
}

void MoveEntity::visitEffect(Effect* effect)
{
   effect->fly();
}

void MoveEntity::visitPoints(Points* points)
{
   points->update();
}

/************************
 * REMOVE ZOMBIE ENTITY
 ************************/
void RemoveZombieEntity::visitBird(Bird* bird)
{
   if (bird->isDead())
   {
      if (bird->getPoints())
         entities.push_back(new Points(bird->getPosition(), bird->getPoints()));
      score.adjust(bird->getPoints());
      remove = true;
   }
}

void RemoveZombieEntity::visitBullet(Bullet* bullet)
{
   if (bullet->isDead())
   {
      bullet->death(entities);
      int value = -bullet->getValue();
      entities.push_back(new Points(bullet->getPosition(), value));
      score.adjust(value);
      remove = true;
   }
}

void RemoveZombieEntity::visitEffect(Effect* effect)
{
   if (effect->isDead())
      remove = true;
}

void RemoveZombieEntity::visitPoints(Points* points)
{
   if (points->isDead())
      remove = true;
}
