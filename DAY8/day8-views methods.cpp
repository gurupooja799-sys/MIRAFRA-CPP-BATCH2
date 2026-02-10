#include<iostream>
#include<ranges>
#include<map>
#include<vector>
using namespace std;
//keys,values,take,drop
int main()
{
    map<int,string>mp={{1,"one"},{2,"two"},{3,"three"}};
    vector<int>vec={1,2,3,4,5,6,7};
    auto k=mp |views::keys;
    auto v=mp|views::values;
    auto d=vec|views::drop(2);
    auto t=vec|views::take(4);
    cout<<"keys\n";
    for(auto x:k)
    {
        cout<<x<<" ";
    }
    cout<<"\nvalues\n";
     for(auto x:v)
    {
        cout<<x<<" ";
    }
    cout<<"\ndrop\n";
     for(auto x:d)
    {
        cout<<x<<" ";
    }
    cout<<"\ntake\n";
     for(auto x:t)
    {
        cout<<x<<" ";
    }
    cout<<"\noriginal vector\n";
     for(auto x:vec)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
    
}