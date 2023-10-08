#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node *buildBinaryTree()
{
    int value;

    cin >> value;

    Node *root = new Node(value);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        int leftValue, rightValue;

        cin >> leftValue;
        if (leftValue != -1)
        {
            current->left = new Node(leftValue);
            q.push(current->left);
        }

        cin >> rightValue;
        if (rightValue != -1)
        {
            current->right = new Node(rightValue);
            q.push(current->right);
        }
    }

    return root;
}

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != nullptr)
        {
            q.push(current->left);
        }

        if (current->right != nullptr)
        {
            q.push(current->right);
        }
    }

    cout << endl;
}
void inOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}


int main()
{
    Node *root = buildBinaryTree();
    //levelOrderTraversal(root);
    //1 2 3 4 5 6 7 
    inOrderTraversal(root);
    //4 2 1 3 7 6 5 

    return 0;
}

// input
//1 2 3 4 -1 -1 5 -1 -1 6-1 7 -1 -1
//1 2 3 4 5 6 7 