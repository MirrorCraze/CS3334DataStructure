#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include<utility>
using namespace std;
#define pid pair<int,double>
double ***V = new double** [11];
pid findweight(int left,int right,int top,int bot,int level)
{
    if((left==right && top == bot))
    {
        /*if(level!=0)
            cout << "SOMETHIG RONG";*/
        return make_pair(1,V[0][top][left]);
    }
    else
    {
        int midx = (left+right)/2;
        int midy = (top+bot)/2;
        pid topleft = findweight(left,midx,top,midy,level-1);
        pid topright = findweight(midx+1,right,top,midy,level-1);
        pid botleft = findweight(midx+1,right,midy+1,bot,level-1);
        pid botright = findweight(left,midx,midy+1,bot,level-1);
        //cout << topleft.second << "  " << topright.second << "  " << botleft.second << "  " << botright.second << "  " <<endl;
        double weight = topleft.second + topright.second + botleft.second +botright.second;
        weight = weight/4;
        if(weight < 0.00000000001)
            weight = 0;
        V[level][left/(int)pow(2,level)][bot/(int)pow(2,level)] = weight/4;
        if(weight == 0 || weight == 4)
            return make_pair(1,weight/4);
        else return make_pair(topleft.first + botleft.first+botright.first+topright.first + 1,weight/4);
    }
}
void changeweight(int x,int y,int level,int &amount,int bound, double old, double newd)
{
    if(level == bound)
        return;
    if((int)V[level+1][x/2][y/2] == V[level+1][x/2][y/2])
        amount +=4;
    double oldd = V[level+1][x/2][y/2];
    V[level+1][x/2][y/2] +=(newd-old)/4;
    if((int)V[level+1][x/2][y/2] == V[level+1][x/2][y/2])
        amount -=4;
    double newdd = V[level+1][x/2][y/2];
    changeweight(x/2,y/2,level+1,amount,bound,oldd,newdd);
}
using namespace std;
main()
{
    int n;
    string S;
    int t;
    cin >>t;
    int q,r,c;
    for(int i=0;i<=10;i++)
    {
        V[i] = new double*[(int)pow(2,10-i)];
        for(int j=0;j<pow(2,10-i);j++)
            V[i][j] = new double[(int)pow(2,10-i)];
    }
    int amount;
    while(t--)
    {
        cin >> n;
        for(int i=0;i<pow(2,n);i++)
        {
            cin >> S;
            for(int j=0;j<pow(2,n);j++)
                V[0][i][j] = S[j]-'0';
        }
        pid weight = findweight(0,pow(2,n)-1,0,pow(2,n)-1,n);
        /*cout << weight.first << endl;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<pow(2,n-i);j++)
            {
                for(int k=0;k<pow(2,n-i);k++)
                    cout << V[i][j][k] << " ";
                cout << endl;
            }
        }*/
        amount = weight.first;
        cin >> q;
        double old,newd;
        while(q--)
        {
            cin >> r >> c;
            old = V[0][r-1][c-1];
            V[0][r-1][c-1] = 1- V[0][r-1][c-1];
            newd = V[0][r-1][c-1];
            changeweight(r,c,0,amount,n,old,newd);
            cout << amount;
            cout << endl;
        }
    }
}
