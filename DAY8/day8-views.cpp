#include<iostream>
#include<ranges>
#include<vector>
using namespace std;
int main()
{
    vector<int>v={1,2,3,4,5,6};
    auto even=v|views::filter([](int x)
    {
        return x%2==0;
    });
    cout<<"even:\n";
    for(auto &x:even)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    
    auto square=v|views::transform([](int x)
    {
        return x*x;
    });
    cout<<"square:\n";
    for(auto x:square)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    
    cout<<"original:\n";
    for(auto &x:v)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}



