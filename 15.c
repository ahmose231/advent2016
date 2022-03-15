#include <stdio.h>
#include <string.h>

#define LEN 128
#define DISCMAX 6

void main()
{
    struct proto_disc {
        int total;
        int position;
    } disc[DISCMAX];
    int k=0;
    int n;
    char line[LEN];
    while(fgets(line,LEN,stdin)!=NULL)
    {
        if(strlen(line)<2) continue;
        sscanf(line, "Disc #%d has %d positions; at time=0, it is at position %d.",
                &n, &disc[k].total, &disc[k].position);
        k++;
    }
    
    
    int diff;
    diff=disc[0].total-disc[0].position-1;
    
    for(int i=0;i<k;i++)
        disc[i].position += diff;
    
    int clock=diff;
    int count;
    int answer;
    while(1)
    {
        count=0;
        for(int i=0;i<k;i++)
            if((disc[i].position+i+1)%disc[i].total==0)
                count++;
        
        if(count==k)
            break;
            
        clock+=disc[0].total;
        
        for(int i=0;i<k;i++)
            disc[i].position+=disc[0].total;
    }
        
    printf("%d\n",clock);
    
    return;
}

    
        
