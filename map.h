//

class Point
{
public:
    int x, y;
    int type; //1 代表可以走的陆地  2 代表障碍物  3 代表货品  4 泊点
    Point(int x, int y, int type){

    }
};


class Map
{
public:
    Point* cnt[201][201];

    int get_type(int x, int y) {
        return cnt[x][y]->type;
    }

};
