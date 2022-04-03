// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License
// Minimal supported VC: 2010

#ifndef __UNION_STRING_OP_H__
#define __UNION_STRING_OP_H__

#ifndef INLINE
#define INLINE inline
#endif

namespace Common {

  INLINE CStringA operator + ( const CStringA str, const int32& val ) {
    return str + CStringA( val );
  }

  INLINE CStringW operator + ( const CStringW str, const int32& val ) {
    return str + CStringW( val );
  }

  INLINE CStringA operator + ( const CStringA str, const long32& val ) {
    return str + CStringA( val );
  }

  INLINE CStringW operator + ( const CStringW str, const long32& val ) {
    return str + CStringW( val );
  }

  INLINE CStringA operator + ( const CStringA str, const uint32& val ) {
    return str + CStringA( val );
  }

  INLINE CStringW operator + ( const CStringW str, const uint32& val ) {
    return str + CStringW( val );
  }

  INLINE CStringA operator + ( const CStringA str, const ulong32& val ) {
    return str + CStringA( val );
  }

  INLINE CStringW operator + ( const CStringW str, const ulong32& val ) {
    return str + CStringW( val );
  }

  INLINE CStringA operator + ( const CStringA str, const int64& val ) {
    return str + CStringA( val );
  }

  INLINE CStringW operator + ( const CStringW str, const int64& val ) {
    return str + CStringW( val );
  }

  INLINE CStringA operator + ( const CStringA str, const uint64& val ) {
    return str + CStringA( val );
  }

  INLINE CStringW operator + ( const CStringW str, const uint64& val ) {
    return str + CStringW( val );
  }

  INLINE CStringA operator + ( const CStringA str, const real32& val ) {
    return str + CStringA( val );
  }

  INLINE CStringW operator + ( const CStringW str, const real32& val ) {
    return str + CStringW( val );
  }

  INLINE CStringA operator + ( const CStringA str, const real64& val ) {
    return str + CStringA( val );
  }

  INLINE CStringW operator + ( const CStringW str, const real64& val ) {
    return str + CStringW( val );
  }

  INLINE CStringA operator + ( const char* val, const CStringA& str ) {
    return CStringA( val ) + str;
  }

  INLINE CStringW operator + ( const wchar_t* val, const CStringW& str ) {
    return CStringW( val ) + str;
  }
}

#endif // __UNION_STRING_OP_H__