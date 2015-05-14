#include "object.h"
#include "tdalist.h"
#include "fsarraylist.h"
#include <iostream>
using namespace std;

FSArrayList::FSArrayList(int capacity){
	this->capacity=capacity;
	data=new Object*[capacity];
}

FSArrayList::~FSArrayList(){
	for (int i = 0; i < size; i++){
		delete data[i];
	}
	delete data;
}

bool FSArrayList::insert(Object* E,int p){
	if (size==capacity){
		return false;
	}
	if (p<0||p>size){
		return false;
	}else{
		for (int i = size; i >p; i--){
			data[i]=data[i-1];
		}
		data[p]=E;
	}
	size++;
	return true;
}

int FSArrayList::indexOf(Object* E)const {
    for (int i=0; i < size; i++){
        if (data[i]->equals(E))
            return i;
    }
    return -1;
}

Object* FSArrayList::get(unsigned index)const {
    if (index < 0 || index >= size){
        return NULL;
    }
    return data[index];
}

bool FSArrayList::erase(unsigned pos){
	if (pos<0||pos>=size){
		return false;
	}
	Object* retval=data[pos];
	data[pos]=NULL;
	if (pos!=size-1){
		for (int i = pos; i < size-1; i++){
			data[i]=data[i+1];
		}
		data[size-1]=NULL;
	}
	size--;
	return true;
}

int FSArrayList::prev(int pos) const {
    return pos - 1;
}

int FSArrayList::next(int pos) const {
    return pos + 1;
}

void FSArrayList::reset() {
    delete [] data;
    data= new Object*[capacity];
	size=0;
}

Object* FSArrayList::first()const {
    if (size>0){
    	return data[0];
    }else{
    	return NULL;
    }
}

Object* FSArrayList::last()const {
	if (size>0){
		return data[size-1];
	}else{
		return NULL;
	}
}

void FSArrayList::print()const {
    for (int i = 0; i < size; i++){
    	data[i]->print();
    }
}

bool FSArrayList::isFull()const {
	if (size>=capacity){
		return true;
	}
    return false;
}

int FSArrayList::getCapacity()const{
    return capacity;
}