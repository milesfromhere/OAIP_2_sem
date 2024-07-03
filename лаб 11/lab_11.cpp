#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        }
        else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

    int countRightLeaves(TreeNode* node) {
        if (node == nullptr)
            return 0;

        if (node->right == nullptr && node->left == nullptr)
            return 1;

        return countRightLeaves(node->left) + countRightLeaves(node->right);
    }

    void printCountRightLeaves() {
        int count = countRightLeaves(root);
        cout << "Количество правых листьев: " << count << endl;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    BinarySearchTree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(8);
    tree.insert(12);
    tree.insert(18);

    tree.printCountRightLeaves();

    return 0;
}
