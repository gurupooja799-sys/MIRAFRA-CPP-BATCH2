#include<iostream>
#include<memory>
#include<queue>
using namespace std;
class BST
{
    struct tree
    {
        int val;
        unique_ptr<tree>left;
        unique_ptr<tree>right;
        
        tree(int v):val(v){}
    };
    unique_ptr<tree>root;
    
    public:
    void insert(int data)
    {
        insertimpl(root,data);
    }
    void levelorder()
    {
        traversal(root.get());
    }
    private:
    void insertimpl(unique_ptr<tree>&root,int data)
    {
        if(!root)
        {
            root=make_unique<tree>(data);
            return;
        }
        if(data < root->val)
        {
            insertimpl(root->left,data);
        }
        else if(data > root->val)
        {
            insertimpl(root->right,data);
        }
    }
    
    void traversal(tree* root)
    {
        if(!root)
        return;
        
        queue<tree*>q;
        q.push(root);
        while(!q.empty())
        {
            tree* current=q.front();
            q.pop();
            cout<<current->val<<" ";
            if(current->left)
            {
                q.push(current->left.get());
            }
            if(current->right)
            {
                q.push(current->right.get());
            }
        }
        cout<<"\n";
    }
};

int main()
{
    BST ptr;
    ptr.insert(50);
    ptr.insert(30);
    ptr.insert(20);
    ptr.insert(40);
    ptr.insert(70);
    ptr.insert(60);
    ptr.insert(80);
    ptr.levelorder();
    return 0;
}















