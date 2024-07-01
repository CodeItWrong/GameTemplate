#ifndef DYNAMICARRAY_CPP
#define DYNAMICARRAY_CPP

#include "String.h"

void DynamicArray::Add(int value)
{
    int *temp = new int[count];
      
    for (int i = 1; i <= count; i++)
    {      
        temp[i] = Values[i];   
    }
    
    count += 1;
    temp[count] = value;
           
    delete [] Values;
    Values = temp;
}

int DynamicArray::Item(int index)
{
    int value;

    if ((index > 0) && (index <= count))
    {
        return Values[index];
    }
    else
    {
        return value;    
    }
}

void DynamicArray::Remove(int index)
{
    String *temp = new String[count];
    
    // Fill temp with the array elements  
    for (int i = 1; i <= count; i++)
    {      
        temp[i] = Strings[i];         
    }
    
    // Shift all items over to the left
    for (int i = index; i < count ; i++)
    {
        temp[index] = temp[index+1];          
    }
    
    // Delete the item on the end
    temp[count-1] = 0;
        
    count -= 1;           
    delete [] Strings;
    Strings = temp;
}

int DynamicArray::Count()
{
    return count;    
}

void DynamicArray$::Add(String string)
{
    String *temp = new String[count];
      
    for (int i = 1; i <= count; i++)
    {      
        temp[i] = Strings[i];   
    }
    
    Count += 1;
    temp[count] = string;
           
    delete [] Strings;
    Strings = temp;
}

String DynamicArray$::Item(int index)
{
    String string;

    if ((index > 0) && (index <= count))
    {
        return Strings[index];
    }
    else
    {
        return string;    
    }
}

void DynamicArray$::Remove(int index)
{
    int *temp = new int[count];
    
    // Fill temp with the array elements  
    for (int i = 1; i <= count; i++)
    {      
        temp[i] = Values[i];         
    }
    
    // Shift all items over to the left
    for (int i = index; i < count ; i++)
    {
        temp[index] = temp[index+1];          
    }
    
    // Delete the item on the end
    temp[count-1] = 0;
        
    count -= 1;           
    delete [] Values;
    Values = temp;
}

int DynamicArray$::Count()
{
    return count;    
}

#endif
