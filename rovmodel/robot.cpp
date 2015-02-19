#include "robot.h"
#include <cmath>


Robot::Robot(float mass, float archimedForce, float waterResistanceK, float enginePower, float maxEnginePower, float proportionalFact)
    : FloatingObject(mass, archimedForce, waterResistanceK),
      enginePower(enginePower), maxEnginePower(maxEnginePower), proportionalFact(proportionalFact), stabilizerValue(0)
 {
 }

float Robot::getEnginePower()
{
    return enginePower;
}

float Robot::getMaxEnginePower()
{
    return maxEnginePower;
}

float Robot::getOldEngPower()
{
    return oldEngPower;
}

float Robot::getNewEngPower()
{
    return newEngPower;
}

float Robot::getDepthToHold()
{
    return depthToHold;
}

float Robot::getProportionalFact()
{
    return proportionalFact;
}

float Robot::getStabilizerValue()
{
    return stabilizerValue;
}

void Robot::setEnginePower(float power)
{
    if (fabs(power) < getMaxEnginePower())
        this->enginePower = power;
    else
        this->enginePower = (fabs(power)/power)*getMaxEnginePower();
}

void Robot::setOldEngPower(float oldPower)
{
    this->oldEngPower = oldPower;
}

void Robot::setNewEngPower(float newPower)
{
    this->newEngPower = newPower;
}

void Robot::setDepthToHold(float depthToHold = 1)
{
    this->depthToHold = depthToHold;
}

void Robot::setStabilizerValue(float stabilizerValue = 0)
{
    this->stabilizerValue = stabilizerValue;
}

float Robot::getForces()
{
    return FloatingObject::getForces() + getEnginePower();
}

void Robot::regulateDepth()
{
    setOldEngPower(getEnginePower());
    setEnginePower((getDepthToHold() - getDepth() + getStabilizerValue())*getProportionalFact());
    setNewEngPower(getEnginePower());

    if ((getNewEngPower() - getOldEngPower() == 0))
        if (fabs(getNewEngPower()) != getMaxEnginePower() && fabs(getOldEngPower()) != getMaxEnginePower())
            if (getStabilizerValue()== 0)
                setStabilizerValue(getDepthToHold() - getDepth());
}

void Robot::process()
{
    if (getDepthToHold() < 1)
        regulateDepth();
}
