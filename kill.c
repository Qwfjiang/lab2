#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	int p1,p2,p3,p4,p5;
	while((p1=fork())==-1);
	if (!p1)
	{
		while((p2=fork())==-1);
		if (!p2)
		{
			while((p4=fork())==-1);
			if (!p4)
			{
				while(1){printf("p4 PID：%d,Parent PID:%d\n",getpid(),getppid());sleep(10);}
				exit(0);
			}

			while((p5=fork())==-1);
			if (!p5)
			{
				while(1){printf("p5 PID：%d,Parent PID:%d\n",getpid(),getppid());sleep(10);}
				exit(0);
			}
			for(int i = 0;i < 5;i++)
			{printf("p2 PID：%d,Parent PID:%d\n",getpid(),getppid());sleep(10);}

			exit(0);

		}

		while((p3=fork())==-1);
		if (!p3)
		{
			while(1){printf("p3 PID：%d,Parent PID:%d\n",getpid(),getppid());sleep(10);}
			exit(0);
		}
		while(1){printf("p1 PID：%d,Parent PID:%d\n",getpid(),getppid());sleep(10);}
	}
	return 0;
}
