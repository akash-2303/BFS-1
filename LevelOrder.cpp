// Time Complexity: O(n)
// Space Complexity: O(n)
// Did this code successfully run on Leetcode : Yes

//Approach: 
//1. We will use a deque to store the nodes of the tree.
//2. We will push the root node into the deque.
//3. We will iterate through the deque and for each node, we will push its left and right children into the deque.
//4. We will keep track of the number of nodes at each level and store them in a vector.
//5. We will keep doing this until the deque is empty.
//6. We will return the vector of vectors.

class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> result; 
            if(root == nullptr){
                return result;
            }
            deque<TreeNode*> q;
            q.push_back(root);
    
            while(!q.empty()){
                vector<int> temp;
                int count = q.size();
                for(int i = 0; i < count; i++){
                    TreeNode* node = q.front();
                    q.pop_front();
                    temp.push_back(node -> val);
                    if(node -> left != nullptr){
                        q.push_back(node -> left);
                    }
                    if(node -> right != nullptr){
                        q.push_back(node -> right);
                    }
                }
                result.push_back(temp);
            }
            return result;
        }
    };