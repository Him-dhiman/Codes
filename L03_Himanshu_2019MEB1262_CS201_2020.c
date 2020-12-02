
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// -------------BINARY TREE NODE---------------------
struct Node
{
    struct Node* left;
    int data;
    int height;
    struct Node* right;
}*root=NULL;

// ------------------HEIGHT---------------------------
int height(struct Node* p)
{
    int x,y;
    if(p==NULL)
    return 0;
    x=height(p->left);
    y=height(p->right);
    return x>y?x+1:y+1;
}


int max(int a, int b) { return (a > b)? a : b; } 


// =========================================
// ------------------SEARCHING---------------
void Search(struct Node* t,int key) {
    
    while (t != NULL){
        if (key == t->data){
            printf("Yes");
            return;
        } else if (key < t->data){
            t = t->left;
        } else {
            t = t->right;
        }
    }
    printf("No");
}

int Search_Present(struct Node* t,int key) {
    
    while (t != NULL){
        if (key == t->data){
            return 1;
        } else if (key < t->data){
            t = t->left;
        } else {
            t = t->right;
        }
    }
    return 0;
}


struct Node* Search_Node(struct Node* t,int key) {
    
    while (t != NULL){
        if (key == t->data){
            return t;
        } else if (key < t->data){
            t = t->left;
        } else {
            t = t->right;
        }
    }
    return 0;
}

void Search_Path(struct Node* t,int key) {
    char path_direction[100];
    int  path_value[100];
    int index_dir=0;
    int index_val=0;
    while (t != NULL){
        if (key == t->data){
            path_value[index_val++]=key;
            int index1=0;
            int index2=0;
            while(index1!=index_val)
            {
                printf("%d ",path_value[index1++]);
                if(index1!=index_val)
                printf("%c ",path_direction[index2++]);
            }
            return;}
        if (key < t->data){
            path_value[index_val++]=t->data;
            path_direction[index_dir++]='L';
            t = t->left;
        } else {
            path_value[index_val++]=t->data;
            path_direction[index_dir++]='R';
            t = t->right;
        }
    }
  
}

int search_lowest_ancestor(struct Node* t,int i, int j)
{   
    struct Node *temp=t;
//------------------Path of first node------------------------
    int  path_value_i[100];
    int index_val_i=0;
    while (t != NULL){
        if (i == t->data){
            path_value_i[index_val_i++]=i;
            break;
            }
        if (i < t->data){
            path_value_i[index_val_i++]=t->data;
            t = t->left;
        } else {
            path_value_i[index_val_i++]=t->data;
            t = t->right;
        }
        
    }
    
//------------------Path of second node----------------------------
t=temp;
 int  path_value_j[100];
    int index_val_j=0;
    while (t != NULL){
        if (j == t->data){
            path_value_j[index_val_j++]=j;
            break;
            }
        if (j < t->data){
            path_value_j[index_val_j++]=t->data;
            t = t->left;
        } else {
            path_value_j[index_val_j++]=t->data;
            t = t->right;
        }
    }
    
   int ans,lower;
   
   if(index_val_j<index_val_i)
   lower=index_val_i;
   else
   lower=index_val_j;
   
   int a=0;
  
   while(a!=lower-1)
   {
       
	   if(path_value_i[a]==path_value_j[a])
       ans=path_value_i[a];
       a++;
   }
   return ans;
}
// ------------------FINDING ROUTE---------------
void route(struct Node*t, int i, int j)
{
    if(Search_Present(t,i)==0)
    {printf("Source does not exist");
     return;
    }
    if(Search_Present(t,j)==0)
    {printf("Destination does not exist");
    return;}
    if(i==j)
    {printf("%d",i);
    return;}
    struct Node* source=Search_Node(t,i);
    if (Search_Present(source,j)==0)
    {   
        printf("Unreachable");
        return;
    }
    Search_Path(source,j);
    
}
// ------------------INSERTION---------------

void insert(int key)
{
    struct Node* t=root;
    struct Node* r, *p;
    
    if (root==NULL)
    {
        p=(struct Node*)malloc(sizeof(struct Node));
        p->data=key;
        p->left=p->right=NULL;
        root=p;
        return;
    }
    
    while(t!=NULL)
    {
        r=t;
        if(key<t->data)
        {t=t->left;}
        else if(key>t->data)
        {t=t->right;}
        else
        {return;}
    }
    
    p=(struct Node*)malloc(sizeof(struct Node));
    p->data=key;
    p->left=p->right=NULL;
    
    if(key<r->data)
    {r->left=p;}
    else
    {r->right=p;}
}
// ------------------PRE-ORDER-------------

