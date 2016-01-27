//Date : 2016-1-20
//POJ 2991
//Segment Tree
#include <cstdio>
#include <algorithm>
#include <math.h>

/*
const int MAX_N = 1<< 17;
int n,dat[MAX_N*2 -1];

void init(int n)
{
    int n2 = 1;
    while (n2 < n) n2*=2;

    for(int i=0;i<n2;i++) dat[i] = MAX_N;
}

void update(int k,int a)
{
    int m = k+n-1
    dat[m] = a;
    while (m > 0){
        m = (m-1)/2;
        dat[m] = min(dat[2*m+1],dat[2*m+2];)
    }
}

int query(int a,int b,int k,int l,int r)
{
   if((l > b) || (r < a)) return MAX_N;
   else if( (l >= a) && (r <= b)) return dat[k];
   else{
        int v1 = query(a,b,2*k+1,l,(l+r)/2);
        int v2 = query(a,b,2*k+2,(l+r)/2,r);
        return min(v1,v2);
   }

}*/

#define MAX_C 10000

int main()
{
    int N,C;
    int A[MAX_C],L[MAX_C];

    scanf("%d%d",&N,&C);
    for(int i=0;i<N;i++) {
        scanf("%d",&L[i]);
        if(i<N-1) A[i] = 180;
    }
    for(int i=0;i<C;i++){
        int j;
        scanf("%d",&j);
        scanf(%"%d",&A[j]);
    }

    for(int i=0;i<)
}
