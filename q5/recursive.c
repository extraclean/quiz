#include<stdio.h>
#include<stdlib.h>

typedef struct list {
	int val;
	struct list *next;
}ListNode;

int detectCycle(ListNode *head,ListNode *p,ListNode *q) {
	if(!head)
		return 0;

	if(p->next!=NULL)
		p=p->next;
	else
		return 0;
	if(q->next!=NULL && q->next->next!=NULL)
		q=q->next->next;
	else
		return 0;
	if (p==q){
		q=head;
		while (p!=q){
			p=p->next;
			q=q->next;
		}
		return p->val;
	}
	detectCycle(head,p,q);
}

int main()
{
	ListNode *input = (ListNode *)malloc(sizeof(ListNode));
	ListNode *input2 = (ListNode *)malloc(sizeof(ListNode));
	ListNode *input3 = (ListNode *)malloc(sizeof(ListNode));
	ListNode *input4 = (ListNode *)malloc(sizeof(ListNode));
	ListNode *input5 = (ListNode *)malloc(sizeof(ListNode));
	ListNode *input6 = (ListNode *)malloc(sizeof(ListNode));

	input->val=1;
	input2->val=2;
	input3->val=3;
	input4->val=4;
	input5->val=5;
	input6->val=6;

	input->next=input2;
	input2->next=input3;
	input3->next=input4;
	input4->next=input5;	
	input5->next=input6;	
	input6->next=input2;

	printf("input: ");
	printf("%d",input->val);//1
	printf("->");
	printf("%d",input->next->val);//2
	printf("->");
	printf("%d",input->next->next->val);//3
	printf("->");
	printf("%d",input->next->next->next->val);//4
	printf("->");
	printf("%d",input->next->next->next->next->val);//5
	printf("->");
	printf("%d",input->next->next->next->next->next->val);//6
	printf("->");
	printf("%d\n",input->next->val);//2

	printf("result: ");
	printf("%d\n",detectCycle(input,input,input));
	return 0;
}
