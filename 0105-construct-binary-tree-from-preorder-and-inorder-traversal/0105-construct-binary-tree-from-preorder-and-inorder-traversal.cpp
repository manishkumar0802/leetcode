class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap;

        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(
            preorder, 0, preorder.size() - 1,
            inorder, 0, inorder.size() - 1, inMap
        );

        return root;
    }

    TreeNode* buildTree(
        vector<int>& preorder, int preStart, int preEnd,
        vector<int>& inorder, int inStart, int inEnd,
        map<int, int>& inMap
    ) {
        // Base case
        if(preStart > preEnd || inStart > inEnd)
            return NULL;

        // Create root
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Find root position in inorder
        int inRoot = inMap[root->val];

        // Count nodes in left subtree
        int numsLeft = inRoot - inStart;

        // Build left subtree
        root->left = buildTree(
            preorder, preStart + 1, preStart + numsLeft,
            inorder, inStart, inRoot - 1, inMap
        );

        // Build right subtree
        root->right = buildTree(
            preorder, preStart + numsLeft + 1, preEnd,
            inorder, inRoot + 1, inEnd, inMap
        );

        return root;
    }
};