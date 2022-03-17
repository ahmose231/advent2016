#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 5000
#define MAX 1000

void move();

int path[MAX][2];
int k=0;

int x=0;
int y=0;

int facing='N';
int distance;

void main()
{
    char line[LEN];
    fgets(line,LEN,stdin);
    char *token;
    token=strtok(line,", ");

    int turn;

    while(token!=NULL)
    {
        turn=token[0];
        token[0]='0';
        distance=atoi(token);
        
        switch(turn)
        {
            case 'R':
                switch(facing)
                {
                    case 'N':
                        facing='E';
                        move();
                        break;
                    case 'W':
                        facing='N';
                        move();
                        break;
                    case 'S':
                        facing='W';
                        move();
                        break;
                    case 'E':
                        facing='S';
                        move();
                        break;
                }
                break;
                
            case 'L':
                switch(facing)
                {
                    case 'S':
                        facing='E';
                        move();
                        break;
                    case 'E':
                        facing='N';
                        move();
                        break;
                    case 'N':
                        facing='W';
                        move();
                        break;
                    case 'W':
                        facing='S';
                        move();
                        break;
                }
                break;       
        }
        
        token=strtok(NULL,", ");
    }
    
    
    return;
}
        
        
void move()
{
    for(int i=0;i<distance;i++)
    {
    
        switch(facing)
        {
            case 'N':
                y++;
                break;
            case 'W':
                x--;
                break;
            case 'S':
                y--;
                break;
            case 'E':
                x++;
                break;
         }   
        
        for(int j=0;j<k;j++)
            if(path[j][0]==x)
                if(path[j][1]==y)
                {
                    printf("%d\n",abs(x)+abs(y));
                    exit(0);
                }
    
        path[k][0]=x;
        path[k][1]=y;

        k++;
    }
                        
    return;
}
