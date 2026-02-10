//old style structure to avoid sparse arrays and matrix
#include<iostream>
#include<vector>
using namespace std;
struct sparse
{
    public:
    int index;
    int value;
};
int main()
{
    vector<sparse>vec;
    vec.push_back({3,2});
    vec.push_back({5,1});
    for(auto x:vec)
    {
        cout<<"index="<<x.index<<", value="<<x.value<<endl;
    }
    return 0;
}