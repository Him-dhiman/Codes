#include <iostream>
#include <limits.h>
#include<bits/stdc++.h> 
using namespace std;

int adjacency_matrix[100][100];

vector <int> part_of_cycle;
int cycle_found=0;
// int loop(int new_i,int i,int n)
// {
 
//  if(i==new_i)
// {
//  cycle_found=1;
//  part_of_cycle.push_back(new_i+1);
//  return 1;
 
// }
//  for(int j=0;j<n;j++)
//  {
//   if(adjacency_matrix[new_i][j]==0 && cycle_found==0)
//   {
   
//    part_of_cycle.push_back(new_i+1);
//    cout<<"-edge is "<<new_i+1<<","<<j+1<<"\n";
//    loop(j,i,n);
//   }
//  }
//  return 0;
// }

// int zero_edge_cycle(int n)
// {
//  int i=0;
//  cycle_found=0; 
//  while(i!=n)
//  {
//  for(int j=0;j<n;j++)
//  {
//   if(adjacency_matrix[i][j]==0)
//   {part_of_cycle.push_back(i+1);
//    cout<<"edge is "<<i+1<<","<<j+1<<"\n";
//    loop(j,i,n);
//    cout<<"the cycle consist of nodes ";
//    for (int i=0;i<part_of_cycle.size();i++)
//    cout<<part_of_cycle[i]<<" ";
//    cout<<"\n";
   
//   }

//  }
//  i++;
//  }
// }

void edge_change(int n,int j)
{
    int minimum=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(adjacency_matrix[i][j]<minimum)
        minimum=adjacency_matrix[i][j];
    }
    if(minimum!=INT_MAX)
    {for(int i=0;i<n;i++)
    {
        if(adjacency_matrix[i][j]!=INT_MAX) 
        adjacency_matrix[i][j]=adjacency_matrix[i][j]-minimum;
    }
    }

}

int main() 
{
   int testcase;
   cin>>testcase;
  
  
   while(testcase--)
   {
       int n,m,s;
       cin>>n>>m>>s;
      
       int original[100][100];
       int flag_matrix[n][n];
       for(int i=0;i<n;i++)
       for(int j=0;j<n;j++)
       {adjacency_matrix[i][j]=INT_MAX;
        flag_matrix[i][j]=0;}
       while(m--)
       {
           int u,v,w;
           cin>>u>>v>>w;
           adjacency_matrix[u-1][v-1]=w;
           flag_matrix[u-1][v-1]=1;
       }
       
      
       
       for(int i=0;i<n;i++)
       for(int j=0;j<n;j++)
       original[i][j]=adjacency_matrix[i][j];
       // int cycle=1;
  
        for(int j=0;j<n;j++)
        edge_change(n,j);
     
        // cycle=zero_edge_cycle(n); 
    
   // for(int i=0;i<n+1;i++)
   // adjacency_matrix[i][n]=INT_MAX;
   // for(int j=0;j<n+1;j++)
   // adjacency_matrix[n][j]=INT_MAX;
   
  
    
   //  for (auto& i : part_of_cycle) { 
   
   //    for(int j=0;j<n+1;j++)
   //    {if(adjacency_matrix[i-1][j]!=INT_MAX)
   //     adjacency_matrix[n][j]=adjacency_matrix[i-1][j];}
   //    for(int k=0;k<n+1;k++)
   //    {
   //     if(adjacency_matrix[k][i-1]!=INT_MAX)
   //     adjacency_matrix[k][n]=adjacency_matrix[k][i-1];}
     
   //  } 
   
    vector <int> visited(n,0);
     vector <int> parent(n);
     vector <int> distance(n,0);
      int sum=0;
       for(int i=0;i<n;i++)
     {{for(int j=0;j<n;j++)
      if(adjacency_matrix[i][j]==0 && visited[j]==0)
      {sum=sum+original[i][j];
       parent[j]=i+1;
       visited[j]=1;
      }
     }}

     cout<<sum<<" ";
     
     int k=-1;
     distance[0]=0;
     for(int j=1;j<n;j++)
     {
      int i=j;
      k=-1;
      while(k!=s)
      {
       
       k=parent[i];
       distance[i]=distance[i]+original[k-1][i];
       i=k+1;
       
      }
     
      
     }
      for(int i=0;i<distance.size();i++)
     cout<<distance[i]<<" ";
     for(int i=0;i<parent.size();i++)
     cout<<parent[i]<<" ";
   }
} 