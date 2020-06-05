#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include<utility>
using namespace std;
#define pid pair<int,double>
class node{
public:
    double weight;
    node* parent;
    node(int val)
    {
        this->weight = (double)val;
        this->parent = NULL;
    }
    double changeval()
    {
        this->weight = 1-this->weight;
        return this->weight;
    }
};
node* construct_tree(node* **V, int left,int right,int top,int bot)
{
    node* root = new node(0);
    node* topleft = new node(0);
    node* topright = new node(0);
    node* botleft = new node(0);
    node* botright = new node(0);
    if(left == right-1 && top == bot-1)
    {
        topleft = V[top][left];
        topright = V[top][right];
        botleft = V[bot][left];
        botright = V[bot][right];
    }
    else
    {
        int midx = (left+right)/2;
        int midy = (top+bot)/2;
        topleft = construct_tree(V,left,midx,top,midy);
        topright = construct_tree(V,midx+1,right,top,midy);
        botleft = construct_tree(V,left,midx,midy+1,bot);
        botright = construct_tree(V,midx+1,right,midy+1,bot);
    }
    topright->parent = root;
    topleft->parent = root;
    botleft->parent = root;
    botright->parent = root;
    root->weight = (topleft->weight + topright->weight + botleft->weight + botright->weight)/4;
    return root;
}
void checkchange(node* &n, int &counter,double now, double prev,int level)
{
    if(level == 0)
        return;
    node* par = n->parent;
    if(par == NULL)
        return;
    int weightprev= par->weight;
    //cout << "Init weight is " << par->weight << endl;
    if(par->weight == 1 || par->weight ==0)
        counter +=4;
    par->weight +=(now-prev)/4;
    //cout << "Weight changed to " << par->weight << endl;
    if(par->weight == 1 || par->weight == 0)
        counter -=4;
    checkchange(par,counter,par->weight,weightprev,level-1);
}
pid findweight(node* **V,int left,int right,int top,int bot)
{
    if(left==right && top == bot)
        return make_pair(1,V[top][left]->weight);
    else
    {
        int midx = (left+right)/2;
        int midy = (top+bot)/2;
        pid topleft = findweight(V,left,midx,top,midy);
        pid topright = findweight(V,midx+1,right,top,midy);
        pid botleft = findweight(V,midx+1,right,midy+1,bot);
        pid botright = findweight(V,left,midx,midy+1,bot);
        double weight = topleft.second + topright.second + botleft.second +botright.second;
        //cout << "WEIGHT" << weight << endl;
        if(weight == 0 || weight == 4)
            return make_pair(1,weight/4);
        else
        {
            //cout << "LR" << left << right << "TB" << top << bot<<"Send " <<topleft.first + botleft.first+botright.first+topright.first<< endl;
            return make_pair(topleft.first + botleft.first+botright.first+topright.first + 1,weight/4);
        }
    }
}
main()
{
    int n;
    string S;
    node* temp = new node(0);
    int init_counter = 0;
    node* par = new node(0);
    int t;
    cin >> t;
    int q,r,c;
    node* **V;
    V = new node* *[(int)pow(2,10)+5];
    for(int i=0;i<pow(2,10);i++)
        V[i] = new node*[(int)pow(2,10)+5];
    node* root;
    while(t--)
    {
        cin >> n;
        for(int i=0;i<pow(2,n);i++)
        {
            cin >> S;
            for(int j=0;j<pow(2,n);j++)
            {
                temp = new node(S[j]-'0');
                V[i][j] = (temp);
            }
        }
        init_counter = findweight(V,0,(int)pow(2,n)-1,0,(int)pow(2,n)-1).first;
        root = new node(0);
        if(n == 0)
            root = V[0][0];
        else root = construct_tree(V,0,(int)pow(2,n)-1,0,(int)pow(2,n)-1);
        cin >> q;
        while(q--)
        {
            cin >> r >> c;
            double down = V[r-1][c-1]->changeval();
            checkchange(V[r-1][c-1],init_counter,down,1-down,n);
            cout << init_counter;
            cout << endl;
        }

    }
}
