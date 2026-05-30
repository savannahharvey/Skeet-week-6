#include "skeetColleague.h"
#include "effect.h"
#include "points.h"

// Effect and Point colleagues already implemented:
void EffectColleague::processMessage(const Event& event)
{
   if (event.type == COLLISION)
   {
      for (int i = 0; i < 25; i++)
         effects.push_back(new Fragment(event.position, event.velocity));
   }
}

void PointColleague::processMessage(const Event& event)
{
   if (event.type == COLLISION)
   {
      points.push_back(Points(event.position, event.pointValue));
      score->adjust(event.pointValue);
   }
}

// Bird and Bullet colleagues: minimal implementations that forward or no-op.
// Implement richer behavior if your game needs (e.g., removing entries, statistics).

void BirdColleague::processMessage(const Event& /* event */)
{
   // No-op by default. Birds are already handled in Skeet::animate
}

void BulletColleague::processMessage(const Event& /* event */)
{
   // No-op by default. Bullets are handled in Skeet::animate/death
}