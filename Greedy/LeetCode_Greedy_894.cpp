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
    vector< vector<TreeNode*> > memoization;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        memoization = vector< vector<TreeNode*> >(n + 1);
        return (genNode(n));
    }
    vector<TreeNode*> genNode(int n) {
        if (n == 1) {
            // 만들 수 있는 노드 개수가 1개일 경우 벡터의 노드 하나만 담아서 리턴한다.
            return vector<TreeNode*>(1, new TreeNode(0));
        }
        if (memoization[n].size()) {
            // 메모이제이션
            return memoization[n];
        }
        vector<TreeNode*> rtn;
        // 이 for 문에서 왼쪽 노드와 오른쪽 노드의 조합을 생성해 낸다.
        for (int i = 1; i < n; i += 2) {
            vector<TreeNode*> left = genNode(i);
            vector<TreeNode*> right = genNode(n - i - 1);
            // 왼쪽 노드와 오른쪽 노드에서의 모든 조합을 자식 노드로 하는 부모 노드를 만들고 리턴할 벡터에 저장한다.
            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    TreeNode* root = new TreeNode(0);
                    root->left = left[j];
                    root->right = right[k];
                    rtn.push_back(root);
                }
            }
        }
        memoization[n] = rtn;
        return memoization[n];
    }
};