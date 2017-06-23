/*
B Onlinejudge好难写
lonelam最近很为智障的OJ头疼，OnlineJudge中有两种问题：一种是在比赛当中的问题，这种问题要根据
大家的提交来更新比赛的排名，另一种是在问题集中的问题，这种问题主要供大家训练用，所以只需要记录提
交信息，但是比赛结束后，比赛中的问题要公开，有时候也会拉取问题集中的问题作为比赛题目，甚至重复添加。
但是为了公平起见，在比赛中的问题不允许在外面被提交，所有包含该问题的比赛结束后，问题应该会自动公开。也就是说，
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
如果在比赛中读取题目，则输出所有题目所在的比赛的编号并换行，如果有多个比赛包含此问题
如果在问题集中读取题目，则输出一行Response
如果结束已经结束或不存在的比赛或者向已经结束的比赛中添加问题，或者结束不存在的问题，
则输出一行Invalid
比赛名字不超过30字符
*/
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
set<string> prob;
map<string, set<int> > cont;
map<int, vector<string> > contest_list;
map<int, int> isopen;
int main()
{
  int n, q;
  freopen("9.in", "r", stdin);
  freopen("9.out", "w", stdout);
  while(cin >> n >> q)
  {
      string tmp;
    for (int i = 0; i < n; i++)
    {
      cin >> tmp;
      //1 refer pub
      prob.insert(tmp);
    }
  int cmd;
  int tot = 0;
    for (int i = 0; i < q; i++)
    {
      cin >> cmd;
      if (cmd == 1)
      {
        cin >> tmp;
        if (cont.find(tmp) == cont.end())
        {
          cout << "DoNotExist" << endl;
        }
        else
        {
          int cnt = cont[tmp].size() - 1;
          for (int x: cont[tmp])
          {
            if (--cnt)
            {
              cout << x << " ";
            }
            else
            {
              cout << x << endl;
            }
          }
        }
      }
      else if (cmd == 2)
      {
        cin >> tmp;
        if (prob.find(tmp) == prob.end())
        {
          cout << "DoNotExist" << endl;
        }
        else
        {
          cout << "Response" << endl;
        }
      }
      else if (cmd == 3)
      {
        isopen[++tot] = 1;
      }
      else if (cmd == 4)
      {
        int id;
        cin >> id;
        if (isopen[id])
        {
          isopen[id] = 0;
          for (string x : contest_list[id])
          {
            cont[x].erase(id);
            if (cont[x].size() == 0)
            {
              prob.insert(x);
              cont.erase(x);
            }
          }
          contest_list.erase(id);
        }
        else
        {
          cout << "Invalid" << endl;
        }
      }
      else if (cmd == 5)
      {
        int id;
        cin >> tmp >> id;
        if (!isopen[id])
        {
          cout << "Invalid" << endl;
        }
        else
        {
          cont[tmp].insert(id);
          contest_list[id].push_back(tmp);
          if (prob.find(tmp) != prob.end())
          {
            prob.erase(tmp);
          }
        }
      }
    }
  }
}
