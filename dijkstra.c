// Implementation of dijkstra algorithm in C
#include<stdio.h>
#include<stdlib.h>
int adj[100][100];
void create_graph();
int n;
int v;
int pathlength[100];
int predecessor[100];
int status[100];
int mintemp();
void shortestpath(int);
void dijkstra();
int main()
{
    printf("Enter the number of vertices");
    scanf("%d",&n);

     create_graph();

      dijkstra();
  
     
                  for(int i=0;i<n;i++)
                  {
                     printf("Shortest distance from %d to %d is %d\n",v,i,pathlength[i]);
                       printf("Shortest path\n");
                     shortestpath(i);
                      printf("\n");
                      
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


void dijkstra()
{

      int i;
      for(i=0;i<n;i++)
       {
       pathlength[i]=99999999;
         predecessor[i]=-1;
          status[i]=0;
      } 
          
       printf("Enter the source vertex"); 
       scanf("%d",&v);
       
         pathlength[v]=0;
            
             
             while(1)
             {
                int a=mintemp();
               if(a==-1)
                 break;
               
            status[a]=1;
            
            for(i=0;i<n;i++)
            {
               if(adj[a][i]!=0&&status[i]==0)
               {
               
                   if(pathlength[a]+adj[a][i]<pathlength[i])
                     {
                       pathlength[i]=pathlength[a]+adj[a][i];
                         predecessor[i]=a;
                     
                     }
               }
            
            }
          }

}

int mintemp()
{
    int i;
     int min=99999999;
        int k=-1;
       for(i=0;i<n;i++)
       {
          if(status[i]==0&&pathlength[i]<min)
            {
               min=pathlength[i];
               k=i;
            }
       
       }


    return k;

}

void shortestpath(int v)
{

     if(v==-1)
       return;
       
           
         shortestpath(predecessor[v]);
         
          printf("%d ->",v);



}

