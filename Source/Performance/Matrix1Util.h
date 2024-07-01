static void (*Import3000)(LPSTR p1); // Call Function Name

#ifdef INCLUDE_MATRIX1UTIL20
#define INCLUDE_MATRIX1UTIL20

HMODULE mod;

mod = GetModuleHandle("Matrix1Util_20.dll");

if (mod) {
    *((void **)&Import3000) = GetProcAddress(mod, "CallFunctionName"); // CALL FUNCTION NAME%S%CallFunctionName
} 

#endif

void MUCallFunctionPointer(LPSTR p1) 
{
    Import3000(p1);
}
