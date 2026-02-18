#include<iostream>
using namespace std;
struct tree
{
    tree *left;
    int val;
    tree *right;
    
    tree(int v)
    {
        left=nullptr;
        val=v;
        right=nullptr;
    }
};  
    void inorder(tree *root)
    {
        if(!root)
           return;
        inorder(root->left);
        cout<<"root->val="<<root->val<<" root->left="<<root->left<<" root->right="<<root->right<<endl;
        inorder(root->right);
    }

int main()
{
    tree* root=new tree(5);
    root->left=new tree(4);
    root->right=new tree(6);
    root->left->left=new tree(3);
    root->right->right=new tree(7);
    inorder(root);
    
}





