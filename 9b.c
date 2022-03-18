#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 15000
#define WLEN 16

void main()
{
    char line[LEN];
    long long int sum=0;
    int a,b;
    char word[WLEN];
    int k;
    int temp;
    int len;
    long long int mirror[LEN];
    
    while(fgets(line,LEN,stdin)!=NULL)
    {
        len=strlen(line);
        if(len<2) continue;
        if(line[len-1]=='\n' || line[len-1]==EOF)
            line[--len]='\0';

        for(int i=0;i<len;i++)
            mirror[i]=1;
        
        for(int i=0;i<len;i++)
        {
            temp=i;
            if(line[i]=='(')
            {
                k=0;    // for word[]
                i++;    // to move after '(' 
                while(line[i]!='x')
                    word[k++]=line[i++];
                word[k]='\0';
                a=atoi(word);   //the first number

                k=0;    // to use word[] again
                i++;    // to move after 'x'
                while(line[i]!=')')
                    word[k++]=line[i++];
                word[k]='\0';
                b=atoi(word);   // the second number
                
                i++;    // to move after ')'
                
                for(int j=0;j<a;j++)
                    mirror[i+j] *= b; 
                
                for(int j=0;j<i-temp;j++)
                    mirror[temp+j] = 0;     // the paranthesis gets 0'd
                    
                i--;   // to offset the increase in for()
            }
        }
    
        for(int i=0;i<len;i++)
            sum+=mirror[i];
           
    }
    
    printf("%lld\n",sum);
    return;
}
