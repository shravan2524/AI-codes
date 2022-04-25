import java.util.Scanner;
public class suduko{
static boolean solvesuduku(int[][]board){
for(int i=0;i<9;i++){
for(int j=0;j<9;j++){
if(board[i][j]==0){
for(int num=1;num<=9;num++){
if(isvalid(board,i,j,num)){
board[i][j]=num;
if(solvesuduku(board)){
return true;
}
else{
board[i][j]=0;
}
}
}
return false;
}
}
}
return true;
}
static void printsuduku(int[][]board){
System.out.println("SolvedSuduku");
for(int i=0;i<9;i++){
for(int j=0;j<9;j++){
System.out.print(board[i][j]+"");
}
System.out.println();
}
}
static boolean isvalid(int[][]board,int row,int col,int num){
return!IsInBOX(board,row,col,num)&&!IsInColumn(board,col,num)&&!IsInRow(board,row,num);
}
static boolean IsInBOX(int[][]board,int row,int col,int num){
int newrow=row-row%3;
int newcol=col-col%3;
for(int i=newrow;i<newrow+3;i++){
for(int  j=newcol;j<newcol+3;j++){
if(board[i][j]==num){
return true;
}
}
}
return false;
}
static boolean IsInColumn(int[][]board,int col,int num){
for(int i=0;i<9;i++){
if(board[i][col]==num){
return true;
}
}
return false;
}
static boolean IsInRow(int[][]board,int row,int num){
for(int j=0;j<9;j++){
if(board[row][j]==num){
return true;
}
}
return false;
}
public static void main(String[]args){
Scanner s=new Scanner(System.in);
int[][]board=new int[9][9];
System.out.println("Enterinitialsuduku");
for(int i=0;i<9;i++){
for(int j=0;j<9;j++){
board[i][j]=s.nextInt();
}
}
if(solvesuduku(board)){
importjava.util.Scanner;
publicclasssuduku{
staticbooleansolvesuduku(int[][]board){
for(inti=0;i<9;i++){
for(intj=0;j<9;j++){
if(board[i][j]==0){
for(intnum=1;num<=9;num++){
if(isvalid(board,i,j,num)){
board[i][j]=num;
if(solvesuduku(board)){
returntrue;
}
else{
board[i][j]=0;
}
}
}
returnfalse;
}
}
}
returntrue;
}
staticvoidprintsuduku(int[][]board){
System.out.println("SolvedSuduku");
for(inti=0;i<9;i++){
for(intj=0;j<9;j++){
System.out.print(board[i][j]+"");
}
System.out.println();
}
}
staticbooleanisvalid(int[][]board,introw,intcol,intnum){
return!IsInBOX(board,row,col,num)&&!IsInColumn(board,col,num)&&!IsInRow(board,row,num);
}
staticbooleanIsInBOX(int[][]board,introw,intcol,intnum){
intnewrow=row-row%3;
intnewcol=col-col%3;
for(inti=newrow;i<newrow+3;i++){
for(intj=newcol;j<newcol+3;j++){
if(board[i][j]==num){
returntrue;
}
}
}
returnfalse;
}
staticbooleanIsInColumn(int[][]board,intcol,intnum){
for(inti=0;i<9;i++){
if(board[i][col]==num){
returntrue;
}
}
returnfalse;
}
staticbooleanIsInRow(int[][]board,introw,intnum){
for(intj=0;j<9;j++){
if(board[row][j]==num){
returntrue;
}
}
returnfalse;
}
publicstaticvoidmain(String[]args){
Scanners=newScanner(System.in);
int[][]board=newint[9][9];
System.out.println("Enterinitialsuduku");
for(inti=0;i<9;i++){
for(intj=0;j<9;j++){
board[i][j]=s.nextInt();
}
}
if(solvesuduku(board)){
printsuduku(board);
}
else{
System.out.println("Sudukuunsolvable");
}
}
}(board);
}
else{
System.out.println("Sudukuunsolvable");
}
}
}