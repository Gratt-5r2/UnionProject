#include "plugin\plugin.h"
#include "UnionAfx.h"
#include <crtversion.h>


extern "C"
int __stdcall DllMain( HMODULE hModule, DWORD fdwReason, LPVOID lpvReserved ) {
  if( fdwReason == DLL_PROCESS_ATTACH ) {
#if _DLL == 1
    UnionCore::Union.DefineCRTVersion(
      _VC_CRT_MAJOR_VERSION,
      _VC_CRT_MINOR_VERSION,
      _VC_CRT_BUILD_VERSION,
      _VC_CRT_RBUILD_VERSION );
#endif
  }
  if( fdwReason == DLL_PROCESS_DETACH ) {
  }
  return TRUE;
}