// Include the header
#include "header.h"
// Include other headers here.


// Whatever code here.
DLLCMDC int HandleFile(int SubLevel)
{
    StartFunction
    
    int FileType = dbGetFileType();
    LPSTR FileName = dbGetFileName();
   
    //MessageBox(NULL, FileName, "File Name", MB_OK);

    char * Found;

    if (FileType != -1)    
    {
        Found = strchr((char*)FileName, '.');      
        if (Found != NULL) { FileType = 2; }
    }
         
    if (Found == NULL) // Crashes because it is a 1 instead of a 0
    {       
        if (FileType == 1)
        {
            MessageBox(NULL, FileName, "Folder", MB_OK);
            
            Folder MyFolder;
            char BS = char(92);
            //char * Backslash = &BS;
                                                        
            MyFolder.Path = dbGetDir();
            MyFolder.Path = MyFolder.Path + BS; 
            MyFolder.Path = MyFolder.Path + FileName;
  
            //LPSTR Str = const_cast<char *>(MyFolder.Path.c_str());            
            //MessageBox(NULL, Str, "Path", MB_OK);     
            
            MyFolder.Name = FileName;
            MyFolder.SubLevel = SubLevel;
            
            Folders.insert(Folders.end(), MyFolder);             
        }                    
                
        if (FileType == 0)
        {
            MessageBox(NULL, FileName, "File", MB_OK);
                     
            File MyFile;      
            char BS = char(92);
            //char * Backslash = &BS;
                       
            MyFile.Path = dbGetDir();
            MyFile.Path = MyFile.Path + BS; 
            MyFile.Path = MyFile.Path + FileName;
            
            MyFile.Name = FileName;
            MyFile.Folder = dbGetDir();
                     
            Files.insert(Files.end(), MyFile);             
        }        
    }
    
    return FileType;
}

// Is stuck on the media folder!
// It does not search the other folders just the media one.
DLLCMDC void FileSearch(LPSTR Dir)
{
    StartFunction
    
    LPSTR CurrentDir = dbGetDir();
    int FolderCount = 0;
    int Count = 0;
    int SubLevel = 0;
    int FileType = -1;
                 
    dbSetDir(Dir);
    
    dbFindFirst();
        
    FileType = HandleFile(0);
    if (FileType == 1) { FolderCount = FolderCount + 1; }
       
    while(FileType != -1)        
    {                   
        dbFindNext();
        FileType = HandleFile(0);        
        
        if (FileType == 1) { FolderCount = FolderCount + 1; }
    }
    
    //char C = (char);
    //LPSTR Str;
    //sprintf(Str, "%d", FolderCount);
    //MessageBox(NULL, Str, "Folder Count", MB_OK); // This returned a 1
    
    // Folder count shouldn't equal 3 it should equal 1!
    
    // New way of doing this:
    // Folders found so far - Search in each folder for more folders
    // Make a for loop that goes threw each folder based on that stored count
    // MyCount = FolderCount
    // For loop with MyCount
        
    do
    {
        Count = FolderCount;
        FolderCount = 0;
        
        // Returned 1
        //LPSTR Str2;
        //sprintf(Str2, "%d", Folders.size());
        //MessageBox(NULL, Str2, "Folder Array Count", MB_OK); // This returned a 1
               
        for (int Index = 0; Index < Folders.size(); Index++)
        {
            
        LPSTR Str2;
        //sprintf(Str2, "%d", SubLevel);
        //MessageBox(NULL, Str2, "Sub Level", MB_OK); // This returned a 1     
        
        //Str2 = "";
        //sprintf(Str2, "%d", Folders[Index].SubLevel);
        //MessageBox(NULL, Str2, "Folder Sub Level", MB_OK); // This returned a 1                 
            
            if (Folders[Index].SubLevel == SubLevel)    
            {
                // Convert to LPSTR
                LPSTR Str = const_cast<char *>(Folders[Index].Path.c_str());
                
                // MessageBox(NULL, Str, "Path", MB_OK); // Path is fine!
                               
                dbSetDir(Str);
                
                dbFindFirst();                
                FileType = HandleFile(SubLevel + 1);
                if (FileType == 1) { FolderCount = FolderCount + 1;  }
                
                // For some reason it won't continue on and find all the files
                // It goes to bitmap and everything it just doesn't continue any further.
                // If I remove FileType != -1 from the handle file it will find them.
                
                while(FileType != -1) 
                {
                    if (FileType == 1) { FolderCount = FolderCount + 1;  }
                    
                    dbFindNext();
                    FileType = HandleFile(SubLevel +  1);         
                    
                    //if (FileType != 1 && FileType != 0 && FileType != -1 && FileType != 2) {MessageBox(NULL, "Unknown Found", "Unknown Found", MB_OK); } 
                    //if (FileType == 2) { MessageBox(NULL, "Dir Up Found", "Dir Up Found", MB_OK); }                                              
                    //if (FileType == -1) { MessageBox(NULL, "End Found", "End Found", MB_OK); }                          
                    //if (FileType == 1) { MessageBox(NULL, "Folder Found", "Folder Found", MB_OK); }
                    //if (FileType == 0) { MessageBox(NULL, "File Found", "File Found", MB_OK); }                          
                }           
            }
        }   
        
        SubLevel = SubLevel + 1;     
    } while(FolderCount != 0);
           
    dbSetDir(CurrentDir);
}    

