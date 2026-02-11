#include<iostream>
using namespace std;
struct Node
{
    Node *prev;
    int val;
    Node *next;
};
void add_front(Node *&root,int v)
{
    Node *nw=new Node{nullptr,v,root};
    root=nw;
}
void add_back(Node *&root,int v)
{
    Node *nw=new Node{nullptr,v,nullptr};
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
        nw->prev=root;
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

int main()
{
    Node* root=nullptr;
    add_back(root,6);
    add_back(root,7);
    add_front(root,5);
    add_front(root,3);
    add_front(root,2);
    add_front(root,1);
    print(root);
    return 0;
}










