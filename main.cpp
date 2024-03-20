#include<iostream>
#include "MAPPA.h"
#include<ctime>
using namespace std;


int main()
{
    srand(time(0));
    FILE *stream=freopen("freopen.out","w",stderr);
    MAPPA* m=new MAPPA;
    m->init();
    for(int zhen = 1; zhen <= 15000; zhen ++) {
        int id=m->input();
//        int id = Input();//
        m->deal();//
        //zhen=id;
        fflush(stdout);
    }
    return 0;
}
