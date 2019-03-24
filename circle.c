#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	pid=fork();
	if(pid<0){
		perror("fork");
	}
	if(!pid){	
		int ret;
		ret = execl ("/usr/bin/vi", "vi","home/qwf/circle.c", NULL);
		if (ret == -1)
		perror ("execl");
	}
	else if(pid>0){
		while(1){
			printf("%d\n",pid);
			sleep(2);
		}
	}
	return 0;

}
