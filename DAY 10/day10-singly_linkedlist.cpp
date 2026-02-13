#include<iostream>
#include<memory>
using namespace std;
class singly_list
{
    struct Node
    {
        int val;
        unique_ptr<Node>next;
        Node(int v):val(v),next(nullptr){}
    };
    unique_ptr<Node>head;
    public:
    singly_list()
    {
        head=nullptr;
    }
    void push_front(int v)
    {
        auto p=make_unique<Node>(v);
        p->next=move(head);
        head=move(p);
    }
    void print()
    {
        auto temp=head.get();
        while(temp)
        {
            cout<<temp->val<<" ";
            temp=(temp->next).get();
        }
        cout<<"\n";
    }
    void push_back(int v)
    {
         auto p=make_unique<Node>(v);
         auto temp=head.get();
         while(temp->next)
         {
             temp=(temp->next).get();
         }
         temp->next=move(p);
    }
    void pop_front()
    {
        auto p=move(head);
        head=move(p->next);
    }
    void pop_back()
    {
        auto p=nullptr;
        auto temp=head.get();
         while((temp->next)->next)
         {
             temp=(temp->next).get();
         }
         temp->next=move(p);
    }
    int size()
    {
        int c=0;
        auto temp=head.get();
         while(temp)
         {
             c++;
             temp=(temp->next).get();
         }
         return c;
    }
    bool empty()
    {
        if(head==nullptr)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void clear()
    {
        auto p=move(head);
    }
    void insert_after(int pos,int n)
    {
        auto p=make_unique<Node>(n);
        auto temp=head.get();
        while(pos--)
        {
            temp=(temp->next).get();
        }
        p->next=move(temp->next);
        temp->next=move(p);
    }
};
int main()
{
    singly_list s1;
    s1.push_front(6);
    s1.push_front(7);
    s1.push_front(8);
    s1.push_back(9);
    s1.insert_after(3,12);
    s1.push_back(10);
    s1.push_back(11);
    s1.pop_front();
    s1.pop_back();
    cout<<"size():"<<s1.size()<<endl;
    cout<<"empty():"<<boolalpha<<s1.empty()<<noboolalpha<<endl;
    s1.print();
    s1.clear();
    cout<<"after clear\n";
     cout<<"size():"<<s1.size()<<endl;
    cout<<"empty():"<<boolalpha<<s1.empty()<<noboolalpha<<endl;
    s1.print();
    return 0;
}






