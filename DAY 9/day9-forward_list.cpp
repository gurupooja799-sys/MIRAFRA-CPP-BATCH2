#include<iostream>
using namespace std;
struct Node
{
    int val;
    Node *next;
};
void push_front(Node *&root,int v)
{
    Node *nw=new Node{v,root};
    root=nw;
}
void push_back(Node *&root,int v)
{
    Node *nw=new Node{v,nullptr};
    if(root==nullptr)
    {
        root=nw;
    }
    else
    {
        while(root->next)
        {
            root=root->next;
        }
        root->next=nw;
    }
}

void print(Node* root)
{
    while(root)
    {
        cout<<root->val<<" ";
        root=root->next;
    }
    cout<<endl;
}

void clear(Node*& root)
{
    while(root)
    {
        Node* temp=root;
        root=temp->next;
        delete temp;
    }
}

unsigned int size(Node *root)
{
    int c=0;
    while(root)
    {
        c++;
        root=root->next;
    }
    return c;
}

void resize(Node*& root,int n)
{
    Node* r=root;
    Node* prev;
    while(n--)
    {
        prev=r;
        r=r->next;
    }
    while(r)
    {
        Node* t=r;
        r=t->next;
        delete t;
    }
    if(prev)
    {
        prev->next=nullptr;
    }
    cout<<"resize\n";
}

bool empty(Node* root)
{
    if(root==nullptr)
    {
        return 1;
    }
    return 0;
}

int front(Node* root)
{
    if(root)
    return root->val;
    else
    return 0;
}

void Remove(Node*& root,int n)
{
    if(root==nullptr)
      return;
    while(root)
    {
        if(root->val==n)
        {
            Node* temp=root;
            root=temp->next;
            delete temp;
        }
        else
        {
            break;
        }
    }
     Node* p=root->next;
    while(p)
    {
        if(p->val==n)
        {
             Node* temp=p->next;
            p->next=temp->next;
            delete temp;
            
        }
        else
        {
            p=p->next;
        }
     
    }
}

int main()
{
    Node* root=nullptr;
    push_front(root,6);
    push_front(root,7);
    push_front(root,5);
    push_front(root,3);
    push_front(root,2);
    push_front(root,1);
    print(root);
    cout<<"size="<<size(root)<<endl;
    resize(root,4);
    print(root);
    cout<<"size="<<size(root)<<endl;
    cout<<"front()="<<front(root)<<endl;
    cout<<"empty()="<<boolalpha<<empty(root)<<noboolalpha<<endl;
    Remove(root,3);
    print(root);
    clear(root);
   cout<<"size="<<size(root)<<endl;
    cout<<"empty()="<<boolalpha<<empty(root)<<noboolalpha<<endl;
    return 0;
}










