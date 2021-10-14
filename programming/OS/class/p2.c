#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

void main()
{
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *str = (char *)shmat(shmid, (void *)0, 0);
    printf("\nData in that shared variable : %s", str);

    do
    {
        while (str != '2')
            ;
        str == '1';
    } while (1);
    shmdt(str);
}
