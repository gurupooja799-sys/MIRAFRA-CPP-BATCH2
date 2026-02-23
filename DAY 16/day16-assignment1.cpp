#include<iostream>
#include<memory>
#include<queue>
#include<cmath>
using namespace std;
class CAR
{
    struct details
    {
        string name;
        bool status;
        
        details(string s,bool t):name(s),status(t){}
    };
    struct tree
    {
        details data;
        int val;
        unique_ptr<tree>left;
        unique_ptr<tree>right;
        
        tree(string s,int v,bool st):data(s,st),val(v){}
    };
    unique_ptr<tree>root;
    
    public:
    void insert(string s,int data,bool st)
    {
        insertimpl(root,s,data,st);
    }
    void levelorder()
    {
        traversal(root.get());
    }
    private:
    void insertimpl(unique_ptr<tree>&root,string s,int data,bool st)
    {
        if(!root)
        {
            root=make_unique<tree>(s,data,st);
            return;
        }
        if(data < root->val)
        {
            insertimpl(root->left,s,data,st);
        }
        else if(data > root->val)
        {
            insertimpl(root->right,s,data,st);
        }
    }
    
    void traversal(tree* root)
    {
        if(!root)
        return;
        
        queue<tree*>q;
        q.push(root);
        
      /*  while(!q.empty())
        {
            tree* current=q.front();
            q.pop();
            
        cout<<"source="<<current->data.name<<"  ,availability status="<<current->data.status<<endl;
            if(current->left)
            {
                q.push(current->left.get());
            }
            if(current->right)
            {
                q.push(current->right.get());
            }
        } */
        int level=0;
        while(!q.empty())
        {
            int sz=q.size();
            cout<<"Level "<<level<<"\n";
            for(int i=0;i<sz;i++)
            {
                tree* current=q.front();
            q.pop();
            
        cout<<"source="<<current->data.name<<"  ,availability status="<<current->data.status<<endl;
            if(current->left)
            {
                q.push(current->left.get());
            }
            if(current->right)
            {
                q.push(current->right.get());
            }
            }
            level++;
        }
        cout<<"\n";
    }
};

int main()
{
    CAR ptr;
    ptr.insert("ECU",50,true);
    ptr.insert("dash borad",30,true);
    ptr.insert("safety system",70,true);
    ptr.insert("speed",20,true);
    ptr.insert("fuel",40,true);
    ptr.insert("air bag",60,false);
    ptr.insert("anti lock",80,true);
    ptr.levelorder();
    return 0;
}















