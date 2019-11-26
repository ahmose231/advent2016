#include <stdio.h>
#include <stdlib.h>

int main()
{	
	int x=0;
	int y=0;
	int c,d;
	int k;
	int facing='n';
	
	c='a';

	top:
		if(c==EOF||c=='\n')
			goto next;
		c=getchar();
		if(c=='R'||c=='L')
		{
			d=getchar();
			k=d-'0';
			d=getchar();
			while(d!=',' && d!='\n' && d!=EOF)
			{
				k=k*10;
				k=k+d-'0';
				d=getchar();
			}
			switch(facing)
			{
				case 'n':
					if(c=='R')
					{
						facing='e';
						x=x+k;
					}
					else
					{
						facing='w';
						x=x-k;
					}
					break;
				
				case 's':
					if(c=='R')
					{
						facing='w';
						x=x-k;
					}
					else
					{
						facing='e';
						x=x+k;
					}
					break;
					
				case 'e':	
					if(c=='R')
					{
						facing='s';
						y=y-k;
					}
					else
					{
						facing='n';
						y=y+k;
					}
					break;				
					
				case 'w':
					if(c=='R')
					{
						facing='n';
						y=y+k;
					}
					else
					{
						facing='s';
						y=y-k;
					}
					break;
			}
		}
		c=getchar();
		goto top;
	
	next:
	
	printf("%d\n",abs(x)+abs(y));
	return 0;
}
