#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUT 10
#define SIZE 10
#define STEPMAX 100
#define PATHMAX 100
#define TARGETX 7
#define TARGETY 4
#define VALIDPATHMAX 10

int is_available();
void move();

int grid[SIZE][SIZE];

struct proto_path {
    int x[STEPMAX];
    int y[STEPMAX];
    int stepcount;
} paths[PATHMAX];

int pathcount;

int validpaths[VALIDPATHMAX];
int validpathcount;

void main()
{
    long long int n;
    for(int y=0;y<SIZE;y++)
        for(int x=0;x<SIZE;x++)
        {
            n = x*x;
            n+= 3*x;
            n+= 2*x*y;
            n+= y;
            n+= y*y;
            n+= INPUT;
            
            int count=0;
            
            while(n!=0)
            {
                if(n%2) count++;
                n=n/2;
            }
            
            if(count%2==0)
                grid[y][x]=' ';
            else
                grid[y][x]='#';
        }
        
    move(1, 1, 0);
    
    int min=SIZE*SIZE;

    for(int i=0;i<validpathcount;i++)
        if(paths[validpaths[i]].stepcount < min)
            min = paths[validpaths[i]].stepcount;
    
    min--;
    printf("total paths: %d\n",pathcount);
    printf("valid paths: %d\n",validpathcount);
    printf("minimum steps: %d\n",min);
    return;
}


int is_available(int x, int y, int path_id)
{
    if(x<0 || y<0 || x>=SIZE || y>=SIZE)
        return 0;
        
    if(grid[y][x]=='#')
        return 0;
    
    for(int i=paths[path_id].stepcount-1;i>=0;i--)
        if(paths[path_id].x[i] == x && paths[path_id].y[i] == y)
            return 0;
    
    return 1;
}
        


void move(int x, int y, int path_id)
{
    paths[path_id].x[paths[path_id].stepcount] = x;
    paths[path_id].y[paths[path_id].stepcount] = y;
    paths[path_id].stepcount++;
    
    if(x==TARGETX && y==TARGETY)
    {
        validpaths[validpathcount++]=path_id;
        return;
    }
    
    int dir[4];
    for(int i=0;i<4;i++)
        dir[i]=0;
    
    int pm[4][2];
    
    pm[0][0]=x;
    pm[0][1]=y-1;
    
    pm[1][0]=x+1;
    pm[1][1]=y;
    
    pm[2][0]=x;
    pm[2][1]=y+1;
    
    pm[3][0]=x-1;
    pm[3][1]=y;
    
    int count=0;
    for(int i=0;i<4;i++)
        if(is_available(pm[i][0], pm[i][1], path_id)) 
        {
            count++;
            dir[i]++;
        }
        

    struct proto_path temp_path;
    
    temp_path.stepcount = paths[path_id].stepcount;
    
    for(int i=0;i<paths[path_id].stepcount;i++)
    {
        temp_path.x[i] = paths[path_id].x[i];
        temp_path.y[i] = paths[path_id].y[i];
    }
    
    
    int first=1;
    int new_path_id;
    
    for(int i=0;i<4;i++)
        if(dir[i])
        {
            if(first)
            {
                first=0;
                move(pm[i][0], pm[i][1], path_id);
            }
            
            else
            {
                new_path_id = pathcount++;
                
                paths[new_path_id].stepcount = temp_path.stepcount;
                
                for(int m=0;m<temp_path.stepcount;m++)
                {
                    paths[new_path_id].x[m] = temp_path.x[m];
                    paths[new_path_id].y[m] = temp_path.y[m];
                }
                
                move(pm[i][0], pm[i][1], new_path_id);
            }
            
        }
    
    return;
}
