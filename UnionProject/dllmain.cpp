#include "GothicAPI/zGothicAPI.h"



extern "C"
int __stdcall DllMain( HMODULE hModule, DWORD fdwReason, LPVOID lpvReserved ) {
  if( fdwReason == DLL_PROCESS_ATTACH ) {
  }
  if( fdwReason == DLL_PROCESS_DETACH ) {
  }
  return TRUE;
}