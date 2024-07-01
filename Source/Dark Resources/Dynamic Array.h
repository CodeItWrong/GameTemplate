#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include "String.h"

class DynamicArray
{
    private:
        int count;
        int *Values; 
    
    public:
       void Add(int value);
       void Remove(int index);      
       int Item(int index);
       int Count();
};

class DynamicArray$
{
    private:
        int count;
        String *Strings; 
    
    public:
       void Add(String string);
       void Remove(int index);      
       String Item(int index);
       int Count();
};

#endif
