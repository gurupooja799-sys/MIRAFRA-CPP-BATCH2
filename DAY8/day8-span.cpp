#include<iostream>
#include<vector>
#include<span>
using namespace std;
void function(span<int>s)
{
    for(auto &x:s)
    cout<<x<<" ";
    cout<<endl;
}
int main()
{
    vector<int>v={1,2,3,4};
    function(v);
    int arr[]={10,20,30};
    function(arr);
    return 0;
}