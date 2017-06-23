/*
B Onlinejudge好难写
lonelam最近很为智障的OJ头疼，OnlineJudge中有两种问题：一种是在比赛当中的问题，这种问题要根据
大家的提交来更新比赛的排名，另一种是在问题集中的问题，这种问题主要供大家训练用，所以只需要记录提
交信息，但是比赛结束后，比赛中的问题要公开，有时候也会拉取问题集中的问题作为比赛题目。
但是为了公平起见，在比赛中的问题不允许在外面被提交，比赛结束后，问题应该会自动公开。也就是说，
同一个问题不能既在比赛中，又在问题集中。
现在需要你编写一个程序来处理用户请求。一开始有一些题目
一共有五种用户请求：
在比赛中读取题目、在问题集中读取题目、创建比赛、结束比赛、添加问题到某个比赛中
其中比赛从1开始，不重复地递增进行编号
输入保证每个题目名字不一样，且都是小写字母

其中格式如下：
在比赛中读取题目：1 题目名字
在问题集中读取题目：2 题目名字
创建比赛：3
结束比赛：4 比赛编号
添加问题：5 题目名字 比赛编号

如果读取题目不可见或不存在，则输出一行DoNotExist
如果在比赛中读取题目，则输出比赛编号并换行，
如果在问题集中读取题目，则输出一行
如果结束已经结束或不存在的比赛或者向已经结束的比赛中添加问题，则输出一行Invalid
比赛名字不超过30字符
*/
#define _USE_MATH_DEFINES
#include <random>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
set<string> string_table;
vector<string> all_string_table;
random_device rd;
char randchar()
{
  uniform_int_distribution<char> rndchar('a', 'z');
  return rndchar(rd);
}
void stringrand()
{
  uniform_int_distribution<int> len_rnd(3, 30);
  for (int i = 0; i < 100000; i++)
  {
    int lenlen = len_rnd(rd);
    string a(lenlen, 'a');
    for (int j = 0; j < lenlen; j++)
    {
      a[j] = randchar();
    }
    string_table.insert(a);
  }
  for (string x : string_table)
  {
    all_string_table.push_back(x);
  }
}
vector<string> inset;
vector<pair<string, int>> incontest;
map<string, int> contestid;
map<int, bool> isopen;
vector<vector<int> > contest_list;
int main()
{
  stringrand();
  for (int k = 1; k < 10; k++)
  {
    string fext = ".in";
    string fname(1, k + '0');
    string iname = fname + fext;
    int tot = 0;
    freopen(iname.c_str(), "w", stdout);
    cout << 1000 <<" "<< 10000<< endl;
    for (int i = 0; i < 1000; i++)
    {
      cout << *string_table.rbegin() << endl;
      inset.push_back(*string_table.rbegin());
      string_table.erase(*string_table.rbegin());
    }
    for (int i = 0; i < 10000; i++)
    {
      uniform_int_distribution<int> cmd_rnd(1, 5);
      int cmd = cmd_rnd(rd);
      if (cmd == 1)
      {
        cout << cmd << " ";
        uniform_int_distribution<int> tidrand(0, all_string_table.size() - 1);
        int tid = tidrand(rd);
        cout << all_string_table[tid] << endl;
      }
      else if (cmd == 2)
      {
        cout << cmd << " ";
        uniform_int_distribution<int> tidrand(0, all_string_table.size() - 1);
        int tid = tidrand(rd);
        cout << all_string_table[tid] << endl;
      }
      else if (cmd == 3)
      {
        cout << cmd << endl;
        tot++;
      }
      else if (cmd == 4)
      {
        cout << cmd << " ";
        uniform_int_distribution<int> con_rnd(1, tot?tot:1000);
        cout << con_rnd(rd) << endl;
      }
      else if (cmd == 5)
      {
        cout << cmd << " ";
        uniform_int_distribution<int> tidrand(0, all_string_table.size() - 1);
        int tid = tidrand(rd);
        uniform_int_distribution<int> con_rnd(1, tot?tot:1000);
        cout << all_string_table[tid] << " " << con_rnd(rd) << endl;
      }
    }
  }
}