DLLCMDC int FolderCount()
{
    return Folders.size();        
}

DLLCMDC int FileCount()
{
    return Files.size();        
}

DLLCMDC DWORD GetFolderPath(int Index)
{
    LPSTR Str = const_cast<char *>(Folders[Index].Path.c_str());    
    return dbpstring(Str);        
}

DLLCMDC DWORD GetFolderName(int Index)
{
    LPSTR Str = const_cast<char *>(Folders[Index].Name.c_str());
    return dbpstring(Str);                
}

DLLCMDC int GetFolderSubLevel(int Index)
{
    return Folders[Index].SubLevel;                
}

DLLCMDC DWORD GetFilePath(int Index)
{
    LPSTR Str = const_cast<char *>(Files[Index].Path.c_str());
    return dbpstring(Str);        
}

DLLCMDC DWORD GetFileName(int Index)
{
    LPSTR Str = const_cast<char *>(Files[Index].Name.c_str());        
    return dbpstring(Str);                
}

DLLCMDC DWORD GetFileFolder(int Index)
{
    LPSTR Str = const_cast<char *>(Files[Index].Folder.c_str());
    return dbpstring(Str);                
}


//Type Folder
//    Path$
//    Name$
//    SubLevel            
//EndType
//    
//Type File
//    Path$
//    Folder$
//    Name$    
//EndType
//
//Function SetupFile()
//    Global Dim Folders() As Folder
//    Global Dim Files() As File
//EndFunction
//
//Function ScanFolder(Dir$)
//    CurrentDir$ = Get Dir$() :  Set Dir Dir$
//
//    Find First    
//    FileType = HandleFile(0)
//    
//    While FileType <> -1        
//        If FileType = 1 Then FolderCount = FolderCount + 1
//            
//        Find Next
//        FileType = HandleFile(0)        
//    EndWhile
//    
//    Repeat
//        Count = FolderCount
//        FolderCount = 0
//                 
//        ArrayCount = Array Count(Folders())
//        
//        For Index = 0 To ArrayCount
//            If Folders(Index).SubLevel = SubLevel            
//                Set Dir Folders(Index).Path$                
//                                
//                Find First
//                FileType = HandleFile(SubLevel + 1)
//                If FileType = 1 Then FolderCount = FolderCount + 1
//                                
//                While FileType <> -1        
//                    If FileType = 1 Then FolderCount = FolderCount + 1
//                        
//                    Find Next
//                    FileType = HandleFile(SubLevel + 1)                        
//                EndWhile                
//            EndIf            
//        Next Index        
//            
//        SubLevel = SubLevel + 1
//    Until FolderCount = 0
//        
//    Set Dir CurrentDir$
//EndFunction
//
//Function HandleFile(SubLevel)    
//    FileType = Get File Type() 
//    FileName$ = Get File Name$()
//
//    If Mid$(FileName$, 1) <> "."
//        If FileType = 1
//            Add To Stack Folders()
//        
//            Folders().Path$ = Get Dir$() + "\" + FileName$
//            Folders().Name$ = FileName$                    
//            Folders().SubLevel = SubLevel            
//        EndIf
//        
//        If FileType = 0
//            Add To Stack Files()
//        
//            Files().Path$ = Get Dir$() + "\" + FileName$
//            Files().Name$ = FileName$                    
//            Files().Folder$ = Get Dir$()        
//        EndIf
//    EndIf
//EndFunction FileType
//
//Function Create_AnimationDatabase(AnimationName$, Dir$)
//    CurrentDir$ = Get Dir$()
//    
//    Set Dir Dir$        
//        
//    ` Create Data File        
//    KFS Create 2, AnimationName$ + ".kfs", 6, 0, 0
//    DFS Create 1, AnimationName$ + ".dat", 1 
//
//    Find First
//    
//    FileName$ = Get File Name$()    
//    FileType = Get File Type() 
//    
//    If FileType = 0
//        If GetFileExtension$(Lower$(FileName$)) = ".anim"
//            Name$ = GetFileName$(FileName$)
//            DFS Add Field 1, "Integer As " + Name$
//        EndIf
//    EndIf
//    
//    While FileType <> -1                        
//        Find Next
//        
//        FileName$ = Get File Name$()        
//        FileType = Get File Type()         
//        
//        If Mid$(FileName$, 1) <> "."            
//            If FileType = 0            
//                If GetFileExtension$(Lower$(FileName$)) = ".anim"
//                    Name$ = GetFileName$(FileName$)
//                    DFS Add Field 1, "Integer As " + Name$                    
//                EndIf
//            EndIf
//        EndIf
//    EndWhile
//    
//    DFS Finish 1
//        
//    ` Create KFS File            
//    RecordCount = 0
//                
//    Find First
//    
//    FileName$ = Get File Name$()    
//    FileType = Get File Type() 
//    
//    If FileType = 0
//        If GetFileExtension$(Lower$(FileName$)) = ".anim"
//            Inc RecordCount, 1
//                        
//            Name$ = GetFileName$(FileName$)
//            
//            Record = DFS Add(1)
//            DFS Put 1, Name$, RecordCount    
//            DFS Save 1, Record            
//        EndIf
//    EndIf
//    
//    While FileType <> -1                        
//        Find Next
//        
//        FileName$ = Get File Name$()        
//        FileType = Get File Type()         
//        
//        If Mid$(FileName$, 1) <> "."            
//            If FileType = 0            
//                If GetFileExtension$(Lower$(FileName$)) = ".anim"
//                    Inc RecordCount, 1
//            
//                    Name$ = GetFileName$(FileName$)
//                    
//                    Record = DFS Add(1)
//                    DFS Put 1, Name$, RecordCount    
//                    DFS Save 1, Record    
//                EndIf
//            EndIf
//        EndIf
//    EndWhile
//    
//    KFS Close 2
//    DFS Close 1
//        
//    Set Dir CurrentDir$
//EndFunction
//
//` THIS STILL SCANS IT DOESN'T REFERENCE FORM THE DATABASE!
//remstart
//Function Load_AnimationDatabase(AnimationName$, Dir$, DFS, KFS)
//    CurrentDir$ = Get Dir$()
//    
//    Set Dir Dir$
//    
//    ` Load DarkData Files        
//    KFS Open KFS, AnimationName$ + ".kfs"
//    DFS Open DFS, AnimationName$ + ".dat"
//
//    Find First
//    
//    FileName$ = Get File Name$()    
//    FileType = Get File Type() 
//    
//    If FileType = 0
//        If GetFileExtension$(Lower$(FileName$)) = ".anim"                    
//            Index = EnAn_AnimLoad(FileName$)
//            Lua_NameAnimation(Index, FileName$)            
//        EndIf
//    EndIf
//    
//    While FileType <> -1                        
//        Find Next
//        
//        FileName$ = Get File Name$()        
//        FileType = Get File Type()         
//        
//        If Mid$(FileName$, 1) <> "."            
//            If FileType = 0            
//                If GetFileExtension$(Lower$(FileName$)) = ".anim"
//                    Index = EnAn_AnimLoad(FileName$)                      
//                    Lua_NameAnimation(Index, FileName$)                                                          
//                EndIf
//            EndIf
//        EndIf
//    EndWhile
//                
//    Set Dir CurrentDir$
//EndFunction
//remend
//
//Function GetFileName$(FilePath$)
//   For Index = 1 To Len(FilePath$)
//      If Mid$(FilePath$, Index) = "." Then Exit
//      FileName$ = FileName$ + Mid$(FilePath$, Index)
//   Next Index
//EndFunction FileName$
//
//Function GetFileName2$(FilePath$)
//    Index = Len(FilePath$)
//    
//    Repeat
//        Index = Index - 1
//    Until Mid$(FilePath$, Index, 1) = "\"
//    
//    FileName$ = Mid$(FilePath$, Index + 1, Len(FilePath$) - Index)
//EndFunction FileName$
//
//Function GetFileFolder(Level, Path$)
//    Index = Len(Path$)
//    
//    For Iter = 1 To Level
//        Repeat : Index = Index - 1 : Until Mid$(Path$, Index) = "\"
//    Next Iter
//    
//    Index2 = Index + 1
//    Repeat : Index2 = Index2 + 1 : Until Mid$(Path$, Index2) = "\"
//    
//    Index2 = Index2 - Index
//    
//    Folder$ = Mid$(Path$, Index + 1, Index2 - 1)
//EndFunction Folder$
//
//Function GetExtentionType(Extention$)
//    Extention$ = Upper$(Extention$)
//
//    Select Extention$
//        Case ".BMP"
//            Type$ = "Image"
//        EndCase
//        
//        Case ".JPG"
//            Type$ = "Image"
//        EndCase
//        
//        Case ".TGA"
//            Type$ = "Image"
//        EndCase
//        
//        Case ".DDS"
//            Type$ = "Image"
//        EndCase
//        
//        Case ".DIB"
//            Type$ = "Image"
//        EndCase
//        
//        Case ".PNG"
//            Type$ = "Image"
//        EndCase
//        
//        Case ".X" 
//            Type$ = "Object"
//        EndCase
//        
//        Case ".DBO"
//            Type$ = "Object"
//        EndCase
//            
//        Case ".3DS"
//            Type$ = "Object"
//        EndCase
//        
//        Case ".MDL"
//            Type$ = "Object"
//        EndCase
//        
//        Case ".MD2"
//            Type$ = "Object"
//        EndCase    
//        
//        Case ".MD3"
//            Type$ = "Object"
//        EndCase    
//        
//        Case ".FX"
//            Type$ = "Effect"
//        EndCase
//        
//        Case ".ANIM"
//            Type$ = "Animation"
//        EndCase
//    EndSelect
//EndFunction Type$
//
//Function GetFileExtension$(FilePath$)
//   For Index = 1 To Len(FilePath$)
//      If Mid$(FilePath$, Index) = "." Then Exit
//   Next Index
//
//   StartIndex = Index
//
//   For Index = StartIndex To Len(FilePath$)
//      FileExtension$ = FileExtension$ + Mid$(FilePath$, Index)
//   Next Index
//EndFunction FileExtension$
//
//
//remstart
//Function ScanFolder(Dir$)
//    CurrentDir$ = Get Dir$() :     Set Dir Dir$        
//        
//    Find First
//    
//    FileName$ = Get File Name$()    
//    FileType = Get File Type() 
//    
//    If FileType = 0
//        Add To Stack Folders() 
//        Folders().Path$ = Get Dir$() + "\" + FileName$
//        Folders().Name$ = FileName$
//        Print FileName$
//    EndIf
//    
//    If FileType = 1
//        Add To Stack Files() 
//        Files().Path$ = Get Dir$() + "\" + FileName$
//        Files().Name$ = FileName$
//        Files().Folder$ = GetFileFolder(1, Get Dir$())
//    EndIf
//        
//    While FileType <> -1                        
//        Find Next
//        
//        FileName$ = Get File Name$()        
//        FileType = Get File Type()         
//        
//        If Mid$(FileName$, 1) <> "."            
//            If FileType = 0
//                Add To Stack Folders() 
//                Folders().Path$ = Get Dir$() + "\" + FileName$
//                Folders().Name$ = FileName$
//                Print Folders().Path$
//            EndIf
//            
//            If FileType = 1
//                Add To Stack Files() 
//                Files().Path$ = Get Dir$() + "\" + FileName$
//                Files().Name$ = FileName$
//                Files().Folder$ = GetFileFolder(1, Get Dir$())
//            EndIf
//        EndIf
//    EndWhile
//            
//    Set Dir CurrentDir$
//EndFunction
//remend
