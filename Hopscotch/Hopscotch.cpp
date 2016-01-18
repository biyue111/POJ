//POJ 3050 hopscotch
//2015 11 19

#include <iostream>
#include <cstdio>
//#include <algorithm>
//#include <functional>
#include <set>

using namespace std;

int digit[5][5];
int tens[]={1,10,100,1000,10000,100000};
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
set<int> numset;

void Read(void)
{
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
        {
            scanf("%d",&digit[i][j]);
        }
}

void hop(int step,int x,int y,int N)
{
    int NN;
    NN = N*10 + digit[x][y];
    if(step+1 < 6)
    for(int i=0;i<4;i++)
    {
        if( (x+dx[i]>=0)&&(x+dx[i]<5)&&(y+dy[i]>=0)&&(y+dy[i]<5) )
        {
            hop(step+1,x+dx[i],y+dy[i],NN);
        }
    }
    else
    {
        numset.insert(NN);
        //printf("%d\n",NN);
        return;
    }
}
int main()
{
    Read();
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
        {
            hop(0,i,j,0);
        }
    //for(int i=numset.begin();i<numset.end();i++) printf("%d ",*i.)
    printf("%d\n",numset.size());
    return 0;
}
