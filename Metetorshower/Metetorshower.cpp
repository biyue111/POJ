//Date : 2015 11 14
//POJ 3669 Meteor Shower
//Algorithm : Breath-First Search

#include <cstdio>
#include <queue>

#define MAX_XY 303
#define INF_TINE 2000
using namespace std;

int Map[MAX_XY][MAX_XY];
//int t[MAX_XY][MAX_XY];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

struct PandT{
    int x;
    int y;
    int t;
};

queue<PandT> que;


void ReadMap()
{
    int N,mx,my,mt;
    for(int i=0;i<MAX_XY;i++)   //initial Map
        for(int j=0;j<MAX_XY;j++)
        {
            Map[i][j]=INF_TINE;
            //t[i][j]=INF_TINE;
        }

    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d%d%d",&mx,&my,&mt);
        if(Map[mx][my]>mt) Map[mx][my]=mt;
        for(int j=0;j<4;j++)
        {
            if((mx+dx[j]<MAX_XY)&&(mx+dx[j]>=0)&&(my+dy[j]<MAX_XY)&&(my+dy[j]>=0))
            {
                if((Map[mx+dx[j]][my+dy[j]]>mt)) Map[mx+dx[j]][my+dy[j]]=mt;
            }

        }
    }
}

int bfs(void)
{
    PandT origin = {0,0,0};
    PandT Npos;
    que.push(origin);
    if(Map[0][0]==0) return -1;
    while (que.size())
    {
        PandT pos=que.front();que.pop();
        printf("%d %d\n",pos.x,pos.y);
        if(Map[pos.x][pos.y]==INF_TINE)//fine safe place
        {
            return pos.t;
            break;
        }
        else
        {
            Map[pos.x][pos.y]=-1;//avoid return to this point;
        }
        for(int i=0;i<4;i++)
        {
            if((pos.x+dx[i]<MAX_XY)&&(pos.x+dx[i]>=0)&&(pos.y+dy[i]<MAX_XY)&&(pos.y+dy[i]>=0)) //inside the map
            {
                if((Map[pos.x+dx[i]][pos.y+dy[i]]>pos.t+1))
                {
                    Npos.x=pos.x+dx[i];Npos.y=pos.y+dy[i];Npos.t=pos.t+1;
                    que.push(Npos);
                }
            }
        }
    }
    return -1;
}

int main()
{
    ReadMap();
    printf("%d\n",bfs());

    return 0;
}
