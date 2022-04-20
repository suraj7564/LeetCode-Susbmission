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
class BSTIterator {
public:
    stack<TreeNode*> s1; 
    BSTIterator(TreeNode* root) {
        findLeft(root);
    }
    
    int next() {
        auto top = s1.top();
        s1.pop();
        if(top->right){
            findLeft(top->right);
        }
        return top->val;
    }
    
    bool hasNext() {
        return !s1.empty();
    }
    
    void findLeft(TreeNode* root){
        TreeNode *temp = root;
        while(temp){
            s1.push(temp);
            temp = temp->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */