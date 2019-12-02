#include <stdio.h>

int main()
{
	int sum=0;
	int c;
	int x,y;
	top:
		c=getchar();
		if(c=='\n')
			goto top;
		if(c==EOF)
			goto next;
		if(c=='(')
		{
			c=getchar();
			x=c-'0';
			c=getchar();
			while(c!='x')
			{
				x=x*10;
				x=x+c-'0';
				c=getchar();
			}
			
			c=getchar();
			y=c-'0';
			c=getchar();
			while(c!=')')
			{
				y=y*10;
				y=y+c-'0';
				c=getchar();
			}
			
			for(int i=0;i<x;i++)
				c=getchar();
			sum=sum+(x*y);
		}
		else
			sum++;
		goto top;
	
	next:
	
	printf("%d\n",sum);
	return 0;
}
