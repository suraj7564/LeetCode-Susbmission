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
    TreeNode* find(vector<int>& arr,int start,int end){
        if (start > end)
        return NULL;

        /* Get the middle element and make it root */
        int mid = (start + end)/2;
        TreeNode *root =new TreeNode(arr[mid]);

        /* Recursively construct the left subtree
        and make it left child of root */
        root->left = find(arr, start,mid - 1);

        /* Recursively construct the right subtree
        and make it right child of root */
        root->right =find(arr, mid + 1, end);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& arr) {
        return find(arr,0,arr.size()-1);
    }
};