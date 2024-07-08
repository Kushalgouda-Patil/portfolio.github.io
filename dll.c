#include<stdio.h>  
#include<stdlib.h>  

struct node  
{  
    struct node *prev;  
    struct node *next;  
    int data;  
};

struct node *head = NULL;  

void insertion_last(int);  
void deletion_specified(int);  
void display();  

void insertion_last(int item)  
{  
    struct node *ptr, *temp;  
    
    ptr = (struct node *) malloc(sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        ptr->data = item;  
        ptr->next = NULL;  
        if(head == NULL)  
        {  
            ptr->prev = NULL;  
            head = ptr;  
        }  
        else  
        {  
            temp = head;  
            while(temp->next != NULL)  
            {  
                temp = temp->next;  
            }  
            temp->next = ptr;  
            ptr->prev = temp;  
        }  
        printf("\nNode inserted at the end\n");  
    }  
}

void deletion_specified(int val)  
{  
    struct node *ptr, *temp;  
    
    if(head == NULL)  
    {  
        printf("\nUNDERFLOW\n");  
    }  
    else  
    {   
        ptr = head;  
        while(ptr != NULL && ptr->data != val)  
        {  
            ptr = ptr->next;  
        }  
        if(ptr == NULL)  
        {  
            printf("\nNode with data %d not found\n", val);  
        }  
        else if(ptr->next == NULL)  
        {  
            printf("\nNode after %d does not exist\n", val);  
        }  
        else  
        {  
            temp = ptr->next;  
            ptr->next = temp->next;  
            if(temp->next != NULL)  
            {
                temp->next->prev = ptr;
            }
            free(temp);  
            printf("\nNode deleted after %d\n", val);  
        }  
    }     
}

void display()  
{  
    struct node *ptr;  
    printf("\nPrinting values...\n");  
    ptr = head;  
    while(ptr != NULL)  
    {  
        printf("%d\n",ptr->data);  
        ptr = ptr->next;  
    }  
}  