#include<iostream>
#include<array>
using namespace std;
void function(array<int,7>&arr)
{
    for(int i=0;i<arr.size();i++)
    arr[i]=i*10;
}

int main()
{
    array<int,7>arr;
    function(arr);
    for(auto it=arr.cbegin();it!=arr.cend();it++)
    cout<<*it<<" ";
    return 0;
}