#include<stdio.h>
main()
{
    int n;
    int A[1005];
    A[0] = 0;
    A[1] = 1;
    for(int i=2;i<1002;i++)
        A[i] = (A[i-1] + A[i-2])%10;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",A[n]);
    }
}
