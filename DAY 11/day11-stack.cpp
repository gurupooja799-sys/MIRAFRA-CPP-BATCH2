#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//int top=0;
struct process
{
    int pid;
    string p_name;
    bool status;
    process(int id,string name,bool st)
    {
        pid=id;
        p_name=name;
        status=st;
    }
    ~process()
    {
        cout<<"process completed\n";
    }
};
int main()
{
    stack<process>st;
    st.push(process(1,"temp",0));
    st.push(process(2,"humid",1));
   while(!st.empty())
   {
       cout<<st.top().pid<<" "<<st.top().p_name<<" "<<st.top().status<<endl;
       st.pop();
   }
}
















