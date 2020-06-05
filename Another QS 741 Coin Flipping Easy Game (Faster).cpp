#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
int solve(vector<int> A[],int V[],int col,int len,int S[],int r)
{
    //A is data, V is "flipped or not in that col", col is how many col, len is how many number is filled in V, S is summation, r is row
    if(len <col) //If V is not full-filled
    {
        int ans;
        V[len] = 0; //Add 0 at the back of V
        len++;
        ans = solve(A,V,col,len,S,r); //Send to deeper level
        V[len-1] = 1; //Replace 0 with 1
        ans = max(ans,solve(A,V,col,len,S,r)); //Send to deeper level
        return ans;
    }
    else //If V is filled.
    {
        int ST[r+5];
        for(int i=0;i<r;i++)
        {
            ST[i] = S[i]; //I don't want to change original sum value, so create copy of it
        }
        for(int i=0;i<col;i++)
        {
            for(int j=0;j<r;j++)
            {
                ST[j] += V[i] * (1-2*A[j][i]); //If V[i]=1, flip that col. Row j will affect by -1 (1->0) or +1 (0->1)
            }
        }
        int allsum = 0; //Keep sum of whole rectangle.
        for(int i=0;i<r;i++)
        {
            if(ST[i]*2 < col)
                ST[i] = col - ST[i]; //If ST[i] *2 < col --> Head less than tail --> Flip it
            allsum+=ST[i];
        }
        return allsum;
    }
}
main()
{
    int r,c; //Row, col
    string T; //Temp string for input
    int V[105]; //Use for marking which col will be flipped. 1 = flip, 0 = non-flip

    while(cin >>r>>c)
    {
        int S[r+5]; //Keep summation of each row
        vector<int> A[r+5]; //Keep the data.
        for(int i=0;i<r;i++)
        {
            cin >> T;
            S[i] = 0;
            for(int j=0;j<c;j++)
            {
                A[i].push_back(T[j]-'0'); //Input data
                S[i] +=A[i][j]; //Sum up to each row
            }
        }
        int ans = solve(A,V,c,0,S,r);
        printf("%d\n",ans);

    }
}
