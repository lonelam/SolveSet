#include<bits/stdc++.h>
using namespace std;
struct a
{
    virtual void fxxk() = 0;

};

struct b :public a
{
    b()
    {
        cout << "b constructor"<<endl;
    }
    void fxxk()
    {
        cout << "hola fxker"<<endl;
    }
};
void dock(a & here)
{
    here.fxxk();
}
int main()
{
    b hola;
    dock(hola);
}
