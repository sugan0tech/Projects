#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

void main()
{
    key_t key = ftok("shmfile", 65);
    printf("key: %d\n", key);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *str = (char *)shmat(shmid, (void *)0, 0);
    printf("\nEnter the data to write :");
    scanf("%s", str);
    printf("\nData in that shared variable : %s", str);
    shmdt(str);
    // int kill;
    // scanf("%d", &kill);
    // shmctl(shmid, IPC_RMID, NULL);
}
