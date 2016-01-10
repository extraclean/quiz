#include <stdio.h>
#include <stdlib.h>

typedef struct list{
	int val;
	struct list *next;
	//struct list (int x) : val(x), next(NULL){}
}ListNode;

ListNode *reverseBetween(ListNode *head, int m, int n) {
	ListNode* h=head;
	int i;
	for (i=0;i<n-m;i++){
		int k1=m+i;
	        int k2=n-i;
        	if (k1>=k2){return head;}
       		ListNode* p = h;
            	ListNode* q = h;
            	while (k1-1>0){p=p->next;k1--;}
            	while (k2-1>0){q=q->next;k2--;}
            	int tmp=p->val;
            	p->val=q->val;
            	q->val=tmp;
        }
        return head;
    }

int main(int argc, char *argv[])
{
	int m=0 ,n=0;
	ListNode *input = (ListNode *)malloc(sizeof(ListNode));
	ListNode *input2 = (ListNode *)malloc(sizeof(ListNode));
	ListNode *input3 = (ListNode *)malloc(sizeof(ListNode));
	ListNode *input4 = (ListNode *)malloc(sizeof(ListNode));
	ListNode *input5 = (ListNode *)malloc(sizeof(ListNode));

	if(argc!=3){
		printf("input should be two integer seperated by space!!!\n");
		return 0;
	}else if(atoi(argv[1])>5||atoi(argv[1])<1||atoi(argv[2])>5||atoi(argv[2])<1){
		printf("input should be 1~5\n");		
		return 0;
	}else{
		m = atoi(argv[1]);
		n = atoi(argv[2]);
	}

	input->val=1;
	input2->val=2;
	input3->val=3;
	input4->val=4;
	input5->val=5;

	input->next=input2;
	input2->next=input3;
	input3->next=input4;
	input4->next=input5;	
	input5->next=NULL;

	printf("input: ");
	printf("%d",input->val);
	printf("->");
	printf("%d",input->next->val);
	printf("->");
	printf("%d",input->next->next->val);
	printf("->");
	printf("%d",input->next->next->next->val);
	printf("->");
	printf("%d",input->next->next->next->next->val);
	printf("->NULL\n");	

	reverseBetween(input, m, n);
	
	printf("result: ");
	printf("%d",input->val);
	printf("->");
	printf("%d",input->next->val);
	printf("->");
	printf("%d",input->next->next->val);
	printf("->");
	printf("%d",input->next->next->next->val);
	printf("->");
	printf("%d",input->next->next->next->next->val);
	printf("->NULL\n");

	return 0;
}
