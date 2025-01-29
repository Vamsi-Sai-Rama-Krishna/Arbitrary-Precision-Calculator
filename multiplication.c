#include "apc.h"
extern int op1_sign;
extern int op2_sign;
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;
	int result = 0;
	int carry =  0;
	int count = 0;

	//create two more extra lists for actual result and next result.
	Dlist *headR1 = NULL, *tailR1 = NULL;
	Dlist *headR2 = NULL, *tailR2 = NULL;

	while(temp2 != NULL)
	{ 
		for(int i=0; i<count; i++)
		{
			insert_at_first(&headR2,&tailR2,0); //insert 0's to the list.
		}
		while(temp1 != NULL)
		{
			result = (temp2->data * temp1->data)+carry;
			if(result > 9)
			{
				insert_at_first(&headR2,&tailR2,result%10);
				carry =  result/10;
			}
			else
			{
				insert_at_first(&headR2, &tailR2, result);
				carry=0;
			}
			temp1=temp1->prev;
		}
		
		if(carry>0) //if there is carry after comming out of loop then insert at first.
		{
			insert_at_first(&headR2,&tailR2,carry); 
			carry=0;
		}
		temp1 = *tail1; //reset temp1 to last.
		temp2 = temp2->prev;	//move to next node.
		count++;

		//before updating R2 call addition function.
		addition(&headR1,&tailR1,&headR2,&tailR2,headR,tailR); 

		//after addition delete the R1 and update result as R1
		// delete R2 and create new R2 by repeating multiplication operation.
		delete_list(&headR1,&tailR1);
		delete_list(&headR2,&tailR2);

		//now update headR & tailR to headR1 & tailR1
		headR1 = *headR;
		tailR1 = *tailR; 
		//after updating headR also update with NULL
		*headR = *tailR =  NULL;	
	}	

	*headR = headR1;
	*tailR = tailR1;

	//remove leading zeros.
	while((*headR)->data == 0 && (*headR != *tailR))
	{
		*headR = (*headR)->next;
		free((*headR)->prev);
		(*headR)->prev = NULL;
	}

	printf("Result : ");
	print_list(*headR);
}
