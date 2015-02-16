#ifndef FLOATINGOBJECT_H
#define FLOATINGOBJECT_H

const float GRAVITY_CONST = 9.81;

class FloatingObject
{

private:
    float mass;
    float archimedForce;
    float waterResistanceK;
    float speed;
    float depth;

public:
    FloatingObject() {}
    FloatingObject(float mass, float archimedForce, float waterResistanceK);

    void Initialize(float speed, float depth);
    void setSpeed(float speed);
    float getSpeed();
    void setDepth(float depth);
    float getDepth();
    float getArchimedForce();
    float getMass();
    float getWaterResistanceK();

    virtual float getForces();
    virtual void controlH(float need, float depth);
};

#endif // FLOATINGOBJECT_H

