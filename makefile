exe: main.o object.o integer.o tdalist.o dllnode.o fsarraylist.o linkedlist.o dlcursorlist.o 
	g++ main.o object.o integer.o tdalist.o dllnode.o fsarraylist.o linkedlist.o dlcursorlist.o -o exe

main.o: main.cpp integer.h tdalist.h fsarraylist.h linkedlist.h dlcursorlist.h
	g++ -c main.cpp 

dlcursorlist.o: dlcursorlist.cpp dlcursorlist.h tdalist.h object.h
	g++ -c dlcursorlist.cpp

fsarraylist.o: fsarraylist.cpp fsarraylist.h tdalist.h object.h
	g++ -c fsarraylist.cpp

linkedlist.o: linkedlist.cpp linkedlist.h tdalist.h object.h
	g++ -c linkedlist.cpp

tdalist.o: tdalist.cpp tdalist.h object.h
	g++ -c tdalist.cpp

integer.o: integer.cpp integer.h object.h
	g++ -c integer.cpp

dllnode.o: dllnode.cpp dllnode.h object.h
	g++ -c dllnode.cpp

object.o: object.cpp object.h
	g++ -c object.cpp
