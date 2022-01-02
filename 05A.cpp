#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void*msg_function(void*ptr);

main()
{
pthread_t thread1,thread2;
char*msg1 = "I'm Thread1";
char*msg2 = "I'm Thread2";
int t1,t2;

t1 = pthread_create(&thread1,NULL,msg_function,(void*)msg1);
t2 = pthread_create(&thread2,NULL,msg_function,(void*)msg2);

pthread_join(thread1,NULL);
pthread_join(thread2,NULL);

printf("Thread 1 returns: %d\n",t1);
printf("Thread 2 returns: %d\n",t2);
exit(0);
}
void*msg_function(void*ptr)
{
char*msg;
msg = (char*)ptr;
printf("%s\n",msg);
}

