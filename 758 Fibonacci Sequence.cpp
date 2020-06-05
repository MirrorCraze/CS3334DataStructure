#include<iostream>
#include<queue>
#include<cmath>

using namespace std;
#define bucket_size 1024
main()
{
    int t;
    long long a;
    cin >> t;
    long long n,q;
    long long counter;
    int Qsize[bucket_size+2];
    long long ans;
    long long maxi;
    int mask = bucket_size-1;
    int *Q; //Bucket
    Q = new int[5000000];
    int *QC;
    QC = new int[5000000];
    long long shift;
    int slot;
    while(t--)
    {

        shift = 0;
        ans = 0;
        maxi = 0;
        cin >> n >>q;
        //Fibo sequence

        Q[0] = 1;
        Q[1] = 1;
        for(int i=2;i<n;i++)
        {
            Q[i] = (Q[i-1] + Q[i-2])%q;
            if(Q[i]> maxi)
                maxi = Q[i];
        }

        //radix sort
        counter = 0;

        while(maxi)
        {
            counter++;
            //cout << maxi<<endl;
            for(int i=0;i<bucket_size;i++)
                Qsize[i] = 0;
            for(int i=0;i<n;i++)
            {
                slot = ((Q[i]>>shift)&mask);
                Qsize[slot]++;
                QC[i] = Q[i];
                /*if(slot == 1)
                    cout << Q[i]<<endl;*/
            }
            for(int i=bucket_size-2;i>=0;i--)
            {
                Qsize[i] +=Qsize[i+1];
            }
            for(int i=0;i<n;i++)
            {
                slot = ((QC[i]>>shift)&mask);

                Q[n-Qsize[slot]] = QC[i];
                Qsize[slot]--;
            }
            shift+=10;
            maxi = maxi >> 10;
        }
        //summation
        counter = 1;
        maxi = 0;
        for(int i=0;i<n;i++)
        {
            ans = (ans +  Q[i]*(counter%q))%q;
            counter++;
        }
        cout << ans << endl;
    }
}
