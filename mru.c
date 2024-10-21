#include<stdio.h>
#define MAX 20

int frames[MAX],ref[MAX],mem[MAX][MAX],faults,
	sp,m,n,time[MAX];

void accept()
{
	int i;

	printf("Enter no.of frames:");
	scanf("%d", &n);

	printf("Enter no.of references:");
	scanf("%d", &m);

	printf("Enter reference string:\n");
	for(i=0;i<m;i++)
	{
		printf("[%d]=",i);
		scanf("%d",&ref[i]);
	}
}

void disp()
{
	int i,j;

	for(i=0;i<m;i++)
		printf("%3d",ref[i]);

	printf("\n\n");

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(mem[i][j])
				printf("%3d",mem[i][j]);
			else
				printf("   ");
		}
		printf("\n");
	}

	printf("Total Page Faults: %d\n",faults);
}

int search(int pno)
{
	int i;

	for(i=0;i<n;i++)
	{
		if(frames[i]==pno)
			return i;
	}

	return -1;
}

int get_mru()
{
	int i,max_i,max=-9999;

	for(i=0;i<n;i++)
	{
		if(time[i]>max)
		{
			max = time[i];
			max_i = i;
		}
	}

	return max_i;
}


void mru()
{
	int i,j,k;

	for(i=0;i<m && sp<n;i++)
	{
		k=search(ref[i]);
		if(k==-1)
		{
			frames[sp]=ref[i];
			time[sp]=i;
			faults++;
			sp++;

			for(j=0;j<n;j++)
				mem[j][i]=frames[j];
		}
		else
			time[k]=i;
		
	}

	for(;i<m;i++)
	{
		k = search(ref[i]);
		if(k==-1)
		{
			sp = get_mru();
			frames[sp] = ref[i];
			time[sp] = i;
			faults++;

			for(j=0;j<n;j++)
				mem[j][i] = frames[j];
		}
		else
			time[k]=i;
	}
}
						

int main()
{
	accept();
	mru();
	disp();

	return 0;
}





	






