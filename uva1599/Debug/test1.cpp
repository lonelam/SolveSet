#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
    srand(time(0));
    ofstream fout;
    fout.open("test1.in");
    ifstream fin;
    fin.open("yuan.in");
    //fout.open("yuan.in");
    if(fout.is_open())
    {
    int n , m ;
    while(fin>>n>>m)
    {
      fout<<n<<' '<<m<<endl;
      for(int i = 0;i<m;i++)
      {
        fout<<rand()%n+1<<' '<< rand() % n+1<<' '<<rand() % 5000<<endl;
      }
     
    }
    }
} 
