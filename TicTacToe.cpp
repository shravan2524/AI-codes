#include<bits/stdc++.h>
#include<stdio.h>
#include<conio.h>
int board[9]={2,2,2,2,2,2,2,2,2};
int turn=1;
int make2()
{
int i;
if(board[4]==2)
   return 5;
for(i=1;i<=7;i+=2)
   if(board[i]==2)
       return i+1;
return -1;
}

//	Its check whether there is a possibility to win for the computer or user
int possWin(int p)  /* if p==1 ==> X  p==2 ==> 0  */
{

int i,j;
if(p==1)
{
 for(i=0;i<=8;i=i+3)                 /* for row. testing   */
   if(board[i]*board[i+1]*board[i+2]==18)
   {
     int j;
     for(j=i;j<=i+2;++j)
	if(board[j]==2)
	    return j;
   }
    for(j=0;j<=2;++j)      /* for col. testing   */
       if(board[j]*board[j+3]*board[j+6]==18)
       {
	int i;
	for(i=j;i<=j+6;i=i+3)
	if(board[i]==2)
	    return i;
	}
      if(board[0]*board[4]*board[8]==18)
      {
      int i;
      for(i=0;i<=8;i=i+4)
	 if(board[i]==2)
	     return i;
      }
      else
	if( board[2]*board[4]*board[6]==18)
	{
	 int i;
	  for(i=2;i<=6;i=i+2)
	     if(board[i]==2)
	       return i;
	 }
      else
	return -1;
    }
   else
   {
    for(i=0;i<=8;i=i+3)                 /* for row. testing   */
   if(board[i]*board[i+1]*board[i+2]==50)
   {
     int j;
     for(j=i;j<=i+2;++j)
	if(board[j]==2)
	    return j;
   }
    for(j=0;j<=2;++j)      /* for col. testing   */
       if(board[j]*board[j+3]*board[j+6]==50)
       {
	int i;
	for(i=j;i<=j+6;i=i+3)
	if(board[i]==2)
	    return i;
	}
      if(board[0]*board[4]*board[8]==50 || board[2]*board[4]*board[6]==50)
      {
      int i;
      for(i=0;i<=8;i=i+4)
	 if(board[i]==2)
	     return i;
      for(i=2;i<=6;i=i+2)
	 if(board[i]==2)
	     return i;
      }
   return -1;
 }
}
int win()
{
int i,j;
 for(i=0;i<=8;i=i+3)  /* for row. testing   */
   if(board[i]*board[i+1]*board[i+2]==125 || board[i]*board[i+1]*board[i+2]==27)
       return 1;
 for(j=0;j<=2;++j)      /* for col. testing   */
       if(board[j]*board[j+3]*board[j+6]==125 || board[j]*board[j+3]*board[j+6]==27)
	  return 1;
if(board[0]*board[4]*board[8]==125 || board[2]*board[4]*board[6]==125 || board[0]*board[4]*board[8]==27 || board[2]*board[4]*board[6]==27)
      return 1;
return 0;
}

//Its check the cell is occupied or not
int go(int p ,int n)
{
if(p==1)
{  if(board[n-1] == 2)
   {   board[n-1]=3; return 1; }
  else
      return -1;
}
else
    if(board[n-1]==2)
    {
      board[n-1]=5;  return 1; }
    else
       return -1;
}
void display()
{
int i;
printf("\n");
for(i=0;i<=8;++i)
   printf("%3d",board[i]);
printf("\n");

}
void displayBoard()
{
int i,j;
//clrscr();
for(i=0;i<=6;i=i+3)
{
  printf("___________\n");
  for(j=i;j<=i+2;++j)
      switch(board[j])
      {
       case 2 :	   printf("|%c|",' ');  break;
       case 3 :    printf("|%c|",'X');  break;
       case 5 :    printf("|%c|",'O');  break;
      }
  printf("\n");
 }
 }

int main()
{
int i,n;
while(turn<=9)
{
displayBoard();
display();

if(turn%2==1)
{
  do
  {
  printf("\nPlease mark  X at any position between  1..9 ");
  scanf("%d",&n);
//  calling the function
  if(go(1,n)==-1)
     printf("\nPOSITION ALREADY OCCUPIED , TRY AGAIN ");
  else
     break;
 }while(1);
 go(1,n);    /*   check  */
 if(turn >4 && win()==1)
	  turn = 90;
 }
 else
 {
   int pos;
   switch(turn)
   {
   case 2 :if(board[4]==2)
	      go(2,5);
	   else
	      go(2,1);
	   break;
   case 4 :if((pos=possWin(1)) != -1 )
		      go(2,pos+1);
	    else
		 go(2,make2());
	    break;
   case 6 : if((pos=possWin(2)) != -1 )
	     {	go(2,pos+1);   turn =100; }
	    else
	       if((pos=possWin(1)) != -1)
		  go(2,pos+1);
		else
		  go(2,make2());
	    break;
   case 8 : if((pos=possWin(2)) != -1 )
	      {	      go(2,pos+1);  turn=100 ; }
	    else
	      if((pos=possWin(1)) != -1 )
		      go(2,pos+1);
	       else
		  {
		    int i;
		    for(i=0;i<=8;++i)
		      if(board[i]==2)
			 {  go(2,i);  break ; }
		   }
	     break;
     }
   }
   display();
   ++turn;
  }
 displayBoard();
 display();
  if(turn==91)
      printf("\nCongrats you won ");
   else
       if(turn==101)
	   printf("\n COMPUTER WINS ");
   else
       printf("\n match DRAWN ");
 getch();
 }

