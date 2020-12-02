
#include <bits/stdc++.h>
using namespace std;



int type(int i, int j, int arrival[], int departure[])
{
 
 if(arrival[i] > arrival[j] && departure[i] < departure[j])
 return 2;
 if(arrival[i] < arrival[j] && departure[i] > departure[j])
 return 3;
 if(arrival[i] > arrival[j] && departure[i] > departure[j])
 return 4;
 else 
 return 0;
}


void DFS(int adj[][100],int d,int v,int s)
{
  vector<bool> visited(v, false); 
  
   
     
    int tree_edges=0;
    int back_edges=0;
    int cross_edges=0;
    int forward_edges=0;
    stack<int> stack; 
    int arrival[v];
    for(int i=0;i<v;i++)
    arrival[i]=0;
    int departure[v];
    for(int i=0;i<v;i++)
    departure[i]=0;
    
    int t=0;

    int first=0;
    stack.push(s); 
    vector<int> one_time(v, false); 
   
    int count;
    while (!stack.empty()) 
    { 
        s = stack.top(); 
       
        if(arrival[s]==0)
        {arrival[s]=++t;
        }
       
         if(one_time[s]==true)
        stack.pop();
       
        one_time[s]=true;
        
       
        if (!visited[s]) 
        { 
          
            visited[s] = true;
            
             
        } 
        count=0;
      
        for(int i=0;i<v;i++)
            if (!visited[i]&&adj[s][i]==1) 
                {
                 
                 stack.push(i);
                 count++;
                 if(d==0)
                 {
                  adj[s][i]=0;
                  adj[i][s]=0;
                 }
                 
                 if(d==1)
                 {
                  adj[s][i]=0;
                 }
                 tree_edges++;
                 break;
                }
       
       
       
       if(count==0&&departure[s]==0)
       {
        departure[s]=++t;
       
       }
     
                
    }

    
    int ans;
    for(int i=0;i<v;i++)
    for(int j=0;j<v;j++)
    if(adj[i][j]==1)
    {
     ans=0;
     ans=type(i,j,arrival,departure);
     
     if(ans==2)
     back_edges++;
     if(ans==3)
     forward_edges++;
     if(ans==4)
     cross_edges++;
   
     
    }
    
    cout<<departure[0]<<" ";
     if(d==1)
    cout<<tree_edges<<" "<<back_edges<<" "<<forward_edges<<" "<<cross_edges<<" ";
    
    else
    cout<<tree_edges<<" "<<back_edges;
}
// ================================================================

int checker[100];
int min_distance_vertex(int n,int dist[], bool visited[]) 
{ 
    int min = INT_MAX, index; 
    
    for (int v = 0; v < n; v++) 
        if (visited[v] == false && dist[v] < min) 
            {
			min = dist[v];
			index = v;
		    }
    checker[index]=min;
  
    return index; 
} 
void mine_dijkstra(int n, int src, int adj[][100]) 
{ 
    int dist[n]; 
    bool visited[n];
    for (int i = 0; i < n; i++) 
        dist[i] = INT_MAX; 
    for (int i = 0; i < n; i++) 
    visited[i] = false; 
    dist[src-1] = 0; 
    for (int count = 0; count < n - 1; count++) { 
        int u = min_distance_vertex(n,dist,visited); 
         visited[u] = true;
        for (int v = 0; v < n; v++) 
           if (!visited[v] && adj[u][v] && dist[u] != INT_MAX && dist[u] + adj[u][v] < dist[v])  
            {dist[v] = dist[u] + adj[u][v]; 
            
            }
    } 
      
     int cycle_mil_gayi=0;
     
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i]!=INT_MAX && adj[i][j] && dist[j] > (dist[i] + adj[i][j]) ){
                    {
                     if(visited[j]!=false&&visited[i]!=false)
                     cycle_mil_gayi=1;
                     
                    }
                   
                }
            }
        }
    
    if(cycle_mil_gayi==0)
    {for (int i = 0; i < n; i++) 
    if(dist[i]==INT_MAX)
    dist[i]=99999;
    for (int i = 0; i < n; i++) 
        printf("%d ", dist[i]); }
        
    else
    cout<<"-1";
} 
 // ==============================================================
