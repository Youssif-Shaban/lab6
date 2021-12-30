#include<stdio.h>
#include<malloc.h>

void main()
{
    int n, i, j, temp, count=0, qt, ex=0, *p, *bt, *at, *wt, *rem_bt, *tat;
    float awt = 0, atat = 0;

    printf("\n Enter the number of processes : ");
    scanf("%d", &n);

    p=(int*)malloc(n*sizeof(int));
    at = (int*)malloc(n*sizeof(int));
    rem_bt = (int*)malloc(n*sizeof(int));
    bt = (int*)malloc(n*sizeof(int));
    wt = (int*)malloc(n*sizeof(int));
    tat = (int*)malloc(n*sizeof(int));
    

printf("enter the process sequence : \n");
for(i=0;i<n;i++)
{
	scanf("%d",&p[i]);
}

printf("enter the arrival time: \n");
for(i=0;i<n;i++)
{
	scanf("%d",&at[i]);
}

printf("enter the burst time: \n");
for(i=0;i<n;i++)
{
	scanf("%d",&bt[i]);
	rem_bt[i]=bt[i];
}

printf("\n Enter the Quantum Time : ");
scanf("%d", &qt);


for(i=0; i<n; i++)
{
	for(j=i+1;j<n;j++)
	{
		if(at[i]>at[j])
		{
        		temp=bt[i];
			bt[i]=bt[j];
			bt[j]=temp;
			
			temp=rem_bt[i];
			rem_bt[i]=bt[j];
			rem_bt[j]=temp;

			temp=p[i];
			p[i]=p[j];
			p[j]=temp;

			temp=at[i];
			at[i]=at[j];
			at[j]=temp;
		}
	}
}

while(1)
{
	for(i=0,count=0;i<n;i++)
	{
		temp=qt;
		if(rem_bt[i]==0) {
			count++;
			continue;
		}
		if(rem_bt[i]>qt) {
			rem_bt[i]=rem_bt[i]-qt;
		}
		else
		if(rem_bt[i]>=0) {
			temp=rem_bt[i];
			rem_bt[i]=0;
		}
		ex+=temp;
		tat[i]=ex-at[i];
	}
	if(n==count)
	break;
}

printf("\n process \t Arrival time \t Burst time \t turnaround time \t waiting time \n");

for(i=0;i<n;i++) {
	atat += tat[i];
	wt[i]=tat[i]-bt[i];
	awt += wt[i];
	printf("p[%d] \t\t %d \t\t %d \t\t %d \t\t %d \n" , p[i], at[i], bt[i], tat[i], wt[i]);
}

atat=atat/n;
awt=awt/n;
   
printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", awt, atat);
}
