#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	Dlist *op1_head = *head1;
	Dlist *op1_tail = *tail1;

	Dlist *op2_head = *head2;
	Dlist *op2_tail = *tail2;

	long long op1_len = find_list_length(*head1);
	long long op2_len = find_list_length(*head2);

	long long count = 0;
	//case-1
	//if operand1 length is less then length of operand2  => directly return print result and return
	if(op1_len < op2_len)
	{
		printf("Result : 0\n");
	}
	else if(op1_len >= op2_len)
	{
		while(1)
		{
			//check list1(head1 & tail1) is less then list or not  
			//for that traverse and compare.
			if(find_list_length(*head1) < find_list_length(*head2))
			{
				printf("Result : %llu\n", count);
				break;
			}
			else if(find_list_length(*head1) == find_list_length(*head2))
			{
				if(compare_lists(*head1, *head2) < 0)
				{
					printf("Result : %llu\n", count);
					break;
				}
			}

			subtraction(head1,tail1,head2,tail2,headR,tailR);

			//delete head1 and tail1
			//before update headR and tailR to head1 and tail1 delete head1 and tail1
			delete_list(head1,tail1);
			*head1 = *headR;
			*tail1 = *tailR;
	
			//update headR and tailR with NULL
			*headR = *tailR = NULL;
			
			//for every subtraction increment count++;
			count++;
		}
	}
	//printf("Result : %d\n", count);
}
