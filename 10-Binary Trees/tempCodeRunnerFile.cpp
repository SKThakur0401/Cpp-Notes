
void inorder_print(BinaryTreeNode<int>* root)
{
    if(root == NULL) {return;}
    inorder_print(root->left);
    cout<< root->data <<  " ";
    inorder_print(root->right);