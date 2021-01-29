#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
int width=30;
int height=30;
int x,y,fruitx,fruity,score,flag,gameover=0;
int tailx[100];
int taily[100];
int countTail=0;
void setup()
{
    gameover=0;
    x=width/2;
    y=height/2;
    label1:
    fruitx=rand()%20;
    if(fruitx==0)
      goto label1;
    label2:
    fruity=rand()%20;
    if(fruity==0)
      goto label2;
    score=0;
}
void display()
  {
    int i,j;
    system("@cls||clear");
    for(i=0;i<width;i++)
    {
      for(j=0;j<height;j++)
      {
        if(i==0 || i==height-1 || j==0 || j==width-1)
          printf("*");
        else{
          if(i==x && j==y)
            printf("O");
          else if(i==fruitx && j==fruity)
            printf("F");
          else
          {
              int z=0;
              for(int k=0;k<countTail;k++)
              {
                  if(i==tailx[k] && j==taily[k]){
                    printf("o");
                    z=1;
                  }
              }
              if(z==0)
                printf(" ");
          }
        }
      }
      printf("\n");
    }
    printf("SCORE: %d\n",score);
  }
void input()
{
    if(kbhit())
    {
        switch(getch())
        {
        case 'a':
          flag=1;
          break;
        case 'd':
          flag=2;
          break;
        case 's':
          flag=3;
          break;
        case 'w':
          flag=4;
          break;
        case 'x':
          gameover=1;
          break;
        }
    }
}
void makelogic()
{
    int prevx=tailx[0];
    int prevy=taily[0];
    int prev2x,prev2y;
    tailx[0]=x;
    taily[0]=y;
    for(int i=1;i<countTail;i++)
    {
        prev2x=tailx[i];
        prev2y=taily[i];
        tailx[i]=prevx;
        taily[i]=prevy;
        prevx=prev2x;
        prevy=prev2y;
    }
    switch(flag)
    {
      case 1:
        y--;
        break;
      case 2:
        y++;
        break;
      case 3:
        x++;
        break;
      case 4:
        x--;
        break;
      default:
        break;
    }
    if(x<0 || x>width-1 || y<0 || y>height-1)
        gameover=1;
    for(int j=0;j<countTail;j++){
            if(x==tailx[j] && y==taily[j])
            {
                gameover=1;
            }
    }
    if(x==fruitx && y==fruity)
    {
    label3:
    fruitx=rand()%20;
    if(fruitx==0)
      goto label3;
    label4:
    fruity=rand()%20;
    if(fruity==0)
      goto label4;
      score+=5;
      countTail++;
    }
}
int main()
{
    char ch;
    label5:
        setup();
        while(!gameover)
            {
                display();
                input();
                makelogic();
                for(int i=0;i<5000;i++)
                for(int j=0;j<5000;j++){}
            }
    printf("Press Y to Play Again: ");
    scanf("%c",&ch);
    if(ch=='y' || ch=='Y')
        goto label5;
    return 0;
}
