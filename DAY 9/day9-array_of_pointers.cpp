#include<iostream>
using namespace std;
int t=0;
int h=0;
int f=0;
struct Sensor
{
    int* temperature;
    int* humidity;
    int* fuel;
    Sensor(int t=0,int h=0,int f=0)
    {
        temperature=new int[t];
        humidity=new int[h];
        fuel=new int[f];
         cout<<"constructor\n";
    }
    void set_temp(int i)
    {
        
        if(t<5)
        {
            temperature[t]=i;
            t++;
        }
        else
        {
            t=0;
        }
    }
    
    void set_humid(int i)
    {
        if(h<4)
        {
            humidity[h]=i;
            h++;
        }
        else
        {
            h=0;
        }
    }
    
    void set_fuel(int i)
    {
       
        if(f<3)
        {
            fuel[3]=i;
            f++;
        }
        else
        {
            f=0;
        }
    }
    ~Sensor()
    {
        delete[] temperature;
        delete[] humidity;
        delete[] fuel;
        cout<<"destructor\n";
    }
};
int main()
{
    Sensor s1(5,4,3);
    int* ptr[3];
    ptr[0]=s1.temperature;
    ptr[1]=s1.humidity;
    ptr[2]=s1.fuel;
    s1.set_temp(25);
    s1.set_temp(22);
    s1.set_temp(30);
    s1.set_humid(27);
    s1.set_humid(24);
    s1.set_fuel(60);
    int sizes[]={t,h,f};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<sizes[i];j++)
        {
            cout<<(*(*ptr+i)+j)<<" ";   //ptr[i][j]
        }
        cout<<"\n";
    }
    return 0;
}









