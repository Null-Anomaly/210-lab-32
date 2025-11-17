/*COMSC 210 | Lab 32/33 | Lawrence Bryant
IDE used: VSC*/
#include "Car.h"
#include <deque>
#include <stdlib.h>
#include <random>
#include <time.h>
#include <array>
#include <iostream>

using namespace std;

//Main function
int main()
{
    //Randomization
    srand(time(NULL));

    //Initial variable initialization
    Car car1;
    Car car2;
    Car car3;
    Car car4;
    Car car5;
    Car car6;
    Car car7;
    Car car8;
    int rando = 0;
    int i = 1;

    
    deque<Car> speed = {car1,car2};
    deque<Car> speeed = {car3,car4};
    deque<Car> spead = {car5,car6};
    deque<Car> speid = {car7,car8};
    array<deque<Car>,4> vehicles = {speed, speeed, spead, speid};

    //Initial cars
    cout << "Initial queue:\n";
    for(int j = 1; j < vehicles.size()+1;j++)
    {
        cout << "Lane " << j << ":\n    ";
        vehicles[j-1].front().print();
        cout << "\n";
        vehicles[j-1].back().print();
        cout << "\n";
    }

    //Goes until the line is empty, however long that takes.
    while(!speed.empty())
    {
        cout << "Time " << i << " Operation: ";
        rando = rand() % 100 + 1; //Randomized on each loop

        //Branching paths
        if(rando >= 55) //Removes a car that pays
        {
            Car temp = speed.front();
            cout << "Car paid: ";
            temp.print();
            cout << "\n";
            speed.pop_front();
        }
        else //Adds a car to the end of the line.
        {
            speed.resize(speed.size()+1);
            Car temp;
            speed.push_back(temp);
            cout << "Joined lane: ";
            temp = speed.back();
            temp.print();
        }

        //Prints out the queue after new car was added/removed
        cout << "Queue:\n";
        for(int j = 0; j < speed.size(); j++)
        {
            Car temp = speed[j];
            temp.print();
        }
        cout << "\n";
        i++;
    }

    return 0;
}