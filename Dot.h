#ifndef Dot_H_H
#define Dot_H_H
#pragma once

#include "boat.h"
class Dot{
	public:
		int type;
		//0:land
		//1:sea
		//2:hurdle
		//3:goods
		//4:bowei
		//5:ship
		int x,y,val,t;
		Dot(){
			printf("Dot init\n");
		}
};

#endif