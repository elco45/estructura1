#ifndef FSARRAYLIST_H
#define FSARRAYLIST_H
#include "object.h"
#include "tdalist.h"
using namespace std;

class FSArrayList: public TDAList{
	int capacity;
	Object** data;
public:
	FSArrayList(int);
	virtual ~FSArrayList();
	virtual bool insert(Object*, int) ;
    virtual int indexOf(Object*)const ;
    virtual Object* get(unsigned)const ;
    virtual bool erase(unsigned) ;
    virtual int prev(int) const ;
    virtual int next(int) const ;
    virtual void reset() ;
    virtual Object* first()const ;
    virtual Object* last()const ;
    virtual void print()const ;
    virtual bool isFull()const ;
    virtual int getCapacity()const;
};
#endif
