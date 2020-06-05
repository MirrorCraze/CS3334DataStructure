#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class node{
public:

    node* parent;
    node* left;
    node* right;
    int weight;
    node(int weight)
    {
        parent = NULL;
        left = NULL;
        right = NULL;
        this-> weight = weight;
    }
};
class minNode{
    public:
    bool operator()(node* &a, node* &b)
    {
        return a->weight > b->weight;
    }
};
main()
{
    int n;
    priority_queue <node*,vector<node*>,minNode> PQ;
    int temp;
    queue <node*> Q;
    while(cin >> n)
    {
        while(!Q.empty())
            Q.pop();
        while(!PQ.empty())
            PQ.pop();
        for(int i=0;i<n;i++)
        {
            cin >> temp;
            node* tempNode = new node(temp);
            PQ.push(tempNode);
        }
        while(PQ.size() > 1)
        {
            node* lessed = PQ.top();
            PQ.pop();
            node* greated = PQ.top();
            PQ.pop();
            node* root  = new node(lessed->weight + greated->weight);
            root->left = lessed;
            root->right = greated;
            lessed->parent = root;
            greated->parent = root;
            PQ.push(root);
            //cout << "less " << lessed->weight << "more " << greated->weight << "New " << root->weight << endl;
        }
        int depth = 0;
        int counter;
        long long weightAll = 0;
        Q.push(PQ.top());
        PQ.pop();
        while(!Q.empty())
        {
            counter = Q.size();
            while(counter--)
            {
                node* n = Q.front();
                Q.pop();
                //cout << "From " << n-> weight;
                if(n->left == NULL && n->right == NULL)
                {
                    weightAll += depth * n->weight;
                    //cout << "Weight" <<n->weight << "Depth" << depth<<endl;
                }
                if(n->left != NULL)
                {
                    Q.push(n->left);
                    //cout << "Left " << n->left->weight;
                }
                if(n->right != NULL )
                {
                    Q.push(n->right);
                    //cout<< "Right " << n->right->weight;
                }
                //cout << endl;
            }
            depth++;
        }
        cout << weightAll << endl;
    }
}
