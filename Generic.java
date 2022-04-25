import java.util.*;
class Genetic
{
// target is to obtain a solution for a+2b+3c+4d=30 
int chromosomes[][]=new int[6][4];   //6 chromosomes i.e. 6 solutions each with 4 genes ( values for a,b,c and d )
int newChromosomes[][]=new int[6][4];
double fitness[]= new double[6];
double prob[] = new double[6];
double cummulative[] = new double[6];
double randomNum[] = new double[6];
void genChromosomes()
{
int i,j;
for(i=0;i<6;++i)
  for(j=0;j<4;++j)
   {
    chromosomes[i][j]=(int)(Math.random()*30);
    }
}
void displayChromosomes()
{
int  i,j;
for(i=0;i<6;++i)
{
  for(j=0;j<4;++j)
     System.out.printf("%3d",chromosomes[i][j]);
System.out.println();
}
}

void fitnessVal()
{
int i,j;
double s=0;
for(i=0;i<6;++i)
{
fitness[i]=1.0/(1+(chromosomes[i][0]+chromosomes[i][1]*2+chromosomes[i][2]*3+chromosomes[i][3]*4-30));
}
}
void newChromosomes()
{
int i,j;
for(i=0;i<5;++i)    // to sort chromosomes in the descending order of thier fitness
  for(j=i+1;j<6;++j)
     if(fitness[i] < fitness[j])
     { 
       double t=fitness[i];  fitness[i]=fitness[j];   fitness[j]=t;
       newChromosomes[i]=chromosomes[i];
       chromosomes[i]=chromosomes[j];
       chromosomes[j]=newChromosomes[i];
}
}   
void crossOver()
{
int i,j,randm;
  for(j=0;j<3;++j)                  // j = 0,1,2    touching middle of 0,1,2,3,4,5
   {
    randm=(int)(Math.random()*3);
    for(i=0;i<4;++i)               // i=0,1,2,3
       if(i!=randm)
       {
         int temp = chromosomes[j][i];
         chromosomes[j][i]=chromosomes[5-j][i];
         chromosomes[5-j][i]=temp;
         }
    }
}
void mutate() // with 10% mutation rate
{
  int i ,j, c=0, randm1,randm2,randm;
  while(c<2)    // total genes are 24 therefore 10 % is 2 i.e. only two genes undergoes mutation
  {
  randm1=(int)(Math.random()*23+1);
  for(i=0;i<6;++i)
    for(j=0;j<4;++j)
       if(4*i+j==randm1)
        {
           randm=(int)(Math.random()*30);
           chromosomes[i][j]=randm;
         }
    ++c;
 }
}   
void displaySolution(int n )
{
System.out.printf("\na = %d  b = %d  c = %d  d = %d ",chromosomes[n][0],chromosomes[n][1],chromosomes[n][2],chromosomes[n][3]);
}
int evaluateSolution()
{
int i;
for(i=0;i<6;++i)
  if(Math.abs(chromosomes[i][0]+chromosomes[i][1]*2+chromosomes[i][2]*3+chromosomes[i][3]*4-30)<0.01)
      return i;
return -1;
}  
}

class Generic
{
public static void  main(String args[])
{
int chromeNum=0 , i,iter=1;;
Genetic g = new Genetic();
g.genChromosomes();
while((chromeNum=g.evaluateSolution())==-1 )
{
System.out.printf("\nIteration Number = %d \n",iter++);
g.displayChromosomes();
g.fitnessVal();
System.out.println("\nFit Chromosomes\n");
g.newChromosomes();
g.displayChromosomes();
g.crossOver();
System.out.println("\nAfter Crossover ");
g.displayChromosomes();
g.mutate();
System.out.println("\nAfter Mutation ");
g.displayChromosomes();
}
g.displaySolution(chromeNum);
}
}