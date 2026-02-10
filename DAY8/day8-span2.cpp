#include<iostream>
#include<span>
using namespace std;
void print(span<int>s,const string &name)
{
    cout<<name<<":\n";
     for(auto x:s)
    cout<<x<<" ";
    cout<<endl;
    
}
int main()
{
    int *ptr=new int[5]{1,2,3,4,5};
    span<int>s(ptr,5);
    for(auto &x:s)
    x+=5;
    cout<<"front="<<s.front()<<endl;
    cout<<"back="<<s.back()<<endl;
    auto first_half=s.first(2);
    auto last_half=s.last(3);
    auto middle=s.subspan(1,3);
    print(first_half,"first_half");
    print(last_half," last_half");
    print(middle,"middle");

    delete []ptr;
    return 0;
}