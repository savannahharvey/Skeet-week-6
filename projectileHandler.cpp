/***********************************************************************
 * Source File:
 *    Projectile Handler
 * Summary:
 *    Concrete handlers for projectile creation
 ************************************************************************/

#include "projectileHandler.h"

 /*********************************************
  * PELLET HANDLER : HANDLE REQUEST
  *********************************************/
bool PelletHandler::handleRequest(const ProjectileRequest& request)
{
   if (!request.ui.isSpace())
      return false;

   request.bullets.push_back(new Pellet(request.angle));
   return true;
}

/*********************************************
 * MISSILE HANDLER : HANDLE REQUEST
 *********************************************/
bool MissileHandler::handleRequest(const ProjectileRequest& request)
{
   if (!request.ui.isM() || request.level <= 1)
      return false;

   request.bullets.push_back(new Missile(request.angle));
   return true;
}

/*********************************************
 * BOMB HANDLER : HANDLE REQUEST
 *********************************************/
bool BombHandler::handleRequest(const ProjectileRequest& request)
{
   if (!request.ui.isB() || request.level <= 2)
      return false;

   request.bullets.push_back(new Bomb(request.angle));
   return true;
}