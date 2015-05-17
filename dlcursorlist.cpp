#include <iostream>
#include "dlcursorlist.h"
#include "object.h"
#include "tdalist.h"
#include <stddef.h>
using namespace std;

DLCursorList::DLCursorList(int capacity){
	this->capacity=capacity;
	rows=new Row*[this->capacity];
	if(!rows){
		throw "NO hay memoria";
	}
	this->head=-1;

}
DLCursorList::~DLCursorList(){
	delete rows;
}
bool DLCursorList::insert(Object* E, int pos) {
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
	}
	size++;
	return true;


}
int DLCursorList::indexOf(Object* E)const {
	int tmp=head;
	for (int i = 0; i < size; ++i){
		if(rows[tmp]->data->equals(E)){
			return i;
		}else{
			tmp=rows[tmp]->next;
		}
	}
	return -1;

}
Object* DLCursorList::get(unsigned pos)const {

	if(pos<0||pos>=size){
		return NULL;
	}
	int tmp=head;
	for (int i = 0; i < pos; ++i){
		tmp=rows[tmp]->next;
	}
	return rows[tmp]->data;

}
bool DLCursorList::erase(unsigned pos) {
	if(pos<0||pos>=size){
		return false;
	}
	Object* retval;
	int tmp;
	if(pos==0){
		tmp=rows[head]->next;
		rows[head]->next=-1;
		retval=rows[head]->data;
		rows[head]->data=NULL;
	}else if(pos==size-1){
		tmp=head;
		for (int i = 1; i < pos; i++){
			tmp=rows[tmp]->next;
		}
		int eliminar=rows[tmp]->next;
		rows[tmp]->next=-1;
		rows[eliminar]->prev=-1;
		//delete rows[eliminar];
	}else{
		tmp=head;
		for (int i = 0; i < pos; i++){
			tmp=rows[tmp]->next;
		}
		int eliminar=rows[tmp]->next;
		rows[tmp]->next=rows[rows[tmp]->next]->next;
		rows[rows[tmp]->next]->prev=tmp;
		rows[eliminar]->next=-1;
		rows[eliminar]->prev=-1;
		retval=rows[eliminar]->data;
		//delete rows[eliminar];
	}
	size--;
	return retval;

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
		return rows[head]->data;
	}
	return NULL;

}
Object* DLCursorList::last()const {
	/*if(size!=0){
		int tmp;
		for (int i = 0; i < size; ++i){
			if(rows[i]!=NULL){
				tmp=i;
			}
		}
		return rows[tmp].data;
	}*/
	return rows[size-1]->data;
}
void DLCursorList::print()const {
	//cout<<"Holaa"<<endl;
	int tmp=head;
	Object* temp;
	for (int i = 0; i < size; ++i){
		//cout<<rows[tmp].data<<endl;
		temp=rows[i]->data;
		cout<<temp<<endl;
		tmp=rows[i]->next;
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