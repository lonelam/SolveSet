

//test.cpp

/*
项目2：字符串类（方案1封装C-字符串。或者方案2不使用串结束标志，另用int num；数据成员记录字符串长度）。
*/


//String.cpp
//String.h
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
class String
{
public:
	String(const char *str = NULL)//通用构造
    {
		if(!str)
		{
			len = 0;
			p = new char [1];
			*p = '\0';
		}
		else
    	{
			len = strlen(str);
      		p = new char [len+1];
      		strcpy(p,str);
		}
    }
	String(const String &other)//拷贝构造
    {
    	len = other.len;
      	p = new char [len+1];
      	strcpy(p,other.p);
    }
	~ String()//析构函数
  	{
      	delete[] p;
		len = 0;
    }
	int getLen() const //获取长度
    {
		return len;
	}
	inline const char* cStr() const//获取C字符串
	{
		return p;
	}
	String subStr(int start,int end)//获得start到end的子序列
	{
		String t;
		if(start < 0||end > len)
			return t;
		t.len = end - start;
		t.p = new char [len + 1];
		strncpy(t.p,p+start,t.len);
		return t;
	}
	void repeat(int times)//重复string内容
	{
		while(times--)
		{
			*this = *this + *this;
		}
		len = len * times;
	}
	void print() const //打印C字符串
  	{
	    printf("%s",cStr());
	}
	void resize(int size)//重新设定容量，如果size小于当前容量，会截断size之后的字符
	{
		if (size <= 0)
			return;
		len = size;
		char *t;
		t = new char [size+1];
		strncpy(t,p,len);
		delete[] p;
		p = t;
		len = size;
	}
	void clear()//将string用0清空
	{
		memset(p,0,len*sizeof(char)+1);
	}

	bool operator ==(const String &other)//重载运算符==
    {
    	if(len!=other.len)
          	return false;
      	else
      		if(strcmp(p,other.p)==0)
				return true;
		return false;
    }
	String & operator =(const String &other)//重载运算符=
	{
    	if (this == &other)
			return *this;
		delete []p;
		len = other.len;
		p = new char[len + 1];
		strcpy(p, other.cStr());
		return *this;
    }
	String operator +(const String &other)//重载运算符+
    {
    	String s;
		s.len = len + other.getLen();
		s.p = new char[s.len + 1];
		strcpy(s.p, p);
		strcat(s.p, other.p);
		return s;
    }
	bool operator >(const String &other)//重载运算符>  <以及<= >= 同理
	{
		if(strcmp(p,other.p)>0)
				return true;
		else
			return false;

	}
private:
	int len;//  字符串长度
	char *p;//  字符串首地址
};
int main()
{
	String t1("Hello");
	t1.print();
	String t2("World");
	t2.print();
	String t3(t1);
	t3.print();
	String t4;
	t4 = t1+t2;
	t4.print();
	if(t1>t2)
		printf("t1>t2\n");
	else
		printf("t1<=t2\n");
	if(t3==t1)
		printf("t1==t2\n");
	else
		printf("t1!=t2\n");
}
