#include<iostream>
#include<string>
#include<map>
#include<cstdio>
#define MAX_LEN 400005
using namespace std;
main()
{
    string S;
    map <string, int> M;
    char A[MAX_LEN];
    while(scanf("%s",A)!=EOF)
    {
        S = A;
        if(M.count(S)!=0)
            M[S]++;
        else M[S] = 1;
    }
    for (map <string,int>::iterator i = M.begin();i!=M.end();i++)
    {
        cout << i->first <<" " << i->second << '\n';
    }
}
