#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
  	int pid,retnice;
	printf("press DEL to stop process\n");
	pid=fork();
	for(;;)
{
		if(pid==0)
		{
		retnice=nice(1);
		printf("child gets higher priority%d\n",retnice);
		sleep(1);
		}
		else
		{
 		 retnice=nice(4);
		printf("parent gets lower priority%d\n",retnice);
			sleep(1);
		}
	 }
}


