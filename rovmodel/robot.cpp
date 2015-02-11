#include "robot.h"


#include <cmath>

Robot::Robot(float mass, float archimedForce, float waterResistanceK, float enginePower)
    : FloatingObject(mass, archimedForce, waterResistanceK),
      enginePower(enginePower)
 {
 }

float Robot::getEnginePower()
{
    return enginePower;
}
float Robot::getDepthToHold()
{
    return depthToHold;
}

void Robot::setEnginePower(float power)
{
    if (fabs(power) < 100)
        this->enginePower = power;
    else
        this->enginePower = (fabs(power)/power)*100;
}

void Robot::setDepthToHold(float depthToHold = 0)
{
    this->depthToHold = depthToHold;
}

float Robot::getForces()
{
    return FloatingObject::getForces() + getEnginePower();
}

void Robot::regulateDepth()
{
    setEnginePower((depthToHold - getDepth())*RANDOM_CONST);
}
