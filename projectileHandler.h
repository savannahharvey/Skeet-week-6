/***********************************************************************
 * Header File:
 *    Projectile Handler
 * Summary:
 *    Chain of Responsibility handlers for creating projectiles
 ************************************************************************/

#pragma once

#include "uiInteract.h"
#include "bullet.h"

#include <list>

 /*********************************************
  * PROJECTILE REQUEST
  * The request object passed through the chain
  *********************************************/
struct ProjectileRequest
{
   const UserInput& ui;
   int level;
   double angle;
   std::list<Bullet*>& bullets;
};

/*********************************************
 * PROJECTILE HANDLER
 * Abstract handler for the chain of responsibility
 *********************************************/
class ProjectileHandler
{
public:
   virtual ~ProjectileHandler() {}
   virtual bool handleRequest(const ProjectileRequest& request) = 0;
};

/*********************************************
 * PELLET HANDLER
 * Handles standard pellet creation
 *********************************************/
class PelletHandler : public ProjectileHandler
{
public:
   bool handleRequest(const ProjectileRequest& request) override;
};

/*********************************************
 * MISSILE HANDLER
 * Handles missile creation
 *********************************************/
class MissileHandler : public ProjectileHandler
{
public:
   bool handleRequest(const ProjectileRequest& request) override;
};

/*********************************************
 * BOMB HANDLER
 * Handles bomb creation
 *********************************************/
class BombHandler : public ProjectileHandler
{
public:
   bool handleRequest(const ProjectileRequest& request) override;
};