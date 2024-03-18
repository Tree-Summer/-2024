#ifndef Dot_H_H
#define Dot_H_H
#pragma once

#include "boat.h"
#include "Good.h"
#include "berth.h"

class Dot{
	public:
		int type;
		Good* good;
		Berth* berth;
		Boat* boat;//暂时不考虑
		int isrobot;
		//0:land
		//1:sea
		//2:hurdle
		//3:goods
		//4:bowei
		//5:ship
		Dot(){
			//printf("Dot init\n");
			type=0;
		}
		void changetype(int type){
			//if(this->type==3&&good!=NULL) delete(good);
			//if(this->type==4&&berth!=NULL) delete(berth);
			//if(this->type==5&&boat!=NULL) delete(boat);
			this->type=type;
		}
};

#endif