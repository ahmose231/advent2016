#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int screen[50][6];
	int i,j;
	for(i=0;i<50;i++)
		for(j=0;j<6;j++)
			screen[i][j]=0;
	char line[64];
	char *token,*token2;
	int x,y;
	int a,b;
	int temp;
	while(fgets(line,64,stdin)!=NULL)
	{
		token=strtok(line," ");
		switch(token[1])
		{
			case 'e':
				token=strtok(NULL," ");
				x=atoi(strtok(token,"x"));
				y=atoi(strtok(NULL,"x"));
				for(i=0;i<x;i++)
					for(j=0;j<y;j++)
						screen[i][j]=1;
				break;
			
			case 'o':
				token=strtok(NULL," ");
				switch(token[0])
				{
					case 'r':
						token2=strtok(NULL," ");
						token=strtok(NULL," ");
						b=atoi(strtok(NULL," "));
						
						token=strtok(token2,"=");
						a=atoi(strtok(NULL,"="));
						
						for(i=0;i<b;i++)
						{
							temp=screen[49][a];
							for(j=48;j>=0;j--)
								screen[j+1][a]=screen[j][a];
							screen[0][a]=temp;
						}
						
						break;
						
					case 'c':
						token2=strtok(NULL," ");
						token=strtok(NULL," ");
						b=atoi(strtok(NULL," "));
						
						token=strtok(token2,"=");
						a=atoi(strtok(NULL,"="));
						
						for(i=0;i<b;i++)
						{
							temp=screen[a][5];
							for(j=4;j>=0;j--)
								screen[a][j+1]=screen[a][j];
							screen[a][0]=temp;
						}
				}
				break;
		}
	}
	
	int total=0;
	for(i=0;i<50;i++)
		for(j=0;j<6;j++)
			if(screen[i][j])
				total++;
	printf("%d\n",total);
	return 0;
}
