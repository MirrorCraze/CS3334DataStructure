#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector <int> V;
void weightXOR(string S,int left,int right,int len)
{
    if(left == right-1)
    {
        V.push_back(1);
        return;
    }
    int weight = 1;
    int counter = 1;
    int rightptr = left;
    while(counter > 0)
    {
        rightptr++;
        if(S[rightptr] == '(')
        {
            counter++;
            weight++;
        }
        else if(S[rightptr] == ')')
            counter--;
        //cout << "rptr" << rightptr << "cnt" << counter << endl;
    }

    V.push_back(weight);
    //cout << "fin" << left << " "<< rightptr-1<<endl;
    if(left+1 < rightptr-1)
        weightXOR(S,left+1,rightptr-1,len);
    if(rightptr+1 < right)
        weightXOR(S,rightptr+1,right,len);
}
main()
{
    string S;
    while(getline(cin,S))
    {
        int ans = 0;
        V.clear();
        int temp;
        //cout <<S.length();
        weightXOR(S,0,S.length()-1,S.length());
        for(int i=0;i<V.size();i++)
        {
            //cout << i << " " << V[i] << endl;
            ans = ans^V[i];
        }
        cout << ans << endl;
    }
}
