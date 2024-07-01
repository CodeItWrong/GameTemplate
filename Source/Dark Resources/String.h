#ifndef STRING_H
#define STRING_H

class String
{
    private:
        char * string;  
        
        void appendSize(int size);
        void setSize(int size);
     
             
    public:
        char * toCharArray(void);   
        
        void operator=(String str);
        void operator=(char * str);
        
        int operator==(char * str);   
        int operator==(String str);
        
        char * operator+(char * str);
        char * operator+(String str);
        
        // Convert to string
        //void operator+(int val);
        //void operator=(int val);
        //void operator==(int val);
            
        
};

#endif
