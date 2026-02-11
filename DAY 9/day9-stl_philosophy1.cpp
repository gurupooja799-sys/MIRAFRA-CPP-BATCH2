#include<iostream>
#include<vector>
#include<list>
#include<array>
#include<deque>
using namespace std;
template<typename iterator>
void print(iterator first,iterator last)
{
    while(first!=last)
    {
        cout<<*first<<" ";
        first++;
    }
    cout<<"\n";
}
int main()
{
    vector<int>v={1,2,3,4,5};
    list<int>l={10,20,30,40};
    array<int,3>a={100,200,300};
    deque<float>d={6.3,8.4,90.76};
    cout<<"vector:\n";
    print(v.begin(),v.end());
    cout<<"list:\n";
    print(l.begin(),l.end());
    cout<<"array:\n";
    print(a.begin(),a.end());
    cout<<"deque:\n";
    print(d.begin(),d.end());
    return 0;
}






