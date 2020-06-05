#include<iostream>
#include<stack>
#include<queue>
#include<map>
using namespace std;
main()
{
    int t,n,val;
    int Fpoint;
    int pointer;
    int m;
    cin >> t;
    bool impos;
    while(t--)
    {
        cin >> n;
        int F[n+5];
        for(int i=0;i<n;i++)
        {
            cin >> F[i];
        }
        cin >> m;
        map <int,bool> M;
        while(m--)
        {
            impos = false;
            M.clear();
            Fpoint = n-1;
            pointer = 0;
            stack<int> S;
            int V[n+5];
            for(int i=0;i<n;i++)
            {
                cin >> V[i];
                M[V[i]] = false;
            }
            while(pointer !=n)
            {
                if(F[Fpoint] != V[pointer])
                {
                    S.push(F[Fpoint]);
                    M[F[Fpoint]] = true;
                }
                else
                {
                    pointer++;
                    while(!S.empty() && V[pointer] == S.top())
                    {
                        pointer++;
                        S.pop();
                    }
                    if(!S.empty() && M[V[pointer]])
                    {
                        cout << "Impossible\n";
                        impos = true;
                        break;
                    }
                }
                Fpoint--;
            }
            if(pointer == n && !impos)
                cout << "Aye\n";
        }

    }
}
