// Include the header
#include "header.h"
// Include other headers here.


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

int MULoadDll(LPSTR p1) 
{
    return Import3000(p1);
}

int MUGetDllFunctionPtr(int p1, LPSTR p2) 
{
    return Import3001(p1, p2);
}

int MUGetFunctionPtrByName(LPSTR p1) 
{
    return Import3002(p1);
}

int MUIsValidFunctionPtr(int p1) 
{
    return Import3003(p1);
}

int MUCallFunctionPtr(int p1, int p2, int p3, int p4, int p5, int p6) 
{
    return Import3004(p1, p2, p3, p4, p5, p6);
}

int MUCallFunctionPtr(int p1, int p2) 
{
    return Import3005(p1, p2);
}

void MUCallFunctionPointer(LPSTR p1) 
{
    Import3006(p1);
}

void MUNiceWait(int p1) 
{
    Import3007(p1);
}

int CreateLoop(LPSTR FunctionName, int LPSCap, int ThreadIndex)
{
    PEvent Event;
    
    Event.FunctionName = FunctionName;
    Event.LPSCap = LPSCap;
    Event.IsThread = true;
    Event.ThreadIndex = ThreadIndex;
    Events.insert(Events.end(), Event);
    return Events.size();
}

// Can run flag is controlled here
// Have to run an update thread
// Sleeps if can run is 0 and doesn't when it is 1

DLLCMDC void UpdateThread(int Thread)
{    
    if (Threads[Thread].CanRun == false)
    {
        //MUNiceWait(1);
        //dbCallDll(Kernel32_Dll, "Sleep", 1);  
    }}

DLLCMDC void UpdateThreads()
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
            
        // Call the Event and Inc the Event_LoopCount and Set NotWasted to 1
        if (Event_LPS <= Event_LPSCap)            
        {  
           if (Events[Index].IsThread == true)
           {
               //MUCallFunctionPointer(Events[Index].FunctionName);       
               Threads[Events[Index].ThreadIndex].CanRun = true;
           }
                      
           Events[Index].LoopCount = Events[Index].LoopCount + 1;
           NonWasted_LPMS = NonWasted_LPMS + Event_LPMS;  
           NotWasted = true;      
        }
        else {
               Threads[Events[Index].ThreadIndex].CanRun = false;
        }
    }
    
    // CALCULATE HERE IF A CERTAIN THREAD SHOULD WAIT AND RETURN WAIT
    
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
            //MUNiceWait(1);
            //dbCallDll(Kernel32_Dll, "Sleep", 1);
            WastedLoops = 0;
        }
    }        
    
    // Inc the Overall Loop Count
    LoopCount = LoopCount + 1; 
    
    //return Events[0].LoopCount; //Events[0].LoopCount - Returns a weird number!    
}

DLLCMDC void StartMultiThreading(int DllIndex)
{
    HMODULE mod;

    mod = GetModuleHandle("Matrix1Util_20.dll");

    if (mod) {
        *((void **)&Import3000) = GetProcAddress(mod, "LoadDll"); // LOAD DLL[%DS%LoadDll%DLL Name
    }       
    
    if (mod) {
        *((void **)&Import3001) = GetProcAddress(mod, "GetDllFunctionPtr"); // GET PTR TO DLL FUNCTION[%DDS%GetDllFunctionPtr%DLL Handle, Function Name
    }  
    
    if (mod) {
        *((void **)&Import3002) = GetProcAddress(mod, "GetFunctionPtrByName"); // GET PTR TO FUNCTION[%DS%GetFunctionPtrByName%Function name
    }
    
    if (mod) {
        *((void **)&Import3003) = GetProcAddress(mod, "IsValidFunctionPtr"); // FUNCTION PTR IS VALID[%DD%IsValidFunctionPtr%Function Pointer
    }
    
    if (mod) {
        *((void **)&Import3004) = GetProcAddress(mod, "CallFunctionPtr"); // CALL FUNCTION PTR[%XLXXXXXXXXX%CallFunctionPtr
    }
    
    if (mod) {
        *((void **)&Import3005) = GetProcAddress(mod, "CallFunctionPtr"); // CALL FUNCTION PTR[%XLXXXXXXXXX%CallFunctionPtr
    }
    
    mod = GetModuleHandle("Matrix1Util_20.dll");

    if (mod) {
        *((void **)&Import3006) = GetProcAddress(mod, "CallFunctionName"); // CALL FUNCTION NAME%S%CallFunctionName
    }
    
    mod = GetModuleHandle("Matrix1Util_15.dll");

    if (mod) {
        *((void **)&Import3007) = GetProcAddress(mod, "NiceSleep"); // NICE WAIT%D%NiceSleep%Milliseconds
    }
    
    StartFunction
    
    Kernel32_Ptr = MULoadDll("Kernel32.dll"); 
    dbLoadDll("Kernel32.dll", DllIndex);
    Kernel32_Dll = DllIndex;
    
    //MessageBox(NULL, "This is a demo. Goto:  to buy it!", "Demo", MB_OK);
}

DLLCMDC int MTCreateThread(LPSTR FunctionName, int LPSCap)
{
    int DllPtr = MUGetDllFunctionPtr(Kernel32_Ptr, "CreateThread");    
    int FunctionPtr = MUGetFunctionPtrByName(FunctionName); 
      
    if (MUIsValidFunctionPtr(DllPtr) == 1)         
    {
        if (MUIsValidFunctionPtr(FunctionPtr) == 1) 
        {    
             
            Thread MyThread;
    
            MyThread.MemoryID = dbMakeMemory(4);
            MyThread.MemorySize = 4;
            MyThread.FunctionName = FunctionName;
            MyThread.FunctionPtr = FunctionPtr;
            MyThread.DllPtr = DllPtr;                        
            
            MyThread.Handle = MUCallFunctionPtr(DllPtr, 0, MyThread.MemorySize, FunctionPtr, 0, MyThread.MemoryID); 
                       
            MyThread.EventIndex = CreateLoop(FunctionName, LPSCap, Threads.size());            
            Threads.insert(Threads.end(), MyThread);  
        }
        else  {
            MessageBox(NULL, "CreateThread: Function Pointer Invalid!", "Error", MB_OK);    
        }
    }
    else  {
        MessageBox(NULL, "CreateThread: DLL Pointer Invalid!", "Error", MB_OK);    
    }  
    
    return Threads.size();        
}

