//对于地图与泊位的交互
#include "Dot.h"
#include "GoodsManager.h"
class MAPPA{
	public:
		const int n = 200;
		const int robot_num = 10;
		const int berth_num = 10;
		const int N = 210;
		int zhen,money;
		int boat_capacity;
		GoodsManager gm;
		Dot d[201][201];
		Berth berth[20];
		Boat boat[6];
		Robot robot[11];
		void init();
		int input();
		void change(); 
		void vanish();
		void output();
		MAPPA(){

		};
}; 


