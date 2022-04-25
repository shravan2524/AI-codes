#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>


void next_move(int posr, int posc, char board[5][5])
 {  
     int i,j,c=0,l,r,u,d,cl=0;
     l=r=u=d=0;
    while(c<=25)
    {
          if(board[posr][posc]=='d')
          { printf("CLEAN\n"); cl=1; } 
          board[posr][posc]='v'; //marking visited cell
//          posr, posc checks whether  my bot is going out of the matrix or not
          if(posc < 4 && !l && board[posr][posc+1] != 'v') //check for rigth
              r=1;
          else if(posr < 4 && !u  && board[posr+1][posc] != 'v') // check for up
              d=1;
          else if(posc>0 && !r && board[posr][posc-1] != 'v') // check for left
              l=1;
          else  if(!d && board[posr-1][posc] != 'v') // check for down
              u=1;
       
        if(l==1 )
         {  printf("LEFT\n");  --posc; }
        else if(r==1 )
         {  printf("RIGHT\n");  ++posc; }
        else if(u==1  )
         {  printf("UP\n");  --posr; }
        else if(d==1 )
         {  printf("DOWN\n");  ++posr; }
        ++c;
        if(posc==4 || board[posr][posc+1] == 'v')  r=0; 
         if(posc==0 || board[posr][posc-1] == 'v') l=0; 
         if(posr==4 || board[posr+1][posc] == 'v') d=0;
         if(posr==0 || board[posr-1][posc] == 'v') u=0;  
        cl=0;
      }  
}

int main(void) {
    int x,y, i;
    char board[5][5], line[6];
//    taking inputs from the user
    scanf("%d", &x);
    scanf("%d", &y);
    for(i=0; i<5; i++) {
        scanf("%s[^\\n]%*c", line);
        strncpy(board[i], line, 5);
    }
    
    next_move(x, y, board); // calls the next_move funtion
    return 0;
}
