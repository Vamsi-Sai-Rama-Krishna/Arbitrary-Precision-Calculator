#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	
	//take temperory variables for traversing
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;
	int borrow = 0;
	int result = 0;
	while( (temp1 != NULL) || (temp2 != NULL) )
	{
		//case-1:
		//if both lists not equal to NULL
		if(temp1 != NULL && temp2 != NULL)
		{
			if(temp1->data < temp2->data)
			{
				//temp1->data = temp1->data + 10;
				result = temp1->data - temp2->data - borrow + 10 ;
				insert_at_first(headR, tailR, result);
				borrow = 1;
			}
			else
			{
				result = temp1->data - temp2->data - borrow;
				borrow = 0;
				if (result < 0)
				{
					result += 10;
					borrow = 1;
				}
				insert_at_first(headR, tailR, result);
			}
			temp1 = temp1->prev;
			temp2 = temp2->prev;
		}
		//if both lists not equal to NULL
		else if(temp1 != NULL && temp2 == NULL)
		{
			result = temp1->data - borrow;
			borrow = 0;
			if (result < 0)
			{
				result += 10;
				borrow = 1;
			}
			insert_at_first(headR, tailR, result);
			temp1 = temp1->prev;
		}
	}

	//after termination of loop check if flag = 1 or not i.e indiactes the list swapping 
	//so multiply the first digit(headR->data) with '-1'.

	//remove leading zeros.
	while((*headR)->data == 0 && (*headR != *tailR))
	{
		*headR = (*headR)->next;
		free((*headR)->prev);
		(*headR)->prev = NULL;
	}

	extern int flag;
	if(flag == 1)
	{
		(*headR)->data = (*headR)->data * (-1);
	}
}

