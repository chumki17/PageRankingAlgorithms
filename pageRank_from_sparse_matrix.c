#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
//The demo graph in matrix form// 
float a[17][17]={{0,0.25,0.25,0.25,0.25,0.25,0.25,0.25,0.125,0.125,1,1,1,1,1,1,1},
                 {0.111,0,0,0,0,0,0,0,0.125,0.125,0,0,0,0,0,0,0},
                 {0.111,0.333,0.333,0.333,0.333,0.333,0.333,0.333,0,0,0,0,0,0,0,0,0}, 
                 {0.111,0.333,0.333,0.333,0.333,0.333,0.333,0.333,0,0,0,0,0,0,0,0,0}, 
                 {0,0.333,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
                 {0,0,0.333,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0.333,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0.333,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0.333,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0.333,0,0,0,0,0,0,0,0,0} };
     //The initial assignment of ranks//
      float rank[17]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
       //The random surfer model effect //
       float d_minus=0.15;
       float d=0.85;
        //To store page ranks //
        float page_rank[17]; 
        //Loop variables//
         int i,j; 
         //This function copies the previous ranks into the next step for iterative purposes//
          void copy() {
          for(i=0;i<17;i++)
          rank[i]=page_rank[i]; }
//This function computes the page ranks //
void cal_rank(){
      int k,cnt;
      cnt=0;
      printf("\n The values are as: \n");
 do{
      for(i=0;i<17;i++)
       {page_rank[i]=0; 
       for(k=0;k<17;k++) 
       page_rank[i]+=a[i][k]*rank[k]; }
for(i=0;i<17;i++)
 page_rank[i]=(d*page_rank[i])+d_minus; 
 copy();
 cnt=cnt+1; }while(cnt<40);
  for(i=0;i<17;i++)
   printf("\n %f",page_rank[i]); 
}
main()
{ 
cal_rank(); 
system ("PAUSE");
}
