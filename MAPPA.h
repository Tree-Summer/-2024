//地图类,支持使用交互
#include "Dot.h"
#include "GoodsManager.h"
class MAPPA{
	public:
		GoodsManager gm;
		Dot d[201][201];
		void init();
		void update(int zhen);
		void change(int zhen); 
		void vanish(int zhen);
}; 


