#ifndef DLCURSORLIST_H
#define DLCURSORLIST_H

#include "object.h"
#include "tdalist.h"


class DLCursorList:public TDAList{
	struct Row{
		int prev,next;
        Object* data;
        row(Object* E){
            prev=next=-1;
            data=E;
        }
	};
	int head,cola, proximo;
	Row* rows;
	int capacity;
    int avail();
public:
	DLCursorList(int);
	virtual ~DLCursorList();
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