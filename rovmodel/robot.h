#ifndef ROBOT_H
#define ROBOT_H

#include "floatingobject.h"

class Robot : public FloatingObject
{
    float enginePower;
    float maxEnginePower;
    float depthToHold;
    float proportionalFact;

public:
    Robot(float mass, float archimedForce, float waterResistanceK, float enginePower, float maxEnginePower, float proportionalFact);

    void setEnginePower(float power);
    void setDepthToHold(float depthToHold);
    void regulateDepth();

    float getEnginePower();
    float getDepthToHold();
    float getProportionalFact();

    virtual float getForces();
    virtual void process();
};


#endif // ROBOT_H

