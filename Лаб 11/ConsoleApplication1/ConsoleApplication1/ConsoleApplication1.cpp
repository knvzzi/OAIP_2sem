#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int countAllNodesToLeftOfRoot(TreeNode* root) {
    if (!root || (!root->left && !root->right)) {
        // если корень дерева не существует или является листом,
        // то нет элементов слева от корня
        return 0;
    }

    int count = 0;
    std::queue<TreeNode*> q;
    q.push(root);
    bool found = false;

    while (!q.empty() && !found) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur->left) {
                if (!found) {
                    // если нашли первый элемент слева от корня,
                    // то все последующие элементы также будут находиться слева
                    found = true;
                }
                count++;
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }
        }
    }

    return count;
}

int main() {
    // создаем дерево
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // выводим количество всех элементов слева от корня
    std::cout << countAllNodesToLeftOfRoot(root); // выводит 3

}
