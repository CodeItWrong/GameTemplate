// Include the header
#include "header.h"
// Include other headers here.
#include "Dynamic Array.h"

int ObjectIndex = 0;
int ImageIndex = 0;
int CameraIndex = 0;
int EffectIndex = 0; 
int SoundIndex = 0; 
int MeshIndex = 0; 
int MusicIndex = 0;
int FileIndex = 0;
int EmitterIndex = 0;
int SpriteIndex = 0;
int MatrixIndex = 0; 
int VectorIndex = 0;
int DatabaseIndex = 0;
int LookupIndex = 0;
int MemblockIndex = 0;
int BankIndex = 0;
int CoroutineIndex = 0;
int MutexIndex = 0;
int DllIndex = 0;

DynamicArray DeletedObjects;
DynamicArray DeletedSprites;
DynamicArray DeletedEmitters;
DynamicArray DeletedVectors;
DynamicArray DeletedMemblocks;
DynamicArray DeletedCameras;
DynamicArray DeletedImages;
DynamicArray DeletedEffects;
DynamicArray DeletedSounds;
DynamicArray DeletedMeshs;
DynamicArray DeletedMusic;
DynamicArray DeletedFiles;
DynamicArray DeletedMatrixes;
DynamicArray DeletedDatabases;
DynamicArray DeletedLookups;
DynamicArray DeletedBanks;
DynamicArray DeletedMutexes;
DynamicArray DeletedDlls;
DynamicArray DeletedAnimations;
DynamicArray DeletedCoroutines;    

DLLCMDC int DRNextObject()
{       
    int Index;
    int Count = DeletedObjects.Count();
    
    if (Count > 0) {
        Index = DeletedObjects.Item(0);
        DeletedObjects.Remove(0); 
    }
    else {
        ObjectIndex = ObjectIndex + 1;    
        Index = ObjectIndex;
    }       
    
    return Index;
}

// Update Indexes function - Gets all the counts by searching though and finding all the objects
// It is a smart function that gets the object count then if object count is bigger then current index
// then it will keep searching and add the indexes that don't exist to the deleted arrays
