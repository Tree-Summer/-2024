#include<iostream>
#include"MAPPA.cpp"
#include "robot.cpp"
using namespace std;


int main()
{
    Robot* test = new Robot(2, 3, 0, 1, 3);
    test->path = "012";
    for(int i = 0;i < 3; i++)
        test->move();
}
