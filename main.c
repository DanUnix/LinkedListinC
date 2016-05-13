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
int lookup(int x, LIST L)
{
    // BASE CASE
    if(L == NULL)
        return 0;
    // If element is in the list return TRUE
    else if(x == L->element)
        return 1;
    return lookup(x, L->next);
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
// When program is done free the memory being used in heap by list
void free_cells(LIST *pL)
{
    // BASE CASE
    if((*pL) == NULL)
        return;
    // create temporary pointer to LIST 
    LIST *temp = pL;
    // Free the current pointer to Cell
    free(*pL);
    // Set current pointer to Cell to next Cell in temp
    (*pL) = (*temp)->next; 
    // Recursively free until BASE CASE 
    free_cells(&(*pL));
        
}

// Display elements in list
void display(LIST *pL)
{
    printf("List: [ ");
    while((*pL) != NULL){
        printf("%d",(*pL)->element);
        printf(","); 
        (*pL) = (*pL)->next;
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
    display(myList);
    //display_recursive(myList);
   
    display(myList);
    // Free memory of list
    free_cells(myList);
}
