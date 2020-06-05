#include<iostream>
#include<queue>
using namespace std;
class customer{
public:
    int aTime;
    int pTime;
    int qMax;
    customer()
    {
        this->aTime = 0;
        this->pTime = 0;
        this->qMax = 0;
    }
    customer(int aTime, int pTime, int qMax)
    {
        this->aTime = aTime;
        this->pTime = pTime;
        this->qMax = qMax;
    }
};
long long maxi(long long a,long long b)
{
    return a>b? a:b;
}
main()
{
    freopen("in","r",stdin);
    freopen("out.txt","w+",stdout);
    int n;
    int aTime;
    int pTime;
    int qMax;
    queue<customer> Q;
    while(cin >> n)
    {
        customer C[n+5];
        for(int i=0;i<n;i++)
        {
            cin >> aTime >> pTime >> qMax;
            customer temp(aTime,pTime,qMax);
            C[i] = temp;
        }
        int counter = 0;
        long long time = 0;
        while(counter <n-1)
        {
            if(Q.empty()) //If queue is empty : all customer before get served.
            {
                Q.push(C[counter]);
                time = C[counter].aTime;
                //cout << "push" << counter<<endl;
                counter++;

            }
            customer serving = Q.front();
            while(time + serving.pTime > C[counter].aTime && counter != n-1)
            {
                if(Q.size() <= C[counter].qMax) //If can wait, then push in.
                {
                    Q.push(C[counter]);
                    //cout << "push" << counter<<endl;
                }
                //If can't wait, then just move.
                counter++;
            }
            //cout << "counter" << counter<<endl;
            if(time+serving.pTime <= C[counter].aTime) //If the arrival time of next guy is more than time rn + process time of "serving", then change time and let this guy got served.
            {
                time +=serving.pTime;
                Q.pop();
            }
            if(Q.size() <=C[counter].qMax && counter == n-1) //If last guy can queue
            {
                while(!Q.empty())
                {
                    time += Q.front().pTime;
                    Q.pop();
                }
                cout << maxi(time,C[counter].aTime)<< endl; //It's whether the guy comes after the queue is empty, or the guy wait in queue.
            }
            else if(counter == n-1) //Last guy can't queue
            {
                cout << -1 << endl;
            }
        }
        if(n==1) // 1 person. definitely got served when he/she arrived.
            cout << C[0].aTime << endl;
        while(!Q.empty())
            Q.pop();
    }
}
