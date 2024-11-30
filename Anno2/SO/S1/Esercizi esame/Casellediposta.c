#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/signal.h>
#include <fcntl.h>

#define PERM 0777

void USR1_catcher(int signal)
{
    if (signal == SIGUSR1)
    {
        printf("Segnale ricevuto da processo 1.\n");
    }
}

int main()
{
    pid_t processo1;
    int mail1 = creat("mail1.txt", PERM);
    int mail2 = creat("mail2.txt", PERM);
    if (mail1 == -1 || mail2 == -1)
    {
        perror("Errore creazione mailbox");
        exit(1);
    }

    processo1 = fork();

    if (processo1 == 0)
    {
        mail2 = open("mail2.txt", O_RDWR);
        char buf[5];
        read(0, buf, 5);
        write(mail2, buf, sizeof(buf));
        close(mail2);
        kill(getppid(), SIGUSR1); // Invia il segnale al processo padre
    }
    else
    {
            signal(SIGUSR1, USR1_catcher);
            pause();
            int i;
            int j = 4;
            char buf1[5], buf2[5];
            mail1 = open("mail1.txt", O_RDWR);
            mail2 = open("mail2.txt", O_RDWR);
            read(mail2, buf1, 5);
            for(i = 0; i < 5; i++)
            {
                buf2[j] = buf1[i];
                j--;
            }
            write(mail1, buf2, sizeof(buf2));
            close(mail1);
            close(mail2);
            exit(0);
        }
    return 0;

}

