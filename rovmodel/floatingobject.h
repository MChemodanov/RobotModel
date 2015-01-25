#ifndef FLOATINGOBJECT_H
#define FLOATINGOBJECT_H

class FloatingObject
{

private:
    float mass;
    float archimedForce;
    float waterResistanceK;
    float speed;
    float depth;

public:
    FloatingObject(float mass, float archimedForce, float waterResistanceK);

    void Initialize(float speed, float depth);
    void setSpeed(float speed);
    float getSpeed();
    void setDepth(float depth);
    float getDepth();
    float getArchimedForce();
    float getMass();
    float getWaterResistanceK();
};

#endif // FLOATINGOBJECT_H

