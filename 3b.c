#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int count=0;
	int a,b,c;
	int d,e,f;
	int g,h,i;
	char *token;
	char line1[64];
	char line2[64];
	char line3[64];
	while(fgets(line1,64,stdin)!=NULL)
	{
		fgets(line2,64,stdin);
		fgets(line3,64,stdin);
		sscanf(line1,"\t%d\t%d\t%d",&a,&b,&c);
		sscanf(line2,"\t%d\t%d\t%d",&d,&e,&f);
		sscanf(line3,"\t%d\t%d\t%d",&g,&h,&i);
		if(a+d>g && a+g>d && d+g>a)
			count++;
		if(b+e>h && b+h>e && h+e>b)
			count++;
		if(c+f>i && c+i>f && i+f>c)
			count++;
	}
	printf("%d\n",count);
	return 0;
}
