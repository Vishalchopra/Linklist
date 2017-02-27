#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};
int ent_choice();

struct node *lin_list(int, struct node *);
struct node *insert_list(struct node *);
struct node *create_list();
struct node *create_nod();
struct node *delete_nod(int, struct node *);
int display(struct node *nod);
struct node *reverse_list(struct node *);

int main()
{
	int i, j;
	j = 0;
	struct node *start, *nod;
	start = NULL;
	//	nod = (struct node*)malloc(sizeof(struct node));
	while(1)
	{
		i = ent_choice();
		if(!start)
		{
			nod = start = lin_list(i, start);
			printf("%d\n", nod->info);
			j++;
			printf("start = %u\n",start);
		}
		else if( i == 1 && start != NULL)
		{
			printf("Please enter the another choice as link list is alreay created\n");
		}
		else if(start != NULL && i == 2) 
		{
			nod->next   = lin_list(i, start);
			printf("%d\n", nod->info);
			nod = nod->next;	
		}
		else if(i == 3)
		{
			start = lin_list(i, start);
		}
		else if(i == 4)
		{
			start = lin_list(i, start);
		}
		else if(i == 5)
		{
			lin_list(i, start);
		}
		else if(i == 6)
		{
			start = lin_list(i, start);
		}
		else if(i == 7)
		{
			free(start);
			start = NULL;
			goto OUT;
		}
	}	
OUT:
	return 0;
}
int ent_choice()
{
	int i;
	printf("1 to create link list\n");
	printf("2 to create node\n");
	printf("3 to delete  node in betwen\n");
	printf("4 to insert node in betwen\n");
	printf("5 to display the linklist\n");
	printf("6 to reverse the linklist");
	printf("7 to exit\n");
	printf("\n");
	printf("Enter the choice:-\n");
	scanf("%d", &i);
	return i;

}

struct node *lin_list(int i, struct node *dat)
{
	int nod_num;
	switch(i)
	{
		case 1:
			{
				struct node *start;
				start = create_list();
				return start;
				break;
			}
		case 2:
			{
				struct node *nod;
				nod = create_nod();
				return nod;
				break;
			}
		case 3:
			{
				struct node *start;
				printf("Enter the number of the node to be delete :\n");
				scanf("%d", &nod_num);
				start = delete_nod(nod_num, dat);
				return start;
			}
		case 4:
			{
				struct node *start;
				start = insert_list(dat);
				printf("Before return\n");
				return start;
			}
		case 5:
			{
				display(dat);
				return dat;
			}
		case 6:
			{
				struct node *start;
				printf("Before return in reverse\n");
				start = reverse_list(dat);
				return start;
			}
		default :
			printf("Invalid choice\n");
			break;

	}		
}

struct node *create_list()
{
	struct node *start;
	start = (struct node *)malloc(sizeof(struct node));
	printf("Enter the information:-\n");
	scanf("%d", &start->info);
	start->next = NULL;
	return start;
}
struct node *create_nod()
{
	struct node *nod;
	nod = (struct node *)malloc(sizeof(struct node));
	printf("Enter the information:-\n");
	scanf("%d", &nod->info);
	nod->next = NULL;
	return nod;
}

struct node * delete_nod(int nod_num, struct node *start)
{
	struct node *cpy, *nod;
	int i;
	nod = start;
	for(i = 1; i <= nod_num; i++)
	{
		if(nod->next == NULL)
		{
			printf("You can't delete the last node from here\n");
			goto OUT;
		}
		cpy = nod;
		nod = nod->next;
		printf("i = %d\n", i);
		sleep(1);
	}
	cpy->next = nod->next;
	return start;
OUT:
	return start;
}
int display(struct node *nod)
{
	int num_node;
	num_node = 1;
	printf("start= %u\n",nod);
	while(nod->next != NULL)
	{
		printf("Data present at %d node is : %d\n", num_node, nod->info);
		nod = nod->next;
		num_node++;
	}
	printf("Data present at %d node is : %d\n", num_node, nod->info);
	return 0;
}

struct node *insert_list(struct node *start)
{
	printf("start= %u\n",start);
	struct node *nod, *cpy, *new_nod;
	int i, nod_num;
	new_nod = create_nod();
	nod = start;
	printf("Enter the postion where nod is to be entered\n");
	scanf("%d", &nod_num);
	for(i = 1;i < nod_num; i++)
	{
		cpy = nod;
		nod = nod->next;
	}
	printf("Enter the postion where nod is to be entered1\n");
	cpy->next = new_nod;
	new_nod->next = nod;
	display(start);
	printf("Enter the postion where nod is to be entered2\n");
	return start;
}

struct node *reverse_list(struct node *start)
{
	struct node *first, *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	first = start;
	int turn;
	turn = 0;
	if(turn == 0)
	{
		first = first->next;
		start->next = NULL;
		printf("first->next = %u\n",first->next);
		
	}
	while(first->next != NULL)
	{
		printf("%d\n", turn);
		temp = first->next;
		first->next = start;
		start = first;
		first = temp;
	}
	printf("start : %d\n", turn);
	first->next = start;
	return first;
	
}
