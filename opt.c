#include<stdio.h>
#define MAX 20

int frames[MAX],ref[MAX],mem[MAX][MAX],faults,
	sp,m,n;

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

int get_opt(int sp, int s)
{
	int i,j,pos_i=-1,pos_j=-1;

	j=sp;
	do
	{
		for(i=s;i<m;i++)
		{
			if(ref[i]==frames[j])
			{
				if(i > pos_i)
				{
					pos_i = i;
					pos_j = j;
				}
				break;
			}
		}

		if(i==m) return j;

		j=(j+1)%n;
	}while(j!=sp);

	return pos_j;
}


void opt()
{
	int i,j,k;

	for(i=0;i<m && sp<n;i++)
	{
		k=search(ref[i]);
		if(k==-1)
		{
			frames[sp]=ref[i];
			faults++;
			sp++;

			for(j=0;j<n;j++)
				mem[j][i]=frames[j];
		}
	}

	sp=0;
	for(;i<m;i++)
	{
		k = search(ref[i]);
		if(k==-1)
		{
			sp = get_opt(sp,i);
			frames[sp] = ref[i];
			faults++;
			sp = (sp+1)%n;

			for(j=0;j<n;j++)
				mem[j][i] = frames[j];
		}
	}
}
						

int main()
{
	accept();
	opt();
	disp();

	return 0;
}





	






