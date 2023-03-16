/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTreeHelper(vector<int>& ino, vector<int>& po, int inSt, int ien, int pSt, int pEn, unordered_map<int, int>& map) {
        if (inSt > ien || pSt > pEn)
            return nullptr;

        int rootValue = po[pEn];
        int rootIndex = map[rootValue];
        int LSbTreeSize = rootIndex - inSt;

        TreeNode* root = new TreeNode(rootValue);
        root->left = buildTreeHelper(ino, po, inSt, rootIndex - 1, pSt, pSt + LSbTreeSize - 1, map);
        root->right = buildTreeHelper(ino, po, rootIndex + 1, ien, pSt + LSbTreeSize, pEn - 1, map);

        return root;
    }
    TreeNode* buildTree(vector<int>& ino, vector<int>& po) {
        int n = ino.size();
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            map[ino[i]] = i;
        }

        return buildTreeHelper(ino, po, 0, n - 1, 0, n - 1, map);
    }
};