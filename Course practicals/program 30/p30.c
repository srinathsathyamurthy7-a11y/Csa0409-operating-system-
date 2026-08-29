#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg)
{
    pthread_t tid = pthread_self();

    printf("Thread created successfully.\n");
    printf("Thread ID: %lu\n", (unsigned long)tid);

    printf("Thread is exiting...\n");

    pthread_exit(NULL);
}

int main()
{
    pthread_t thread1, thread2;

    /* create */
    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);

    /* equal */
    if (pthread_equal(thread1, thread2))
        printf("Both threads are equal.\n");
    else
        printf("Threads are not equal.\n");

    /* join */
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Both threads joined successfully.\n");

    return 0;
}
