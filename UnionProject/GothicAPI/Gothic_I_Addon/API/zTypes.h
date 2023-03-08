// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZTYPES_H__VER1__
#define __ZTYPES_H__VER1__

namespace Gothic_I_Addon {

  typedef float               zREAL;
  typedef int                 zTFrameCtr;
  typedef int                 zBOOL;
  typedef char                zBOOL8;
  typedef short int           zBOOL16;
  typedef int                 zBOOL32;
  typedef char                zINT8;
  typedef char                zSINT8;
  typedef unsigned char       zUINT8;
  typedef short               zINT16;
  typedef short               zSINT16;
  typedef unsigned short      zUINT16;
  typedef long                zINT32;
  typedef long                zSINT32;
  typedef unsigned long       zUINT32;
  typedef unsigned __int64    zQWORD;
  typedef unsigned __int64    zUQWORD;
  typedef signed  __int64     zSQWORD;
  typedef unsigned long       zDWORD;
  typedef unsigned long int   zUDWORD;
  typedef signed long int     zSDWORD;
  typedef signed long         zLONG;
  typedef unsigned short int  zWORD;
  typedef unsigned short int  zUWORD;
  typedef signed short int    zSWORD;
  typedef signed short int    zINT;
  typedef unsigned char       zBYTE;
  typedef unsigned char       zUBYTE;
  typedef signed char         zSBYTE;
  typedef float (*LerpFunc)( const float, const float );

  typedef int(
    zTStaticIntersectionTest)(zREAL timeStamp, 
    zCCollisionObject*  collObject0, const zMAT4& trafoObj0,
    zCCollisionObject*  collObject1, const zMAT4& trafoObj1,
    zCCollisionReport** ppoCollReport);

  typedef int(zTDynamicIntersectionTest)(
    zCCollisionObject*  collObject0,
    zCCollisionObject*  collObject1,
    zCCollisionReport** ppoCollReport);

#ifndef _FILE_DEFINED
  struct _iobuf {
    char* _ptr;
    int   _cnt;
    char* _base;
    int   _flag;
    int   _file;
    int   _charbuf;
    int   _bufsiz;
    char* _tmpfname;
  };
  typedef struct _iobuf FILE;
#define _FILE_DEFINED
#endif

#ifndef _finddata_t
  struct _finddata_t {
    unsigned int  attrib;
    long long     time_create;
    long long     time_access;
    long long     time_write;
    unsigned long size;
    char          name[260];
  };
#endif

} // namespace Gothic_II_Addon

#endif // __ZTYPES_H__VER1__