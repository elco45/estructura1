#include "dlcursorlist.h"
#include "object.h"
#include "tdalist.h"
using namespace std;

DLCursorList::DLCursorList(int capacity){
	this->capacity=capacity;
}
DLCursorList::~DLCursorList(){

}
bool DLCursorList::insert(Object* E, int pos) {

}
int DLCursorList::indexOf(Object* E)const {

}
Object* DLCursorList::get(unsigned pos)const {

}
bool DLCursorList::erase(unsigned pos) {

}
int DLCursorList::prev(int pos) const {
	return pos-1;
}
int DLCursorList::next(int pos) const {
	return pos+1;
}
void DLCursorList::reset() {

}
Object* DLCursorList::first()const {

}
Object* DLCursorList::last()const {

}
void DLCursorList::print()const {

}
bool DLCursorList::isFull()const {

}
int DLCursorList::getCapacity()const{
	return capacity;
}