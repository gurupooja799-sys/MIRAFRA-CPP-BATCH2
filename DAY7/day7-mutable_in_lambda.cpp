#include<iostream>
using namespace std;
//[&] every value captured by reference
//[=] every value captured in value
int main()
{
    int threshhold=50;
    int offset=10;
    bool enableset=true;
    auto checkval=[&,offset,&enableset](int value)mutable{
        threshhold+=value;
        offset=20;//mutable allows changes in call by value,but value cannot effect the original.
        enableset=false;
        cout<<"threshhold="<<threshhold<<endl;
        cout<<"off set="<<offset<<endl;
        cout<<"enable set="<<enableset<<endl;
    };
    checkval(10);
    cout<<"threshhold="<<threshhold<<endl;
    cout<<"off set="<<offset<<endl;
     cout<<"enable set="<<enableset<<endl;
    return 0;
}