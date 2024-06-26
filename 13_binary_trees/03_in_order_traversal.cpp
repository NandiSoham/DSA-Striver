
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void findInorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    findInorder(root->left, ans);
    ans.push_back(root->val);
    findInorder(root->right, ans);
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    findInorder(root, ans);
    return ans;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result = inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}