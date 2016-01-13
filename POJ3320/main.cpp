#include <cstdio>
#include <map>
#include <set>

#define MAX_P 1000000

using namespace std;

int main()
{
    int l,r,P,N,countN,minread;


    map<int,int> num;
    //map<int,int>::iterator I_it;
    set<int> all;

    scanf("%d",&P);
    int a[P];
    for(int i=0;i<P;i++)
    {
        scanf("%d",&a[i]);
        num[a[i]]=0;
        all.insert(a[i]);
    }

    N=all.size();
    minread=P;
    l=0;r=-1;countN=0;
    while(r+1<P)
    {
        while((countN < N) && (r+1<P))
        {
            if(num[a[++r]]++==0) countN++;

        }
        minread = min(minread,r-l+1);
        while((countN >= N))
        {
            minread = min(minread,r-l+1);
            num[a[l]]--;
            if(num[a[l++]]==0) countN--;
        }
    }

    printf("%d\n",minread);
    return 0;
}
