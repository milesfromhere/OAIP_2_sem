#include <iostream>
#include <queue>
#include <vector>
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

    void printLevelSums() {
        vector<int> levelSums;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            int sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();
                sum += current->data;
                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }
            levelSums.push_back(sum);
            level++;
        }

        cout << "Суммы значений вершин для каждого уровня дерева:" << endl;
        for (int i = 0; i < levelSums.size(); i++) {
            cout << "Уровень " << i << ": " << levelSums[i] << endl;
        }
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

    tree.printLevelSums();

    return 0;
}
