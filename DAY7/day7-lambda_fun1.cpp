#include<iostream>
using namespace std;
int main()
{
    int threshhold=50;
    int offset=10;
    bool enableset=true;
    auto checkval=[&](int value){
        threshhold+=value;
        offset=20;
        enableset=false;
    };
    checkval(10);
    cout<<"threshhold="<<threshhold<<endl;
    cout<<"off set="<<offset<<endl;
    return 0;
}