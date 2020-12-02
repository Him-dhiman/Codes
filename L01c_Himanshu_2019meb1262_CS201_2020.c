#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
int max=10000;  // used for declaring an array of size 1000. 

// ===============================NODE STRUCTURE TO STORE x^x TYPE VALUES==================================
struct part_links{
    int data;
    struct part_links*next;
};
int next_time;
// ====================Function to create a new node and add it to linkedlist==================
void push(struct part_links** head_ref, int new_data)  
{   
    struct part_links* new_node = (struct part_links*)malloc(sizeof(struct part_links));  
    new_node->data=new_data; 
    new_node->next = (*head_ref);   
    (*head_ref) = new_node;  
}  
// =================================Function to create a new list====================================================
struct part_links* make_empty_list(int size)  
{  
    struct part_links* head = NULL;  
    while (size--)  
        push(&head, 0);  
    return head;  
}  
// =====================================Function to reverse a list=====================================================
int reverse(struct part_links** head_ref)  
{  
    struct part_links* prev = NULL;  
    struct part_links* current = *head_ref;  
    struct part_links* next;  
    int len = 0;  
    while (current != NULL) {  
        len++;  
        next = current->next;  
        current->next = prev;  
        prev = current;  
        current = next;  
    }  
    *head_ref = prev;  
    return len;  
}  
// ========================================================================================================
struct part_links* multiplyLists(struct part_links* first,  struct part_links* second)  
{  
     
    int m = reverse(&first), n = reverse(&second);  
  
    struct part_links* result = make_empty_list(m + n + 1);  
  
    struct part_links *second_ptr = second,  
        *result_ptr1 = result, *result_ptr2, *first_ptr;  
    while (second_ptr) {  
  
        int carry = 0;  
  
        // each time we start from the next of part_links
        // from which we started last time  
        result_ptr2 = result_ptr1;  
  
        first_ptr = first;  
  
        while (first_ptr) {  
   
            int mul = first_ptr->data * second_ptr->data  
                    + carry;  
    
            result_ptr2->data += mul % 10;  
   
            carry = mul / 10 + result_ptr2->data / 10;  
            result_ptr2->data = result_ptr2->data % 10;  
  
            first_ptr = first_ptr->next;  
            result_ptr2 = result_ptr2->next;  
        }  
  
        // if carry is remaining from last multiplication  
        if (carry > 0) {  
            result_ptr2->data += carry;  
        }  
  
        result_ptr1 = result_ptr1->next;  
        second_ptr = second_ptr->next;  
    }  
    return result;
}
// ===================================FUNCTION TO CREATE A LINKED-LIST BY A GIVEN ARRAY==============================

void create(struct part_links** head,int A[],int res_size)
{
 int i;
 struct part_links *t,*last;
 struct part_links *p=*head;
 p=(struct part_links *)malloc(sizeof(struct part_links));
 p->data=A[res_size-1];
 p->next=NULL;
 last=p;
for (int i = res_size-2 ;i>=0;i--)
 {
 t=(struct part_links*)malloc(sizeof(struct part_links));
 t->data=A[i];
 t->next=NULL;
 last->next=t;
 last=t;
 }
 *head=p;
}
// ================ This function multiplies x with the number represented by res[]. 
// res_size is size of res[] or number of digits in the number represented by res[].===================

int multiply(int n, int res[], int res_size) { 
int carry = 0; 
//  One by one multiply x with individual digits of res[].
for (int i = 0; i < res_size; i++) { 
    int prod = res[i] * n + carry; 
    res[i] = prod % 10; 
    carry = prod / 10; 
} 
  
// Put carry in res and 
// increase result size 
while (carry) { 
    res[res_size] = carry % 10; 
    carry = carry / 10; 
    res_size++; 
} 
return res_size; 
} 
// ====================FUNCTION TO display A LINKED LIST==================================

int string_size;
void display(struct part_links* p, char string[]){
    
    int i=0;
    while (p->data==0){
        p=p->next;
    }
    while(p!=NULL)
        {if(next_time)
         {printf("%d",p->data);}
         string[i++]=p->data+'0';
         p=p->next;
        }
    string_size=i;
    next_time++;
} 

// ====================================FUNCTION TO FIND x^x==================================  
void power(int n,struct part_links**head)  
{ 
int res[max];        //array to store the number (n^n)
int res_size=0; 
int temp=n; 

while (temp != 0) { 
    res[res_size++] = temp % 10; 
    temp = temp / 10; 
} 
   
// Multiply n^n times 
for (int i = 2; i <= n; i++) 
    res_size = multiply(n, res, res_size); 

create(head,res,res_size);

} 


void count_zeroes(struct part_links* p){
    int count=0;
    while(p->data==0)
    {count++;
    p=p->next;}
    printf("%d",count);
}


void count_pattern(char string[] , char k[]){
    int N=strlen(string),M=strlen(k),count=0;
  
    int res = 0; 
    
   
    for (int i = 0; i <= N - M; i++) 
    {  
      
        int j; 
        for (j = 0; j < M; j++) 
            if (string[i+j] != k[j]) 
                break;
        if (j == M)   
        { 
           res++; 
           j = 0; 
        } 
    } 
   printf("%d",res);} 

// Driver program 
int main() {
int testcase,n,p;
char k[200];
scanf("%d",&testcase);

while(testcase--){
    next_time=0;
    int yes=0;
    char string[100];
    int counter=0;
    struct part_links *result;
    
    scanf("%d",&n);
    scanf("%s",k);
    if(*k=='1'){yes=1;}
    if (n==0){printf("0 %d 1",yes);}
    else{
    struct part_links *head[200]={NULL};  //creating n heads one each for storing 1^1, 2^2 .... n^n.
    for (int i=1;i<=n;i++)
    power(i,&head[counter++]); 
    if(counter==1){printf("0 %d 1",yes);}
    else if (counter>=2){
        result=multiplyLists(head[0],head[1]);
        p= reverse(&result);
        for (int i = 0; i < counter-2 ; i++){
            result=multiplyLists(head[i+2],result);
            p= reverse(&result);
        }}
    if(counter!=1)
   { p= reverse(&result);
    count_zeroes(result);
    printf(" ");
    p= reverse(&result);
    
    display(result,string);

    count_pattern(string,k);
    printf(" ");
    display(result,string);
   }
    
}
printf("\n");}




return 0; 
} 




