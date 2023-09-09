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
    int widthOfBinaryTree(TreeNode* root) {
     if(!root)return 0;
     int ans=0;
     queue<pair<TreeNode*,int>> q;
     q.push({root,0});
     while(!q.empty()){
         int s=q.size();
         int t=q.front().second;
         int first,last;
         for(int i=0;i<s;i++){
             TreeNode* ce = q.front().first;
             int cid=q.front().second-t;
             q.pop();
             if(i==0) first=cid;
             if(i==s-1)last=cid;
             if(ce->left)q.push({ce->left,(long long)cid*2+1});
             if(ce->right)q.push({ce->right,(long long)cid*2+2});

         }
         ans=max(ans,last-first+1);
     }   
     return ans;
    }
};