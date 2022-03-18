#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 64
#define TOTALBOTS 210
#define TOTALOUTPUTS 20

struct proto_bot {
    int value[2];
    int count;
    int low[2];     // first int 0 for output, 1 for bot
    int high[2];    // first int 0 for output, 1 for bot
} bots[TOTALBOTS];

int outputs[TOTALOUTPUTS];

void main()
{
    int len;
    char line[LEN];
    char *token;
    int bot, high, low, value, output;
    int flag;
    
    while(fgets(line,LEN,stdin)!=NULL)
    {
        len=strlen(line);
        if(len<2) continue;
        if(line[len-1]=='\n' || line[len-1]==EOF)
            line[--len]='\0';
        
        token=strtok(line," ");
        switch(token[0])
        {
            case 'v':
                token=strtok(NULL, " ");
                value=atoi(token);
                for(int i=0;i<4;i++)
                    token=strtok(NULL, " ");
                bot=atoi(token);

                bots[bot].value[bots[bot].count++]=value;
                
                break;
                
            case 'b':
                token=strtok(NULL," ");
                bot=atoi(token);
                
                for(int i=0;i<4;i++)
                    token=strtok(NULL," ");
                    
                if(token[0]=='o')
                    flag=0;
                else
                    flag=1;
                    
                token=strtok(NULL," ");
                
                bots[bot].low[0]=flag;
                bots[bot].low[1]=atoi(token);
                
                for(int i=0;i<4;i++)
                    token=strtok(NULL," ");
                
                if(token[0]=='o')
                    flag=0;
                else
                    flag=1;
                    
                token=strtok(NULL," ");
                
                bots[bot].high[0]=flag;
                bots[bot].high[1]=atoi(token);
                
                break;
        }
    }
    

    
    
    int a,b;
    int found=1;
    int processed[TOTALBOTS];
    for(int i=0;i<TOTALBOTS;i++)
        processed[i]=0;
        
    int lowvalue, highvalue;
    int lowtarget, hightarget;
    while(found)
    {   
        found=0;
        for(int i=0;i<TOTALBOTS;i++)
        {
            if(bots[i].count==2 && !processed[i])
            {
                processed[i]=1;
                found=1;
                a=bots[i].value[0];
                b=bots[i].value[1];
                
                if(a>b)
                {
                    lowvalue=b;
                    highvalue=a;
                }
                else
                {
                    lowvalue=a;
                    highvalue=b;
                }
                
                if(highvalue==61 && lowvalue==17)
                    printf("%d\n",i);
                
                lowtarget=bots[i].low[1];
                hightarget=bots[i].high[1];
                
                if(bots[i].low[0])
                    bots[lowtarget].value[bots[lowtarget].count++] = lowvalue;
                else
                    outputs[lowtarget] = lowvalue;
                            
                if(bots[i].high[0])
                    bots[hightarget].value[bots[hightarget].count++] = highvalue;
                else
                    outputs[hightarget] = highvalue;   
            }
        }
    }
    
    int p=1;
    for(int i=0;i<3;i++)
        p *= outputs[i];
    printf("%d\n",p);
    
       
        
    return;
}
        
        
            
