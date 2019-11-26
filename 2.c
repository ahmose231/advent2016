#include <stdio.h>
int main()
{
	int grid[3][3];
	
	int m=1;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			grid[i][j]=m++;
	
	int x,y;
	x=y=1;
	int c;
	int k=0;
	
	for(int i=0;i<4;i++)
	{
		c=getchar();
		while(c!='\n'&&c!=EOF)
		{
			
			switch(c)
			{
				case 'U':
					if(y)
						y--;
					break;
				
				case 'D':
					if(y<2)
						y++;
					break;
					
				case 'R':
					if(x<2)
						x++;
					break;
					
				case 'L':
					if(x)
						x--;
					break;
			}
			c=getchar();
		}
		k=k*10;
		k=k+grid[y][x];
	}
	
	printf("%d\n",k);
	return 0;
}
