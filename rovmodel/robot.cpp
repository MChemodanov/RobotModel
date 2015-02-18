#include "robot.h"
#include <cmath>


Robot::Robot(float mass, float archimedForce, float waterResistanceK, float enginePower, float maxEnginePower, float proportionalFact)
    : FloatingObject(mass, archimedForce, waterResistanceK),
      enginePower(enginePower), maxEnginePower(maxEnginePower), proportionalFact(proportionalFact)
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

float Robot::getProportionalFact()
{
    return proportionalFact;
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
    setEnginePower((getDepthToHold() - getDepth())*getProportionalFact());
}

void Robot::process()
{
    if (getDepthToHold() < 1)
        regulateDepth();
}
