#include<iostream>
#include<deque>
using namespace std;
int tablesize=4;
const int blocksize=4;
class simple_deque
{
    int **blocktable;
    int startblock;
    int endblock;
    int startoffset;
    int endoffset;
    int currentsize;
    public:
    simple_deque()
    {
        blocktable=new int*[tablesize];
        for(int i=0;i<tablesize;i++)
        {
            blocktable[i]=nullptr;
        }
        startblock=endblock=tablesize/2;
        blocktable[endblock]=new int[blocksize];
        startoffset=0;
        endoffset=0;
        currentsize=0;
    }
    void push_back(int val)
    {
        if(endoffset==blocksize)
        {
            endblock++;
            if(endblock==tablesize)
            {
                reallocation();
            }
            blocktable[endblock]=new int[blocksize];
            endoffset=0;
        }
        blocktable[endblock][endoffset++]=val;
        currentsize++;
    }
    void push_front(int val)
    {
        if(startoffset>0)
        {
            startoffset--;
        }
        else
        {
            startblock--;
            if(startblock<0)
            {
                reallocation();
            }
            blocktable[startblock]=new int[blocksize];
            startoffset=blocksize-1;
        }
        blocktable[startblock][startoffset]=val;
        currentsize++;
    }
    void display()
    {
        for(int i=startblock;i<=endblock;i++)
        {
            for(int j=0;j<4;j++)
            {
                cout<<blocktable[i][j]<<" ";
            }
        }
    }
    
    void reallocation()
    {
        int newsize=tablesize*2;
        int **newblock=new int*[newsize];
        for(int i=0;i<newsize;i++)
        {
            newblock[i]=nullptr;
        }
        int j=tablesize/2;
        for(int i=j,k=0;i<(j+tablesize);i++,k++)
        {
            newblock[i]=blocktable[k];
        }
        delete[] blocktable;
        blocktable=newblock;
        startblock+=j;
        endblock+=j;
        tablesize=newsize;
        cout<<"reallocation called\n";
        
    }
    
};
int main()
{
    simple_deque d1;
    for(int i=0;i<20;i++)
    {
        d1.push_back(i+1);
    }
     for(int i=0;i<40;i++)
    {
        d1.push_front(i+10);
    }
    d1.display();
}












