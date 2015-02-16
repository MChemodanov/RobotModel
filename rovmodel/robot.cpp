#include "robot.h"

Robot::Robot(float mass, float archimedForce, float waterResistanceK, float enginePower)
    : FloatingObject(mass, archimedForce, waterResistanceK),
      enginePower(enginePower)
 {
 }

float Robot::getEnginePower()
{
    return enginePower;
}


void Robot::setEnginePower(float power)
{
    this->enginePower = power;
}

void Robot::controlH(float need, float depth)
{
    if (need+1 > depth && need-1 < depth)
    {
        if ( need<depth && (getForces() >= 0))
            enginePower=enginePower-getForces()-5;

        if (need>depth && (getForces() <= 0))
            enginePower=enginePower-getForces()+5;
    }
    else
    {
    if ( need<depth && (getForces() >= 0))
        enginePower=enginePower-getForces()-30;

    if (need>depth && (getForces() <= 0))
        enginePower=enginePower-getForces()+30;
    }
}

float Robot::getForces()
{
    return FloatingObject::getForces() + getEnginePower();
}
