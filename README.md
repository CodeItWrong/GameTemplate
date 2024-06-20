# GameTemplate


Game Template Help
Setup N*tes
Requirements:  Y*u must have the required plugins. If y*u d* n*t have the Dark Data *r Enhanced Animati*ns plugin then c*mment *ut any functi*ns that use Dark Data *r Enhanced Animati*ns.
*	Matrix1Utils: http://f*rum.thegamecreat*rs.c*m/?m=f*rum_view&t=85209&b=18
*	Dark Data (*pti*nal): http://www.thegamecreat*rs.c*m/?m=view_pr*duct&id=2067
*	Lua
	*	Unity: http://www.thegamecreat*rs.c*m/?m=view_pr*duct&id=2081
	*	Barnski’s Lua: http://f*rum.thegamecreat*rs.c*m/?m=f*rum_view&t=74095&b=5


Debugger (Alpha): The debugger is b*th build int* the template and the C*mmand Center. The c*mmand center is f*r debugging, message l*gging, and err*r handing. Y*u can als* pause the game fr*m the C*mmand Center. The debugging features are currently in the alpha stage. This feature will be updated in future.
*	Err*r Rep*rting: Rep*rts err*rs and pauses the game. Y*u can “[R]esume - [S]ave and Exit - [E]xit”. “Resume” will ign*re the err*r. “Save and Exit“will save the err*r l*g and shutd*wn the game. “Exit” will just shutd*wn the game.
*	Pause: Y*u can pause the game by pressing the P key *n the keyb*ard when the C*mmand C*ns*le wind*w is in f*cus.
*	C*ns*le: The warnings and messages can be *utputted via c*ns*le if C*ns*leM*de = 1. 


Game Template Flags:
*	Display_FPS: Displays the Frames Per Sec*nd in the right hand c*rner if set t* 1.
*	DataM*de: A DataM*de *f 1 creates/l*ads a file database. A DataM*de *f 2 creates/l*ads a Dark Data database.
*	RebuildDatabase: Rem*ves the current database files s* it can be rebuilt using the ScanF*lders functi*n.
*	L*adFileArray: If y*u are l*ading by Database set this flag t* *ne t* als* add the data t* the File/F*lder Arrays.
*	SetupAnimati*n: This flag set t* 1 will setup all the animati*n files aut*matically. Set t* 0 t* save *n l*ad time. This *nly needs t* be run *nce then updated if the files change.
*	CharacterSh*p: If y*u are using CharacterSh*p *bjects and have then setup c*rrectly then set CharacterSh*p t* 1.
*	Ap*calypticPack: If y*u are using Ap*calypticPack *bjects and have then setup c*rrectly then set Ap*calypticPack t* 1.
*	M*delPack10: If y*u are using M*delPack10 *bjects and have then setup c*rrectly then set M*delPack10 t* 1.
*	DebugM*de: DebugM*de will *pen the C*mmand Center if set t* 1. The err*rs, warnings, and messages will be sent t* the C*mmand Center if set t* 1.
*	C*ns*leM*de: If C*ns*leM*de is set t* 1 then a c*ns*le will be *pened and display all imp*rtant data including perf*rmance data.
*	Wind*w*n: If Wind*w*n is set t* 1 then the game will be displayed in a Wind*w and if set t* 0 it will be full screen.


Game Template L**p:
*	This l**p is run if the Escape Key is n*t pressed and the Game Template isn’t shutting d*wn
*	In the l**p it will update the perf*rmance c*de
*	When the Escape Key is press *r the Game Template is Shutting D*wn then it will run the cl*se functi*n


While EscapeKey() = 0 And ShuttingD*wn = 0
Update_Perf*rmance()        
EndWhile


Main L**p:
*	This is the functi*n that will be called by the perf*rmance functi*n. 
*	The main l**p is f*r l*gic


Functi*n L**p_Main()
    Update_Main()
EndFuncti*n

Display L**p:
*	This is the functi*n that will be called by the perf*rmance functi*n. 
*	The display l**p is f*r anything that needs t* be rendered *r *utputted t* the screen
*	Put these c*mmands in the Display L**p: Print, Sync, Camera, *r Sprite C*mmands


Functi*n L**p_Display()    
    Update_Display()
EndFuncti*n

Functi*n Tags


Setup Functi*ns: 
*	A functi*n with the “Setup_” tag will be called first. 
*	The Setup functi*ns are used t* setup a class


C*r*utines: 
*	A functi*n with the “C*r*utine_” tag is c*nsidered a c*ur*utine
*	A c*r*utine requires the Update_C*r*utines() functi*n t* be called within the l**p


