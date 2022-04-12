#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <errno.h>
#include <sys/wait.h>

using namespace std;


int main(int argc, char *argv[]) 
{

    string nombreC = " ";
    nombreC = argv[1];

    //Arreglo de caracteres, donde se introduce el código para que descargue el video que se pone en los argumentos
    char *descarga[] = { "youtube-dl", "-x", "--audio-format", "mp3", (char *)nombreC.c_str(),"-o","song.mp3", NULL };

    //Arreglo de caracteres, donde se reproduce la canción descargada anteriormente con el nombre designado
    char *reproducir[] = { "ffplay", "song.mp3", NULL };

    pid_t pid = fork();

    //Ejecución del proceso hijo
    if (pid == 0) 
    {
        if (execvp ( descarga[0], descarga) == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
    } 

    //Ejecución del proceso padre
    else 
    {
        if(wait(0) == -1)
        {
            perror("wait");
        }
        if(execvp (reproducir[0], reproducir) == -1)
        {
        perror("exec");
        }

    }

    exit(EXIT_SUCCESS);
}

