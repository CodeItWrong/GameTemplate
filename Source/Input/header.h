/*
   There are several flags which can be defined to help the DBPPluginTemplate
   best perform to your needs. They are listed and described below:
   
    INCLUDE_DIRECTX               - This will include d3d9.h, and d3dx9.h. This
                                    will help you if you are doing some
                                    Direct3D work.
    
    NO_EXTRADX_FUNCTIONS          - This will strip out an automatically created
                                    Direct3D Object, and Direct3D Device, which
                                    would be automatically set to DBP's D3D
                                    object, and device.
    
    NO_GLOBSTRUCT                 - This will keep GlobStruct from being
                                    included. If GlobStruct isn't used, this
                                    will help keep your output DLL small.
    
    EXTRA_DBPDATA                 - This will include extra internal structures
                                    of DBP, such as the sObject, sMesh, etc.
                                    This is mainly for very special plugins
                                    which deal with manipulation.
    
    NO_EXTRA_DBPCOMMANDS          - This will keep all DBP commands from being
                                    able to be used in the plugin. There are a
                                    series of other flags which will help you
                                    keep certain
    
    NO_HELPER_FUNCTIONS           - This will keep functions such as dbpstring,
                                    dbpfloat, GetGlobstruct, etc, out of the
                                    plugin.

   The following are alternatives to NO_EXTRA_DBPCOMMANDS:
    EXCLUDE_ADVANCEDTERRAIN
    EXCLUDE_ANIMATION
    EXCLUDE_BASIC2D
    EXCLUDE_BASIC3D
    EXCLUDE_BITMAP
    EXCLUDE_CAMERA
    EXCLUDE_CORE
    EXCLUDE_FILE
    EXCLUDE_FTP
    EXCLUDE_GAMEFX
    EXCLUDE_IMAGE
    EXCLUDE_INPUT
    EXCLUDE_LIGHT
    EXCLUDE_TERRAIN
    EXCLUDE_MATRIX
    EXCLUDE_MEMBLOCKS
    EXCLUDE_MULTIPLAYER
    EXCLUDE_MUSIC
    EXCLUDE_PARTICLES
    EXCLUDE_SETUP
    EXCLUDE_SOUND
    EXCLUDE_SPRITES
    EXCLUDE_SYSTEM
    EXCLUDE_TEXT
    EXCLUDE_VECTORS
    EXCLUDE_WORLD3D
*/
// Main Include
#include <DBPPlugin\DBPPluginTemplate.h>

// Your includes here

vector<int> Keys;
vector<int> Mouse;

int AnyPressed = 0;
int AnyDown = 0;
int AnyReleased = 0;

int MAX_KEYS = 5;
