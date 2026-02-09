#include<iostream>
#include<functional>
using namespace std;
void fun(auto value)//c++20
{
    cout<<"value="<<value<<endl;
}
int main()
{
    int x=10;
    auto genericfun=[=](auto a,auto b) //c++14
    {
        return a+b+x;  //for generic dont use built in function 
    };
    cout<<genericfun(2,3)<<endl;
    cout<<genericfun(7.5,20)<<endl;
    fun(genericfun(3.5,5.3));
    return 0;
}