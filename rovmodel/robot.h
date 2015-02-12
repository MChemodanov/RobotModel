#ifndef ROBOT_H
#define ROBOT_H

#include "floatingobject.h"

class Robot : public FloatingObject
{
    float enginePower;
    float maxEnginePower;
    float depthToHold;

public:
    Robot(float mass, float archimedForce, float waterResistanceK, float enginePower, float maxEnginePower);

    void setEnginePower(float power);
    void setDepthToHold(float depthToHold);

    float getEnginePower();
    float getDepthToHold();

    virtual float getForces();
    virtual void regulateDepth();
};


#endif // ROBOT_H

