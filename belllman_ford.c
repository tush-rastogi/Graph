#include<stdio.h>
#include<stdlib.h>
int queue[100];
int front=-1;
int end=-1;
#define MAX 100
void enqueue(int);
int dequeue();
int n,v;
void create_graph();
void bellman_ford();
int pathlength[100];
int predecessor[100];
int inqueue[100];
void shortestpath(int);
int adj[100][100];
int main()
{
        
              
             printf("Enter the number of vertices");
             scanf("%d",&n);

             create_graph();
              
             bellman_ford();

          int i;
          for(i=0;i<n;i++)
          {
             
             printf("\nShortest distance from %d to %d is %d\n",v,i,pathlength[i]);
              shortestpath(i);
             
          }

}


void create_graph()
{
      int origin,destination;
      
       int max=n*(n-1);
       
         int i;
         printf("Enter -1 -1 to exit\n");
         
         for(i=1;i<=max;i++)
         {
               printf("Enter origin and destination\n");
             scanf("%d%d",&origin,&destination);
             
                if(origin==-1&&destination==-1)
                  break;
                
                printf("Enter edge weight");
                 int w;
                 scanf("%d",&w);
                 
                 adj[origin][destination]=w;
         
         }
}

 void bellman_ford()
 {
 
        int i,k=0;
        for(i=0;i<n;i++)
        {
           pathlength[i]=99999;
           predecessor[i]=-1; 
           inqueue[i]=0;
        }
 
         printf("Enter the source vertex");
          scanf("%d",&v);
          
            pathlength[v]=0;
            enqueue(v);
            inqueue[v]=1;
             while(front!=-1)
             {
             
                int a=dequeue();
                
                 inqueue[a]=0;
                 
                   if(v==a)
                     k++;
                     
                     if(k>n)
                     {
                       printf("Negative cycle reachable from source vertex");
                       exit(1);
                     
                     }
                  for(i=0;i<n;i++)
                  {
                     
                      if(adj[a][i]!=0)
                      {
                      
                         if(pathlength[a]+adj[a][i]<pathlength[i])
                            {
                             pathlength[i]=pathlength[a]+adj[a][i];
                               predecessor[i]=a;
                               
                                if(inqueue[i]==0)
                                {
                                  enqueue(i);
                                  inqueue[i]=1;
                                
                                }
                               
                             }
                          
                      
                      }
                  
                  
                  
                  
                  }
             
             
             }
         
}

void enqueue(int v)
{
   
    if(front==0&&end==MAX-1)
      {
        printf("Queue Overflow\n");
          return ;
      }
 
 
   if(front==-1)
    {
      front=0;
      end=0;
       queue[end]=v;
    }
   
      else
      {
         end++;
         queue[end]=v;
      }

}

 int dequeue()
 {
 
       if(front==-1)
       {
          printf("Queue Underflow\n");
            return -1;
       
       }
 
          int y=queue[front];
             if(front==end)
             {
                front=-1;
                end=-1;
             }
          
            else
            front++;
            
             return y;
 
}

void shortestpath(int i)
{
   if(i==-1)
    return;
    
    shortestpath(predecessor[i]);
      
      
     printf("%d ->",i);

}
