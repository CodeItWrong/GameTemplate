// Include the header
#include "header.h"
// Include other headers here.
#include <string>
#include <sstream>
using namespace std;

// Shouldn't I have MyLoop 2 show up twice as often?

// Whatever code here.
float PerfTimer()
{
    if (TimerSetup == false)
    {
        QueryPerformanceFrequency(&Frequency);
        
        LARGE_INTEGER CurrentTick;
        QueryPerformanceCounter(&CurrentTick);
        
        OldTime = CurrentTick.QuadPart / (Frequency.QuadPart / 1000000);
               
        TimerSetup = true;               
        
        return OldTime;
    }
    
    LARGE_INTEGER CurrentTick;
    QueryPerformanceCounter(&CurrentTick);

    return CurrentTick.QuadPart / (Frequency.QuadPart / 1000000);
}

DLLCMDC void SetupPerformance()
{
    HMODULE mod;

    mod = GetModuleHandle("Matrix1Util_20.dll");

    if (mod) {
        *((void **)&Import3000) = GetProcAddress(mod, "CallFunctionName"); // CALL FUNCTION NAME%S%CallFunctionName
    }
    
    mod = GetModuleHandle("Matrix1Util_15.dll");

    if (mod) {
        *((void **)&Import3001) = GetProcAddress(mod, "NiceSleep"); // NICE WAIT%D%NiceSleep%Milliseconds
    }
    
    //MessageBox(NULL, "This is a demo. Goto: http://tinyurl.com/cz2tllq to buy it!", "Demo", MB_OK);
}

void MUCallFunctionPointer(LPSTR p1) 
{
    Import3000(p1);
}

void MUNiceWait(int p1) 
{
    Import3001(p1);
}

DLLCMDC void CreateLoop(LPSTR FunctionName, int LPSCap)
{
    PEvent Event;
    
    Event.FunctionName = FunctionName;
    Event.LPSCap = LPSCap;
    Events.insert(Events.end(), Event);
}
//
//Function Update_Performance()  
//	InActive = 0
//  
//    ` Get Game Time in both seconds and mili-seconds
//    Seconds# = GetSeconds(GameTimer) 
//    MiliSeconds# = GetMilliSeconds(GameTimer)
//    
//    ` Calculate Overall LPMS
//    Loop_LPMS# = (LoopCount / MiliSeconds#)
//    
//    ` Reset NotWasted & Reset NonWasted_LPMS Variables
//    NotWasted = 0 : NonWasted_LPMS = 0
//    
//    Count = Array Count(Performance_Events())
//            
//    ` Handle Events
//    For Index = 0 To Count                      
//        Event_LPSCap = Performance_Events(Index).LPSCap
//        Event_LoopCount = Performance_Events(Index).LoopCount
//                        
//        Event_LPS = Event_LoopCount / Seconds#
//        Event_LPMS = Event_LoopCount / MiliSeconds#
//            
//        ` Call the Event and Inc the Event_LoopCount and Set NotWasted to 1
//        If Event_LPS <= Event_LPSCap            
//            If Performance_Events(Index).IsThread = 1                
//                Set_CanRunFlag(Performance_Events(Event).ThreadIndex, 1)
//            Else
//                Call Function Name Performance_Events(Index).FunctionName$
//            EndIf
//            
//            Inc Performance_Events(Index).LoopCount, 1
//            NonWasted_LPMS = NonWasted_LPMS + Event_LPMS : NotWasted = 1
//        EndIf        
//    Next Index
//    
//    ` Calculates the Wasted Loops Per Mili-Second
//    ` Inc WastedLoops by one if Display and Main were not run!
//    WastedLPMS# = Loop_LPMS# - NonWasted_LPMS : If NotWasted = 0 Then Inc WastedLoops, 1
//    
//    ` Output before the WastedLoops variable is reset
//    ` Output Performance Data to the Console if active
//    If PerformanceData = 1    
//        Clear Console            
//        Print Console "Performance Functions/Threads: " + Str$(PEvent_Count + 1) + LF$()
//        Print Console "Seconds: " + Str$(Seconds#, 10) + LF$()
//        Print Console "Mili-Seconds: " + Str$(MiliSeconds#, 10) + LF$()
//        Print Console "Overal Loops Per Mili-Second: " + Str$(Loop_LPMS#, 10) + LF$()
//        Print Console "Wasted Loops Per Mili-Second: " + Str$(WastedLPMS#, 10) + LF$()
//        Print Console "Wasted Loops: " + Str$(WastedLoops) + LF$()
//        Print Console "Wasted Mili-Seconds: " + Str$((WastedLoops / WastedLPMS#), 10) + LF$()
//        Print Console "Non-Wasted Loops Per Mili-Second: " + Str$(NonWasted_LPMS) + LF$()        
//        Print Console "Active: " + Str$(InActive) + LF$()        
//    EndIf
//            
//    ` Handle Wasted Time and returns the wasted time back to the processor    
//    If WastedLoops <> 0 And WastedLPMS# <> 0.0            
//        WastedTime# = (WastedLoops / WastedLPMS#)
//        
//        If WastedTime# >= 1.0
//        	InActive = 1
//            Nice Wait 1.0
//            WastedLoops = 0
//        EndIf
//    EndIf        
//    
//    ` Inc the Overall Loop Count
//    Inc LoopCount, 1    
//EndFunction

