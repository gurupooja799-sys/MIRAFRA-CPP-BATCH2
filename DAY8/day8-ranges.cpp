#include<iostream>
#include<ranges>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int>v={5,-2,8,1,9,0,1};
    ranges::sort(v);
    for(auto &x:v)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    auto it=ranges::find(v,8);
    if(it!=v.end())
    {
        cout<<"the element 8 found at index:"<<distance(v.begin(),it)<<endl;
    }
    vector<int>destination(v.size());
    ranges::copy(v,destination.begin());
    cout<<"after copy:\n";
    for(auto &x:destination)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    
    ranges::for_each(v,[](int x)
    {
        x= x*2;
        cout<<x<<" ";
    });
    
    bool all_positive=ranges::all_of(v,[](int x)
    {
        return x>0;
    }
   );

    cout<<endl<<boolalpha<<all_positive<<endl;
    
    int c=ranges::count(v,1);
    cout<<"count of 1:"<<c<<endl;
    
    return 0;
}

















