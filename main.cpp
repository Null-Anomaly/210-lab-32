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
    int rando = 0;

    deque<Car> speed = {car1,car2};

    cout << "Initial queue:\n";
    car1.print();
    car2.print();

    int i = 1;
    while(!speed.empty())
    {
        cout << "Time " << i << " Operation: ";
        rando = rand() % 100 + 1;
        if(rando >= 55)
        {
            Car temp = speed.front();
            cout << "Car paid: ";
            temp.print();
            cout << "\n";
            speed.pop_front();
        }
        else
        {
            speed.resize(speed.size()+1);
            Car temp;
            speed.push_back(temp);
            cout << "Joined lane: ";
            temp = speed.back();
            temp.print();
        }

        cout << "Queue\n";
        for(int j = 0; j < speed.size(); j++)
        {
            print(speed.begin());
        }
    }

    return 0;
}