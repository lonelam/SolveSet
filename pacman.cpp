
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<list>
#include<string>
#include<ctime>
#include"jsoncpp/json.h"
using namespace std;
int n,m;
const int maxn=25;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
bool invalid[maxn][maxn];

struct point
{
	int x,y;
	point(int _x,int _y)
	{
		x=_x;
		y=_y;
	}
};

list<point> snake[2]; // 0表示自己的蛇，1表示对方的蛇
int possibleDire[10];
int posCount;

bool whetherGrow(int num)  //本回合是否生长
{
	if (num<=9) return true;
	if ((num-9)%3==0) return true;
	return false;
}

void deleteEnd(int id)     //删除蛇尾
{
	snake[id].pop_back();
}

void move(int id,int dire,int num)  //编号为id的蛇朝向dire方向移动一步
{
	point p=*(snake[id].begin());
	int x=p.x+dx[dire];
	int y=p.y+dy[dire];
	snake[id].push_front(point(x,y));
	if (!whetherGrow(num))
		deleteEnd(id);
}
void outputSnakeBody(int id)    //调试语句
{
	cout<<"Snake No."<<id<<endl;
	for (list<point>::iterator iter=snake[id].begin();iter!=snake[id].end();++iter)
		cout<<iter->x<<" "<<iter->y<<endl;
	cout<<endl;
}

bool isInBody(int x,int y)   //判断(x,y)位置是否有蛇
{
	for (int id=0;id<=1;id++)
		for (list<point>::iterator iter=snake[id].begin();iter!=snake[id].end();++iter)
			if (x==iter->x && y==iter->y)
				return true;
	return false;
}

bool validDirection(int id,int k)  //判断当前移动方向的下一格是否合法
{
	point p=*(snake[id].begin());
	int x=p.x+dx[k];
	int y=p.y+dy[k];
	if (x>n || y>m || x<1 || y<1) return false;
	if (invalid[x][y]) return false;
	if (isInBody(x,y)) return false;
	return true;
}

int Rand(int p)   //随机生成一个0到p的数字
{
	return rand()*rand()*rand()%p;
}

int main()
{
	memset(invalid,0,sizeof(invalid));
	string str;
	string temp;
	while (getline(cin,temp))
		str+=temp;

	Json::Reader reader;
	Json::Value input;
	reader.parse(str,input);

	n=input["requests"][(Json::Value::UInt) 0]["height"].asInt();  //棋盘高度
	m=input["requests"][(Json::Value::UInt) 0]["width"].asInt();   //棋盘宽度

	int x=input["requests"][(Json::Value::UInt) 0]["x"].asInt();  //读蛇初始化的信息
	if (x==1)
	{
		snake[0].push_front(point(1,1));
		snake[1].push_front(point(n,m));
	}
	else
	{
		snake[1].push_front(point(1,1));
		snake[0].push_front(point(n,m));
	}
	//处理地图中的障碍物
	int obsCount=input["requests"][(Json::Value::UInt) 0]["obstacle"].size();

	for (int i=0;i<obsCount;i++)
	{
		int ox=input["requests"][(Json::Value::UInt) 0]["obstacle"][(Json::Value::UInt) i]["x"].asInt();
		int oy=input["requests"][(Json::Value::UInt) 0]["obstacle"][(Json::Value::UInt) i]["y"].asInt();
		invalid[ox][oy]=1;
	}

	//根据历史信息恢复现场
	int total=input["responses"].size();

	int dire;
	for (int i=0;i<total;i++)
	{
		dire=input["responses"][i]["direction"].asInt();
		move(0,dire,i);

		dire=input["requests"][i+1]["direction"].asInt();
		move(1,dire,i);
	}

	if (!whetherGrow(total)) // 本回合两条蛇生长
	{
		deleteEnd(0);
		deleteEnd(1);
	}

	for (int k=0;k<4;k++)
		if (validDirection(0,k))
			possibleDire[posCount++]=k;

	srand((unsigned)time(0)+total);

	//随机做出一个决策
	Json::Value ret;
	ret["response"]["direction"]=possibleDire[rand()%posCount];

	Json::FastWriter writer;
	cout<<writer.write(ret)<<endl;

	return 0;
}
