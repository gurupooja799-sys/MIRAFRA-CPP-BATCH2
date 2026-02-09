#include<iostream>
using namespace std;
void LED_ON(int pin)
{
    cout<<"pin "<<pin<<" led is in on state\n";
}
void MOTOR_ON(int pin)
{
    cout<<"pin "<<pin<<" motor is in on state\n";
}
int main()
{
    int t;
    void(*fp)(int)=LED_ON;
    fp(5);
    cout<<"enter temp:";
    cin>>t;
    if(t>25)
    {
    fp=MOTOR_ON;
    fp(7);
    }
    return 0;
}