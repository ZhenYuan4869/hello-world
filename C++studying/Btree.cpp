void layerTrace(BTreeNode *T)  //层序遍历
{
    if(T== nullptr)return;
    BTreeNode *p=T;
    queue<BTreeNode*>q;
    q.push(p);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        cout<<<<p->data;
        if(p->left!= nullptr)q.push(p->left);
        if(p->right!= nullptr)q.push(p->right);
    }
}

TreeNode* helper(vector<int>pre,int startPre,int endPre,vector<int>in,int startIn,int endIn)
{   //传进来了前序和中序两个vector并且位置也传进来了
    if(startPre>endPre||startIn>endIn)
        return nullptr;
    TreeNode * root=new TreeNode(pre[startPre]);
    for(int i=startIn;i<=endIn;++i)
    {
        if(in[i]==pre[startPre]) //在中序中找到前序的根，把左子树和右子树还原出来
        {   //迭代思想来做
            root->left=helper(pre,startPre+1,startPre+i-startIn,in,startIn,i-1);
            root->right=helper(pre,i-startIn+startPre+1,endPre,in,i+1,endIn);
            break;
        }
    }
    return root;
}
TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin)
{
    TreeNode *root=helper(pre,0,pre.size()-1,vin,0,vin.size()-1);
    return root;
}