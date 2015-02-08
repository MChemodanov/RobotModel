#ifndef ROBOT_H
#define ROBOT_H

#include "floatingobject.h"

class Robot : public FloatingObject
{
    float enginePower;
    float depthToHold;

public:
    Robot(float mass, float archimedForce, float waterResistanceK, float enginePower);

    void setEnginePower(float power);
    void setDepthToHold(float depthToHold);
    void regulateDepth();

    float getEnginePower();
    float getDepthToHold();

    virtual float getForces();
};


#endif // ROBOT_H

