#include "robot.h"


#include <cmath>

Robot::Robot(float mass, float archimedForce, float waterResistanceK, float enginePower, float maxEnginePower)
    : FloatingObject(mass, archimedForce, waterResistanceK),
      enginePower(enginePower), maxEnginePower(maxEnginePower)
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
    if (fabs(power) < maxEnginePower)
        this->enginePower = power;
    else
        this->enginePower = (fabs(power)/power)*maxEnginePower;
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
    setEnginePower((depthToHold - getDepth())*SYS_CONST);
}
