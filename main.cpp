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
    while((!speed.empty() || !speeed.empty() || !spead.empty() || !speid.empty()) && i < 20)
    {
        cout << "Time " << i << " Operation: \n";


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
                    cout <<"Lane: " << j+1 << " Car paid: ";
                    temp.print();
                    cout << "\n";
                    vehicles[j].pop_front();
                }
                else if(rando > 46 && rando < 85) //Adds a car to the end of the line.
                {
                    vehicles[j].resize(vehicles[j].size()+1);
                    Car temp;
                    vehicles[j].push_back(temp);
                    cout <<"Lane: "<< j+1 << "Joined lane: ";
                    temp = vehicles[j].back();
                    temp.print();
                    cout << "\n";
                }
                else //Has a car switch lanes.
                {
                    //From Lane 1
                    if(j == 0)
                    {
                        Car temp = vehicles[j].back();
                        vehicles[j].pop_back();
                        rando = rand() % 3;
                        if(rando == 0)
                        {
                            vehicles[1].push_back(temp);
                            cout << "Lane: " << j+1 << " Switched: \n";
                            temp.print();
                        }
                        if(rando == 1)
                        {
                            vehicles[2].push_back(temp);
                            cout << "Lane: " << j+1 << " Switched: \n";
                            temp.print();

                        }
                        if(rando == 2)
                        {
                            vehicles[3].push_back(temp);
                            cout << "Lane: " << j+1 << " Switched: \n";
                            temp.print();
                        }
                    }
                    //From Lane 2
                    if(j == 1)
                    {
                        Car temp = vehicles[j].back();
                        vehicles[j].pop_back();
                        rando = rand() % 3;
                        if(rando == 0)
                        {
                            vehicles[0].push_back(temp);
                            cout << "Lane: " << j+1 << " Switched: \n";
                            temp.print();
                        }
                        if(rando == 1)
                        {
                            vehicles[2].push_back(temp);
                            cout << "Lane: " << j+1 << " Switched: \n";
                            temp.print();

                        }
                        if(rando == 2)
                        {
                            vehicles[3].push_back(temp);
                            cout << "Lane: " << j+1 << " Switched: \n";
                            temp.print();
                        }

                    }
                    //From Lane 3
                    if(j == 2)
                    {
                        Car temp = vehicles[j].back();
                        vehicles[j].pop_back();
                        rando = rand() % 3;
                        if(rando == 0)
                        {
                            vehicles[0].push_back(temp);
                            cout << "Lane: " << j+1 << " Switched: \n";
                            temp.print();
                        }
                        if(rando == 1)
                        {
                            vehicles[1].push_back(temp);
                            cout << "Lane: " << j+1 << " Switched: \n";
                            temp.print();

                        }
                        if(rando == 2)
                        {
                            vehicles[3].push_back(temp);
                            cout << "Lane: " << j+1 << " Switched: \n";
                            temp.print();
                        }

                    }
                    //From Lane 4
                    if(j == 3)
                    {
                        Car temp = vehicles[j].back();
                        vehicles[j].pop_back();
                        rando = rand() % 3;
                        if(rando == 0)
                        {
                            vehicles[0].push_back(temp);
                            cout << "Lane: " << j+1 << " Switched: \n";
                            temp.print();
                        }
                        if(rando == 1)
                        {
                            vehicles[1].push_back(temp);
                            cout << "Lane: " << j+1 << " Switched: \n";
                            temp.print();

                        }
                        if(rando == 2)
                        {
                            vehicles[2].push_back(temp);
                            cout << "Lane: " << j+1 << " Switched: \n";
                            temp.print();
                        }

                    }
                }

            }
 
        }
        
        //Prints out the queue after new car was added/removed
        int l = 1;
        for(int j = 0; j < vehicles.size(); j++)
        {
            cout << "Lane " << l <<" Queue: \n";
            for(int k = 0; k < vehicles[j].size(); k++)
            {
                Car temp = vehicles[j][k];
                temp.print();
            }
            if(vehicles[j].empty())
            {
                    cout << "Empty\n";
            }
            l++;
        }
        cout << "\n";
        i++;
    }

    return 0;
}