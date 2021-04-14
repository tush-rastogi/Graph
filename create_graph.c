// Representation of Graph Through Adjacency Matrix
#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int adj[MAX][MAX];
void create_graph();
void display();
int vertices;
void insert_edge(int ,int);
void delete_edge(int ,int);

int main()
{
              create_graph();
           
               display();
             
               int origin,dest,x;
             
              while(1)
           {
               
                 printf("Enter 1 to delete the edge\n");
                 printf("Enter 2 to add the edge\n");
                  printf("Enter 3 to exit\n"); 
                   
                   scanf("%d",&x);
                     if(x==3)
                      break;
                   
                   switch(x)
                   {
                 
                    case 1: 
                    printf("Enter the edge to be deleted source and destination\n");
                    scanf("%d%d",&origin,&dest);
                    delete_edge(origin,dest);
                      break;
                    
                   case 2:
                   printf("Enter the edge to be added source and destination\n");
                   scanf("%d %d",&origin,&dest);
                     insert_edge(origin,dest);
                       break;
                   
                   } 

              }

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
void insert_edge(int origin,int dest)
{
     
     adj[origin][dest]=1;

}
void delete_edge(int origin,int dest)
{
     
     adj[origin][dest]=0;

}