string convertInt(float number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}


DLLCMDC float UpdateSync()
{
    StartFunction
        
    bool InActive = false;
    float Temp = ((PerfTimer() - OldTime) / Frequency.QuadPart);  // First time this is called it is garbage!   
    float MiliSeconds = ((PerfTimer() - OldTime) / Frequency.QuadPart) * 1000; 
    float Seconds = ((PerfTimer() - OldTime) / Frequency.QuadPart); 
    float Loop_LPMS = (LoopCount / MiliSeconds);
    
    bool NotWasted = false;
    float NonWasted_LPMS = 0;
    float WastedTime;
   
    for (int Index = 0; Index < Events.size(); Index++)
    {
        int Event_LPSCap = Events[Index].LPSCap;
        int Event_LoopCount = Events[Index].LoopCount;    
                        
        float Event_LPS = Event_LoopCount / Seconds;
        float Event_LPMS = Event_LoopCount / MiliSeconds;
        
        //string MyString = convertInt(Event_LoopCount);        
        //MessageBox(NULL, MyString.c_str(), "Demo", MB_OK); 
            
        // Call the Event and Inc the Event_LoopCount and Set NotWasted to 1
        if (Event_LPS <= Event_LPSCap)            
        {  
           MUCallFunctionPointer(Events[Index].FunctionName);       
           Events[Index].LoopCount = Events[Index].LoopCount + 1;
           NonWasted_LPMS = NonWasted_LPMS + Event_LPMS;  
           NotWasted = true;
           
           dbFastsync();        
        }
    }
    
    //string MyString = convertInt(NonWasted_LPMS); 
    //GetGlobStruct()->PrintStringFunction(MyString, false);
     
    // Calculates the Wasted Loops Per Mili-Second
    // Inc WastedLoops by one if Display and Main were not run!
    float WastedLPMS = Loop_LPMS - NonWasted_LPMS;    
    if (NotWasted == false) { WastedLoops = WastedLoops + 1; }
    
    // Handle Wasted Time and returns the wasted time back to the processor    

    if (WastedLoops != 0 && WastedLPMS != 0.0)          
    {
        WastedTime = (WastedLoops / WastedLPMS);
        
        if (WastedTime >= 1.0) 
        {           
        	InActive = true;
            MUNiceWait(1); // Doesn't work!
            WastedLoops = 0;
        }
    }        
    
    // Inc the Overall Loop Count
    LoopCount = LoopCount + 1; 
    
    //return Events[0].LoopCount; //Events[0].LoopCount - Returns a weird number!    
}

DLLCMDC void Update()
{
    StartFunction
    
    
    //if (Started == true) 
    //{
        //MUNiceWait(1000);
        //Started = false;            
    //}
        
    bool InActive = false;
    //float Temp = ((PerfTimer() - OldTime) / Frequency.QuadPart);  // First time this is called it is garbage!   
    float MiliSeconds = ((PerfTimer() - OldTime) / Frequency.QuadPart) * 1000; 
    float Seconds = ((PerfTimer() - OldTime) / Frequency.QuadPart); 
    float Loop_LPMS = (LoopCount / MiliSeconds);
    
    bool NotWasted = false;
    float NonWasted_LPMS = 0;
    float WastedTime;
   
    for (int Index = 0; Index < Events.size(); Index++)
    {
        int Event_LPSCap = Events[Index].LPSCap;
        int Event_LoopCount = Events[Index].LoopCount;    
                        
        float Event_LPS = Event_LoopCount / Seconds;
        float Event_LPMS = Event_LoopCount / MiliSeconds;
        
        //string MyString = convertInt(Event_LoopCount);        
        //MessageBox(NULL, MyString.c_str(), "Demo", MB_OK); 
            
        // Call the Event and Inc the Event_LoopCount and Set NotWasted to 1
        if (Event_LPS <= Event_LPSCap)            
        {  
           MUCallFunctionPointer(Events[Index].FunctionName);       
           Events[Index].LoopCount = Events[Index].LoopCount + 1;
           NonWasted_LPMS = NonWasted_LPMS + Event_LPMS;  
           NotWasted = true;      
        }
    }
    
    //string MyString = convertInt(NonWasted_LPMS); 
    //GetGlobStruct()->PrintStringFunction(MyString, false);
     
    // Calculates the Wasted Loops Per Mili-Second
    // Inc WastedLoops by one if Display and Main were not run!
    float WastedLPMS = Loop_LPMS - NonWasted_LPMS;    
    if (NotWasted == false) { WastedLoops = WastedLoops + 1; }
    
    // Handle Wasted Time and returns the wasted time back to the processor    

    if (WastedLoops != 0 && WastedLPMS != 0.0)          
    {
        WastedTime = (WastedLoops / WastedLPMS);
        
        if (WastedTime >= 1.0) 
        {           
        	InActive = true;
            MUNiceWait(1); // Doesn't work!
            WastedLoops = 0;
        }
    }        
    
    // Inc the Overall Loop Count
    LoopCount = LoopCount + 1; 
    
    //return Events[0].LoopCount; //Events[0].LoopCount - Returns a weird number!    
    
    //return MiliSeconds;
}


DLLCMDC void CallFunction(LPSTR Name)
{
    MUCallFunctionPointer(Name);
}
