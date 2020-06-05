#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
main()
{
    int n;
    scanf("%d",&n);
    string A;
    int Alen;
    int llen = 0;
    char max_char = 'a'-10;

    for(int i=0;i<n;i++)
    {
        vector <char> V;
        max_char = 'a'-10;
        cin >> A;
        Alen = A.length();
        for(int j=Alen-1;j>=0;j--)
        {
            if(max_char <= A[j])
            {
                V.insert(V.begin(),A[j]);
                max_char = A[j];
            }
        }
        for(int i = 0;i!=V.size();i++)
        {
            printf("%c",V[i]);
        }
        printf("\n");
    }
}
