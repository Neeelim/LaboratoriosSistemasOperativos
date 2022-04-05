#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <chrono>

using namespace std;

//Contadores globales de las lineas, caracteres y palabras de todos los documentos que se lean
int cnt_l_totales = 0;
int cnt_car_totales = 0;
int cnt_pal_totales = 0;

//Funcion que muestra lo que contiene cada archivo y además muestra cuantas lineas y caracteres tiene cada uno
void leerArchivo(string archivo)
{
    ifstream file(archivo);
    string str;
    
    //Contadores de lineas, caracteres y palabras
    int cnt_l = 0;
    int cnt_car = 0;
    int cnt_pal = 1;

    while(std::getline(file, str))
    {
        //Contar lineas
        cnt_l++;

        //Contar caracteres
        for(int i=0;i<str.length();i++)
        {
            
            if(str[i] == ' ')
            {
                //Contar palabras
                cnt_pal++;
            }
            
            cout<< str[1];
            cnt_car++;

        }

        cout<<endl;

    }

    //El contador de caracteres suma los saltos entre cada linea, por lo que es necesario restarlos para obtener la cantidad total de caracteres
    cnt_car -= (cnt_l - 1);

    //Muestra por pantalla la cantidad de lineas, caracteres y palabras que contiene el archivo
    cout << cnt_l << " lineas" << endl;
    cout << cnt_car << " caracteres" << endl;
    cout << cnt_pal << " palabras" << endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<endl;

    //Se le suman los valores obtenidos del texto en los contadores totales
    cnt_l_totales += cnt_l;
    cnt_car_totales += cnt_car;
    cnt_pal_totales += cnt_pal;
    
}


//Funcion principal del programa
int main (int argc, char *argv[])
{
    //Cronometro para medir el tiempo de ejecución del codigo completo
    auto start = chrono::system_clock::now();
    
    string nArchivo;
    int i;

    //Recibe los archivos a leer a través de los argumentos de la consola
    for(i = 0; i < argc - 1; i++)
    {
        nArchivo = argv[i+1];
        leerArchivo(nArchivo);
    }
    
    
    //Muestra por pantalla la cantidad total de lineas, caracteres y palabras de los archivos que se le pida leer
    cout<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<cnt_l_totales<<" lineas totales" << endl;
    cout<<cnt_car_totales<<" caracteres totales" << endl;
    cout<<cnt_pal_totales<<" palabras totales" << endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<endl;

    auto end = chrono::system_clock::now();

    chrono::duration<float,milli> duration = end - start;

    cout << "Tiempo de ejecución del programa: " << duration.count() << " segundos" << endl;

    return 0;

}