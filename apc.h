#ifndef APC_H
#define APC_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}Dlist;

/* Include the prototypes here */

/*store the operands into the list */
void digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[]);

/*Addition */
int addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*subtraction*/
int subtraction(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*Multiplication*/
int multiplication(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*Division */
int division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

int cla_check(char *argv[]);

void insert_at_last(Dlist **head,Dlist **tail,int digit);

void insert_at_first( Dlist **headR, Dlist **tailR,int digit);

int delete_list(Dlist **head, Dlist **tail);

void print_list(Dlist *head);

long find_list_length(Dlist *operand);

int compare_lists(Dlist *head1, Dlist *head2);

#endif
