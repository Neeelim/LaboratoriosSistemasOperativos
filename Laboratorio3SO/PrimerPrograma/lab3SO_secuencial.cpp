#include <iostream>
using namespace std;
#include <fstream>

//Funcion que muestra lo que contiene cada archivo y además muestra cuantas lineas y caracteres tiene cada uno
void procesar_archivo(string archivo)
{
    ifstream file(archivo);
    string str;
    int cnt = 0;
    int cnt_car = 0;

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

    }

    //Mostrar por pantalla la cantidad de lineas y caracteres del archivo
    cout<<cnt<<" lineas" << endl;
    cout << cnt_car << " caracteres" << endl;
}

//Funcion que se encarga de calcular las lineas de cada archivo por separado
int contarLineasTotales(string archivo)
{
    ifstream file(archivo);
    string str;
    int lineas_totales = 0;

    while(std::getline(file, str))
    {
        //contar lineas
        lineas_totales++;
    }

    return lineas_totales;
}

//Funcion que calcula los caracteres de cada archivo a parte sin mostrar lo que dice cada archivo
int contarCarTotales(string archivo)
{
    ifstream file(archivo);
    string str;
    int cnt_car = 0;

    while(std::getline(file, str))
    {
        //contar caracteres

        for(int i=0;i<str.length();i++)
        {
            cnt_car++;
        }
    }

    return cnt_car;
}

int main (int argc, char *argv[])
{
    //Se abre el archivo y se muestran cuantas lineas y caracteres tienen por separado, luego se hace una suma de los caracteres que tiene cada uno y se da el total al final
    procesar_archivo("lab3SO.txt");
    int lineas = contarLineasTotales("lab3SO.txt");
    int caracteres = contarCarTotales("lab3SO.txt");
    procesar_archivo("texto2.txt");
    int lineasTotales = lineas + contarLineasTotales("texto2.txt");
    int carTotales = caracteres + contarCarTotales("texto2.txt");
    
    //Muestra por pantalla la cantidad total
    cout<<endl;
    cout<<lineasTotales<<" lineas totales" << endl;
    cout<<carTotales<<" caracteres totales" << endl;

    return 0;

}