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
