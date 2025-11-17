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
        cout << "\n    ";
        vehicles[j-1].back().print();
        cout << "\n";
    }

    //Goes until the line is empty, however long that takes.
    while(!speed.empty() || !speeed.empty() || !spead.empty() || !speid.empty())
    {
        cout << "Time " << i << " Operation: ";


        for(int j = 0; j < vehicles.size(); j++)
        {
            rando = rand() % 100 + 1; //Randomized on each loop

            //Branching paths
            //If the lane is empty.
            if(vehicles[j].empty())
            {
                if(rando >= 51)
                {
                    Car temp;
                    vehicles[j].push_front(temp);
                    cout << "\n";
                    temp.print();
                    cout << " joined lane" << j+1;
                }
            }
            else
            {
                if(rando <= 46) //Removes a car that pays
                {
                    Car temp = vehicles[j].front();
                    cout << "Car paid: ";
                    temp.print();
                    cout << "\n";
                    vehicles[j].pop_front();
                }
                else if(rando > 46 && rando < 85) //Adds a car to the end of the line.
                {
                    vehicles[j].resize(vehicles[j].size()+1);
                    Car temp;
                    vehicles[j].push_back(temp);
                    cout << "Joined lane: ";
                    temp = vehicles[j].back();
                    temp.print();
                }
                else
                {
                    
                }

            }

    
        }
        


        //Prints out the queue after new car was added/removed
        int l = 1;
        for(int j = 0; j < vehicles.size(); j++)
        {
            cout << "Lane " << l <<"Queue: \n";
            for(int k = 0; k < vehicles[j].size(); k++)
            {
                Car temp = vehicles[j][k];
                temp.print();
                if(vehicles[j].empty())
                {
                    cout << "empty";
                }
            }
            l++;
        }
        cout << "\n";
        i++;
    }

    return 0;
}