#include<iostream>
#include<vector>
using namespace std;
class person
{
    public:
    person()
    {
        cout<<"constructor\n";
    }
    person(person&)
    {
        cout<<"copy constructor\n";
    }
    person(const person&&)
    {
        cout<<"move constructor\n";
    }
};

int main()
{
    vector<person>vec;
    cout<<"push back:\n";
    vec.push_back(person{});
    cout<<"\nemplace back:\n";
    vec.emplace_back(person());
    cout<<"\npush back:\n";
    vec.push_back(person{});
     cout<<"\npush back:\n";
    vec.push_back(person{});
     cout<<"\npush back:\n";
    vec.push_back(person{});
    cout<<"\nemplace back:\n";
    vec.emplace_back(person{});
  
    cout<<"size()="<<vec.size()<<endl;
    cout<<"capacity()="<<vec.capacity();
    return 0;
}

//emplace calls move constructor only during reallocation
//push calls move constructor every time










