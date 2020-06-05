#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
int solve(vector<int> A[],int V[],int maxi,int len,int S[],int r)
{
    if(len <maxi)
    {
        int ans;
        V[len] = 0;
        len++;
        ans = solve(A,V,maxi,len,S,r);
        V[len-1] = 1;
        ans = max(ans,solve(A,V,maxi,len,S,r));
        return ans;
    }
    else
    {
        int Vsize = maxi;
        int ST[r+5];
        for(int i=0;i<r;i++)
        {
            ST[i] = S[i];
            printf("%d ",ST[i]);
        }
        printf("\n");
        for(int i=0;i<Vsize;i++)
        {
            for(int j=0;j<r;j++)
            {
                if(V[i])
                    A[j][i] = 1-A[j][i];
            }
        }
        int allsum = 0;
        int rowsum = 0;
        for(int i=0;i<r;i++)
        {
            rowsum = 0;
            for(int j=0;j<maxi;j++)
                rowsum +=A[i][j];
            if(rowsum*2 < maxi)
                rowsum = maxi-rowsum;
            allsum+=rowsum;
        }
        for(int i=0;i<Vsize;i++)
        {
            for(int j=0;j<r;j++)
            {
                if(V[i])
                    A[j][i] = 1-A[j][i];
            }
        }
        return allsum;
    }
}
main()
{
    int r,w;
    string T;
    int V[105];

    while(cin >>r>>w)
    {
        int S[r+5];
        vector<int> A[r+5];
        for(int i=0;i<r;i++)
        {
            cin >> T;
            S[i] = 0;
            for(int j=0;j<w;j++)
            {
                A[i].push_back(T[j]-'0');
                S[i] +=A[i][j];
            }
        }
        int ans = solve(A,V,w,0,S,r);
        printf("%d\n",ans);

    }
}
