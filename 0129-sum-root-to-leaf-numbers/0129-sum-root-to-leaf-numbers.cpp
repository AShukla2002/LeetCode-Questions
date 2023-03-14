class Solution {
    int total=0;
    void dfs(TreeNode* node,int sum){
        if(node!=nullptr) sum=sum*10+node->val;
        if(node!=nullptr&&node->left==nullptr&&node->right==nullptr){
            cout<<sum<<" ";
            total+=sum;
            return;
        }
        if(node==nullptr) return;
        dfs(node->left,sum);
        dfs(node->right,sum);
    }
public:
    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        return total;
    }
};