#include<iostream>
#include<memory>
using namespace std;
class custom_list
{
    struct Node
    {
        Node* prev;
        int val;
        Node* next;
        Node(int v):prev(nullptr),val(v),next(nullptr){}
    };
    Node* head=nullptr;
    public:
    custom_list()
    {
        head=nullptr;
    }
    void push_front(int v)
    {
        auto p=new Node(v);
        if(head==nullptr)
        {
            head=p;
        }
        else
        {
            p->next=head;
            head=p;
        }
    }
    void print()
    {
        auto temp=head;
        while(temp)
        {
            cout<<temp->val<<" ";
            temp=(temp->next);
        }
        cout<<"\n";
    }
   void push_back(int v)
    {
         auto p=new Node(v);
         auto temp=head;
         while(temp->next)
         {
             temp=(temp->next);
         }
         p->prev=temp;
         temp->next=p;
    }
    
    void pop_front()
    {
        auto p=head;
        head=head->next;
        p->next->prev=nullptr;
        delete p;
    }
    
    void pop_back()
    {
        auto temp=head;
        auto p=head;
         while(temp->next)
         {
             p=temp;
             temp=(temp->next);
         }
         p->next=nullptr;
         temp->prev=nullptr;
         delete temp;
    }
    int size()
    {
        int c=0;
        auto temp=head;
         while(temp)
         {
             c++;
             temp=(temp->next);
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
        while(head)
        {
             auto p=head;
             head=head->next;
             delete p;
        }
    }
    void insert(int pos,int n)
    {
        auto p=new Node(n);
        auto temp=head;
        while(--pos)
        {
            temp=(temp->next);
        }
        temp->next->prev=p;
        p->next=temp->next;
        temp->next=p;
        p->prev=temp;
       
    }
};
int main()
{
    custom_list s1;
    s1.push_front(6);
    s1.push_front(7);
    s1.push_front(8);
    s1.push_back(9);
    s1.insert(3,12);
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






