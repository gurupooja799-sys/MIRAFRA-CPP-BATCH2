#include<iostream>
#include<deque>
using namespace std;
class Datatype
{
    public:
    int val;
    Datatype()
    {
        cout<<"Default constructor\n";
    }
    Datatype(int i):val(i)
    {
        cout<<"Parameterized constructor\n";
    }
    Datatype(const Datatype& ob)
    {
        val=ob.val;
        cout<<"Copy constructor\n";
    }
    Datatype& operator=(const Datatype& ob)
    {
        if(&ob==this)
        {
            return *this;
        }
        val=ob.val;
        cout<<"Copy assignement operator\n";
        return *this;
    }
    Datatype(Datatype&& ob)
    {
        val=ob.val;
        ob.val=0;
        cout<<"Move constructor\n";
    }
    Datatype& operator=(Datatype&& ob)
    {
        if(&ob==this)
        {
            return *this;
        }
        val=ob.val;
        ob.val=0;
        cout<<"Move assignement operator\n";
        return *this;
    }
    ~Datatype()
    {
        cout<<"Destructor\n";
    }
    
};
void print(deque<Datatype>&dq)
{
    cout<<"\nprint elements:\n";
    for(auto &x:dq)
    {
        cout<<x.val<<" ";
    }
    cout<<endl;
}

int main()
{
    deque<Datatype>dq={1,2,3,4};
    cout<<"\npush_back:\n";
    dq.push_back(Datatype(5));
    cout<<"\nemplace_back:\n";
    dq.emplace_back(6);
    cout<<"\npush_front:\n";
    dq.push_front(Datatype(0));
    cout<<"\nemplace_front:\n";
    dq.emplace_front(-1);
    cout<<"dq.begin()="<<&(*dq.begin())<<endl;
    cout<<"dq.end()="<<&(*dq.end())<<endl;
    cout<<"dq.rbegin()="<<&(*dq.rbegin())<<endl;
    cout<<"dq.rend()="<<&(*dq.rend())<<endl;
    cout<<"\npop_back:\n";
    dq.pop_back();
    cout<<"\npop_front:\n";
    dq.pop_front();
    cout<<"\nerase:\n";
    dq.erase(dq.begin()+2);
    cout<<"\ninsert:\n";
    dq.insert(dq.end()-3,Datatype(9));
    cout<<"\nsize()="<<dq.size()<<endl;
    print(dq);
    cout<<"\nresize()\n";
    dq.resize(4);
    cout<<"\nsize()="<<dq.size()<<endl;
    print(dq);
    
    
    return 0;
}










