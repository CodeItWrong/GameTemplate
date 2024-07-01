#ifndef TIMER_H
#define TIMER_H

//#include "String.h"

#include <string>
#include <vector>
using namespace std;

class Timer
{
    private:        
             
     
    public:    
       Timer();                    
       void Reset_Timer();
       float GetHours();
       float GetMinutes();
       float GetSeconds();
       float GetMilliSeconds();  
       void SetName(string MyName);  
       void SetGameTime(float HoursPer24);                 
       float GetDays();
       
       string name;
       string type;
       string units;
        
       float StartTime; 
       float OldTime;
       float CurrentTime;
       float HoursToDay;
};

class TimerArray
{
    private:
        int count;
        //Timer *Timers;                
    
    public:
       int Create_EventTimer(float StartTime, string Units);
       int Create();       
       void Add(Timer timer);
       void Remove(int Index);      
       Timer Item(int index);
       int Count();
       vector<Timer> MyTimers; 
       
};

//` Called by Setup_Timers()
//Function GetFreq()
//    Load DLL "Kernel32.dll", 1
//
//    Memory = Make Memory(16)
//    Call Dll 1, "QueryPerformanceFrequency", Memory
//    Freq# = *Memory
//    
//    Delete DLL 1 : Delete Memory Memory    
//EndFunction Freq#

#endif
