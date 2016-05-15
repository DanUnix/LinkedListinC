#include <stdio.h>
#include <stdlib.h>


// Pointer to a Cell
typedef struct CELL *LIST;
// Cell structure
struct CELL{
    int element;
    LIST next;
};


// Lookup an element in the list
// return 1 if true and 0 if false
int lookup(int x, LIST *pL)
{
    // BASE CASE
    if((*pL) == NULL)
        return 0;
    // If element is in the list return TRUE
    else if(x == (*pL)->element)
        return 1;
    return lookup(x, &((*pL)->next));
}

// insert an element into the list
void insert(int x, LIST *pL)
{
    // BASE CASE
    if((*pL) == NULL){
        (*pL) = (LIST)malloc(sizeof(struct CELL));
        (*pL)->element = x;
        (*pL)->next = NULL;
    }else if(x != (*pL)->element)
        insert(x, &((*pL)->next));
}

// Delete an element from the list
void delete(int x, LIST *pL)
{
    // BASE CASE
    if((*pL) != NULL)
        // if x is equvilant to element then delete from list
        if(x == (*pL)->element)
            (*pL) = (*pL)->next;
        // If x is not equal to the current element of the current Cell
        // Then delete x from the tail of the list
        else
            delete(x, &((*pL)->next));
}

// Display elements in list
void display(LIST L)
{
    printf("List: [ ");
    while(L != NULL){
        printf("%d",L->element);
        printf(","); 
        L = L->next;
    }
    printf(" ]\n");
}

void display_recursive(LIST *pL)
{
    // BASE CASE
    if((*pL) == NULL)
        return;
    printf("%d,", (*pL)->element);
    display_recursive(&(*pL)->next);
}

int main()
{
    // Allocate memory for myList
    LIST *myList = malloc(sizeof(struct CELL));
	time_t t;
    int i;
    // Insert random values into list
    srand((unsigned) time(&t));
    for(i = 0; i < 10; i++)
        insert(rand() % 100, myList);
    // Display new list
    display(*myList);
	// Test Lookup Function
	int find;
	printf("What Number would you like to find? ");
	scanf("%d",&find);
	int look = lookup(find,myList);
	if(look == 1)
		printf("%d is in the List\n",find);
	else
		printf("%d is not in the List\n", find);	
	

    display(*myList);
}
