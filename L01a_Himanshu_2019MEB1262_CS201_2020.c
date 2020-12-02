/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


/* struct node* del_last() */


#include <stdio.h>
#include <stdlib.h>
/* node structure====================== */

struct node
{
  int data;
  struct node *next;
} *head = NULL, *t;

/* 00000000000000000000000000000000000000000000 */
void clear_list(struct node **head){
   struct node* current = *head; 
   struct node* next; 
  
   while (current != NULL)  
   { 
       next = current->next; 
       free(current); 
       current = next; 
   } 
   *head = NULL; 
}

/* 111111111111111111111111111111111111111111111 */

struct node* insert_beginning(struct node **head, int data){
    t=(struct node*)malloc(sizeof(struct node));
    t->data=data;
    t->next=*head;
    *head=t;
    
}

/* 2222222222222222222222222222222222222222222222 */

struct node* insert_end(struct node **head,int data){
     t=(struct node*)malloc(sizeof(struct node));
     t->data=data;
     t->next=NULL;
     if(*head == NULL)
         *head = t;
     else{
	 
     struct node* temporary=*head;
     while(temporary->next!=NULL){
         temporary=temporary->next;
     }
     temporary->next=t;
}}
/* 333333333333333333333333333333333333333333333 */
void del_first(){
    if(head == NULL)
    {
        printf("\tCannot delete as NO nodes in the linked-list\n");
    }
    else{
    struct node *p =head;
    head=head->next;
    free(p);}
}

/* 4444444444444444444444444444444444444444444444 */

void del_last(struct node **head){
     struct node *p=*head, *q=*head;

    if(*head == NULL)
    {
        printf("\tCannot delete as NO nodes in the linked-list\n");
    }
    else
    {
        while(p->next!=NULL)
        {
            q=p;
            p=p->next;
        }
        if(p == *head)
        {
            *head = NULL;
        }
        else{
        q->next = NULL;
        free(p);
        }
}
    
}

/* 5555555555555555555555555555555555555555555555 */

void del_specific(struct node **head,int data){
    struct node *p=*head;
    struct node *q=NULL;
    int flag=0;
    while (p!=NULL){
         if (p->data==data){
             flag++;
         }
         if(flag!=0){
            q->next=p->next;
            p->next=NULL;
            free(p);
            break;
         }
         q=p;
         p=p->next;
    }
    if (flag==0){printf("\tCannot delete as no such node in the linked-list\n");}
    
}
/* 666666666666666666666666666666666666666 */
void find_node(struct node* head,int data){
    struct node *p=head;
    int flag=0,position=0;
    while (p!=NULL){ 
         position++;
         if (p->data==data){
             flag++;
         } 
         if(flag!=0){
             printf("\tValue %d node is at position %d in the linked list.\n\tDifference in its allocated memory to that of current head : %ld\n",data,position,p-head);
             break;
         }
         p=p->next;
    }
    if (flag==0){printf("\tCannot find any such node in the linked-list\n");}
}


/* 777777777777777777777777777777777777777 */
void size(struct node *head){
     int count=0;
     struct node *p=head;
     while (p != NULL)
    {
      count++;
      p = p->next;
    }
    printf("\tSize of the linked list = %d\n",count);
}

/* 8888888888888888888888888888888888888888 */

void display(struct node **head){
    struct node *p=*head;
    if (p==NULL){printf("\tEmpty\n");}
    else{
    printf("\tLinked list: ")  ;     
    while (p != NULL)
    {
      printf("%d",p->data);
      if(p->next!=NULL){
      printf(" => ");}
      p = p->next;
    }
    printf("\n");
        }
}

/* ===================================== */
int main()
{   int re_enter=0;
    int data;
    int choice=-1;
    while (choice!=0){
    if (re_enter!=1){
    	printf("Enter the choice:\n");
	}
    re_enter=0;
    scanf("%d",&choice);
    switch(choice)
    {   case 0:clear_list(&head);
               break;
        case 1:printf("Enter the data value:\n");
               scanf("%d",&data);
               insert_beginning(&head,data);
               break;
        
        case 2:printf("Enter the data value:\n");
               scanf("%d",&data);
               insert_end(&head,data);
               break;
        
        case 3:del_first();
               break;
        case 4:del_last(&head);
               break;
       
        case 5:printf("Enter the data value:\n");
               scanf("%d",&data);
               del_specific(&head,data);
               break;
               
        case 6:printf("Enter the data value:\n");
               scanf("%d",&data);
               find_node(head,data);
               break;
        case 7:size(head);
               break;
        case 8:display(&head);
               break;
        default:printf("\tWrong Input.\nEnter your choice again:\n");
                re_enter=1;
                break;
    }
    
    }

    return 0;
}








