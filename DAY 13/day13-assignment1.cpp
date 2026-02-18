#include<iostream>
using namespace std;
struct car{
    car *left;
    string cname;   //car name
    float rating;
    car *right;
    
    car(string s,float r)
    {
        cname=s;
        rating=r;
    }
};

car* insert(car *root,string name,float r)
{
    if(root==nullptr)
    {
        return new car(name,r);
    }
    
    if(root->rating > r)
    {
        root->left=insert(root->left,name,r);
    }
    else if(root->rating <r)
    {
        root->right=insert(root->right,name,r);
    }
    
    return root;
}

void inorder(car *root)
 {
        if(!root)
           return;
        inorder(root->left);
        cout<<root->cname<<" "<<root->rating<<endl;
        inorder(root->right);
 }
 
 int main()
 {
     car *root=nullptr;
     root=insert(root,"Toyota",9);
     root=insert(root,"Honda",8.5);
     root=insert(root,"Tesla",8);
     root=insert(root,"Lexus",9.6);
     root=insert(root,"Ford",7);
     
     inorder(root);
     return 0;
 }
















