#include"stdio.h"

typedef struct tree{
	int val;
	struct tree *left;
	struct tree *right;
}TreeNode;

TreeNode *initial(){
	TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *l = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *ll = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *lr = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *r = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *rr = (TreeNode *)malloc(sizeof(TreeNode));

	root->val = 1;
	l->val = 2;
	ll->val = 3;
	lr->val = 4;
	r->val = 5;
	rr->val = 6;

	root->left = l;
	root->right = r;
	l->left = ll;
	l->right = lr;
	ll->left = NULL;
	ll->right = NULL;
	lr->left = NULL;
	lr->right = NULL;
	r->left = NULL;
	r->right = rr;
	rr->left = NULL;
	rr->right = NULL;

	return root;
}

void flatten(TreeNode *root) {
	if(!root){ 
		printf("no root\n");
		return;
	}
	TreeNode *cur = root;
        while(cur) {
		TreeNode *right = cur->right;
		if(cur->left) {
			TreeNode *tmp = cur->left;
			while(tmp->right) {
				tmp = tmp->right;
			}
			tmp->right = right;
			cur->right = cur->left;
			cur->left = NULL;
		}
		printf("%d->", cur->val);
		cur = cur->right;
	}
}

int main()
{
	TreeNode *root = initial();
	printf("Output: ");
	flatten(root);
	printf("null\n");
	
    return 0;
}


