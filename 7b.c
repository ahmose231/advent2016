#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define WLEN 32
#define LEN 256

char inner[MAX][WLEN];
char outer[MAX][WLEN];
int inner_i;
int outer_i;
int total=0;

void process()
{
    int len, len2;
    char a,b;
    for(int i=0;i<outer_i;i++)
    {
        len=strlen(outer[i]);
        for(int j=0;j<len-2;j++)
            if(outer[i][j]==outer[i][j+2])
            {
                a=outer[i][j];
                b=outer[i][j+1];
                
                if(a!=b)
                    for(int m=0;m<inner_i;m++)
                    {
                        len2=strlen(inner[m]);
                        for(int n=0;n<len2-2;n++)
                        {
                            if(inner[m][n]==b)
                                if(inner[m][n+2]==b)
                                    if(inner[m][n+1]==a)
                                    {
                                        total++;
                                        return;
                                    }
                        }
                    }
            }
    }
    
    return;
}
                        

void main()
{
    int k;
    char line[LEN];
    int cycle=0;
    char word[WLEN];
    int i;
    
    while(fgets(line,LEN,stdin)!=NULL)
    {
        if(strlen(line)<2) continue;
        
        inner_i = outer_i = 0;
        i = 0;
        cycle = 0;
        
        while(1)
        {
            k=0;
            
            while(line[i]!='[' && line[i]!=']' && line[i]!='\n' && line[i]!=EOF)
                word[k++]=line[i++];
                
            i++;
            word[k]='\0';
            
            if(cycle)
                strcpy(inner[inner_i++], word);
            else
                strcpy(outer[outer_i++], word);

            if(i>=strlen(line))
            {
                process();
                break;
            }
            
            cycle = 1 - cycle;
        }
    }
 
    printf("%d\n",total);
    
    return;
}
