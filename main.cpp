#include<iostream>
#include"MAPPA.h"
#include"MAPPA.cpp"
using namespace std;
int main()
{
    MAPPA m;
    m.init();
    for(int zhen = 1; zhen <= 15000; zhen ++)
    {
        m.input();
        //int id = Input();
        m.deal();
        m.output();
    }
    return 0;
}
