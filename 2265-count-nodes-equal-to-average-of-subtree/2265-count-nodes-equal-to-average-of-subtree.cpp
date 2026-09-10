class Solution {
    int ginti = 0;

    pair<int,int> khoj(TreeNode* node) {
        if (!node) return {0, 0};

        auto [baaya, baayiGinti] = khoj(node->left);
        auto [daaya, daayiGinti] = khoj(node->right);

        int yog = baaya + daaya + node->val;
        int sankhya = baayiGinti + daayiGinti + 1;

        if (yog / sankhya == node->val)
            ginti++;

        return {yog, sankhya};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        khoj(root);
        return ginti;
    }
};