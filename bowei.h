#include<iostream>

class Berth
{
    public:
    int x,y;
    int transport_time;
    int loading_speed;
    int boatid;
    
/*
    int boatid[11];
    int boatnum,boatfirst,boatend;
*/
    Berth(){}
    Berth(int x, int y, int transporttime, int loadingspeed) {
        this -> x = x;
        this -> y = y;
        this -> transport_time = transporttime;
        this -> loading_speed = loadingspeed;
        this -> boatid = -1;
        //for(int i=0;i<11;i++) this -> boatid[i] = -1;
    }

}berth[20];