int relax_performed=0;
int nahi_karna=0;
int relax_that_brought_changes;
void mine_bellman_ford(int source, vector<vector<int> > &adj){
    int n = adj.size();
    vector<int> distance_from_source(n, INT_MAX);
    relax_that_brought_changes=0;
   
    distance_from_source[source] = 0;
    for(int k = 0; k < n-1; k++){
        int change=0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
         
                if(distance_from_source[i] != INT_MAX && adj[i][j] && distance_from_source[j] > (distance_from_source[i] + adj[i][j]) )
                    {
                     distance_from_source[j] = distance_from_source[i] + adj[i][j];
                     relax_that_brought_changes++;
                     relax_performed++;
                     change=1;
                    }
            
            if(distance_from_source[i]!=INT_MAX && adj[i][j])           
            relax_performed++;
                 
            }
              
            
        }
        if(change==0)
            break;
        
    }


    int cycle_mil_gayi=0;
   
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(distance_from_source[i]!=INT_MAX && adj[i][j] && distance_from_source[j] > (distance_from_source[i] + adj[i][j]) ){
                    {
                     cycle_mil_gayi=1;
                     nahi_karna=1;
                     break;
                    }
                   
                }
            }
        }
    
    if(cycle_mil_gayi==0)
    {for(int i = 0; i < n; i++)
       if(distance_from_source[i]==INT_MAX)
         cout<<"999999 ";
       else
         cout << distance_from_source[i]<<" ";}
    else
    cout<<"-1 ";
    return ;
}
// =====================================================

int cross_or_back(int v,int vertex1, int vertex2, int parent[], int parent_exists[])
{
 
 int flag=0;
 int temp=vertex2;
 while(parent_exists[vertex2])
 {
  if(vertex2==vertex1)
  {
   flag=1;
  }
  vertex2=parent[vertex2];
  
 }
 
 vertex2=temp;
 while(parent_exists[vertex1])
 {
  if(vertex1==vertex2)
  {
   flag=1;
  }
  vertex1=parent[vertex1];
  
 }

  if(flag==1)
 {return 1;}
 else
 {return 0;}
}

void BFS(int adj[][100],int d,int v,int start)
{
    vector<bool> visited(v, false); 
    vector<int> queue; 
    queue.push_back(start); 
  
   
    visited[start] = true; 
    int result[100];
    int vis; 
    int index=0;
    int edges=0;
    int indegree[v];
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
          if(adj[i][j]==1)
           {edges++;
           }
    if (d==0)
    edges=edges/2;
    int parent[v];
    int parent_exists[v];
    int sum=0;
    parent[0]=-1;
    parent_exists[0]=0;
    while (!queue.empty()) { 
        vis = queue[0];  
       
       
        queue.erase(queue.begin()); 
        int push_times=0;
    
        for (int i = 0; i < v; i++) { 
            if (adj[vis][i] == 1 && (!visited[i])) { 
  
                queue.push_back(i); 
                adj[vis][i]=0;
                visited[i] = true; 
                push_times++;
                
                parent[i]=vis;
                parent_exists[i]=1;
                adj[vis][i]=0;
                adj[i][vis]=0;
            } 
        }
    result[index++]=push_times;
    }
    

    for(int i=0;i<index;i++)
    sum=sum+result[i];
    int forward_edges=0;
    int cross_edges=0;
    int back_edges=0;
    int tree_edges=0;
    int ans;
    
    
     for(int i=0;i<v;i++)
    for(int j=0;j<v;j++)
    {
    ans=-1;
    if (adj[i][j]==1)
    ans=cross_or_back(v,i,j,parent,parent_exists);
    if(ans==0)
    cross_edges++;
    
    else 
    if(ans==1)
    back_edges++;
    }
   
       
    if(d==0)
    {cross_edges=cross_edges/2;
    back_edges=back_edges/2;}
    
  
    tree_edges=sum;
    int flag=0;
    
    for(int i=0;i<index-1;i++)
    {   if(result[i]!=0)
        cout<<result[i]<<" ";
        if(result[i]==0)
        {flag++;}
        if (flag==v-1)
        break;
    }
    cout<<"0 ";
    if(d==1)
    cout<<tree_edges<<" "<<back_edges<<" "<<forward_edges<<" "<<cross_edges<<" ";
    
    else
    cout<<tree_edges<<" "<<cross_edges; 
    
   
}

