/* 
 * Problem 101:	Symmetric Tree
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 *
 * For example, this binary tree is symmetric:

	    1
	   / \
	  2   2
	 / \ / \
	3  4 4  3
 * But the following is not:
	    1
	   / \
	  2   2
	   \   \
	   3    3
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.s
 */

/* 
 * ���Ļ���������
 * 1��ʹ�õݹ鷽��������Ҷ�ӽڵ���δ���Ȼ��ݹ�õ��𰸣�
 * 2��ʹ�õ���������Ŀǰ��δд���д�������ӣ�
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return is_same(root->left, root->right);
    }
    bool is_same(TreeNode *cur_left, TreeNode *cur_right) {
        if (cur_left == NULL && cur_right == NULL)
            return true;
        if (cur_left == NULL || cur_right == NULL)
            return false;
        if (cur_left->val != cur_right->val) {
            return false;
        } else {
            return is_same(cur_left->left, cur_right->right) && 
                    is_same(cur_left->right, cur_right->left);
        }
    }
};

/*
 * �Ľ�������
 * �ʼ�����õ�ָ�룬��������n��λ�ã������Ϳ�������һ��ָ��Ϳ���ɾ��������n���ڵ㡣
 */
