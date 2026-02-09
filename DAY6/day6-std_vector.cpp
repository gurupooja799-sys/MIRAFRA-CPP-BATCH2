#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>vec(3,100);
    vec.push_back(500);
    vec.emplace_back(600);
    vec.insert(vec.begin()+3,200);
    vec.pop_back();
    vec.erase(vec.begin()+2);
    cout<<"front()="<<vec.front()<<endl;
    cout<<"back()="<<vec.back()<<endl;
    cout<<"size()="<<vec.size()<<endl;
    cout<<"capacity()="<<vec.capacity()<<endl;
    vec.shrink_to_fit();
    vec.push_back(700);
    cout<<"capacity()="<<vec.capacity()<<endl;
    for(int i=0;i<vec.size();i++)
    cout<<vec[i]<<" ";
    return 0;
}