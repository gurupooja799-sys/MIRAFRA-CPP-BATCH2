#include<iostream>
#include<functional>
using namespace std;
int main()
{
    int x=10;
    function<int(int,int)>f=[=](int a,int b)
    {
        return a+b+x;
    };
    cout<<f(3,5);
    return 0;
}