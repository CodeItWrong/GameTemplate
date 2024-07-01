#ifndef MAIN_CPP
#define MAIN_CPP


// Include the header
#include "header.h"
// Include other headers here.


// Event based countdown to calling function!
// Time Conversion to GameTime

// IsDay/IsNight commands

// Whatever code here.

//typedef list<Timer> TimerList;

// IM HAVING ITEM ISSUES!!!!

// YOU CAN NOT RETURN AN ITEM YOU MUST RETURN THE POINTER TO AN ITEM INSTEAD BECAUSE IF
// YOU RETURN THE ITEM IT IS JUST A COPY OF THAT ITEM AND NOT THE ACTUAL ITEM


float PerfTimer()
{
    LARGE_INTEGER CurrentTick;
    QueryPerformanceCounter(&CurrentTick);

    return CurrentTick.QuadPart / (Frequency.QuadPart / 1000000);
}

//int dbInt(float p1)
//{
//    return Import3001(p1);
//}

DLLCMDC float GetPerfTime()
{
    return PerfTimer();
}

DLLCMDC float GetOldTime(int Index)
{
    return timers.Item(Index).OldTime;
}

DLLCMDC void SetupTimers()
{
    QueryPerformanceFrequency(&Frequency);   
    
    //MessageBox(NULL, "This is a demo. Goto: http://tinyurl.com/cz2tllq to buy it!", "Demo", MB_OK);  
    
    //HMODULE mod;
//
//    mod = GetModuleHandle("DBProCore.dll");
//
//    if (mod) {
//        *((void **)&Import3001) = GetProcAddress(mod, "?IntLF@@YAKM@Z"); // INT[%LF%?IntLF@@YAKM@Z%Value
//    }   
}

DLLCMDC int CreateTimer()
{
    return timers.Create();        
}

DLLCMDC void CreateEventTimer()
{
    //timers.Create();        
}

DLLCMDC float GetDays(int Index)
{
    float Days = ((((PerfTimer() - timers.Item(Index).OldTime) / Frequency.QuadPart) / 60.0) / 60.0) / 24.0;              
    if (timers.Item(Index).HoursToDay != 0) { Days = Days * (24.0 / (24.0 / timers.Item(Index).HoursToDay)); } 
    
    return Days;      
}

DLLCMDC float GetHours(int Index)
{
    float Hours = ((PerfTimer() - timers.Item(Index).OldTime) / Frequency.QuadPart / 60.0) / 60.0;              
    if (timers.Item(Index).HoursToDay != 0) { Hours = Hours * (24.0 / timers.Item(Index).HoursToDay); } 
    
    return Hours;      
}

DLLCMDC float GetMinutes(int Index)
{
    float Minutes = ((PerfTimer() - timers.Item(Index).OldTime) / Frequency.QuadPart) / 60.0;
    if (timers.Item(Index).HoursToDay != 0) { Minutes = Minutes * (24.0 / timers.Item(Index).HoursToDay); } 
 
    return Minutes;            
}

DLLCMDC float GetSeconds(int Index)
{
    float Seconds = (PerfTimer() - timers.Item(Index).OldTime) / Frequency.QuadPart;
    if (timers.Item(Index).HoursToDay != 0) { Seconds = Seconds * (86400 / (timers.Item(Index).HoursToDay * 3600)); }
    return Seconds;           
}

//MessageBox(NULL, "Team Deathmatch", "Demo", MB_OK);

DLLCMDC float GetMilliSeconds(int Index)
{
    float MiliSeconds = ((PerfTimer() - timers.Item(Index).OldTime) / Frequency.QuadPart) * 1000;  
    if (timers.Item(Index).HoursToDay != 0) { MiliSeconds = MiliSeconds * (86400000 / (timers.Item(Index).HoursToDay * 3600000));  }   
    
    return MiliSeconds;            
}

DLLCMDC void SetGameTimeFactor(int Index, float HoursPer24)
{
    timers.MyTimers[Index].HoursToDay = HoursPer24;      
}

bool IsOdd( int integer )
{

  if ( integer % 2== 0 )
     return true;
  else
     return false;
}

