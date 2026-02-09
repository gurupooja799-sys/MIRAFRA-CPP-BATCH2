#include<iostream>
using namespace std;
constexpr int factorial(int n)
{
    int result=1;
    for(int i=1;i<=n;i++)
    {
        result*=i;
    }
    return result;
}

int main()
{
    constexpr int f5=factorial(5);
    int f6=factorial(6);
    cout<<"f5="<<f5<<endl;
    cout<<"f6="<<f6<<endl;
    return 0;
}