void preorder(struct Node *root)
 {
   struct Node *arr[100];
   int top = 0;
 
   if (root == NULL)
   {
     return;
   }
 
   arr[top++] = root;
   while (top != 0)
   {
     root = arr[--top];
 
     printf("%d ", root->data);
 
     if (root->right != NULL)
       arr[top++] = root->right;
     if (root->left != NULL)
       arr[top++] = root->left;
   }
 }


// ------------------POSTORDER-------------
void postorder(struct Node *p)
{
    if (p)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d ",p->data);
    }
}
// ------------------INORDER---------------

void inorder(struct Node *p)
{
    if (p)
    {
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}
// ------------------LEVEL-ORDER---------------
void Level(struct Node* root, int level) 
{ 
    if (root == NULL) 
        return; 
    if (level == 1) 
        printf("%d ", root->data); 
    else if (level > 1) 
    { 
        Level(root->left, level-1); 
        Level(root->right, level-1); 
    } 
} 

void levelorder(struct Node* root) 
{ 
    int h = height(root); 
    int i; 
    for (i=1; i<=h; i++) 
        Level(root, i); 
} 
// ------------------Lowest Common Ancestor--------------
void LCA(struct Node *t, int i, int j)
{
    if (Search_Present(t,i)&&Search_Present(t,j)==0)
    {printf("-1");}
    else if(i==j)
    {printf("%d",i);}
    else
    {
        int lowest=search_lowest_ancestor(t,i,j);
        printf("%d",lowest);
    }
}


// ------------------returning Predecessor---------------
struct Node * inpre(struct Node *p)
{
    while (p&&p->right!=NULL)
    {p=p->right;}
    return p;
}
// -----------------number of nodes-------------------
int countnodes(struct Node *root)
{
     static int count=0;
    if(root != NULL)
    {
        countnodes(root->left);
        count++;
        countnodes(root->right);
    }
    return count;
}
// ------------------number of leafs---------------

int leafnodes(struct Node* root)
{
    static int count = 0;
    if(root != NULL)
    {
        leafnodes(root->left);
        if((root->left == NULL) && (root->right == NULL))
        {
            count++;
        }
        leafnodes(root->right);
    }
    return count;
 
}
// ------------------returning Successor---------------
struct Node * insuc(struct Node *p)
{
    while (p&&p->left!=NULL)
    {p=p->left;}
    return p;
}
// ------------------Diameter---------------
int diameter(struct Node * root) 
{ 
   
   if (root == NULL) 
     return 0; 
  
 
  int l_height = height(root->left); 
  int r_height = height(root->right); 

  int l_diameter = diameter(root->left); 
  int r_diameter = diameter(root->right); 
  
 
  return max(l_height + r_height + 1, max(l_diameter, r_diameter)); 
}  
// ------------------DELETING---------------
struct Node* delete_it(struct Node*p, int key)
{    
    struct Node* q;
    if(p==NULL)
    return NULL;
    
    if(p->left==NULL && p->right==NULL)
    {
        if(p==root)
        {root=NULL;}
        free(p);
        return NULL;
    }
    if(key<p->data)
    {
        p->left=delete_it(p->left,key);
    }
    else if(key>p->data)
    {
        p->right=delete_it(p->right,key);
    }
    else
    {
        if(height(p->left)>height(p->right))
        {
        q=inpre(p->left);
        p->data=q->data;
        p->left=delete_it(p->left,q->data);
        }
        else
        {
        q=insuc(p->right);
        p->data=q->data;
        p->right=delete_it(p->right,q->data); 
        }
    }
    return p;
}
// =====================printing the boundaries====================

int sum;
int q;
int array[100];
void Leaves(struct Node* root) 
{ 
  
	if (root == NULL) 
        return; 
    
    Leaves(root->right); 
    
  
    if (!(root->left) && !(root->right)) 
         {
         array[q++]=root->data;
         	sum=sum+root->data;
		 } 
  
     Leaves(root->left);
   
} 
  
void Left_Part(struct Node* root) 
{ 
    if (root == NULL) 
        return; 
  
    if (root->left) { 
    Left_Part(root->left); 
  
      array[q++]=root->data; 
        	sum=sum+root->data;
    } 
    else if (root->right) { 
    Left_Part(root->right); 
       array[q++]=root->data;
        	sum=sum+root->data;
    }  
} 
void Right_Part(struct Node* root) 
{ 
    if (root == NULL) 
        return; 
    
    if (root->right) { 
       
       
        array[q++]=root->data;
		 Right_Part(root->right); 
         	sum=sum+root->data;
    } 
    else if (root->left) { 
         	sum=sum+root->data;
        array[q++]=root->data; 
        Right_Part(root->left);
    } 
}
void Boundary(struct Node* root) 
{ 
    if (root == NULL) 
        return; 
    q=1;
    sum=0;
    
    
     
    sum=sum+root->data;
    array[q++]=root->data;
   
    
  Right_Part(root->right); 
   
   
    Leaves(root->right); 
    Leaves(root->left);
    
    
    
     Left_Part(root->left);
     
     array[0]=sum;
     
     for(int i=0;i<q;i++)
     printf("%d ",array[i]);
} 
int Width(struct Node* root, int level) 
{ 
      
  if(root == NULL) 
    return 0; 
    
  if(level == 1) 
    return 1; 
              
  else if (level > 1) 
    return Width(root->left, level-1) +  
             Width(root->right, level-1); 
} 

int getmaximum(struct Node* root) 
{ 
  int maximum = 0;    
  int width; 
  int h = height(root); 
  int i; 
    
  for(i=1; i<=h; i++) 
  { 
    width = Width(root, i); 
    if(width > maximum) 
      maximum = width; 
  }      
    
  return maximum; 
} 
  
// =====================================================================================================
// ====================================FUNCTION FOR AVL TREES(SAME AS ABOVE)===============================
// ===========================================


// ------------------BALANCE FACTOR-------------------
int BalanceFactor(struct Node *N)
{
 if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right);
}

