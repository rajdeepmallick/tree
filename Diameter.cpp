#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child and a pointer to right child  */

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

/* Function to get diameter of a binary tree */

int diameter(struct Node * tree);

/* Driver program to test size function*/

int main()
{
  int t;
  scanf("%d", &t);
  
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
            parent = new Node(n1);
            m[n1] = parent;
            if (root == NULL)
                root = parent;
        }
        else
            parent = m[n1];
            child = new Node(n2);
        if (lr == 'L')
            parent->left = child;
        else
            parent->right = child;
            m[n2]  = child;
     }
     cout << diameter(root) << endl;
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* Tree node structure  used in the program
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
/* Computes the diameter of binary tree with given root.  */



//my code

int height(Node *node,int& res){
    if(node==NULL)
        return 0;
    int lh=height(node->left,res);    
    int rh=height(node->right,res); 
    res=max(res,(lh+rh+1));
    return (max(lh,rh)+1);
}
/*
produce same output
int diameter(Node* node){
    if(node==NULL)
        return 0;
    int ans=INT_MIN;
    int ht=height(node,ans);
    return ans;
}
*/
int diameter(Node* node){
    if(node==NULL)
        return 0;
    int res=INT_MIN;
    int ht=height(node,res);
    return res;
}
