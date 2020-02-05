#include <stdio.h>

int main()
{
	int alphabet[26];
	char line[128];
	char csum[5];
	int sid;
	int totalsid=0;
	int max[5];
	int maxindex[5];
	int temp;
	int valid;
  
	while(fgets(line,128,stdin)!=NULL)
	{
		for(int i=0;i<26;i++)
			alphabet[i]=0;
      
		for(int i=0;i<strlen(line);i++)
		{
			if(line[i]=='-')
				continue;
			
      if(line[i]>='0' && line[i]<='9')
			{
				sid=0;
			
        for(int j=0;j<3;j++)
				{
					sid=sid*10;
					sid=sid+line[i]-'0';
					i++;
				}
				
        i++;
				
        for(int j=0;j<5;j++)
				{
					csum[j]=line[i];
					i++;
				}
				
        break;
			}
			
      alphabet[line[i]-'a']++;
		}
		
    for(int i=0;i<5;i++)
		{
			max[i]=0;
			
      for(int j=0;j<26;j++)
			{
				for(int h=0;h<i;h++)
					if(maxindex[h]==j)
						goto next;
				
        if(alphabet[j]>max[i])
				{
					max[i]=alphabet[j];
					maxindex[i]=j;
				}
				
        next:;
			}
		}
		
    for(int i=0;i<4;i++)
			for(int j=i;j<5;j++)
				if(max[i]==max[j])
					if(maxindex[i]>maxindex[j])
					{
						temp=maxindex[i];
						maxindex[i]=maxindex[j];
						maxindex[j]=temp;
					}
		
    valid=1;
		
    for(int i=0;i<5;i++)
			if(maxindex[i]+'a' != csum[i])
			{
				valid=0;
				break;
			}
		
		if(valid)
			totalsid=totalsid+sid;
		
	}
	
  printf("%d\n",totalsid);
	return 0;
}
