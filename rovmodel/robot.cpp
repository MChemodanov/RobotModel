#include "robot.h"
#include <cmath>

const float SYS_CONST = 100;
const float ERROR_CONST = 0.5981;

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

void Robot::setDepthToHold(float depthToHold = 1)
{
    this->depthToHold = depthToHold;
}

float Robot::getForces()
{
    return FloatingObject::getForces() + getEnginePower();
}

void Robot::regulateDepth()
{
    setEnginePower((depthToHold - ERROR_CONST - getDepth())*SYS_CONST);
}

void Robot::process()
{
    if (depthToHold < 1)
        regulateDepth();
}
