#include "robot.h"
#include "floatingobject.h"


#include <iostream>
#include <iomanip>



const float TIME_CONST = 0.1;
const float ITERATIONS = 200;

int main()
{
    Robot r(1, 50, 0.1, -35, 100);
    FloatingObject w(1, 50, 0.1);
    FloatingObject w1(1, 40, 0.1);
    FloatingObject w2(1, 30, 0.1);
    FloatingObject w3(1, 20, 0.1);
    r.Initialize(0, -50);
    r.setDepthToHold(-20);
    w.Initialize(0, -50);
    w1.Initialize(0, -50);
    w2.Initialize(0, -50);
    w3.Initialize(0, -50);

    FloatingObject *objects[5];
    objects[0] = &r;
    objects[1] = &w;
    objects[2] = &w1;
    objects[3] = &w2;
    objects[4] = &w3;

    for (int i =0; i < ITERATIONS; i++)
    {
        for (int j=0; j < 4; j++)
        {
            objects[j]->process();
            float forceSum = objects[j]->getForces();
            float acceleration = forceSum/objects[j]->getMass();

            objects[j]->setSpeed(acceleration*TIME_CONST);
            objects[j]->setDepth(objects[j]->getDepth() + objects[j]->getSpeed()*TIME_CONST);
            std::cout << std::setw(15) << objects[j]->getDepth();
        }
        std::cout << std::endl;
    }

    system("pause");

    return 0;
}

