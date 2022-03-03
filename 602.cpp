
#include <iostream>
#include <queue>

struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

    struct IndexNode
    {
        TreeNode* node;
        int idx;
        
        IndexNode(TreeNode* node = nullptr, int idx = 0) : node(node), idx(idx) {}
    };
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ret = 0;
        
        std::queue<IndexNode> nodeQueue;       
        nodeQueue.push(IndexNode(root, 1));
        
        int min_index_in_current_depth = 0;
        int max_index_in_current_depth = 0;
        
        while (!nodeQueue.empty())
        {
            auto num_of_nodes_in_current_depth = nodeQueue.size();
            min_index_in_current_depth = nodeQueue.front().idx;
            
            IndexNode ptr;
            while(num_of_nodes_in_current_depth--)
            {
                ptr = nodeQueue.front();
                nodeQueue.pop();
                
                auto current_index = ptr.idx - min_index_in_current_depth;
                if (ptr.node->left)
                {
                    nodeQueue.push(IndexNode(ptr.node->left, 2*current_index));
                }
                if (ptr.node->right)
                {
                    nodeQueue.push(IndexNode(ptr.node->right, 2*current_index+1));
                }
            }
            
            max_index_in_current_depth = ptr.idx;

            int candidate = max_index_in_current_depth - min_index_in_current_depth + 1;
            if (ret < candidate)
                ret = candidate;
        }
    
        return ret;
    }
};

int main()
{
    Solution solution;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(2);   

    int ret;
    ret = solution.widthOfBinaryTree(root);
    printf("%d\n", ret);
}