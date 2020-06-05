#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
class node{
public:
    double weight;
    node* topleft;
    node* topright;
    node* botleft;
    node* botright;
    node(int val)
    {
        this->weight = (double)val;
        this->botleft = NULL;
        this->botright =NULL;
        this->topleft = NULL;
        this->topright = NULL;
    }
};
node* root;
int midx;
int midy;
node * construct_tree(node***V, int left,int right,int top,int bot)
{
    root = new node(0);
    if(left == right-1 && top == bot-1)
    {
        root->topleft = V[top][left];
        root->topright = V[top][right];
        root->botleft = V[bot][left];
        root->botright = V[bot][right];
    }
    else
    {
        midx = (left+right)/2;
        midy = (top+bot)/2;
        root->topleft = construct_tree(V,left,midx,top,midy);
        root->topright = construct_tree(V,midx+1,right,top,midy);
        root->botleft = construct_tree(V,left,midx,midy+1,bot);
        root->botright = construct_tree(V,midx+1,right,midy+1,bot);

    }
    root->weight = (root->topleft->weight + root->topright->weight + root->botleft->weight + root->botright->weight)/4;
    return root;
}
main()
{
    int n;
    string S;
    node* temp;
    node* root;
    queue<node*> Q;
    int counter;
    node* par;
    //vector < vector<node*> > V((int)pow(2,10));
    node* **V;
    V = new node**[1025];
    for(int i=0;i<1024;i++)
        V[i] = new node*[1024];
    while(cin >> n)
    {
        for(int i=0;i<pow(2,n);i++)
        {
            cin >> S;
            for(int j=0;j<pow(2,n);j++)
            {
                temp = new node(S[j]-'0');
                V[i][j] = (temp);

            }
        }

        root = new node(0);
        root = construct_tree(V,0,(int)pow(2,n)-1,0,(int)pow(2,n)-1);
        Q.push(root);
        counter = 0;
        while(!Q.empty())
        {
            counter++;
            par = Q.front();
            //cout<<S.size()<<endl;
            if(par->weight !=1 && par->weight !=0 && par->topleft !=NULL)
            {
                Q.push(par->topleft);
                //cout << "push" <<(par->topleft->weight)<<endl;
                Q.push(par->botleft);
                //cout << "push" <<(par->botleft->weight)<<endl;
                Q.push(par->topright);
                //cout << "push" <<(par->topright->weight)<<endl;
                Q.push(par->botright);
                //cout << "push" <<(par->botright->weight)<<endl;
            }
            Q.pop();
        }
        cout << counter << endl;
    }
}
