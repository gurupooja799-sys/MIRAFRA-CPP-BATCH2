#include<iostream>
#include<functional>
using namespace std;
void Outside(function<int()>f)
{
        int x=10;
        f=[&x]()
        {
            return x;
        };
   
}
int main()
{
   function<int()>f;
   Outside(f);
    cout<<f();
    return 0;
}