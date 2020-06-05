#include<iostream>
using namespace std;
main()
{
    int t;
    cin >> t;
    int n;
    int prev;
    int cur;
    int up,down;
    for(int i=1;i<=t;i++)
    {
        up = 0;
        down = 0;
        cin >> n;
        cin >> prev;
        n--;
        while(n--)
        {
            cin >> cur;
            if(cur > prev)
                up++;
            else if(cur < prev)
                down++;
            prev = cur;
        }
        cout << "Case " << i << ": " << up <<" " << down<<endl;
    }
}