DLLCMDC void MTCloseThread(int Index)
{
    StartFunction
    
    int DllPtr = MUGetDllFunctionPtr(Kernel32_Ptr, "CloseHandle"); 
    
    if (MUIsValidFunctionPtr(DllPtr) == 1)         
    {
        MUCallFunctionPtr(DllPtr, Threads[Index].Handle);  
        dbDeleteMemory(Threads[Index].MemoryID);
    }    
    else  {
        MessageBox(NULL, "CloseHandle: Function Pointer is Invalid!", "Error", MB_OK);    
    }
    //       
}

// Load DLL is from Matrix commands!

//Global Kernel32Ptr : Kernel32Ptr = Load Dll("Kernel32.dll")
//Global Kernel32_DLL : Kernel32_DLL = LoadDll("Kernel32.dll") ` Used by Multi-Threading and Timers
//
//Function LoadDll(DllName$)
//    Index = NextDll()
//    Load DLL DllName$, Index
//EndFunction Index
//
//`````````````````````````````
//` Multi-Threading Functions `
//```````````````````````````````````````````````````````````````````````````````````````````````
//Function CreateThread(FunctionName$)    
//    DllPtr = Get Ptr To Dll Function(Kernel32Ptr, "CreateThread")
//    FunctionPtr = Get Ptr To Function(FunctionName$)
//    
//    If Function Ptr Is Valid(FunctionPtr) = 1
//        If Function Ptr Is Valid(DllPtr) = 1
//            Add To Stack Threads() : Index = Array Count(Threads())        
//            
//            Threads().MemoryID = Make Memory(ThreadMem)
//            Threads().MemorySize = ThreadMem
//            Threads().FunctionName$ = FunctionName$
//            Threads().FunctionPtr = FunctionPtr        
//            Threads().DllPtr = DllPtr
//                        
//            Threads().Handle = Call Function Ptr(DllPtr, 0, Threads().MemorySize, FunctionPtr, 0, Threads().MemoryID)
//            
//            `Lua_NameThread(Index, FunctionName$) ` Uses Lua to store the Name and Index
//        Else            
//            If DebugMode = 1 Then Send_Error$("CreateThread: Function Pointer is Invalid!")
//        EndIf
//    Else
//        If DebugMode = 1 Then Send_Error$(FunctionName$ + ": Function Pointer is Invalid!")
//    EndIf
//EndFunction Index
//
//Function CloseThread(Index)
//    ClosePtr = Get Ptr To Dll Function(Kernel32Ptr, "CloseHandle")
//
//    If Function Ptr Is Valid(ClosePtr) = 1
//        Call Function Ptr ClosePtr, Threads(Index).Handle
//        Delete Memory Threads(Index).MemoryID
//    Else
//        If DebugMode = 1 Then Send_Error$("CloseHandle: Function Pointer is Invalid!")
//        Delete Memory Threads(Index).MemoryID
//    EndIf    
//EndFunction
//
//Function CloseAll_Threads()
//    ThreadCount = Array Count(Threads())
//    
//    If ThreadCount <> -1        
//        For Index = 0 To ThreadCount        
//            CloseThread(Index)
//        Next Index
//    EndIf
//EndFunction
//
//Function ThreadSleep(MilliSeconds)
//    Call DLL Kernel32_DLL, "Sleep", MilliSeconds
//EndFunction
//
//```````````
//` Mutexes `
//````````````````````````````````````````````````````````````````````````````````````````````````
//Function CreateMutex()
//    ` Create the Mutex/Bank that will be used by the Threads
//    Make SysObj Mutex ThreadMutex, "Thread_Mutex"
//    
//    Count = Array Count(Threads()) + 1
//    
//    If Count <> 0 
//        Map Shared Mem To Bank "Thread_Bank", ThreadBank, (1 * Count)
//    Else
//        Map Shared Mem To Bank "Thread_Bank", ThreadBank, 1
//    EndIf    
//EndFunction
//
//Function Set_CanRunFlag(ThreadIndex, CanRunFlag)
//    Index = ThreadIndex + 1
//    
//    If Index <= Get Bank Size(ThreadBank)
//        Lock SysObj ThreadMutex
//        Write Bank Boolean ThreadBank, Index, CanRunFlag
//        Unlock SysObj ThreadMutex
//    Else        
//        If DebugMode = 1 Then Send_Error$("Thread Index outside allocated Bank Range!")        
//    EndIf
//EndFunction
//
//Function Get_CanRunFlag(ThreadIndex)
//    Index = ThreadIndex + 1
//    
//    ` Wait until the SysObj is Unlocked
//    While Is SysObj Locked(ThreadMutex) = 1
//        If EscapeKey() = 1 Then ExitFunction 0
//    EndWhile
//    
//    If Index <= Get Bank Size(ThreadBank)
//        Lock SysObj ThreadMutex
//        CanRunFlag = Bank Boolean(ThreadBank, Index)
//        Unlock SysObj ThreadMutex
//    Else
//        If DebugMode = 1 Then Send_Error$("Thread Index outside allocated Bank Range!")        
//    EndIf
//EndFunction CanRunFlag
