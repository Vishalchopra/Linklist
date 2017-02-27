#include <stdio.h>
#include <stdlib.h>

struct list{
	int data;
	struct list *next;
};
struct list *start_node = NULL;
enum {
	CREATE_NODE,
	INSERT_NODE,
	DELETE_NODE,
	MIDDLE_NODE,
	REVERSE_LIST,
	DISPLAY_LIST = 5,
	EXIT_LIST
};
int user_input();
struct list *create_node();
int display_list();
int middle_node();
int exit_list();
int insert_node();
int delete_node();
int reverse_list();
int operation_choice(int);

int main()
{
	struct list *start = NULL;
	int input;
	while(1){
		input = user_input();
		operation_choice(input);
		printf("\n\n\n\n\n");
	}	
	return 0;
}

int user_input()
{
	unsigned int input;
	printf("Please Enter your choice\n");
	printf("0 to Create starting node\n");
	printf("1 to insert node\n");
	printf("2 to delete node\n");
	printf("3 to print middle node\n");
	printf("4 to reverse list\n");

	printf("5 to Display linklist\n");
	printf("6 to EXIT\n");
	scanf("%d", &input);
	printf("%d\n", input);
//	while(1);
	
	return input;
}

int operation_choice(int choice)
{
	struct list *start = NULL;
	switch(choice){
	case CREATE_NODE:
		start_node = create_node();
	break;
	case INSERT_NODE:
		insert_node();
	break;
	case DELETE_NODE:
		delete_node();
	break;
	case DISPLAY_LIST:	//to display linklist
		display_list();
	break;
	case MIDDLE_NODE:
		middle_node();
	break;
	case REVERSE_LIST:
		reverse_list();
	break;
	case EXIT_LIST:
		exit_list();
	break;
	default:
		printf("Invalid option \n");
	}
	return 0;	
}

struct list *create_node()
{
	if(start_node != NULL){
		printf("Starting node already exit\n");
		return 0;
	}
	struct list *start = NULL;
	start = (struct list *)malloc(sizeof(struct list *));
	printf("Please enter the data\n");
	scanf("%d", &start->data);
	start->next = NULL;
	return start;
}

int insert_node()
{
	struct list *new, *start;
	if(start_node == NULL){
		printf("Linklist is empty inster starting node first\n");
		return 0;
	}
    	start = start_node;
	while(start->next != NULL){
		start = start->next;
	}
	new = (struct list *)malloc(sizeof(struct list *));
	printf("Enter the data in the new node\n");
	scanf("%d", &new->data);
	new->next = NULL;
	start->next = new;

	return 0;
}

int delete_node()
{
	struct list *start, *prev;
	if(start_node == NULL){
		printf("List is already empty\n");
		return 0;
	}
	start = start_node;
	prev = NULL;
	while(start->next != NULL){
		prev = start;
		start = start->next;
	}
	free(start);
	start = NULL;
	if(prev != NULL)
		prev->next = NULL;
else
		start_node = NULL;
	return 0;
}

int middle_node()
{
	struct list *single_list, *double_list;
	int val = 1;
	single_list = double_list = start_node;

	while(double_list->next != NULL && double_list->next->next != NULL){
		single_list = single_list->next;
		double_list = double_list->next->next;
		val++;
	}
	printf("%d\n", single_list->data);
	return 0;
}

int reverse_list()
{
	struct list *start, *end, *middle;
	middle = NULL;
	start = end = start_node;
	if(start->next == NULL){
		printf("One node can't be reverse\n");
		return 0;
	}

	while(end->next != NULL){
		start = end;
		end = end->next;
		start->next = middle;
		middle = end;
		end = end->next;
		middle->next = start;
	}
	end->next = middle;
	start_node = end;
	return 0;
}
int display_list()
{
	struct list *start = start_node;
	int i = 0;
	if(start == NULL){
		printf("List is empty \n");
		return 0;
	}
	do{
		printf("Data present at list %d is %d\n", i++, start->data);
		start = start->next;
	}while(start != NULL);
	return 0;
}

int exit_list()
{
	if(start_node != NULL)
		printf("linklist is not empty \n Delete all nodes\n");
	else
		exit(EXIT_SUCCESS);
	return 0;
}
