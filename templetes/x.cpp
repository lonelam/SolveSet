#include<iostream>
#include<string>
using namespace std;
struct a
{
    a(){ cout << "def constor\n";}
    a(int a) {cout << "int constor\n";}
   // a(a src) {cout << "naive constor\n";}
    a(a & src) {cout <<"copy constor";}
    a(a && src)
    {
        cout <<"move ctor\n";
    }
    a & operator = (a && rhs)
    {
        cout <<"move ope\n";
        return *this;
    }

};
a b()
{
    a k(5);
    return k;
}
main()
{
    a hhh;
    hhh = b();

}
