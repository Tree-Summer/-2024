#include<iostream>
using namespace std;

class Berth
{
    public:
    int x,y;
    int transporttime;
    int loadingspeed;
    Berth(){}
    Berth(int x, int y, int transporttime, int loadingspeed) {
        this -> x = x;
        this -> y = y;
        this -> transporttime = transporttime;
        this -> loadingspeed = loadingspeed;
    }
}berth[20];