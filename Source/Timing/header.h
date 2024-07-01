#ifndef HEADER_H
#define HEADER_H

#define EXCLUDE_ADVANCEDTERRAIN
#define EXCLUDE_ANIMATION
#define EXCLUDE_BASIC2D
#define EXCLUDE_BASIC3D
#define EXCLUDE_BITMAP
#define EXCLUDE_CAMERA
//#define EXCLUDE_CORE
#define EXCLUDE_FILE
#define EXCLUDE_FTP
#define EXCLUDE_GAMEFX
#define EXCLUDE_IMAGE
#define EXCLUDE_INPUT
#define EXCLUDE_LIGHT
#define EXCLUDE_TERRAIN
#define EXCLUDE_MATRIX
#define EXCLUDE_MEMBLOCKS
#define EXCLUDE_MULTIPLAYER
#define EXCLUDE_MUSIC
#define EXCLUDE_PARTICLES
#define EXCLUDE_SETUP
#define EXCLUDE_SOUND
#define EXCLUDE_SPRITES
#define EXCLUDE_SYSTEM
#define EXCLUDE_TEXT
#define EXCLUDE_VECTORS
#define EXCLUDE_WORLD3D
    
//#define NO_EXTRA_DBPCOMMANDS
#define NO_GLOBSTRUCT
#define NO_EXTRADX_FUNCTIONS
#define NO_HELPER_FUNCTIONS


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
#include "Timing.h"
#include <cstdlib>
#include <vector>

// Global Variables
TimerArray timers;
LARGE_INTEGER Frequency;

//static int (*Import3001)(float p1); // Int

#endif
