#include "zGothicAPI.h"

// native engine operators
void* operator new ( size_t sz )      { return shi_malloc( sz ); }
void* operator new []( size_t sz )    { return shi_malloc( sz ); }
void  operator delete ( void* mem )   { shi_free( mem ); }
void  operator delete []( void* mem ) { shi_free( mem ); }

// static RTTI DynamicCast pointer
#if _DLL != 1
extern void* __cdecl __RTDynamicCast( void*, long, void*, void*, int );
cexport void* RTDynamicCast_MT = (void*)__RTDynamicCast;
#endif