struct Node * LLRotation(struct Node *p)
{
 struct Node *pl=p->left;
 struct Node *plr=pl->right;

 pl->right=p;
 p->left=plr;
 p->height=height(p);
 pl->height=height(pl);

 if(root==p)
 root=pl;

 return pl;
}
struct Node * LRRotation(struct Node *p)
{
 struct Node *pl=p->left;
 struct Node *plr=pl->right;

 pl->right=plr->left;
 p->left=plr->right;

 plr->left=pl;
 plr->right=p;

 pl->height=height(pl);
 p->height=height(p);
 plr->height=height(plr);

 if(root==p)
 root=plr;
 return plr;
}
struct Node * RRRotation(struct Node *p)
{
 int left_height,right_height;
 struct Node *pr=p->right;
 pr->height=0;
 p->right=pr->left;
 pr->left=p;
 left_height=height(p->left)+1;
 right_height=height(p->right)+1;
 p->height=left_height-right_height;
 if(p==root)root=pr;
 return pr;
}
struct Node * RLRotation(struct Node *p)
{
 int left_height,right_height;
 struct Node *pr=p->right;
 struct Node *prl=pr->left;
 prl->height=0;

 p->right=prl->left;
 pr->left=prl->right;
 prl->right=pr;
 prl->left=p;
 left_height=height(p->left)+1;
 right_height=height(p->right)+1;
 p->height=left_height-right_height;
 
 left_height=height(pr->left)+1;
 right_height=height(pr->right)+1;
 pr->height=left_height-right_height;
 if(p==root)root=prl;
 return prl;
}
struct Node *RInsert(struct Node *p,int key)
{
 struct Node *t=NULL;

 if(p==NULL)
 {
 t=(struct Node *)malloc(sizeof(struct Node));
 t->data=key;
 t->height=1;
 t->left=t->right=NULL;
 return t;
 }
 if(key < p->data)
 p->left=RInsert(p->left,key);
 else if(key > p->data)
 p->right=RInsert(p->right,key);

 p->height=height(p);

 if(BalanceFactor(p)==2 && BalanceFactor(p->left)==1)
 return LLRotation(p);
 else if(BalanceFactor(p)==2 && BalanceFactor(p->left)==-1)
 return LRRotation(p);
 else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==-1)
 return RRRotation(p);
 else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==1)
 return RLRotation(p);
 return p;

}
// ===================AVL delete======================

struct Node* deleteNode(struct Node* p, int key) 
{ 
    
    struct Node* q;
    if(p==NULL)
    return NULL;
   
    if(p->left==NULL && p->right==NULL)
    {
	   
		if(p==root)
        {p=NULL;}
        free(p);
        return NULL;
    }
    if(key<p->data)
    {
        p->left=deleteNode(p->left,key);
    }
    else if(key>p->data)
    {
        p->right=deleteNode(p->right,key);
    }
    else
    {
        if(height(p->left)>height(p->right))
        {
        
        q=inpre(p->left);
        p->data=q->data;
        p->left=deleteNode(p->left,q->data);
        }
        else
        {
        
        q=insuc(p->right);
        p->data=q->data;
        p->right=deleteNode(p->right,q->data); 
        }
    }
    
  
    
