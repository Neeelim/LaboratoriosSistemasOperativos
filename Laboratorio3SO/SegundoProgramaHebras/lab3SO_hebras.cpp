#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

void *procesarArchivo (void *param);
void *procesarSegArchivo (void *param);

//Funcion principal del programa
int main(int argc, char *argv[]) {
  
  //Hebra principal para la primera función
  pthread_t p_archivo, archivo2;
  pthread_attr_t attr;

  pthread_attr_init (&attr);

  pthread_create(&p_archivo, &attr, procesarArchivo, argv[1]);
  pthread_create(&archivo2, &attr, procesarSegArchivo, argv[1]);
  
  pthread_join(p_archivo, NULL);
  pthread_join(archivo2, NULL);


  return 0;
}


//Funcion para contar las lineas y caracteres del archivo indicado
void *procesarArchivo (void *param) {
  
  ifstream file("lab3SO.txt");
  string str;
  //char *str;
  char c[2];
  int cnt = 0;
  int cnt_car = 0;

  //str = (char *) param;

  int stream = open ("lab3SO.txt", O_RDONLY);

  if (stream == -1) 
  {
    std::cout << "Error al abrir archivo" << std::endl;
    pthread_exit(0);
  }

  while (read(stream,c,1)) 
  {
   
        while(std::getline(file, str))
        {
            //contar linea
            cnt++;

            //contar caracteres

            for(int i=0;i<str.length();i++)
            {
                cout<< str[1];
                cnt_car++;
            }

            cout<<endl;
            sleep(1);
        }
    }

    close (stream);

    //Imprime por pantalla la cantidad de cada cosa
    cout<<cnt<<" lineas" << endl;
    cout << cnt_car << " caracteres" << endl;

    pthread_exit(0);
}

//Funcion para contar las lineas y caracteres del segundo archivo indicado
void *procesarSegArchivo (void *param) {
  
  ifstream file("texto2.txt");
  string str;
  //char *str;
  char c[2];
  int cnt2 = 0;
  int cnt_car2 = 0;

  //str = (char *) param;

  int stream = open ("texto2", O_RDONLY);

  if (stream == -1) 
  {
    std::cout << "Error al abrir archivo" << std::endl;
    pthread_exit(0);
  }

  while (read(stream,c,1)) 
  {
   
        while(std::getline(file, str))
        {
            //contar linea
            cnt2++;

            //contar caracteres

            for(int i=0;i<str.length();i++)
            {
                cout<< str[1];
                cnt_car2++;
            }

            cout<<endl;
            sleep(1);
        }
    }

    close (stream);

    //Imprime por pantalla la cantidad de cada cosa
    cout<<cnt2<<" lineas" << endl;
    cout << cnt_car2 << " caracteres" << endl;

    pthread_exit(0);
}

