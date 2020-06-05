#include<iostream>
#include<vector>
using namespace std;
main()
{
    int n;
    char cmd;
    int k;
    int temp;
    vector <int> V;
    int pos;
    long long sum = 0;
    while(cin >> n)
    {
        sum = 0;
        V.clear();
        while(n--)
        {
            cin >> cmd;
            switch(cmd)
            {
            case 'a': //insert k
                cin >> k;
                sum +=k;
                V.push_back(k);
                pos = V.size()-1;
                while(pos != 0 && V[pos] > V[(pos-1)/2])
                {
                    temp  = V[pos];
                    V[pos] = V[(pos-1)/2];
                    pos = (pos-1)/2;
                    V[pos] = temp;
                }
                break;
            case 'p': //pop
                sum -= V[0];
                V[0] = V[V.size()-1];
                V.pop_back();
                pos = 0;
                while(pos*2+1 <V.size() && (V[pos*2+1] > V[pos] || (pos*2+2 < V.size() && V[pos*2+2] > V[pos])))
                {
                    temp = V[pos];
                    if(pos*2+2 == V.size() || V[pos*2+1] > V[pos*2+2])
                    {
                        V[pos] = V[(pos*2+1)];
                        pos = (pos*2+1);
                    }
                    else
                    {
                        V[pos] = V[(pos*2+2)];
                        pos = (pos*2+2);
                    }
                    V[pos] = temp;
                }
                break;
            case 'r': //print sum
                cout << sum << endl;
                break;
            }
        }

    }
}
