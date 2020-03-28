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