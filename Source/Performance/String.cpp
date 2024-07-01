#ifndef STRING_CPP
#define STRING_CPP

#include "String.h"
#include <iostream.h>

void String::operator=(char * str)
{
    setSize(strlen(str));
    strcpy(string,str);
}

int String::operator==(char * str)
{
    return strcmp(string,str);     
}

int String::operator==(String str)
{
    return strcmp(string,str.toCharArray());     
}

void String::operator=(String str)
{
    setSize(strlen(str.toCharArray()));
    strcpy(string,str.toCharArray());
}

char * String::operator+(char * str)
{
    appendSize(strlen(str));
    strcat(string,str);     
    return string;
}

char * String::operator+(String str)
{
    appendSize(strlen(str.toCharArray()));
    strcat(string,str.toCharArray());
    return string;          
}

char * String::toCharArray()
{
    return string;      
}   

void String::appendSize(int size)
{
    char * temp = new char[strlen(string)+1];
    strcpy(temp,string);
    string = new char[strlen(temp)+size];
    strcpy(string, temp);     
}

void String::setSize(int size)
{
    string = new char[size]; 
}

#endif
