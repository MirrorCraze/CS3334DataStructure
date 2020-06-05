#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include<utility>
using namespace std;
#define pid pair<int,double>
pid findweight(int **V,int left,int right,int top,int bot)
{
    if(left==right && top == bot)
        return make_pair(1,(double)V[top][left]);
    else
    {
        int midx = (left+right)/2;
        int midy = (top+bot)/2;
        pid topleft = findweight(V,left,midx,top,midy);
        pid topright = findweight(V,midx+1,right,top,midy);
        pid botleft = findweight(V,midx+1,right,midy+1,bot);
        pid botright = findweight(V,left,midx,midy+1,bot);
        double weight = topleft.second + topright.second + botleft.second +botright.second;
        if(weight == 0 || weight == 4)
            return make_pair(1,weight/4);
        else return make_pair(topleft.first + botleft.first+botright.first+topright.first + 1,weight/4);
    }
}
using namespace std;
main()
{
    int n;
    int **V;
    V = new int*[1025];
    for(int i=0;i<1024;i++)
        V[i] = new int[1024];
    string S;
    while(cin >>n)
    {
        for(int i=0;i<pow(2,n);i++)
        {
            cin >> S;
            for(int j=0;j<pow(2,n);j++)
                V[i][j] = S[j]-'0';
        }
        pid weight = findweight(V,0,pow(2,n)-1,0,pow(2,n)-1);
        cout << weight.first << endl;
    }
}
