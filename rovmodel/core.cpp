#include "robot.h"
#include "floatingobject.h"


#include <iostream>
#include <iomanip>


const float TIME_CONST = 0.1;
const float ITERATIONS = 200;
const float NEED_DEPTH = -25;

int main()
{
    Robot r(1, 50, 0.1, -35);
    FloatingObject w(1, 50, 0.1);


    r.Initialize(0, -5);
    w.Initialize(0, -5);

    FloatingObject *objects[5];
    objects[0] = &r;
    objects[1] = &w;

    for (int i =0; i < ITERATIONS; i++)
    {
        for (int j=0; j < 2; j++)
        {
            float forceSum = objects[j]->getForces();
            float acceleration = forceSum/objects[j]->getMass();

            objects[j]->setSpeed(acceleration*TIME_CONST);
            objects[j]->setDepth(objects[j]->getDepth() + objects[j]->getSpeed()*TIME_CONST);
            std::cout << std::setw(15) << objects[j]->getDepth();

            objects[j]->controlH(NEED_DEPTH, objects[j]->getDepth());
        }
        std::cout << std::endl;
    }

    system("pause");

    return 0;
}

