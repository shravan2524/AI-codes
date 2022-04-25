
#include<bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
/* Head ends here */
void nextMove(int n, int r, int c, char grid[101][101]){ 

int i,j,px,py,mx,my; 
     float s; 
        for(i=0;i<=n-1;++i) 
         for(j=0;j<=n-1;++j) 
              if(grid[i][j]=='p') 
               { px=i; py=j; } 
              else  
                 if(grid[i][j]=='m') 
                 {mx=i;my=j;} 
         if(px==mx && py==my) 
             return; 

          if(py-my==0)   s=100000; 
          else   s=(px-mx)/(py-my); 

         if(fabs(s) < 1) 
         { 
             if(py-my>0) 
             { 
                 printf("RIGHT\n"); ++my; 
             } 
             else 
             { 
                 printf("LEFT\n"); --my; 
             }   
         } 
        else 
        {  
        if(px-mx>0) 
             { 
                 printf("DOWN\n"); ++mx; 
             } 
             else 
             { 
                 printf("UP\n"); --mx; 
             }  
         }  
} 

int main(void) {
 
  int n, x, y;
 
  scanf("%d", &n);
  scanf("%d", &x);
  scanf("%d", &y);
 
  char grid[101][101];
 
  for(int i=0; i<n; i++) {
    scanf("%s[^\n]%*c", grid[i]);
  }
 
  nextMove(n, x, y, grid);
  return 0;
}
