#include <iostream>
#include "dlcursorlist.h"
#include "object.h"
#include "tdalist.h"
#include <stddef.h>
using namespace std;

DLCursorList::DLCursorList(int capacity){
	this->capacity=capacity;
<<<<<<< HEAD
	rows=new Row*[this->capacity];
	if(!rows){
		throw "NO hay memoria";
	}
	this->head=-1;
=======
	rows=new Row[capacity];
	size=0;
	if(!rows){
		throw "NO hay memoria";
	}
	for (int i = 0; i < capacity; i++){
		rows[i].prev=-1;
		rows[i].data=NULL;
		rows[i].next=-1;
	}
	head=-1;
>>>>>>> 88df29fe9bc9c784653173688986898f9fefa3c4

}
DLCursorList::~DLCursorList(){
	int tmp=head;
	for (int i = 0; i < size; i++){
		delete rows[tmp].data;
		tmp=rows[tmp].next;
	}
	delete[] rows;
}
bool DLCursorList::insert(Object* E, int pos) {
<<<<<<< HEAD
	cout<<"entro"<<endl;
	
	if(pos<0||pos>size){
		return false;
	}
	cout<<"entro 1,4"<<endl;
	if(size==capacity){
		return false;
	}
	cout<<"entro 1.9"<<endl;
	int neo = avail();
	cout<<"entro 2 "<<endl;
	if(head==-1){
		Row* elemento=new Row(E);
		cout<<" 1 "<<endl;
		this->head=neo;
		rows[head]=elemento;
		cout<<"fin"<<endl;
	}else if(pos==0&&head!=-1){
		cout<<"entro 3 "<<endl;
		Row* elemento=new Row(E);
		elemento->next=head;
		rows[head]->prev=neo;
		head=neo;
		rows[head]=elemento;
	}else{
		cout<<"entro 4"<<endl;
		Row* elemento=new Row(E);
		int tmp=head;
		if(neo==size){
			for (int i = 0; i < pos-1; i++){
				tmp=rows[tmp]->next;
			}
			

		}
		for (int i = 0; i < pos-1; i++){
			tmp=rows[tmp]->next;
		}

		cout<<"paso for "<<endl;
		elemento->prev=tmp;
		//rows[neo]->prev=tmp;
		cout<<"sub1"<<endl;
		elemento->next=rows[tmp]->next;
		cout<<"sub2 "<<endl;
		rows[rows[tmp]->next]->prev=neo;
		cout<<"sub3"<<endl;
		rows[tmp]->next=neo;
		cout<<"vamos a lo ultimo"<<endl;
		rows[neo]=elemento;
		/*if(pos<size){
			rows[rows[neo]->next]->prev=neo;
		}*/
=======
	if(pos<0||pos>=capacity){
		return false;
	}
	int neo= nextavail();
	if(head==-1){
		head=neo;
		rows[head].prev=-1;
		rows[head].next=-1;
		rows[head].data=E;
	}else if(pos==0 && head!=-1){
		rows[neo].prev=-1;
		rows[neo].next=head;
		rows[neo].data=E;
		rows[head].prev=neo;
		head=neo;
	}else{
		int tmp = head;
		for (int i = 0; i < pos-1; i++){
			tmp = rows[tmp].next;
		}
		rows[neo].prev = tmp;
		rows[neo].next = rows[tmp].next;
		rows[neo].data = E;
		rows[tmp].next=neo;
		if(pos < size){
			rows[rows[neo].next].prev = neo;
		}
>>>>>>> 88df29fe9bc9c784653173688986898f9fefa3c4
	}
	size++;
	return true;
}

int DLCursorList::indexOf(Object* E)const {
	int tmp=head;
	for (int i = 0; i < capacity; i++){
		if (tmp==-1){
			continue;
		}
		if(rows[tmp].data->equals(E)){
			return i;
		}
		tmp=rows[tmp].next;
		
	}
	return -1;
}

Object* DLCursorList::get(unsigned pos)const {
<<<<<<< HEAD

	if(pos<0||pos>=size){
=======
	if(pos<0||size==0){
>>>>>>> 88df29fe9bc9c784653173688986898f9fefa3c4
		return NULL;
	}
	int tmp=head;
	for (int i = 0; i < pos; i++){
		tmp=rows[tmp].next;
	}
	return rows[tmp].data;
}

bool DLCursorList::erase(unsigned pos) {
	if(pos<0||pos>=size){
		return false;
	}
	Object* retval;
	int tmp,neo;
	if(pos==0){
		tmp=head;
		retval=rows[head].data;
		head=rows[head].next;
		rows[tmp].prev = -1;
		rows[tmp].data = NULL;
		rows[tmp].next = -1;
		rows[head].prev = -1;
	}else{
		tmp = head;
		for(int i =0 ; i < pos-1; i++){
			tmp = rows[tmp].next;
		}
		neo = rows[tmp].next;
		retval = rows[neo].data;
		rows[tmp].next = rows[neo].next;
		rows[rows[neo].next].prev = tmp;
	}
	size--;
	return true;


}

int DLCursorList::prev(int pos) const {
	return pos-1;
}

int DLCursorList::next(int pos) const {
	return pos+1;
}

void DLCursorList::reset() {
	size=0;
}

Object* DLCursorList::first()const {
	if(head!=-1){
		return rows[head].data;
	}
	return NULL;
}

Object* DLCursorList::last()const {
	int tmp = head;
	int cont = 0;
	do{
		tmp = rows[tmp].next;
		cont++;
	}while(cont<size);
	return rows[tmp].data;
}

void DLCursorList::print()const {
	int tmp=head;
	int cont = 0;
	for (int i = 0; i <size; i++){
		rows[tmp].data->print();
		tmp = rows[tmp].next;
	}
		
	
}

bool DLCursorList::isFull()const {
	if(size==capacity){
		return true;
	}
	return false;

}

int DLCursorList::getCapacity()const{
	return capacity;
}
<<<<<<< HEAD
int DLCursorList::avail(){
	cout<<"entro a avail"<<endl;
	int retval=0;
	for(retval=0; retval<capacity; retval++){
	
		if(rows[retval]==NULL){
			break;
				
		}
	}
	cout<<"rompe "<<retval<<endl;
	return retval;
}
=======

int DLCursorList::nextavail(){
	for(int i=0; i<capacity; i++){
		if(rows[i].data==NULL && rows[i].prev==-1 && rows[i].next==-1){
			return i;
		}
	}
}
>>>>>>> 88df29fe9bc9c784653173688986898f9fefa3c4
