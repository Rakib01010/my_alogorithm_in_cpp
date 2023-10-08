#include <iostream>
#include <queue>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void levelOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        std::cout << current->data << " ";

        if (current->left != NUll) {
            q.push(current->left);
        }

        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}

int main() {
    // Create a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    std::cout << "Level-order traversal of the binary tree: ";
    levelOrderTraversal(root);
    std::cout << std::endl;

    return 0;
}