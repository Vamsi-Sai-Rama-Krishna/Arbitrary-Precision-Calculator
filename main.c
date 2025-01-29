//Name : Vamsi Krishna
//Description : To implement arbitrary precision caliculator using data structures (doubly linked list) which gives precise result for longer operands.
//Date : 25/01/2025.

#include "apc.h"

int flag = 0;
char operator;
int main(int argc, char *argv[])
{
	/* Declare the pointers */
	Dlist *head1=NULL, *tail1=NULL;
	Dlist *head2=NULL, *tail2=NULL; 
	Dlist *headR=NULL,*tailR=NULL;
	if(argc < 4 || argc > 4)
	{
		printf("Usage: ./a.out Operand-1 Operator Operand-2\n");
		return FAILURE;
	}
	if(strlen(argv[2]) != 1)
	{
		printf("Invalid Operator\n");
		return FAILURE;
	}
	//checks whether the operands having digits or not.
	if(cla_check(argv) == FAILURE)
	{
		return FAILURE;
	}
	operator = argv[2][0];
	digit_to_list(&head1,&tail1,&head2,&tail2,argv);

	//for subtraction
	if(operator == '-')
	{
		//case 1
		//check length of the operends
		if( strlen(argv[1]) < strlen(argv[3]) )
		{
			//swap by taking temp.  
			Dlist *temp1 = head1;
			Dlist *temp2 = tail1;

			//update to 1st list with 2nd list.
			head1 = head2;
			tail1 = tail2;

			//update 2nd list with temp
			head2 = temp1;
			tail2 = temp2;
			flag = 1;
		}
		// if both operand length are equal then compare the strings.
		else if( strlen(argv[1]) == strlen(argv[3]) )
		{
			if(strcmp(argv[1],argv[3]) < 0)
			{
				//swap 
				//swap by taking temp.  
				Dlist *temp1 = head1;
				Dlist *temp2 = tail1;

				//update to 1st list with 2nd list.
				head1 = head2;
				tail1 = tail2;

				//update 2nd list with temp
				head2 = temp1;
				tail2 = temp2;

				flag = 1;
			}
			else if(strcmp(argv[1],argv[3]) == 0)
			{
				printf("Result : 0\n");
				return SUCCESS;
			}
		}
	}

	switch (operator)
	{
		case '+':
			/* call the function to perform the addition operation */
			addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
			printf("Result : ");
			print_list(headR);
			break;
		case '-':				
			/* call the function to perform the subtraction operation */
			subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
			printf("Result : ");
			print_list(headR);
			break;
		case 'x': 			
			/* call the function to perform the multiplication operation */
			multiplication(&head1,&tail1,&head2,&tail2,&headR,&tailR);
			break;
		case '/':	 	
			/* call the function to perform the division operation */
			division(&head1,&tail1,&head2,&tail2,&headR,&tailR);
			break;
		default:
			printf("Invalid Input:-( Try again...\n");
	}
	return 0;
}
