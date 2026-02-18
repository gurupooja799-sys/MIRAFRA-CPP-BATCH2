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

tree* insert(tree *root,int v)
{
    if(root==nullptr)
    {
        return new tree(v);
    }
    
    if(root->val > v)
    {
        root->left=insert(root->left,v);
    }
    else if(root->val <v)
    {
        root->right=insert(root->right,v);
    }
    
    return root;
}

 void inorder(tree *root)
 {
        if(!root)
           return;
        inorder(root->left);
        cout<<"root->val="<<root->val<<" root->left="<<root->left<<" root->right="<<root->right<<endl;
        inorder(root->right);
 }
 
 void delete_tree(tree *root)
 {
     if(root==nullptr)
     {
         return;
     }
     delete_tree(root->left);
     delete_tree(root->right);
     
     cout<<"deleting node="<<root->val<<" address="<<root<<endl;
     delete root;
 }
 
 int main()
 {
     tree* root=nullptr;
     root=insert(root,7);
     root=insert(root,4);
     root=insert(root,9);
     root=insert(root,6);
     
     inorder(root);
     
     cout<<"\n\n";
     delete_tree(root);
     return 0;
 }











