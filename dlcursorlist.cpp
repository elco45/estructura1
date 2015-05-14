#include "dlcursorlist.h"
#include "object.h"
#include "tdalist.h"
using namespace std;

DLCursorList::DLCursorList(int capacity){
	this->capacity=capacity;
	rows=new Row[capacity];
	if(!rows){
		throw "NO hay memoria";
	}
	head=-1;

}
DLCursorList::~DLCursorList(){
	delete rows;
}
bool DLCursorList::insert(Object* E, int pos) {
	if(pos<0||pos>size){
		return false;
	}
	if(size==capacity){
		return false;
	}
	int neo= avail();
	if(head==-1){
		head=neo;
		rows[head]->prev=-1;
		rows[head]->next=-1;
		rows[head]->data=E;
	}else if(pos==0&&head!=-1){
		rows[neo]->prev=-1;
		rows[neo]->next=head;
		rows[head]->prev=neo;
		head=neo;
		rows[head].data=E;
	}else{
		int tmp=head;
		for (int i = 0; i < pos; i++){
			tmp=rows[tmp]->next;
		}
		rows[neo]->prev=tmp;
		rows[neo]->next=rows[tmp]->next;
		rows[neo]->data=E;
		rows[tmp]->next=neo;
		if(pos<size){
			rows[rows[neo]->next]->prev=neo;
		}
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
	if(pos<0||p>=size){
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
		delete[] row[eliminar];
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
		delete[] rows[eliminar];
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
	if(size!=0){
		int tmp;
		for (int i = 0; i < size; ++i){
			if(rows[i]){
				tmp=i;
			}
		}
		return rows[tmp]->data;
	}
}
void DLCursorList::print()const {
	cout<<"Holaa"<<endl;

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
	int retval;
	for(retval=0; retval<capacity; retval++){
		if(!rows[retval]->data)
			break;
		return retval;
	}
}