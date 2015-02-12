#include "floatingobject.h"


FloatingObject::FloatingObject(float mass,
                               float archimedForce,
                               float waterResistanceK) :
    mass(mass),
    archimedForce(archimedForce),
    waterResistanceK(waterResistanceK)
{/*
        this->mass = mass;
        this->archimedForce = archimedForce;
        this->waterResistanceK = waterResistanceK;*/
}


void FloatingObject::Initialize(float speed, float depth)
{
    setSpeed(speed);
    setDepth(depth);
}

void FloatingObject::setSpeed(float speed)
{
    this->speed = speed;
}


float FloatingObject::getSpeed()
{
    return speed;
}

void FloatingObject::setDepth(float depth)
{
    if (depth < 0)
        this->depth = depth;
    else
        this->depth = 0;
}

float FloatingObject::getDepth()
{
    return depth;
}

float FloatingObject::getArchimedForce()
{
    return archimedForce;
}

float FloatingObject::getMass()
{
    return mass;
}

float FloatingObject::getWaterResistanceK()
{
    return waterResistanceK;
}

float FloatingObject::getForces()
{
    float weight = getMass()*GRAVITY_CONST;
    float waterResistance = getSpeed()*getWaterResistanceK();
    return weight + getArchimedForce() + waterResistance;
}

void FloatingObject::process()
{
    //FloatingObject have nothing to process =(.
}
