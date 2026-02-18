#include<iostream>
#include<memory>
using namespace std;
struct tree
{
    unique_ptr<tree>left;
    int val;
    unique_ptr<tree>right;
    
    tree(int v)
    {
        val=v;
    }
};

void inorder(const tree* root)
{
    if(!root)
    {
        return;
    }
    inorder(root->left.get());
    cout<<root->val<<" ";
    inorder(root->right.get());
}

int main()
{
    auto root=make_unique<tree>(5);
    root->left=make_unique<tree>(6);
    root->right=make_unique<tree>(7);
    root->left->left=make_unique<tree>(8);
    root->right->right=make_unique<tree>(9);
    
    inorder(root.get());
    return 0;
}























