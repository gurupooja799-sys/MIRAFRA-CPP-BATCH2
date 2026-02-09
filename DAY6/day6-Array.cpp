#include<iostream>
#include<array>
#include<algorithm>
using namespace std;
int main()
{
    array<int,6>a={8,4,9,2};
    cout<<"a[2]="<<a[2]<<endl;
    cout<<"a.at(2)="<<a.at(2)<<endl;
    cout<<"a.size()="<<a.size()<<endl;
    cout<<"a.max_size()"<<a.max_size()<<endl;
    cout<<"front element="<<a.front()<<endl;
    cout<<"back element="<<a.back()<<endl;
    cout<<"a.data()="<<a.data()<<endl;
    cout<<"prints using range based for loop\n";
    for(int i:a)
    cout<<i<<" ";
    cout<<"\nsorted array:\n";
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++)
    cout<<a[i]<<" ";
    return 0;
}