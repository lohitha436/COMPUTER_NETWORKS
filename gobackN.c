#include<stdio.h>
int main()
{
    int windowsize,sent=0,ack,i;
    printf("Enter window size:");
    scanf("%d",&windowsize);
    while(1)
    {
        for( i = 0; i < windowsize; i++)
            {
                printf("Frame %d has been transmitted.\n",sent);
                sent++;
                if(sent == windowsize)
                    break;
            }
            printf("\nPlease enter the last Acknowledgement received.\n");
            scanf("%d",&ack);
            
            if(ack == windowsize-1)
                break;
            else
                sent = 0;
    }
return 0;
}
