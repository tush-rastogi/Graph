// Representation of Graph Through Adjacency Matrix
#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int adj[MAX][MAX];
void create_graph();
void display();
int vertices;
int main()
{
              create_graph();
           
               display();
          














}
void create_graph() //directed graph
{

    
    printf("Enter the number of vertices\n");
      scanf("%d",&vertices);
      
       int max_edge=vertices*(vertices-1);//directed graph

         int i,origin,dest;
         for(i=1;i<=max_edge;i++)
         {
             printf("Enter edge and origin -1 -1 to exit\n");
              
              printf("Enter origin and destination\n");
               scanf("%d%d",&origin,&dest);
               
                  if(origin==-1&&dest==-1)
                    break;
                    
                      else
                      adj[origin][dest]=1;
           
         }


}

void display(){

     int i,j;
     
        for(i=0;i<vertices;i++)
        {
          for(j=0;j<vertices;j++)
          {
            printf("%d ",adj[i][j]);
          
          }
        
           printf("\n");
        }
     

}