    if (p == NULL) 
      return p; 
  
   
    p->height = height(p); 

  if(BalanceFactor(p)==2 && (BalanceFactor(p->left)==1||BalanceFactor(p->left)==0))
 return LLRotation(p);
 else if(BalanceFactor(p)==2 && BalanceFactor(p->left)==-1)
 return LRRotation(p);
 else if(BalanceFactor(p)==-2 && (BalanceFactor(p->right)==-1||BalanceFactor(p->right)==0))
 return RRRotation(p);
 else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==1)
 return RLRotation(p);
 return p;
} 

// ===================================================

int main()
{
    int testcase;
    int AVL;
    scanf("%d",&testcase);
    while(testcase--)
    {
     
     char query;
     scanf(" %c",&query);
   
     if (query=='T')
     {
        root=NULL;
        int i=0, j=0; 
        int arr[100]; 
        char temp; 
        do { 
        scanf("%d%c", &arr[i], &temp); 
        i++; 
        } while(temp != '\n'); 
   
        AVL=0;
        for(j=0; j<i; j++) 
        {
        
         if(arr[j]!=0)
         {
          
          if(arr[j]>0)
          insert(arr[j]);
          else
          delete_it(root,-arr[j]);
         }}}
        
        
        if (query=='H')
     {
        root=NULL;
        int i=0, j=0; 
        int arr[100]; 
        char temp; 
        do { 
        scanf("%d%c", &arr[i], &temp); 
        i++; 
        } while(temp != '\n'); 
   
        AVL=1;
        for(j=0; j<i; j++) 
        {
        
         if(arr[j]!=0)
         {
          
          if(arr[j]>0)
          root=RInsert(root,arr[j]);
          else
          { 
          
          root=deleteNode(root,-arr[j]);
		  }
         }}}
        
     if (query=='A')
     {
        int i=0, j=0; 
        int arr[100]; 
        char temp; 
        do { 
        scanf("%d%c", &arr[i], &temp); 
        i++; 
        } while(temp != '\n'); 
   
        for(j=0; j<i; j++) 
        if(arr[j]!=0)
        {
        	 if(AVL==1)
			 root=RInsert(root,arr[j]);
			 else
			 insert(arr[j]);
		}
        
     }
        
    
     if (query=='U')
     {
        int i=0, j=0; 
        int arr[100]; 
        
        char temp; 
        do { 
        scanf("%d%c", &arr[i], &temp); 
        i++; 
        } while(temp != '\n'); 
        
        	
        for(j=0; j<i; j++) 
        {
         if(AVL==0)
		 delete_it(root,arr[j]);
		 else
		 {
		 	root=deleteNode(root,arr[j]);
		     
		 }
        }
      
     }
     
      if (query=='F')
     {
        int x;
        scanf("%d",&x);
        Search(root,x);
        printf("\n");
     }
     
      if (query=='Q')
     {
        printf("%d",leafnodes(root));
        printf("\n");
     }
     
      if (query=='N')
     {
        printf("%d",countnodes(root));
        printf("\n");
     }
     
     
      if (query=='P')
     {
        preorder(root);
        printf("\n");
     }
     
     
      if (query=='I')
     {
        inorder(root);
        printf("\n");
     }
     
     
	  if (query=='S')
     {
        postorder(root);
        printf("\n");
     }
     
      
	  if (query=='L')
     {
        
		levelorder(root);
        printf("\n");
     }
     
     
	  if (query=='D')
     {
        printf("%d",height(root)-1);
        printf("\n");
     }
     
     
	 if (query=='W')
     {
        printf("%d",getmaximum(root));
        printf("\n");
     }
     
     
	 if (query=='C')
     {
        int i,j;
        scanf("%d",&i);
        scanf("%d",&j);
        LCA(root,i,j);
        printf("\n");
     }
     
     
     if (query=='R')
     {
        int i,j;
        scanf("%d",&i);
        scanf("%d",&j);
        route(root,i,j);
        printf("\n");
     }
     
     
     if (query=='X')
     {
       printf("%d",diameter(root));
       printf("\n");
     }
     
     
     if (query=='Y')
     {
        Boundary(root);
        printf("\n");
     }
     
     
     
     
    
     
    }
    
    return 0;
}
