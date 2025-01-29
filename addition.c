#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;
	int carry = 0;
	int result= 0;

	while(temp1 || temp2)
	{
		//case-1
		//if both operands of same no.of digits/nodes
		if(temp1 != NULL && temp2 != NULL)
		{
			//do addition.
			result = temp1->data + temp2->data + carry;
			carry = 0;	//after adding carry reset carry
			//check if result is greater then 9 or not
			if(result > 9)
			{
				insert_at_first(headR, tailR, result%10);
				carry = result/10;  //carry = 1;
			}
			else
			{
				insert_at_first(headR, tailR, result);
			}
			temp1 = temp1->prev;
			temp2 = temp2->prev;
		}

		//case-2
		//if operand-1 having more digits/nodes and temp2 have less digits/nodes
		else if(temp1 != NULL && temp2 == NULL)
		{
			result = temp1->data + carry;
			carry = 0;
			if(result > 9)
			{
				insert_at_first(headR, tailR, result%10);
				carry = result/10;  //carry = 1;
			}
			else
			{
				insert_at_first(headR, tailR, result);
			}
			temp1 = temp1->prev;	
		}

		//case-3
		//if operand-2 having more digits/nodes and temp1 having less digits /nodes.
		else if(temp1 == NULL && temp2 != NULL)
		{
			result = temp2->data + carry;
			carry = 0;
			if(result > 9)
			{
				insert_at_first(headR, tailR, result%10);
				carry = result/10;  //carry = 1;
			
			}
			else
			{
				insert_at_first(headR, tailR, result);
			}
			temp2 = temp2->prev;	
		} 
	}

	//after both temps reaching NULL check if still carry is present or not
	if(carry != 0)
	{
		insert_at_first(headR,tailR,carry);
		carry = 0;
	}
}

