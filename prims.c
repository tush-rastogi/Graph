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
void prims();
int main()
{
    printf("Enter the number of vertices");
    scanf("%d",&n);

     
       
       create_graph();

      prims();  
      
      
         int i,cost;
         for(i=0;i<n;i++)
         {
                     if(i==v)
                       continue;
            
              printf("%d -> %d\n",predecessor[i],i);
            cost+=adj[predecessor[i]][i];
         }
       printf("Minimum cost of spanning tree is %d\n",cost);
}

void create_graph()
{
      int origin,destination;
      
       int max;
       
      
        max=(n*(n-1))/2;
        
       
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
                 
                 
                 adj[destination][origin]=w;
                   
         
         }

       


}


void prims()
{

      int i;
      for(i=0;i<n;i++)
       {
       pathlength[i]=99999999;
         predecessor[i]=-1;
          status[i]=0;
      } 
          
       printf("Enter the root vertex"); 
       scanf("%d",&v);
       
         pathlength[v]=0;
            
              int x=0; 
             while(1)
             {
                int a=mintemp();
                 
               if(a==-1)
                 {  
                     if(x==n)
                       break;
                       
                        else
                        {
                          printf("Graph is not connected so no spanning tree\n");
                           exit(1);
                        } 
                 }
               
                 x++;
            status[a]=1;
            
            for(i=0;i<n;i++)
            {
               if(adj[a][i]!=0&&status[i]==0)
               {
               
                   if(adj[a][i]<pathlength[i])
                     {
                       pathlength[i]=adj[a][i];
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

