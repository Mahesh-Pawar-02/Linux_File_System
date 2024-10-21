#include<stdio.h>

struct Input
{
	char pname[10];
	int  bt,at,ct,p,tbt;
}tab[5];

struct Sequence
{
	int start,end;
	char pname[10];
}seq[100],seq1[20];

int finish,time,n,k,prev;

void getinput()
{
	int i;
	clrscr();
	printf("\nEnter No.of Processes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Process name:");
		scanf("%s",tab[i].pname);
		printf("Burst time:");
		scanf("%d",&tab[i].bt);
		printf("Arrival time:");
		scanf("%d",&tab[i].at);
		printf("Priority level:");
		scanf("%d",&tab[i].p);
		tab[i].tbt = tab[i].bt;
	}
}

void printinput()
{
	int i;
	clrscr();
	printf("\nProcess\tBT\tAT\tPriority");
	for(i=0;i<n;i++)
		printf("\n%s\t%d\t%d\t%d",tab[i].pname,tab[i].tbt,tab[i].at,tab[i].p);
	getch();
}

void sort()
{
	struct Input t;
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j< n-1-i;j++)
			if(tab[j+1].p<tab[j].p)
			{
				t = tab[i];
				tab[i] = tab[j];
				tab[j] = t;
			}
}

void processinput()
{
	int i;
	k=finish=0;
	while(finish!=n)
	{
	outside:
		for(i=0;i<n;i++)
		{
			if(tab[i].at<=time && tab[i].tbt!=0)
			{
				time++;
				tab[i].tbt--;
				printinput();
				seq[k].start=prev;
				seq[k].end = time;
				strcpy(seq[k++].pname,tab[i].pname);
				prev = time;
				tab[i].ct=time;
				if(tab[i].tbt==0)
					finish++;
				goto outside;
			}
		}
		if(finish!=n)
		{
			time++;
			seq[k].start=prev;
			seq[k].end = time;
			strcpy(seq[k++].pname,"*");
			prev = time;
		}
	}
}
void printoutput()
{
	int i;
	float AvgTAT=0,AvgWT=0;
	printf("\nProcess\tAT\tBT\tCT\tTAT\tWT");
	for(i=0;i<n;i++)
	{
		printf("\n%s\t%d\t%d\t%d\t%d\t%d",tab[i].pname,
							  tab[i].at,
							  tab[i].bt,
							  tab[i].ct,
							  tab[i].ct-tab[i].at,
							  tab[i].ct-tab[i].at-tab[i].bt);
		AvgTAT += tab[i].ct-tab[i].at;
		AvgWT += tab[i].ct-tab[i].at-tab[i].bt;
	}
	AvgTAT/=n;
	AvgWT/=n;
	printf("\nAverage TAT = %f",AvgTAT);
	printf("\nAverage WT = %f",AvgWT);
	getch();
}

void ganttchart()
{
	int i,j=1;
	clrscr();
	seq1[0] = seq[0];
	for(i=1;i<k;i++)
	{
		if(strcmp(seq1[j-1].pname,seq[i].pname)==0)
			seq1[j-1].end = seq[i].end;
		else
			seq1[j++] = seq[i];
	}
	for(i=0;i<j;i++)
		printf("\n%d\t%s\t%d",seq1[i].start,seq1[i].pname,seq1[i].end);
	getch();
}

void main()
{
	int i;
	getinput();
	sort();
	processinput();
	printoutput();
	ganttchart();
	for(i=0;i<n;i++)
	{
		tab[i].tbt = tab[i].bt=rand()%10+1;
		tab[i].at=tab[i].ct+2;
	}
	processinput();
	printoutput();
	ganttchart();
}