/*
题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int length = pre.size();
        int root_position;
        TreeNode* head = new TreeNode(pre[0]);//调用结构的时候要new非配空间
        for(int i=0;i<length;i++)
        {
            if(pre[0]==vin[i])
            {
                root_position = i;
                break;
            }
        }
        vector<int> left_front.assign((pre.begin()+1,pre.begin()+1+root_position+1));//左子树的前序，其余同理
        vector<int> left_in (vin.begin(),vin.begin()+root_position+1);
        vector<int> right_front (pre.begin()+1+root_position+1,pre.end());//左子树的前序，其余同理
        vector<int> right_in (vin.begin()+root_position+1+1,vin.end());
        head->left = reConstructBinaryTree(left_front,left_in);
        head->left = reConstructBinaryTree(right_front,right_in);

        return head;
    }
};