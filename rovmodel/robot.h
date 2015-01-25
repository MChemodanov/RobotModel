#ifndef ROBOT_H
#define ROBOT_H

#include "floatingobject.h"

class Robot : public FloatingObject
{
    float enginePower;

public:
    Robot(float mass, float archimedForce, float waterResistanceK, float enginePower);

    void setEnginePower(float power);

    float getEnginePower();
};


#endif // ROBOT_H

