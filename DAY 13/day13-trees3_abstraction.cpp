    

#include<iostream>
#include<memory>
using namespace std;
class BST
{
    struct tree
    {
    unique_ptr<tree>left;
    int val;
    unique_ptr<tree>right;
    
    tree(int v):val(v){}
    };
    unique_ptr<tree>root;
    public:
    void insert(int v)
    {
        implinsert(root,v);
    }
    void inorder()
    {
        implinorder(root.get());
    }
 private:
   void implinsert(unique_ptr<tree>&root,int r)
   {
        if(root==nullptr)
       {
           root=make_unique<tree>(r);
        return ;
       }
    
    if(root->val > r)
    {
        implinsert(root->left,r);
    }
    else if(root->val <r)
    {
       implinsert(root->right,r);
    }
    }
    
    void implinorder(tree* root)
    {
        if(!root)
        {
            return;
        }
        implinorder(root->left.get());
        cout<<root->val<<" ";
        implinorder(root->right.get());
    }
};

int main()
{
    BST ptr;
    ptr.insert(10);
    ptr.insert(6);
    ptr.insert(9);
    ptr.insert(15);
    ptr.insert(26);
    
    ptr.inorder();
    return 0;
}























