	/*
	FCFS CPU Scheduling algo implementation
*/
	#include<stdio.h>
	struct Process
	{	
	char PName[5];
	int AT,BT,TAT,WT,CT;
	int tempBT;
	}P[10];
	int N;
void Input()
{
	int i;
	printf("\nEnter Number of process:");
	scanf("%d",&N);

	for(i = 0; i < N; i++)
	{
		printf("\nEnter details of process %d",i+1);
		printf("\nEnter process name:");
		scanf("%s",P[i].PName);

		printf("\nEnter AT:");
		scanf("%d",&P[i].AT);

		printf("\nEnter BT:");
		scanf("%d",&P[i].BT);

		P[i].tempBT = P[i].BT;
	}
}
void SortProcessAT()
{
	int i;
	int j;
	int tval;
	char temp[5];

	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
		{
			if(P[i].AT < P[j].AT)
			{
			//swap pname
				strcpy(temp, P[i].PName);
				strcpy(P[i].PName,P[j].PName);
				strcpy(P[j].PName,temp);
			//swap at
				tval = P[i].AT;
				P[i].AT = P[j].AT;
				P[j].AT = tval;

			//swap bt
				tval = P[i].BT;
				P[i].BT = P[j].BT;
				P[j].BT = tval;

			//swap tempbt
				tval = P[i].tempBT;
				P[i].tempBT = P[j].tempBT;
				P[j].tempBT = tval;
			}
		}
}
void Output()
{
	int i;
	int totalTAT = 0;
	int totalWT = 0;
	for(i = 0; i < N; i++)
	{
		P[i].TAT = P[i].CT - P[i].AT;
		totalTAT = totalTAT + P[i].TAT;

		P[i].WT = P[i].TAT - P[i].BT;
		totalWT = totalWT + P[i].WT;
	}

	printf("\nProcess Details");
	printf("\n***********************************");
	printf("\nPName\tAT\tBT\tTAT\tWT");
	printf("\n***********************************");
	for(i = 0; i < N; i++)
	{
		printf("\n%s\t%d\t%d\t%d\t%d",P[i].PName,P[i].AT,P[i].BT,\
			P[i].TAT,P[i].WT);
	}
	printf("\n***********************************\n");
	printf("\nAVG TAT:%d / %d",totalTAT,N);
	printf("\nAVG WT:%d / %d",totalWT,N);
}
void FCFS()
{
	int time = 0;
	int finish = 0;
	int i;
	int flag = 0;
	while(finish != 1)
	{
		flag = 0;
		for(i = 0; i < N; i++)
		{
			if(P[i].AT <= time && P[i].tempBT != 0)
			{
				printf("|%d %s",time,P[i].PName);
				time = time + P[i].tempBT;
				printf(" %d|",time);
				P[i].tempBT = 0;
				P[i].CT = time;

				flag = 1;
			}		
		}
		if(flag == 0)
		{
			printf("|%d # ",time);
			time++;
			printf(" %d|",time);
		}
		for(i = 0; i < N; i++)
			if(P[i].tempBT == 0)
				continue;
			else
				break;
		if(i == N)
			finish = 1;
	}
}
int main()
{
	Input();
	SortProcessAT();
	FCFS();
	Output();

	return 0;
}


