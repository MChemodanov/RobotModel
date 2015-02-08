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

int mark = 0;
void Robot::holdDepth(float depthToHold)
{
    if (getDepth() > depthToHold)
    {
        mark = 1;
        setEnginePower((depthToHold - getDepth())*230);
    }
    if (getDepth() < depthToHold && mark == 1)
    {
        setEnginePower((getDepth() - depthToHold)*230);
    }
}

void Robot::setEnginePower(float power)
{
    this->enginePower = power;
}

float Robot::getForces()
{
    return FloatingObject::getForces() + getEnginePower();
}
