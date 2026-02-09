#include<iostream>
using namespace std;
class intvector
{
    int *data;
    int sz;
    int cap;
    public:
    intvector()
    {
        cout<<"constructor called\n";
        data=nullptr;
        sz=0;
        cap=0;
    }
    void grow()
    {
        if(cap)
        cap*=2;
        else
        cap=1;
        int *ptr=data;
        //delete []data;
        data =new int[cap];
        if(cap>1)
        data =ptr;
    }
    void push_back(int x)
    {
        if(sz==cap)
        grow();
        data[sz++]=x;
    }
    void pop_back()
    {
        if(sz)
        {
            data[sz-1]=0;
            sz--;
        }
    }
    bool empty()
    {
        if(sz==0)
        return true;
        return false;
    }
    void print()
    {
        cout<<"print an array:\n";
        for(int i=0;i<cap;i++)
        cout<<data[i]<<" ";
        cout<<endl;
    }
    int size()
    {
        return sz;
    }
    int capacity()
    {
        return cap;
    }
    void fill()
    {
        for(int i=sz;i<cap;i++)
        data[i]=0;
    }
    int* begin()
    {
        return data;
    }
    int* end()
    {
        return (data+sz);
    }
    void erase(int* p)
    {
        int i=p-begin();
        for(i;i<sz-1;i++)
        {
            data[i]=data[i+1];
        }
        data[sz-1]=0;
    }
    void clear()
    {
        data=NULL;
        sz=0;
    }
    void shrink_to_fit()
    {
        int *p=data;
        //delete[] data;
        data=new int[sz];
        data=p;
        cap=sz;
    }
    ~intvector()
    {
        cout<<"destructor called\n";
        delete []data;
    }
};

int main()
{
    intvector v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(8);
    v.push_back(9);
    v.push_back(7);
    v.print();
    cout<<"pop_back()\n";
    v.pop_back();
    v.print();
    cout<<"size()="<<v.size()<<endl;
    cout<<"capacity()="<<v.capacity()<<endl;
    cout<<"empty()="<<v.empty()<<endl;
    cout<<"begin()="<<v.begin()<<endl;
    cout<<"end()="<<v.end()<<endl;
    v.erase(v.begin()+2);
    cout<<"fill():\n";
    v.fill();
    cout<<"shrink to fit\n";
    v.shrink_to_fit();
    cout<<"size()="<<v.size()<<endl;
    cout<<"capacity()="<<v.capacity()<<endl;
    cout<<"clear\n";
    v.clear();
    v.print();
    cout<<"size()="<<v.size()<<endl;
    cout<<"capacity()="<<v.capacity()<<endl;
    return 0;
}









