#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int pid;
	pid = fork();
	if(pid<0)
	{
		printf("Failed to fork()");
		exit(1);
	}
	else if(pid>0)
	{
		printf("I am Parent Process & id is : %d\n",pid);

	}
	else
	{
		printf("I am Child Process & id is : %d\n",pid);
	}

	return 0;
}