void topological(int indeg[], int n, int arr[][100])
{
 int tops[n];
 int visit[n];
 for(int i=0;i<n;i++)
 visit[i]=0;
 int k=0;
 vector<int> queue;
 for(int i=0;i<n;i++)
      if (indeg[i]==0)
      {queue.push_back(i);
      visit[i] = 1; }
  int node;    
  while(!queue.empty())
        { node = queue.front();
          queue.erase(queue.begin());
          tops[k++]=node+1;
        for(int j=0;j<n;j++)
             if (arr[node][j]==1 && visit[j]==0)
                    {indeg[j] = indeg[j] - 1;
                    arr[node][j]=0;
                       if (indeg[j] == 0)
                    {queue.push_back(j);
                visit[j] = 1;}}}
 int cycle_mil_gayi=0;
 for(int i=0;i<n;i++)
 for(int j=0;j<n;j++)
 if(arr[i][j]==1)
 cycle_mil_gayi=1;
 
 
  if(cycle_mil_gayi==0)                                    
 {for(int i=0;i<n;i++)
 cout<<tops[i]<<" ";
 cout<<"\n";}
 else
 cout<<"-1\n";
}

int
main ()
{ 
  int testcase;
  cin >> testcase;
  while (testcase--)
    {
      int query;
      cin >> query;
      
          if (query == 1)
	{
    
    
      int n, d, s;
	  cin >>n >> d >> s;
	  int arr[100][100];
	  for (int i = 0; i < n; i++)
	    for (int j = 0; j < n; j++)
	      {
	          cin >> arr[i][j];
	      }
	   
	   BFS(arr,d,n,s-1);
	   cout<<"\n";
    
	}
	
	
          if (query == 2)
	{
    
    
      int n, d, s;
	  cin >>n >> d >> s;
	  int arr[100][100];
	  for (int i = 0; i < n; i++)
	    for (int j = 0; j < n; j++)
	      {
	          cin >> arr[i][j];
	      }
	   
	   DFS(arr,d,n,s-1);
	    cout<<"\n";
       
	}
      
      
if(query==3)
{
 int n;
 
 cin>>n;
 int arr[100][100];
 for (int i = 0; i < n; i++)
	    for (int j = 0; j < n; j++)
	      {cin >> arr[i][j];}
	int indeg[n];
	int count;
	for (int j = 0; j < n; j++)
	  { { count=0;
	     for (int i = 0; i < n; i++)
	      if(arr[i][j]==1)
	      count++;
	   }
	   indeg[j]=count;}
	   
	   
	   
	   
	 topological(indeg,n,arr);
	   
	   }


      
      
      
      if (query == 4)
	{
      int negative=0;
	  int flag=0;
      int n, d, s;
	     cin >>n >> d >> s;
	     int arr[100][100];
	     for (int i = 0; i < n; i++)
	      for (int j = 0; j < n; j++)
	      {
	          cin >> arr[i][j];
	          
	          if(arr[i][j]==99999)
	          arr[i][j]=0;
	          if(arr[i][j]<0)
	          {
	          	negative++;
	          	
			  }
	      }
	   
	   if(negative==0)
	   mine_dijkstra (n,s,arr);
	   else
	   cout<<"-1";
	    cout<<"\n";

	}
      
    if (query == 5)
	{
    
   int flag=0;
   int n, d, s;
	  cin >>n >> d >> s;
	  vector<vector<int> > arr(n, vector<int>(n, 0));
	  for (int i = 0; i < n; i++)
	    for (int j = 0; j < n; j++)
	      {
	          cin >> arr[i][j];
	          if(arr[i][j]==999999)
	          arr[i][j]=0;
	      }
	int E;
	for (int i = 0; i < n; i++)
	    for (int j = 0; j < n; j++)
	      {
	         if(arr[i][j]!=0)
	         E++;
	      }
	    mine_bellman_ford(s-1, arr); 
	    if(nahi_karna==0)
	    {cout<<relax_performed;
	    cout<<" "<<relax_that_brought_changes;}
	    
	     cout<<"\n";
	}}
	return 0;
}
