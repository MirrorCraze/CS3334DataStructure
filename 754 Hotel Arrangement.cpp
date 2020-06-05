#include<iostream>
#include<algorithm>
using namespace std;
int bsearch(int A[], int c,int len, int left, int right,int maxi)
{
    if(left > right)
        return maxi;
    int mid = (left + right) /2;
    //cout <<
    //cout << "MID" << mid << endl;
    int counter = 1;
    int recent = A[0];
    for(int i=0;i<len;i++)
    {
        if(A[i] - recent >= mid)
        {
            counter++;
            recent = A[i];
        }
    }
    if(counter >= c)
    {
        //cout << "Mid App : " << mid << endl;
        return bsearch(A,c,len,mid+1,right,mid);
    }
    else
    {
        //cout << "Mid Rej : " << mid << endl;
        return bsearch(A,c,len,left,mid-1,maxi);
    }
}
main()
{
    int t;
    cin >> t;
    int n;
    int c;
    while(t--)
    {
        cin >> n >> c;
        int A[n+5];
        for(int i=0;i<n;i++)
            cin >> A[i];
        sort(A,A+n);
        /*for(int i=0;i<n;i++)
            cout <<  A[i];*/
        int ans = bsearch(A,c,n,0,A[n-1]-A[0],-100);
        cout << ans << endl;
    }
}
