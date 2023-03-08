// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZSTRING_H__VER1__
#define __ZSTRING_H__VER1__

#define USING_UNION_STRING_METHODS TRUE
#define UNPROTECT_ZSTRING_METHODS  FALSE

namespace Gothic_I_Addon {

  enum zTSTR_KIND {
    zSTR_ONLY,
    zSTR_BEFORE,
    zSTR_AFTER,
    zSTR_TO,
    zSTR_FROM
  };

  enum zTSTR_ALIGN {
    zSTR_RIGHT,
    zSTR_CENTER,
    zSTR_LEFT
  };

  class zSTRING {
    int   allocater;
    char* vector;
    int   length;
    int   reserved;
  public:
    zMEMPOOL_DECLARATION( zSTRING, 0x008AE6D8 )

    // Constructors
    zDefineInheritableCtor( zSTRING ) {}
    void zSTRING_OnInit( char const* )      zCall( 0x004010C0 );
    void zSTRING_OnInit()                   zCall( 0x00402F90 );
    void zSTRING_OnInit( zSTRING const& )   zCall( 0x00417CA0 );
    void zSTRING_OnInit( int )              zCall( 0x0046D520 );
    void zSTRING_OnInit( long )             zCall( 0x0046D620 );
    void zSTRING_OnInit( unsigned long )    zCall( 0x0046D720 );
    void zSTRING_OnInit( float, int )       zCall( 0x0046D820 );
    void zSTRING_OnInit( double, int )      zCall( 0x0046D970 );
    void zSTRING_OnInit( char )             zCall( 0x0051FA10 );
    void zSTRING_OnInit( zSTRING const* )   zCall( 0x00722540 );
    zSTRING( char const* vec )              zInit( zSTRING_OnInit( vec ));
    zSTRING()                               zInit( zSTRING_OnInit() );
    zSTRING( zSTRING const& val )           zInit( zSTRING_OnInit( val ));
    zSTRING( int val )                      zInit( zSTRING_OnInit( val ));
    zSTRING( long val )                     zInit( zSTRING_OnInit( val ));
    zSTRING( unsigned long val )            zInit( zSTRING_OnInit( val ));
    zSTRING( float val, int rad = 3 )       zInit( zSTRING_OnInit( val, rad ));
    zSTRING( double val, int rad = 5 )      zInit( zSTRING_OnInit( val, rad ));
    zSTRING( char val )                     zInit( zSTRING_OnInit( val ));
    zSTRING( zSTRING const* val )           zInit( zSTRING_OnInit( val ));
    virtual ~zSTRING()                      zCall( 0x00401160 );
    
    char& operator[]( unsigned int )        zCall( 0x00447300 );
    zSTRING& operator += ( char const* )    zCall( 0x0066C7D0 );
    zSTRING& operator =  ( char const* )    zCall( 0x004D5310 );
    zSTRING& operator =  ( zSTRING const& ) zCall( 0x005988F0 );
    char* ToChar() const                    zCall( 0x00465C00 );
    void Clear()                            zCall( 0x00598A50 );
    bool IsEmpty() const                    zCall( 0x0077F500 );
    zSTRING& Lower()                        zCall( 0x0046CF70 );
    zSTRING& Upper()                        zCall( 0x0046D090 );
    zSTRING& UpperFirstLowerRest()          zCall( 0x0046D1B0 );
    
    inline operator const char*() const { return ToChar(); }
    inline int Length() const { return length; }
    inline bool operator == ( const char* other ) const { return ((int(__stdcall*)( const char*, const char* ))*(void**)0x008132D0)( ToChar(), other ) == 0; }
    inline bool operator != ( const char* other ) const { return !operator == ( other ); }
    inline zSTRING& Append( const zSTRING& other ) { Insert( length, other ); }

    zSTRING& Align( zTSTR_ALIGN, int, char )                                      zCall( 0x0046D300 );
    zSTRING PickWord( unsigned int, zSTRING const&, zSTRING const& ) const        zCall( 0x0046DAC0 );
    char const* PickWordPos( unsigned int, zSTRING const&, zSTRING const& ) const zCall( 0x0046DDB0 );
    zSTRING PickWord_Old( int, zSTRING const& ) const                             zCall( 0x0046DF30 );
    int Insert( unsigned int, zSTRING const& )                                    zCall( 0x0046E010 );
    zSTRING Inserted( unsigned int, zSTRING const& ) const                        zCall( 0x0046E140 );
    int Overwrite( unsigned int, zSTRING const& )                                 zCall( 0x0046E2E0 );
    zSTRING Overwritten( unsigned int, zSTRING const& ) const                     zCall( 0x0046E4E0 );
    int DeleteRight( unsigned int )                                               zCall( 0x0046E600 );
    int Delete( unsigned int, unsigned long )                                     zCall( 0x0046E710 );
    zSTRING Deleted( unsigned int, unsigned long ) const                          zCall( 0x0046E820 );
    int Delete( zSTRING const&, zTSTR_KIND )                                      zCall( 0x0046E980 );
    zSTRING Deleted( zSTRING const&, zTSTR_KIND ) const                           zCall( 0x0046EB60 );
    zSTRING Copied( unsigned int, unsigned long ) const                           zCall( 0x0046EE10 );
    int Copy( zSTRING const&, zTSTR_KIND const& )                                 zCall( 0x0046EFA0 );
    int Copy( unsigned int, unsigned long )                                       zCall( 0x0046EC60 );
    zSTRING Copied( zSTRING const&, zTSTR_KIND const& ) const                     zCall( 0x0046F260 );
    void TrimLeft( char )                                                         zCall( 0x0046F360 );
    void TrimRight( char )                                                        zCall( 0x0046F4A0 );
    int Search( int, char const*, unsigned int ) const                            zCall( 0x0046F650 );
    int SearchRev( zSTRING const&, unsigned int ) const                           zCall( 0x0046F760 );
    bool __cdecl Sprintf( char const*, ... )                                      zCall( 0x0046F9F0 );
    int Search( zSTRING const&, unsigned int ) const                              zCall( 0x00495310 );
    long ToInt() const                                                            zCall( 0x00598B20 );
    float ToFloat() const                                                         zCall( 0x00598B40 );
    int Search( char const*, unsigned int ) const                                 zCall( 0x00598B60 );
    void Init()                                                                   zCall( 0x00629900 );
  };

  inline zSTRING operator + ( const zSTRING& s1, const zSTRING& s2 ) {
    return zSTRING( s1 ) += s2.ToChar();
  }

  inline zSTRING operator + ( const zSTRING& s1, const char* s2 ) {
    return zSTRING( s1 ) += s2;
  }

  inline zSTRING& operator += ( zSTRING& s1, const zSTRING& s2 ) {
    return s1.Append( s2 );
  }

  // case Insensitive
  inline int operator == ( const zSTRING& s1, const zSTRING& s2 ) {
    return s1.operator ==( s2 );
  }

  // case Insensitive
  inline int operator == ( const zSTRING& s1, const char* s2 ) {
    return s1.operator ==( s2 );
  }

  // case Insensitive
  inline int operator != ( const zSTRING& s1, const zSTRING& s2 ) {
    return s1.operator !=( s2 );
  }

  // case Insensitive
  inline int operator != ( const zSTRING& s1, const char* s2 ) {
    return s1.operator !=( s2 );
  }

} // namespace Gothic_I_Addon

#undef USING_UNION_STRING_METHODS
#undef UNPROTECT_ZSTRING_METHODS
#endif // __ZSTRING_H__VER1__