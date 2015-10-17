/* FIXME: Implement! */

int main()
{
    return 0;
}

void flatten(TreeNode *root){
	if(root == NULL|| root->right == NULL)
		return root;
	return merge(root, flatten(root->right));
}

TreeNode *merge(TreeNode *a, TreeNode *b){
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;
	TreeNode *result;
	if(a->data<b->data){//why
		result = a;
		result->next = merge(a->next,b);
	}else{
		result = b;
		result->next = merge(a,b->next);
	}
	return result;
}
