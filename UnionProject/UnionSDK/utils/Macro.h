// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License
// Minimal supported VC: 2010

#ifndef __UNION_ALLOCATOR_32_H__
#define __UNION_ALLOCATOR_32_H__

#define untyped_ptr  ...
#define memsize(dst) shi_msize(dst)
#define True         (1)
#define False        (0)
#define Yes          True
#define No           False
#define Null         (nullptr)
#define None         (0)
#define Invalid      (-1)
#define HookDelayed  (0)
#define Undefined    Invalid
#define NotFound     Invalid
#define NullStrA     ((char*)None)
#define NullStrW     ((wchar_t*)None)
#define Success      True
#define Failed       False

#define MemDel(obj)       { shi_free(obj); obj = Null; }
#define DeleteObject(obj) { delete obj; obj = Null; }

#ifdef UNICODE
#define NullStr			NullStrW
#else
#define NullStr			NullStrA
#endif

#define zPixelX screen->anx
#define zPixelY screen->any
#define zVirtualX screen->nax
#define zVirtualY screen->nay
#define zNax( v, p ) v->nax( p )
#define zNay( v, p ) v->nay( p )
#define zAnx( v, p ) v->anx( p )
#define zAny( v, p ) v->any( p )

#define zKeyPressed( a ) zinput->KeyPressed(a)
#define zKeyToggled( a ) zinput->KeyToggled(a)
#define zMouseKeyPressed( button ) zinput->GetMouseButtonPressed##button()
#define zMouseKeyToggled( button ) zinput->GetMouseButtonToggled##button()
#define zBindPressed( logic ) zinput->GetState( logic )
#define zBindToggled( logic ) zinput->IsBindedToggled(logic, zinput->GetKey())

#define VID_MAX_XDIM GetSystemMetrics( SM_CXSCREEN )
#define VID_MAX_YDIM GetSystemMetrics( SM_CYSCREEN )

#define _HUGE_ENUF 1e+300
#define INFINITY   ((float)(_HUGE_ENUF * _HUGE_ENUF))
#define NAN        ((float)(INFINITY * 0.0F))
#define ISNAN(x)   _isnan(x)
#define THISCALL(a) (this->*a)

#ifndef zCall
#define zCall( address ) { XCALL( address ); }
#define zInit( call ) { call; }
#endif

#define XCALL(uAddr)      \
 __asm { mov esp, ebp   } \
 __asm { pop ebp        } \
 __asm { mov eax, uAddr } \
 __asm { jmp eax        }

#ifndef CORE_SECURE_DISABLE
#define UNSAFE_MESSAGE "Unsafe function. Don't call it or use CORE_SECURE_DISABLE"
#define UNSAFE __declspec(deprecated(UNSAFE_MESSAGE)) 
#else
#define UNSAFE
#endif

#define Enabled(v) (!v) ? 0 : 
#define zEngineDefined( e ) Union.GetEngineVersion() != e ? 0 : 

#define zMouseFix_SetInputWindow(x)                                                          \
  HMODULE zMouseFix = GetModuleHandle( "zMouseFix.dll" );                                    \
  if( zMouseFix ) {                                                                          \
    auto SetInputWindow = ( void( *)( HWND ) )GetProcAddress( zMouseFix, "SetInputWindow" ); \
    if( SetInputWindow )                                                                     \
      SetInputWindow( x );                                                                   \
  }

#endif // __UNION_ALLOCATOR_32_H__