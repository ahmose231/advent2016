#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool abba(char *text)
{
	if(text[0]==text[3])
		if(text[0]!=text[1])
			if(text[2]==text[1])
				return true;
	return false;
}

int main()
{
	char line[512];
	int count=0;

	char token[64];
	char word[4];
	int k,m;
	int valid,invalid;
	while(fgets(line,512,stdin)!=NULL)
	{
		k=0;
		valid=0;
		invalid=0;
		
		label1:	
		m=0;
		while(line[k]!='[' && line[k]!=']' && line[k]!='\n')
			token[m++]=line[k++];
		token[m]='\0';
		for(int i=0;i<strlen(token)-3;i++)
		{
			for(int j=0;j<4;j++)
				word[j]=token[i+j];
			
			if(abba(word))
			{
				if(line[k]=='[' || line[k]=='\n')
					valid=1;
				else
					invalid=1;
				break;
			}
		}
		
		
		if(line[k]!='\n') {
			k++;
			goto label1;
		}
		if(valid && !invalid)
			count++;
	}

	printf("%d\n",count);
	return 0;
}
