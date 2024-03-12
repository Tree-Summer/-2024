#include<iostream>
#include"MAPPA.cpp"
using namespace std;


int main()
{
    MAPPA m;
    //printf("a");
    m.init();
    for(int zhen = 1; zhen <= 15000; zhen ++)
    {
        int id=m.input();
        //int id = Input();
        m.deal();
        m.output();
        zhen=id;
    }
    return 0;

}
