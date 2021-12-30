#include<stdio.h>
#include<malloc.h>

void main()
{
	int n, i, j, d, min, tt=0, temp, *a, *bt, *wt, *tat, *p, *c;
	float avgwt = 0, avgtat = 0 , t_tat=0 , t_wt=0;
	printf("\n Enter the number of processes : ");
    scanf("%d", &n);

    p = (int*)malloc(n*sizeof(int));
    a = (int*)malloc(n*sizeof(int));
    c = (int*)malloc(n*sizeof(int));
    bt = (int*)malloc(n*sizeof(int));
    wt = (int*)malloc(n*sizeof(int));
    tat = (int*)malloc(n*sizeof(int));
 	
    printf("\n enter the arrival time for each process \n");
    for(i=0 ; i<n ; i++)
    {
	printf("p%d" : " , i+1);
	printf("the arrival time for p%d : ",i);
	scanf("%d" , &a[i]);
	p[i]=i+1;
     }

    printf("\n Enter the burst time for each process \n");
    for(i=0; i<n; i++)
    {
	printf("p%d : , i+1);
        printf(" Burst time for P%d : ", i);
        scanf("%d", &bt[i]);
        p[i] = i+1;
    }

    
    for(i=0; i<n; i++)
    {
    	for(j=i+1; j<n; j++)
    	{
    		if(bt[i] > bt[j])
    		{
    			temp = p[i];
			p[i] = p[j];
			p[j] = temp;

			temp = a[i];
			a[i] = a[j];
			a[j] = temp;

			temp = bt[i];
			bt[i] = bt[j];
			bt[j] = temp;
		}
	}
}

min = a[0];
for(i=0 ; i,n ; i++)
{
	if(min > a[i])
	{
		min = a[i];
		d = i;
	}
}

tt = min;
c[d] = tt + bt[d];
tt = c[d];

for(i=0; i<n; i++)
{
	if(a[i] != min)
	{
		c[i] = bt[i] + tt;
		tt=c[i];
	}        
}

for(i=0 ; i,n ; i++)
{
	tat[i] = c[i] - a[i];
	t_tat = t_tat + tat[i];
	wt[i] = tat[i] - bt[i];
	t_wt += wt[i];
}


    
    avg_wt = t_wt/n;
    avg_tat = t_tat/n;

    printf("\n PROCESS \t Arrival Time \t BURST TIME \t WAITING TIME \t TURNAROUND TIME \n");
    printf("-----------------------------------------------------------------------------\n");
    for(i=0; i<n; i++)
    {
        printf(" P%d \t\t %d \t\t %d \t\t %d \t\t %d \n", p[i], a[i], bt[i], , wt[i], tat[i]);
    }

    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", avg_wt, avg_tat);

    printf("\n \tGAANT CHART \n");
    printf("-------------------------\n");
    for(i=0; i<n; i++)
    {
        printf(" %d\t|| P%d ||\t%d\n", wt[i], p[i], tat[i]);
    }
}
