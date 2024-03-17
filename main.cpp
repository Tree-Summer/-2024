#include<iostream>
#include "MAPPA.h"
using namespace std;


int main()
{
    FILE *stream=freopen("freopen.out","w",stderr);
    MAPPA* m=new MAPPA;
    m->init();
    for(int zhen = 1; zhen <= 15000; zhen ++) {
        int id=m->input();
//        int id = Input();//
        m->deal();//
        zhen=id;
        fflush(stdout);
    }
    return 0;
}
