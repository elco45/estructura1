#include <iostream>
#include <cstdlib>
#include "tdalist.h"
#include "linkedlist.h"
#include "fsarraylist.h"
#include "dlcursorlist.h"
#include "integer.h"
#include <ctime>
#include <stdio.h>
#include <cstdlib>
#include <fstream>

using namespace std;

/*
* Programa de Prueba para el TDALista implementado con LinkedList
* -- Listas Doblemente Enlazadas --
* Se prueban las siguientes operaciones:
*  - Inserción
*  - Eliminación
*  - Listado
*  - Búsqueda
*/


int menu();

int main(int argc, char *argv[]){
  /**ofstream f13("ClInsert.txt");
  ofstream f14("Clremove.txt");
  ofstream f15("Clget.txt");
  ofstream f16("ClIndex.txt");
  ofstream f17("CLfirst.txt");
  ofstream f18("CLlast.txt");
  **/
  double tiempo;
  time_t inicio,fin;
 // srand(time(0));

  TDAList* lista1 = new FSArrayList(5);
  TDAList* lista2 = new LinkedList();
  TDAList* lista3 = new DLCursorList(5);
  //funcion insert de FSArrayList

  ofstream f1("FSInsert.txt");
  for (int i = 0; i <5; ++i){ 
    inicio=clock(); 
    lista1->insert(new Integer(i),i);
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    f1<<tiempo<<"\n";
  }

  f1.close();
  ofstream f3("FSget.txt");
   //funcion get de FSArrayList
  for (int i = 0; i <5; ++i){ 
    inicio=clock(); 
    lista1->get(i);
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    f3<<tiempo<<"\n";
  }

  f3.close();
  ofstream f4("FSInfex.txt");
   //funcion indexof de FSArrayList
  for (int i = 0; i <5; ++i){ 
    inicio=clock(); 
    lista1->indexOf(new Integer(i));
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    f4<<tiempo<<"\n";
  }

  f4.close();
  ofstream f5("FSFirst.txt");
   //funcion fisrt de FSArrayList
  for (int i = 0; i <5; ++i){ 
    inicio=clock(); 
    lista1->first();
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    f5<<tiempo<<"\n";
  }

  f5.close();
  ofstream f6("FSLast.txt");
   //funcion last de FSArrayList
  for (int i = 0; i <5; ++i){ 
    inicio=clock(); 
    lista1->last();
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    f6<<tiempo<<"\n";
  }
 
  f6.close();
  ofstream f2("FSRemove.txt");
   //funcion remove de FSArrayList
  for (int i = 0; i <5; ++i){ 
    inicio=clock(); 
    lista1->erase(0);
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    f2<<tiempo<<"\n";
  }
 
  f2.close();
  //************************************************************
   //funcion insert de LinkedList
  ofstream f7("DLinsert.txt");
  for (int i = 0; i <5; ++i){ 
    inicio=clock(); 
    lista2->insert(new Integer(i),i);
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    f7<<tiempo<<"\n";
  }

  f7.close();
   //funcion get de linkedlist
  ofstream f9("DLget.txt");
  for (int i = 0; i <5; ++i){ 
    inicio=clock(); 
    lista2->get(i);
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    f9<<tiempo<<"\n";
  }
 
  f9.close();
   //funcion indexof de linkedlist
   ofstream f10("DLindex.txt");
  for (int i = 0; i <5; ++i){ 
    inicio=clock(); 
    lista2->indexOf(new Integer(i));
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    f10<<tiempo<<"\n";
  }
  f10.close();
 
   //funcion fisrt de linkedlist
   ofstream f11("DLfirst.txt");
  for (int i = 0; i <5; ++i){ 
    inicio=clock(); 
    lista2->first();
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    f11<<tiempo<<"\n";
  }
  f11.close();

   //funcion last de linkedlist
  ofstream f12("DLlast.txt");
  for (int i = 0; i <5; ++i){ 
    inicio=clock(); 
;
    Object* objeto=lista2->last();
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    f12<<tiempo<<"\n";
  }

  f12.close();
   //funcion remove de linkedlist
  ofstream f8("DLremove.txt");
  for (int i = 0; i <5; ++i){ 
    inicio=clock();
    lista2->erase(0);
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    f8<<tiempo<<"\n";
  }
  f8.close();

  /*
    // En el caso de que quisieramos utilizar otra implementación
    // SÓLO se tendría que cambiar esta línea.
    TDAList* lista = new DLCursorList(5);
    Integer* intTemp;
    int val, pos;
    bool flag = true;
    while (flag)
    {
        switch(menu())
        {
           case 1:
               cout << "Valor a Insertar: " ;
               cin >> val;
               cout << "Posicion a Insertar: ";
               cin >> pos;
               if (lista->insert(new Integer(val), pos))
                  cout << "Exito en la Insercion" << endl;
               else
                  cout << "Fracaso en la Insercion" << endl;
               break;
           case 2:
               cout << "Posicion de la que quiere Borrar: ";
               cin >> pos;
               if (lista->erase(pos))
                  cout << "Exito en el Borrado" << endl;
               else
                  cout << "Fracaso en el Borrado" << endl;
               break;
           case 3:
               lista->print();
               break;
           case 4:
               cout << "Valor del Elemento a Buscar: ";
               cin >> val;
               intTemp = new Integer(val);
               pos = lista->indexOf(intTemp);
               delete intTemp;
               cout << "El Elemento esta en la posicion = " << pos << endl;
               break;
           case 9:
               flag = false;
        }
    }
    delete lista;
    */

     
    return 0;
}
int menu()
{
    cout << "1. Insertar "  << endl;
    cout << "2. Borrar "  << endl;
    cout << "3. Listar " << endl;
    cout << "4. Buscar " << endl;
    cout << "9. Salir " << endl;
    cout << endl << "Opcion? ";
    int opcion;
    cin >> opcion;
    return opcion;
}
