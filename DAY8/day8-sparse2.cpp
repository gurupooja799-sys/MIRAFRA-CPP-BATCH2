//modern stl to avoid sparse array
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<pair<int,int>>vec;
    vec.push_back({3,2});
    vec.push_back({5,1});
    for(auto x:vec)
    {
        cout<<"index:"<<x.first<<", value:"<<x.second<<endl;
    }
    return 0;
}