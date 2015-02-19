#ifndef ROBOT_H
#define ROBOT_H

#include "floatingobject.h"

class Robot : public FloatingObject
{
    float enginePower;
    float maxEnginePower;
    float depthToHold;
    float proportionalFact;
    float stabilizerValue;
    float EngPowerDiff;
    float oldEngPower;
    float newEngPower;

public:
    Robot(float mass, float archimedForce, float waterResistanceK, float enginePower, float maxEnginePower, float proportionalFact);

    void setEnginePower(float power);
    void setOldEngPower(float oldPower);
    void setNewEngPower(float newPower);
    void setDepthToHold(float depthToHold);
    void setStabilizerValue(float stabilizerValue);
    void regulateDepth();

    float getEnginePower();
    float getMaxEnginePower();
    float getOldEngPower();
    float getNewEngPower();
    float getDepthToHold();
    float getProportionalFact();
    float getStabilizerValue();

    virtual float getForces();
    virtual void process();
};


#endif // ROBOT_H

