#include<iostream>
using namespace std;
template<typename T>
void process(T val)
{
    if constexpr(sizeof(T)==4)
    {
        cout<<"32 bits type\n";
    }
    else
    {
        cout<<"not a 32-bit type\n";
    }
}
int main()
{
    process(5);
    process(3.5);
    process('j');
    return 0;
}