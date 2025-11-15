/*COMSC 210 | Lab 32 | Lawrence Bryant
IDE used: VSC*/
#include "Car.h"
#include <deque>
#include <stdlib.h>
#include <random>
#include <time.h>
#include <iostream>

using namespace std;


int main()
{
    srand(time(NULL));

    Car car1;
    Car car2;

    deque<Car> speed = {car1,car2};

    return 0;
}