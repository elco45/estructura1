#include <iostream>
#include "dlcursorlist.h"
#include "object.h"
#include "tdalist.h"
#include <stddef.h>
using namespace std;

DLCursorList::DLCursorList(int capacity){
	this->capacity=capacity;
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
	if(pos<0||size==0){
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

int DLCursorList::nextavail(){
	for(int i=0; i<capacity; i++){
		if(rows[i].data==NULL && rows[i].prev==-1 && rows[i].next==-1){
			return i;
		}
	}
}
