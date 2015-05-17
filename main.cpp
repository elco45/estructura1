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
  double tiempo;
  time_t inicio,fin;
  srand(time(0));
  TDAList* lista1 = new FSArrayList(1000);
  TDAList* lista2 = new LinkedList();
  TDAList* lista3 = new DLCursorList(1000);

  //crear una lista con posiciones random
  int lista_random[1000];
  int random;
  bool existe=false;
  for (int i = 0; i < 1000; i++){
    random= rand()%1000;
    for (int j = 0; j < 1000; j++){
      if (lista_random[j]=random){
        existe=true;
        break;
      }
    }
    if (existe){
      existe=false;
      i--;
    }else{
      lista_random[i]=random;
    } 
  }


//**********************************FSArrayList****************************************
  //funcion insert de FSArrayList
  ofstream f1("FSInsert.txt");
  for (int i = 0; i < 1000; i++){ 
    inicio=clock(); 
    lista1->insert(new Integer(i),lista_random[i]);
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    if ((i+1)%10==0)
      f1<<tiempo<<"\n";
  }
  f1.close();

  //funcion get de FSArrayList
  ofstream f3("FSget.txt");
  for (int i = 0; i < 1000; i++){ 
    inicio=clock(); 
    lista1->get(lista_random[i]);
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    if ((i+1)%10==0)
      f3<<tiempo<<"\n";
  }
  f3.close();

  //funcion indexof de FSArrayList
  ofstream f4("FSInfex.txt");
  for (int i = 0; i < 1000; i++){ 
    inicio=clock(); 
    lista1->indexOf(new Integer(i));
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    if ((i+1)%10==0)
      f4<<tiempo<<"\n";
  }
  f4.close();

   //funcion fisrt de FSArrayList
  ofstream f5("FSFirst.txt");
  for (int i = 0; i < 1000; i++){ 
    inicio=clock(); 
    lista1->first();
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    if ((i+1)%10==0)
      f5<<tiempo<<"\n";
  }
  f5.close();

  //funcion last de FSArrayList
  ofstream f6("FSLast.txt");
  for (int i = 0; i < 1000; i++){ 
    inicio=clock(); 
    lista1->last();
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    if ((i+1)%10==0)
      f6<<tiempo<<"\n";
  }
  f6.close();

  //funcion remove de FSArrayList
  ofstream f2("FSRemove.txt");
  for (int i = 0; i < 1000; i++){ 
    inicio=clock(); 
    lista1->erase(lista_random[i]);
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    if ((i+1)%10==0)
      f2<<tiempo<<"\n";
  }
  f2.close();  

  //********************************LinkedList**********************************
   //funcion insert de LinkedList
  ofstream f7("DLinsert.txt");
  for (int i = 0; i < 1000; i++){ 
    inicio=clock(); 
    lista2->insert(new Integer(i),lista_random[i]);
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    if ((i+1)%10==0)
      f7<<tiempo<<"\n";
  }
  f7.close();

   //funcion get de linkedlist
  ofstream f9("DLget.txt");
  for (int i = 0; i < 1000; i++){ 
    inicio=clock(); 
    lista2->get(lista_random[i]);
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    if ((i+1)%10==0)
      f9<<tiempo<<"\n";
  }
  f9.close();

   //funcion indexof de linkedlist
   ofstream f10("DLindex.txt");
  for (int i = 0; i < 1000; i++){ 
    inicio=clock(); 
    lista2->indexOf(new Integer(i));
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    if ((i+1)%10==0)
      f10<<tiempo<<"\n";
  }
  f10.close();

   //funcion first de linkedlist
   ofstream f11("DLfirst.txt");
  for (int i = 0; i < 1000; i++){ 
    inicio=clock(); 
    lista2->first();
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    if ((i+1)%10==0)
      f11<<tiempo<<"\n";
  }
  f11.close();

   //funcion last de linkedlist
  ofstream f12("DLlast.txt");
  for (int i = 0; i < 1000; i++){ 
    inicio=clock(); 
    lista2->last();
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    if ((i+1)%10==0)
      f12<<tiempo<<"\n";
  }
  f12.close();

  //funcion remove de linkedlist
  ofstream f8("DLremove.txt");
  for (int i = 0; i < 1000; i++){ 
    inicio=clock();
    lista2->erase(lista_random[i]);
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    if ((i+1)%10==0)
      f8<<tiempo<<"\n";
  }
  f8.close();

//****************************************CursorList******************************
  ofstream f13("CLinsert.txt");
  for (int i = 0; i < 1000; i++){ 
    inicio=clock(); 
    lista3->insert(new Integer(i),lista_random[i]);
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    if ((i+1)%10==0)
      f13<<tiempo<<"\n";
  }
  f13.close();

   //funcion get de Cursorlist
  ofstream f15("CLget.txt");
  for (int i = 0; i < 1000; i++){ 
    inicio=clock(); 
    lista3->get(lista_random[i]);
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    if ((i+1)%10==0)
      f15<<tiempo<<"\n";
  }
  f15.close();

  //funcion indexof de Cursorlist
   ofstream f16("CLindex.txt");
  for (int i = 0; i < 1000; i++){ 
    inicio=clock(); 
    lista3->indexOf(new Integer(i));
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    if ((i+1)%10==0)
      f16<<tiempo<<"\n";
  }
  f16.close();

  //funcion first de Cursorlist
   ofstream f17("CLfirst.txt");
  for (int i = 0; i < 1000; i++){ 
    inicio=clock(); 
    lista3->first();
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    if ((i+1)%10==0)
      f17<<tiempo<<"\n";
  }
  f17.close();

   //funcion last de Cursorlist
  ofstream f18("CLlast.txt");
  for (int i = 0; i < 1000; i++){ 
    inicio=clock(); 
    lista3->last();
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    if ((i+1)%10==0)
      f18<<tiempo<<"\n";
  }
  f18.close();

   //funcion remove de Cursorlist
  ofstream f14("CLremove.txt");
  for (int i = 0; i < 1000; i++){ 
    inicio=clock();
    lista3->erase(lista_random[i]);
    fin=clock();
    tiempo=(double)(fin-inicio)/(double)CLOCKS_PER_SEC;
    if ((i+1)%10==0)
      f14<<tiempo<<"\n";
  }
  f14.close();

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
