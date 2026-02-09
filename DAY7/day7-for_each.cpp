#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int>v={1,2,3,4};
    for_each(v.begin(),v.end(),[](auto val)
    {
        cout<<val<<" ";
    });
    return 0;
}