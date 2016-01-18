#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(const pair<int,int> a,const pair<int,int> b)
{
    return a.first < b.first;
}



int main()
{
    vector< pair<int,int> > teams;
    int N,T,tmpb,tmpe,endtime,num,begintime,flag;

    scanf("%d%d",&N,&T);
    for(int i=0;i<N;i++){
        scanf("%d%d",&tmpb,&tmpe);
        teams.push_back(make_pair(tmpb,tmpe));
    }
    sort(teams.begin(),teams.end(),compare);

    endtime = 0;
    begintime = 0;
    num = 1;
    flag = 1;
    for(int i=0;i<N;i++){
        if(teams[i].first<=begintime+1){
            if(teams[i].second>endtime) endtime = teams[i].second;
            if(endtime == T) break;
        }
        else if(teams[i].first<=endtime+1){ //teams[i].frist > begintime+1
            begintime = endtime;
            num++;
            if(teams[i].second>endtime) endtime = teams[i].second;
            if(endtime == T) break;
        }
        else if(teams[i].first>endtime+1){
            flag = 0;
            break;
        }
    }
    if(endtime < T) flag = 0;
    if(flag) printf("%d\n",num);
    else printf("-1\n");
    return 0;
}

