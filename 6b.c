#include <stdio.h>

int alphabet[26];

void zeroalphabet()
{
	for(int i=0;i<26;i++)
		alphabet[i]=0;
	return;
}

int main(int argc, char *argv[])
{
	int count=0;
	FILE *fp=fopen(argv[1],"r");
	char line[10];
	while(fgets(line,10,fp)!=NULL)
		count++;
	char m[count][10];
	rewind(fp);
	int k=0;
	while(fgets(line,10,fp)!=NULL)
		strcpy(m[k++],line);
	fclose(fp);
	char final[10];
	final[8]='\0';
	int min;
	int mini;
	for(int i=0;i<8;i++)
	{
		zeroalphabet();
		for(int j=0;j<count;j++)
			alphabet[m[j][i]-'a']++;
		min=count;
		for(int j=0;j<26;j++)
			if(min>alphabet[j])
			{
				min=alphabet[j];
				mini=j;
			}
		final[i]=mini+'a';
	}
	printf("%s\n",final);
	return 0;
}
