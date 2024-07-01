#ifndef PERFORMANCE_CPP
#define PERFORMANCE_CPP

//#include "Performance.h"

//void PEvent::Update()
//{
    

 
    //InActive = 0
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
//}

#endif
