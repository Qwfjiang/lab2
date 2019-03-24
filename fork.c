#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	int p1,p2,p3,p4,p5;
	while((p1=fork())==-1);
	if (!p1)
	{
		printf("PID：%d,Parent PID:%d\n",getpid(),getppid());
		while((p2=fork())==-1);
		if (!p2)
		{
			printf("PID：%d,Parent PID:%d\n",getpid(),getppid());
			while((p4=fork())==-1);
			if (!p4)
			{
				printf("PID：%d,Parent PID:%d\n",getpid(),getppid());
				exit(0);
			}
			else
				wait(0);
			while((p5=fork())==-1);
			if (!p5)
			{
				printf("PID：%d,Parent PID:%d\n",getpid(),getppid());
				exit(0);
			}
			else
				wait(0);
			exit(0);
		}
		else
			wait(0);
		while((p3=fork())==-1);
		if (!p3)
		{
			printf("PID：%d,Parent PID:%d\n",getpid(),getppid());
			exit(0);
		}
		else
			wait(0);
		exit(0);
	}
	return 0;
}
