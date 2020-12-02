#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// declaring a node with 3 elements.
struct node{
   int coefficient;
   int power;
   struct node *next; 
}*p1=NULL,*p2=NULL,*p3=NULL,*p4=NULL;   //p1 will be the pointer to polynomial by addition
                                        // p2 will be the pointer to polynomial by subtraction

// this is a function to create a linked-list by and storing coeffiecent and power values 
void create_list(struct node **first,int array[],int degree){
 int i;
 struct node *t,*last;
 struct node *p=*first;
 p=(struct node *)malloc(sizeof(struct node));
 p->coefficient=array[0];
 p->power=--degree;
 p->next=NULL;
 last=p;
 int power=degree;
 for(i=1;i<=degree+1;i++)
 {
 t=(struct node*)malloc(sizeof(struct node));
 t->coefficient=array[i];
 t->power=--power;
 t->next=NULL;
 last->next=t;
 last=t;
 }
 *first=p;
}
    
int is_empty(struct node*p){
	int sum=0;
	while(p->next!=NULL){
	sum=sum+p->coefficient;
	p=p->next;}
	if(sum==0)
	{return 1;}
	else{
	return 0;}
}

// function to display the polynomial
void display(struct node *p){
   if (is_empty(p)){printf("0");}
	else{
	
   if(p->coefficient>=0)
          printf("%dx^%d", p->coefficient, p->power);
       else
          printf("- %dx^%d", -1*p->coefficient, p->power);
    p=p->next;
   while(p ->next!= NULL){
      if(p->power!=0)
      {if (p->coefficient!=0)
      {if(p->coefficient>0)
          printf(" + %dx^%d", p->coefficient, p->power);
       else
       if(p->coefficient<0)
          printf(" - %dx^%d", -1*p->coefficient, p->power);
      }}
      else
      {if(p->coefficient> 0)
	  printf(" + %d",p->coefficient);
	  else
	  if(p->coefficient<0)
	  printf(" - %d",-1*p->coefficient);}
      p= p->next; 
   }}
}


// function to add to polynomials
void add_poly(struct node* p1, struct node *p2, struct node *p3){
    // we first start with obtaining the highest degree from the two
    // if polynomial1 has higher degree.
    while(p1->next && p2->next){
      if(p1->power>p2->power){
         p3->power=p1->power;
         p3->coefficient = p1->coefficient;
         p1 = p1->next;
      }
    
    //   if polynomial2 has higher degree
      else if(p1->power < p2->power){
         p3->power = p2->power;
         p3->coefficient = p2->coefficient;
         p2 = p2->next;
      } 
      
      else {
         p3->power = p1->power;
         p3->coefficient = p1->coefficient+p2->coefficient;
         p1 = p1->next;
         p2 = p2->next;
      }
      p3->next = (struct node *)malloc(sizeof(struct node));
      p3 = p3->next;
      p3->next = NULL;
// =======================================new node created==========================

 while(p1->next || p2->next){         //loop while both of them become NULL
//  ====================same code as above is repeated=================================
       if(p1->power>p2->power){
         p3->power=p1->power;
         p3->coefficient = p1->coefficient;
         p1 = p1->next;
      }
    
    //   if polynomial2 has higher degree
      else if(p1->power < p2->power){
         p3->power = p2->power;
         p3->coefficient = p2->coefficient;
         p2 = p2->next;
      } 
      
      else {
         p3->power = p1->power;
         p3->coefficient = p1->coefficient+p2->coefficient;
         p1 = p1->next;
         p2 = p2->next;
      }
      p3->next = (struct node *)malloc(sizeof(struct node));
      p3 = p3->next;
      p3->next = NULL;
  
}}

}


// function to add to polynomials
void sub_poly(struct node* p1, struct node *p2, struct node *p3){
    // if polynomial1 has higher degree.
    while(p1->next && p2->next){
      if(p1->power>p2->power){
         p3->power=p1->power;
         p3->coefficient = p1->coefficient;
         p1 = p1->next;
      }
    
    //   if polynomial2 has higher degree
      else if(p1->power < p2->power){
         p3->power = p2->power;
         p3->coefficient = -p2->coefficient;
         p2 = p2->next;
      } 
      
      else {
         p3->power = p1->power;
         p3->coefficient = p1->coefficient-p2->coefficient;
         p1 = p1->next;
         p2 = p2->next;
      }

      p3->next = (struct node *)malloc(sizeof(struct node));
      p3 = p3->next;
      p3->next = NULL;


 while(p1->next || p2->next){         //loop while both of them become NULL
//  ====================same code as above is repeated=================================
       if(p1->power>p2->power){
         p3->power=p1->power;
         p3->coefficient = p1->coefficient;
         p1 = p1->next;
      }
    
    //   if polynomial2 has higher degree
      else if(p1->power < p2->power){
         p3->power = p2->power;
         p3->coefficient = -p2->coefficient;
         p2 = p2->next;
      } 
      
      else {
         p3->power = p1->power;
         p3->coefficient = p1->coefficient-p2->coefficient;
         p1 = p1->next;
         p2 = p2->next;
      }
      p3->next = (struct node *)malloc(sizeof(struct node));
      p3 = p3->next;
      p3->next = NULL;
  
}}

}
// function to calculate the value of polynomial at x
void calculate(struct node *p,int x){
    int sum=0;
    while(p->next!=NULL){
        sum=sum+p->coefficient*pow(x,p->power);
        p=p->next;
    }
    printf("%d",sum); 
}



// main function -- execution starts from here
int main()
{   int x;
    int testcase; 
    scanf("%d",&testcase);
    while(testcase--)
    {
        int degree1,degree2;       //to store highest power of the two polynomials respectively.
       
// ===============================================================
        int i=0;                      //iterator to store values in the array.
        scanf("%d",&degree1);      
        degree1++;
        int poly1[degree1];
        int max_deg1=degree1;
        while ((degree1)--)
        {   
            scanf("%d",&poly1[i++]);  //this stores the coefficients of polynomial 1.
        }
        create_list(&p1,poly1,max_deg1);
// ==============================================================
        i=0;                          //iterator to store values in the array.
        scanf("%d",&degree2);
        degree2++;
        int poly2[degree2];
        int max_deg2=degree2;
        while ((degree2)--)
        {   
            scanf("%d",&poly2[i++]);   //this stores the coefficients of polynomial 2.
        }
        
        create_list(&p2,poly2,max_deg2);
        scanf("%d",&x);
       
      
       
// with this, two linked lists representing polynomials have been created.
//===================================================================   
//display part
printf("P1(x) : ");  
display(p1);
printf("\n");
printf("P2(x) : ");
display(p2);
printf("\n");
p3=(struct node*)malloc(sizeof(struct node));
add_poly(p1,p2,p3);
printf("P3(x) = P1(x) + P2(x) : ");
display(p3);
printf("\n");
p4=(struct node*)malloc(sizeof(struct node));
sub_poly(p1,p2,p4);
printf("P4(x) = P1(x) - P2(x) : ");
display(p4);
printf("\n");
printf("P1(%d) = ",x);
calculate(p1,x);
printf("\n");
printf("P2(%d) = ",x);
calculate(p2,x);
printf("\n");
printf("P3(%d) = ",x);
calculate(p3,x);
printf("\n");
printf("P4(%d) = ",x);
calculate(p4,x);
if (testcase!=0)     //done so that a newline does not occur at the last testcase
printf("\n");
}}