Threads:
*	A functi*n with the “Thread_” tag is c*nsidered a Thread. (Used in Multi-Threading class)
*	A Thread functi*n requires this c*de:
	*	Sleep 250

Index = Lua_GetThreadIndex("Thread_Functi*nName")

Repeat
    If Get_CanRunFlag(Index) = 0 Then ThreadSleep(1.0)
    ` D* Stuff Here
    Set_CanRunFlag(Index, 0)                                
Until EscapeKey() = 1 *r ShuttingD*wn = 1
*	Y*u must sleep f*r 250 milisec*nds *r the Thread will crash
*	Y*u have t* check t* see if the game is Shutting D*wn and exit the thread when it d*es start shutting d*wn
*	If CanRun = 0 then it will Sleep s* it can return the Time back t* the pr*cess*r
*	After the c*de is run it has t* reset the CanRun flag t* 0 

L**ps:
*	A functi*n with the “L**p_” tag is c*nsidered a l**p
*	A l**p is handled aut*matically by the perf*rmance functi*n
*	Y*u can create m*re l**ps and set a cust*m L**ps Per Sec*nd rate

Input:
*	A functi*n with a “KeyPressed_” tag is the Key Pressed event f*r when a key is pressed *n the keyb*ard.
*	A functi*n with a “KeyReleased_” tag is the Key Released event f*r when a key is released *n the keyb*ard.
*	A functi*n with a “KeyD*wn_” tag is the Key D*wn event f*r when a key is held d*wn *n the keyb*ard.
*	A functi*n with a “M*usePressed_” tag is the M*use Pressed event f*r when a M*use Butt*n is pressed *n the m*use.
*	A functi*n with a “M*useReleased_” tag is the M*use Released event f*r when a M*use Butt*n is released *n the m*use.
*	A functi*n with a “M*useD*wn_” tag is the M*use D*wn event f*r when a M*use Butt*n is held d*wn *n the m*use.
*	A key is f*ll*wed after the functi*n tag f*r the keyb*ard events. (Uppercase)
*	A butt*n is f*ll*wed after the functi*n tag f*r the m*use events. (Left, Right, Middle)


Functi*ns

Main.dba
*	L**p_Main ()
	*	This is the functi*n that will be called by the perf*rmance functi*n. 
	*	The main l**p is f*r l*gic
*	L**p_Display ()
	*	This is the functi*n that will be called by the perf*rmance functi*n. 
	*	The display l**p is f*r anything that needs t* be rendered *r *utputted t* the screen
	*	Put these c*mmands in the Display L**p: Print, Sync, Camera, *r Sprite C*mmands
*	Update_Main ()
	*	Everything that pertains t* the template that needs t* be updated
*	Update_Display ()
	*	Everything that pertains t* the template that needs t* be updated *r *utputted

Animati*n.dba
*	Setup_Animati*n ()
	*	Extracts the animati*n and writes all animati*ns exp*rted t* an animati*n list
*	CharacterSh*p_Extract ()
	*	Extracts the Character Sh*p animati*n and N* Anim *bject file
*	Ap*calypticPack_Extract ()
	*	Extracts the Ap*calyptic Pack animati*n and N* Anim *bject file
*	M*delPack10_Extract ()
	*	Extracts the M*del Pack 10 animati*n and N* Anim *bject file
*	CharacterSh*p_WriteList ()
	*	Exp*rts the full animati*n file list in a text file
*	Ap*calypticPack_WriteList ()
	*	Exp*rts the full animati*n file list in a text file
*	M*delPack10_WriteList ()
	*	Exp*rts the full animati*n file list in a text file
*	CharacterSh*p_N*AnimAll ()
	*	Exp*rts a c*py *f the *bject with n* animati*ns
*	Ap*calypticPack_N*AnimAll ()
	*	Exp*rts a c*py *f the *bject with n* animati*ns
*	M*delPack10_N*AnimAll ()
	*	Exp*rts a c*py *f the *bject with n* animati*ns
*	Extract_FPSCreat*rBase ()
	*	Extracts the base animati*n *f the FPS Creat*r animati*n list. The f*rmat is the same s* I can extract the base and then the extra animati*ns.
*	Extract_CharacterSh*pBase ()
	*	Extracts the base animati*n *f the Character Sh*p animati*n list. The f*rmat is the same s* I can extract the base and then the extra animati*ns.

Dynamic Res*urces.dba
*	C*r*utine_GarbageC*llecti*n ()
	*	This c*r*utine checks every index f*r empty indexes and adds them t* the delete res*urce arrays

Delete Res*urce: Adds the index t* the Deleted Res*urce Array and deletes/cl*ses res*urce.
*	Delete*bject (Index)
*	DeleteSprite (Index)
*	DeleteMembl*ck (Index)
*	DeleteCamera (Index)
*	DeleteEmitter (Index)
*	DeleteVect*r2 (Index)
*	DeleteVect*r3 (Index)
*	DeleteVect*r4 (Index)
*	DeleteImage (Index)
*	DeleteEffect (Index)
*	DeleteS*und (Index)
*	DeleteMesh (Index)
*	DeleteMusic (Index)
*	Cl*seFile (Index)
*	DeleteMatrix (Index)
*	Cl*seDFS (Index)
*	Cl*seKFS (Index)
*	DeleteL**kup (Index)
*	DeleteBank (Index)
*	DeleteMutex (Index)

Next Res*urce: Gets the next res*urce index. If a deleted res*urce was added t* the array then it will rem*ve *ne fr*m the stack and return that index making sure it fills empty indexes. Returns Index.
*	Next*bject ()
*	NextImage ()
*	NextCamera ()
*	NextEffect ()
*	NextS*und ()
*	NextMesh ()
*	NextMembl*ck ()
*	NextVect*r ()
*	NextEmitter ()
*	NextMusic ()
*	NextFile ()
*	NextSprite ()
*	NextMatrix ()
*	NextDatabase ()
*	NextL**kup ()
*	NextBank ()
*	NextC*r*utine ()
*	NextMutex ()
*	NextDll ()

File Array Index: Assigns a filename t* a File Array Index. FileGet returns the index fr*m the filename given. Lua_FileGet(Name$) Returns Index
*	Lua_FileAdd (Index, Name$)
*	Index = Lua_FileGet (Name$) 

File L*ad Res*urce: L*ads the res*urce with that Name$ and Returns the Index
*	File_L*ad*bject (Name$)
*	File_L*adS*und (Name$)
*	File_L*adMusic (Name$)
*	File_L*adEffect (Name$)
*	File_L*adImage (Name$)
*	File_L*adAnimati*n (Name$)

Lua L*ad Res*urce: L*ads the res*urce with that Name$ and Returns the Index
*	Lua_L*ad*bject (Name$)
*	Lua_L*adS*und (Name$)
*	Lua_L*adMusic (Name$)
*	Lua_L*adEffect (Name$)
*	Lua_L*adImage (Name$)
*	Lua_L*adAnimati*n (Name$)

Database L*ad Res*urce: L*ads the res*urce with that Name$ and Returns the Index
*	Database_L*ad*bject (Name$)
*	Database_L*adS*und (Name$)
*	Database_L*adMusic (Name$)
*	Database_L*adEffect (Name$)
*	Database_L*adImage (Name$)
*	Database_L*adAnimati*n (Name$)

Lua Get Res*urce Index: Finds a res*urce with the name Name$ and Returns the Index 
*	Lua_Get*bject (Name$)
*	Lua_GetImage (Name$)
*	Lua_GetCamera (Name$)
*	Lua_GetEffect (Name$)
*	Lua_GetS*und (Name$)
*	Lua_GetMesh (Name$)
*	Lua_GetMusic (Name$)
*	Lua_GetFile (Name$)
*	Lua_GetEmitter (Name$)
*	Lua_GetSprite (Name$)
*	Lua_GetMatrix (Name$)
*	Lua_GetVect*r (Name$)
*	Lua_GetDatabase (Name$)
*	Lua_GetL**kup (Name$)
*	Lua_GetBank (Name$)
*	Lua_GetC*r*utine (Name$)
*	Lua_GetMutex (Name$)
*	Lua_GetAnimati*nByName (Name$)
*	Lua_GetAnimati*n (Name$)

Lua Name Res*urce: Assigns a res*urce Index with a Name$ f*r easy l**kup
*	Lua_Name*bject (Index, Name$)
*	Lua_NameImage (Index, Name$)
*	Lua_NameCamera (Index, Name$)
*	Lua_NameEffect (Index, Name$)
*	Lua_NameS*und (Index, Name$)
*	Lua_NameMesh (Index, Name$)
*	Lua_NameMusic (Index, Name$)
*	Lua_NameFile (Index, Name$)
*	Lua_NameEmitter (Index, Name$)
*	Lua_NameSprite (Index, Name))
*	Lua_NameMatrix (Index, Name$)
*	Lua_NameVect*r (Index, Name$)
*	Lua_NameDatabase (Index, Name$)
*	Lua_NameL**kup (Index, Name$)
*	Lua_NameMembl*ck (Index, Name$)
*	Lua_NameBank (Index, Name$)
*	Lua_NameC*r*utine (Index, Name$)
*	Lua_NameMutex (Index, Name$)
*	Lua_NameAnimati*n (Index, Name$)

Res*urce Search: File d*es a search th*ugh the File() Array. Database d*es a search th*ugh the File Database. Lua d*es a search t* find the File() Array Index. (Lua is quicker then File Search)
*	Database_Res*urceSearch (Name$)
*	File_Res*urceSearch (Name$)
*	Lua_Res*urceSearch (Name$)

Free Res*urce: Finds a empty Index by searching all Indexes. (Very sl*w)
*	Free*bject ()
*	FreeImage ()
*	FreeCamera ()
*	FreeEffect ()
*	FreeS*und ()
*	FreeMesh ()
*	FreeMusic ()
*	FreeEmmitter ()
*	FreeSprite ()
*	FreeFile ()
*	FreeMatrix ()
*	FreeVect*r ()
*	FreeL**kup ()
*	FreeMembl*ck ()
*	FreeBank ()

Extra Functi*ns: These functi*ns are c*mmand sh*rtcuts. They Return the Index
*	L*ad*bject (Path$)
*	L*adImage (Path$)
*	L*adEffect (Path$)
*	L*adS*und (Path$)
*	L*adMusic (Path$)
*	L*adMesh (Path$)
*	*penFileT*Write (Path$)
*	*penFileT*Read (Path$)
*	Cl*seCurrentFile ()
*	L*adSprite (Path$, X, Y)
*	CreateSprite (X#, Y#, Image)
*	CreateCamera ()
*	CreateSphere (Size#)
*	CreateC*mplexSphere (Size#, R*ws, C*lumns)
*	CreateCube (Size#)
*	*bjectT*Mesh (*bject)
*	MeshT**bject (Mesh)
*	CreateAnimatedSprite (FileName$, Acr*ss, D*wn)
*	L*adDll (DllName$)

Events.dba
Setup Events: Checks all the functi*ns f*r tags and calls the appr*priate functi*ns t*
*	SetupEvents ()

Perf*rmance Events: Creates a perf*rmance event which is handled by the UpdatePerf*rmance() functi*n. SetThread functi*n will set the perf*rmance event t* a thread event. A thread event needs permissi*n t* run using the CanRun flag.
*	Perf*rmanceEvent_Create ()
*	Perf*rmanceEvent_SetThread ()

Event Functi*ns: Creates, assigns parameters, and calls events. Everything t* make events, assign parameters, and call them easier. 
*	Event_Create (Functi*nName$)
*	Event_Call (Index)
*	Event_CallByName$ (Functi*nName)
*	Event_CallByPtr (P*inter)
*	Event_CallByNumber ()
*	Event_SetParameter1# (Number#)
*	Event_SetParameter1$ (String$)
*	Event_SetParameter2# (Number#)
*	Event_SetParameter2$ (String$)
*	Event_SetParameter3# (Number#)
*	Event_SetParameter3$ (String$)
*	Event_SetParameter4# (Number#)
*	Event_SetParameter4$ (String$)
*	Event_SetParameter5# (Number#)
*	Event_SetParameter5$ (String$)

C*r*utines: Creates a c*r*utine. Every c*r*utine must call Update_C*r*utines() within the l**p. This is aut*matically handled by the SetupEvents functi*n by Tagging the functi*n with the tag: “C*r*utine_”
*	CreateC*r*utine (Functi*nName$)
*	Update_C*r*utines ()
*	Cl*se_DeleteC*r*utines ()

Threads (Alpha): Creates a new thread. This technique is called Multi-Threading. This is aut*matically handled by the SetupEvents functi*n by Tagging the functi*n with the tag: “Thread_”
*	CreateThread (Functi*nName$)
*	Cl*seThread ()
*	Cl*seAll_Threads ()
*	ThreadSleep ()

Mutexes: Creates the mutex which is handled by the Threads. The CanRun flag c*ntr*ls the Threads perf*rmance which is handled by the UpdatePerf*rmance() functi*n. CreateMutex() is aut*matically called in SetupEvents() functi*n.
*	CreateMutex ()
*	Set_CanRunFlag ()
*	Get_CanRunFlag ()

Lua Name/Get Thread: Name a thread and Returns the Index *f a thread by giving it a Name$. Lua_NameThread () is aut*matically called in CreateThread() functi*n when a new thread is created.
*	Lua_GetThreadIndex (Name$)
*	Lua_NameThread (Index, Name$)

File.dba
*	Setup_File ()
	*	If the database d*esn’t exists then it will scan. If it exist then it will l*ad the database.
*	SaveAsDatabase ()
	*	Saves the Database using Dark Data
*	SaveAsFile ()
	*	Saves the Database using a File
*	L*adFile ()
	*	L*ads the File Database
*	L*adDatabase ()
	*	L*ads the Dark Data Database
*	File_WriteList (F*lderName$ , F*lderPath$)
	*	Writes a list *f every file in that f*lder
*	ScanF*lder (Dir$)
	*	Scans every f*lder and every f*lder inside that f*lder f*r files and f*lders and writes them t* the c*rresp*nding arrays
*	HandleFile (SubLevel)
	*	Determines if it is a file *r f*lder.  Adds t* c*rresp*nding array.
*	Rem*veExtensi*n$ (FilePath$)
	*	Rem*ves the extensi*n fr*m the path *r file name.
*	GetFileExtensi*n$ (FilePath$)
	*	Gets the file extensi*n fr*m the path *r file name. 
*	GetPathF*lder (Level, Path$)
	*	Gets a f*lder fr*m a path. The level is the f*lder Index starting fr*m the end *f the path.
*	GetExtenti*nType (Extenti*n$)
	*	Gets the extensi*n type and returns the extensi*n name. 
*	DeleteFileDatabase()
	*	Deletes the database

Input.dba
*	Thread_ScanInput ()
	*	Will scan the keyb*ard and m*use f*r input can call the appr*priate functi*ns/events.
	*	This is a thread meaning it will aut*matically be created and run parallel with the main thread.
*	KeyPressed (C*de)
	*	Will check the Keys() array f*r any keys that match the C*de given. Will Return the state *f 1 if the Key is pressed.
*	M*usePressed (C*de)
	*	Will check the M*use() array f*r any butt*ns that match the C*de given. Will Return the state *f 1 if the Butt*n is pressed.
*	M*use_GetState (C*de)
	*	Checks the current pressed m*use butt*n and c*mpares it with the c*de given. This will w*rk if multiple keys are pressed returning 1 if the butt*n is pressed.
*	M*useName$ (C*de)
	*	Returns the m*use Name$ fr*m the C*de given
*	FindKeyIndex ()
	*	Finds an empty Keys() index
*	FindM*useIndex ()
	*	Finds an empty M*use() index

Messages.dba: Sends messages t* the c*ntr*l center and als* receives messages and the messages can c*ntr*l the game in s*me way.
*	Send_Err*r$ (Message$)
	*	Sends an err*r t* the c*mmand center. Will pause the game and ask if the game sh*uld be c*ntinued.
*	Send_Message$ (Message$)
	*	Sends an message t* the c*mmand center
*	Send_Warning$ (Message$)
	*	Sends an Warning t* the c*mmand center
*	Handle_Messages ()
	*	Handles all inc*ming messages
*	Send_ShutD*wn ()
	*	Sends the shutd*wn flag s* the c*mmand center shuts d*wn

Perf*rmance.dba: Perf*rmance c*ntr*ls the rate at which each l**p runs and als* the rate *f the threads.
*	Update_Perf*rmance ()
	*	D*es tw* things: C*ntr*ls the rate in L**ps Per Sec*nd and returns the time n*thing is running back t* the pr*cess*r. This ensures a l*w CPU usage.

Setup.dba: Sets up every class and the game.
*	Setup ()
	*	Master Setup() functi*n. Call bef*re the main l**p.
*	Cl*se ()
	*	Master Cl*se() functi*n. Call after main l**p.
*	Lua_L*adScript ()
	*	L*ads the master Lua Script.

Timers.dba: F*r creating Game Timers and Timers with Events.
*	Create_Timer ()
	*	Creates a new Timer.
*	Create_TimedEvent ()
	*	Creates a new Event Timer.
*	Update_TimedEvents (EventIndex, StartTime#, Units$, ResetFlag)
	*	When the c*untd*wn timer reaches 0 it will call the event and restart if the ResetFlag is set t* 1
	*	The EventIndex is the Index *f an Event() t* call
	*	The Units$ are: “H*urs”, “Minutes”, “Sec*nds”, “MiliSec*nds”
	*	StartTime#  is the time will c*unt d*wn fr*m
	*	ResetFlag if set t* 1 then the c*untd*wn timer will restart
*	Reset_Timer (Index)
	*	It will restart the timer back t* 0
*	GetH*urs (Index)
	*	Gets the time in h*urs
*	GetMinutes (Index)
	*	Gets the time in Minutes
*	GetSec*nds (Index)
	*	Gets the time in Sec*nds
*	GetMilliSec*nds (Index)
	*	Gets the time in Millisec*nds
*	GetFreq ()
	*	Gets the pr*cess*r frequency 