// Have to fix this!! Do some more tests on the board
DLLCMDC int IsDay(int Index)
{
    StartFunction
    
    int IsDayFlag = 0;
    
    if (IsOdd(dbInt(GetHours(Index) / 12)) == true)         
    {
        IsDayFlag = 1;                                
    }
    
    return IsDayFlag;
}

//  int IsDayFlag = 0;    
//    float DaysInHours = 24 / GetHours(Index);    
//    float Remainder = DaysInHours - dbInt(DaysInHours);
//    
//    if (Remainder <= 0.5)
//    {
//        IsDayFlag = 1;                      
//    }    

//float DaysInHours = 24 / GetHours(Index);    
//    float Remainder = DaysInHours - dbInt(DaysInHours);
//    
//    if (Remainder > 0.5)
//    {
//        IsDayFlag = 1;                      
//    }            
//    

DLLCMDC int IsNight(int Index)
{
    StartFunction
    
    int IsDayFlag = 0;
    
    if (IsOdd(dbInt(GetHours(Index) / 12)) == false)         
    {
        IsDayFlag = 1;                                
    }    
    
    return IsDayFlag;        
}

// Timer Class CPP Start

Timer::Timer()
{
    HoursToDay = 0;              
}

void Timer::Reset_Timer()
{
    OldTime = PerfTimer();         
}

float Timer::GetHours()
{
    

    return 0;
}

float Timer::GetDays()
{
    return 0;
}

void Timer::SetGameTime(float HoursPer24)
{
    HoursToDay = HoursPer24;               
}


float Timer::GetMinutes()
{       
    
    
    return 0;
}

float Timer::GetSeconds()
{
    
    return 0; // If I set this to any number it will still return a weird #!!!!
}

float Timer::GetMilliSeconds()
{
    
           
    return 0;
}

void Timer::SetName(string MyName)
{
    name = MyName;     
}

int TimerArray::Create()
{
    Timer timer;
    //Timers().StartTime# = StartTime#    
    timer.OldTime = PerfTimer();
    timer.type = "Timer";
    
    timers.Add(timer); 
    
    int count = Count() - 1;
    
    return count;
}

int TimerArray::Create_EventTimer(float StartTime, string Units)
{
    Timer timer;
    timer.StartTime = StartTime;  
    timer.units = Units;    
    timer.OldTime = PerfTimer();
    timer.type = "Timer";
    
    Add(timer);
    
    int count = Count() - 1;                       
    
    return count;
}

void TimerArray::Add(Timer timer)
{
 //   Timer *temp = new Timer[count + 1];
//      
//    for (int i = 1; i <= count; i++)
//    {      
//        temp[i] = Timers[i];   
//    }
//    
//    count += 1;
//    temp[count] = timer; // This is crashing!!
//           
//    delete [] Timers;
//    Timers = temp;

    MyTimers.insert(MyTimers.end(), timer); 
}

// Have to return pointer to item!!!!!!!!!!!!!!
Timer TimerArray::Item(int index)
{        
//    iterator i;    
//    i = MyTimers.begin();    
//    return *i;
// Learn how to return an item!
    //Timers[index];
    return MyTimers[index]; //MyTimers.at(index); //MyTimers[index];
}

void TimerArray::Remove(int Index)
{
    MyTimers.erase(MyTimers.begin() + Index);
    
    //list<Timer> *temp = new list<Timer>[MyTimers.size()];
//    
//    for (int i = 1; i <= count - 1; i++)
//    {      
//        temp.insert(temp.end(), MyTimers.front());     
//        MyTimers.PopFront();     
//    }
//    
//    MyTim
    
    //Timer *temp = new Timer[count];
//    
//     Fill temp with the array elements  
//    for (int i = 1; i <= count - 1; i++)
//    {      
//        temp[i] = Timers[i];         
//    }
//    
//     Shift all items over to the left
//    for (int i = 1; i <= count - 1; i++)
//    {
//        temp[i] = temp[i+1];          
//    }
//    
//     Delete the item on the end
//    temp[count] = 0;
//        
//    count -= 1;           
//    delete [] Timers;
//    Timers = temp;
}
//


int TimerArray::Count()
{
    return MyTimers.size();    
}

#endif
