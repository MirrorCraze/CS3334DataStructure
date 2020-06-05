#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int val;
    int index;
    node(int v,int index)
    {
        val = v;
        this->index = index;
    }
};
main()
{
    int t,n,k,temp,maxval,maxin;
    cin >> t;
    while(t--)
    {
        queue<node> Q;
        cin >> n >> k;
        queue<node> TQ;
        for(int i=1;i<=n;i++)
        {
            cin >> temp;
            node tempnode(temp,i);
            Q.push(tempnode);
        }
        while(Q.size() > 1)
        {
            maxval = -1000000;
            maxin = 0;
            for(int i=0;i<k&&!Q.empty();i++)
            {
                TQ.push(Q.front());
                if(maxval < Q.front().val)
                {

                    maxval = Q.front().val;
                    maxin = Q.front().index;
                    //cout << "MV" << maxval;
                }
                Q.pop();
            }
            cout << maxin << " ";

            while(!TQ.empty())
            {
                if(maxin != TQ.front().index)
                {
                    node temp(TQ.front().val-1,TQ.front().index);
                    Q.push(temp);
                }
                TQ.pop();
            }
            //cout << "Q left " << Q.size();
        }

        cout <<Q.front().index<< endl;
    }
}
