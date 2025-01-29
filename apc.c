#include "apc.h"
int op1_sign;
int op2_sign;

int cla_check(char *argv[])
{
	//check if operands are digits or not.
	//for operand1.
	for(int i=0; i<strlen(argv[1]); i++)
	{
		if(argv[1][0] == '+' || argv[1][0] == '-')
		{
			continue;
		}	
		else if((argv[1][i] <'0' || argv[1][i] > '9'))
		{
			printf("Invalid operand-1\n");
			return FAILURE;
		}	
	}
	
	//for operand2.
	for(int i=0; i<strlen(argv[3]); i++)
	{
		if(argv[3][0] == '+' || argv[3][0] == '-')
		{
			continue;
		}
		else if((argv[3][i] <'0' || argv[3][i] > '9'))
		{
			printf("Invalid operand-2\n");
			return FAILURE;
		}
	}
	return SUCCESS;
}

void digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[])
{   
    char *argv1 = argv[1];
	char *argv3 = argv[3];
    // //sign check for both operands.
	int i=0; //index for operand 1.
	int j=0; //index for operand 2.

	// //check if both operands are negative.
	// if((argv[1][0] == '-') && (argv[3][0] == '-'))
	// {
	// 	// argv1 = argv1[1];
	// 	// argv3 = argv3[1];
	// 	i=1;
	// 	j=1;
	// }
    // if(argv[1][0] == '-') //if 1st operand is negative.
    // {
    //     //update sign.
    //     op1_sign = -1;

    //     //update/pass form next index excluding sign.
	// 	i++;
    // }
    // if(argv3[0] == '-') //if 2nd operand is negative.
    // {
    //     //update sign.
    //     op2_sign = -1;

    //     //update/pass form next index excluding sign.
	// 	j++;
    // }
	// if((argv1[0] == '+') && (argv3[0] == '+'))
	// {
	// 	i++;
	// 	j++;
	// }
	// if(argv1[0] == '+')
	// {
	// 	i++;
	// }
	// if(argv3[0] == '+')
	// {
	// 	j++;
	// }

	
	//for 1st operand.
	while(argv1[i] != '\0')
	{
		int digit  = argv1[i] - '0';
		insert_at_last(head1,tail1,digit);
		i++;
	}

	//for 2nd operand.
	while(argv3[j] != '\0')
	{
		int digit  = argv3[j] - '0';
		insert_at_last(head2,tail2,digit);
		j++;
	}
    return;
}

void insert_at_last(Dlist **head,Dlist **tail,int digit)
{
	//create a node and validate
	Dlist *new = malloc(sizeof(Dlist));

	if(new == NULL) 
	{
		return; //FAILURE;
	}

	//if created the update the bocks(prev,data,next) of newly created node.
	new->data = digit;
	new->prev = NULL;
	new->next = NULL;

	//check if list is empty or not.
	if(*head == NULL && *tail == NULL)
	{
		//if empty update head and tail.
		*head = new;
		*tail = new;
		return;
	}

	//if list not empty(already containing some nodes)
	(*tail)->next = new;
	new->prev = *tail;
	*tail = new;
}

void insert_at_first( Dlist **headR, Dlist **tailR,int digit)
{
	//create a node and update its 3 parts
	Dlist *new = malloc(sizeof(Dlist));
	if(new == NULL)
	{
		return;
	}
	new->prev = NULL;
	new->data = digit;
	new->next = NULL;

	//check if list is empty of not 
	if(*headR == NULL & *tailR == NULL)
	{
		*headR = new;
		*tailR = new;
		return;
	}

	//if not empty establish link between new node and previous node.
	(*headR)->prev = new;
	new->next = *headR;
	*headR = new;
}

int delete_list(Dlist **head, Dlist **tail)
{
    //check if list is empty or not.
    if((*head == NULL) && (*tail == NULL))
    {
        return FAILURE;
    }
    
    //if list with multiple Nodes
    while((*head)->next != NULL)
    {
        *head = (*head)->next;
        free((*head)->prev);
    }
    free(*head);
    *head = NULL;
    *tail = NULL;
    return SUCCESS;
}

void print_list(Dlist *head)
{
    if(head==NULL)
	{
        printf("NULL\n");
		return;
    }
	while(head)
	{
		printf("%d",head->data);
		head = head->next;
	}
	printf("\n");
}

long find_list_length(Dlist *operand)
{
	long len = 0;
	while(operand != NULL)
	{
		operand = operand->next;
		len++;
	}
	return len;
}

int compare_lists(Dlist *head1, Dlist *head2)
{
	while(head1 != NULL && head2 != NULL)
	{
		if(head1->data > head2->data)
		{
			return 1;
		}
		else if(head1->data < head2->data)
		{
			return -1;
		}

		head1 = head1->next;
		head2 = head2->next;
	}
}