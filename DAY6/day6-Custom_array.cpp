#include<iostream>
using namespace std;
class Array 
{
    int data[5];
    public:
    Array()
    {
        cout<<"constructor called\n";
        cout<<"enter 5 elements\n";
        int i;
        for(i=0;i<5;i++)
        {
            cin>>data[i];
        }
        
    }
    
    int size()
    {
        return 5;
    }
    
    int* begin() noexcept
    {
        return data;
    }
    
    int* end() noexcept
    {
        return data+5;
    }
    
    int& operator[](int i)
    {
        return data[i];
    }
    
    int& at(int i)
    {
        if(i>=5)
        {
            throw out_of_range("array::at");
        }
        return data[i];
    }
    
    void print()
    {
        cout<<"printing all elements\n";
        for(int i=0;i<5;i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
    
    const int& constat(int i)
    {
        if(i>=5)
        {
            throw out_of_range("array::at");
        }
        return data[i];
    }
    
  int front()
  {
      return data[0];
  }
  int back()
  {
      return data[4];
  } 
    ~Array()
    {
        cout<<"destructor called\n";
    }
};

int main()
{
    Array arr;
    cout<<"size="<<arr.size()<<endl;
    cout<<"at()="<<arr.at(3)<<endl;
    cout<<"front()="<<arr.front()<<endl;
    cout<<"back()="<<arr.back()<<endl;
    return 0;
}





















