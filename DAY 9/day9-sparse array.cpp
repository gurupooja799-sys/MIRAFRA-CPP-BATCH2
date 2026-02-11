#include<iostream>
#include<vector>
#include<utility>
using namespace std;
class Sparsearray
{
    vector<pair<int,int>>data;
    public:
    Sparsearray()
    {
        cout<<"constructor\n";
    }
    void set(int i,int v)
    {
       // data.first=i;
        //data.second=v;
        data.push_back({i,v});
    }
    int get(int index)
    {
        for(const auto &[i,v]:data)
        {
            if(i==index)
            return v;
        }
        return 0;
    }
    void print()
    {
        for(const auto &[i,v]:data)
        {
            cout<<"index:"<<i<<", value:"<<v<<endl;
        }
    }
    ~Sparsearray()
    {
        cout<<"destructor\n";
    }
    
};
int main()
{
    Sparsearray s;
    s.set(1,3);
    s.set(4,6);
    int r=s.get(1);
    cout<<r<<endl;
    s.print();
}









