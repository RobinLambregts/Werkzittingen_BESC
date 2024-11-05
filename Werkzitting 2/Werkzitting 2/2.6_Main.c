/*#include <stdio.h>

struct person {
 char *name;
} p1, p2;

int main() {
	matrices();
	haakjes();
	whitespaceRemover();

	char s[] = "Ha";
p1.name = s;
p2 = p1;
p2.name[1] = 'o';
printf("---%s,%s---", p1.name, p2.name);
	return 0;
}*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
int value = 0;
void *Runner( void *param )
{
value = 5;
pthread_exit( 0 );
}
int main()
{
pid_t pid;
pthread_t tid;
pthread_attr_t attr;
pid = fork( );
if (pid == 0) /* child process */
{
pthread_attr_init( &attr );
pthread_create( &tid, &attr, Runner, NULL );
pthread_join( tid, NULL );
printf( "CHILD: value = %d\n", value ); /* LINE C */
}
else if (pid > 0) /* parent process */
{
wait( NULL );
printf( "PARENT: value = %d\n", value ); /* LINE P */
}
}