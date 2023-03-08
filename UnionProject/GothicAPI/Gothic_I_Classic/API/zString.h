// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZSTRING_H__VER0__
#define __ZSTRING_H__VER0__

namespace Gothic_I_Classic {

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
    zMEMPOOL_DECLARATION( zSTRING, 0x008699A0 )
      
    // Constructors
    zDefineInheritableCtor( zSTRING ) {}
    void zSTRING_OnInit( char const* )      zCall( 0x004013A0 );
    void zSTRING_OnInit()                   zCall( 0x00402B30 );
    void zSTRING_OnInit( zSTRING const& )   zCall( 0x00415F40 );
    void zSTRING_OnInit( int )              zCall( 0x00465810 );
    void zSTRING_OnInit( long )             zCall( 0x00465910 );
    void zSTRING_OnInit( unsigned long )    zCall( 0x00465A10 );
    void zSTRING_OnInit( float, int )       zCall( 0x00465B10 );
    void zSTRING_OnInit( double, int )      zCall( 0x00465C60 );
    void zSTRING_OnInit( char )             zCall( 0x0050AC70 );
    void zSTRING_OnInit( zSTRING const* )   zCall( 0x006E9570 );
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
    virtual ~zSTRING()                      zCall( 0x00401260 );
    
    char& operator[]( unsigned int )        zCall( 0x00441AC0 );
    zSTRING& operator += ( char const* )    zCall( 0x00644ED0 );
    zSTRING& operator =  ( char const* )    zCall( 0x004C5820 );
    zSTRING& operator =  ( zSTRING const& ) zCall( 0x0057E0C0 );
    char* ToChar() const                    zCall( 0x0045E2E0 );
    void Clear()                            zCall( 0x0057E220 );
    bool IsEmpty() const                    zCall( 0x0073F440 );
    zSTRING& Lower()                        zCall( 0x00465280 );
    zSTRING& Upper()                        zCall( 0x00465390 );
    zSTRING& UpperFirstLowerRest()          zCall( 0x004654A0 );

    inline operator const char*() const                 { return ToChar(); }
    inline int Length() const                           { return length;   }
    inline bool operator == ( const char* other ) const { return ((int( __stdcall* )(const char*, const char*))*(void**)0x007D02C4)(ToChar(), other) == 0; }
    inline bool operator != ( const char* other ) const { return !operator == ( other ); }
    inline zSTRING& Append( const zSTRING& other )      { Insert( length, other ); }

    zSTRING& Align( zTSTR_ALIGN, int, char )                                      zCall( 0x004655F0 );
    zSTRING PickWord( unsigned int, zSTRING const&, zSTRING const& ) const        zCall( 0x00465DB0 );
    char const* PickWordPos( unsigned int, zSTRING const&, zSTRING const& ) const zCall( 0x00466000 );
    zSTRING PickWord_Old( int, zSTRING const& ) const                             zCall( 0x00466170 );
    int Insert( unsigned int, zSTRING const& )                                    zCall( 0x00466230 );
    zSTRING Inserted( unsigned int, zSTRING const& ) const                        zCall( 0x00466350 );
    int Overwrite( unsigned int, zSTRING const& )                                 zCall( 0x004664D0 );
    zSTRING Overwritten( unsigned int, zSTRING const& ) const                     zCall( 0x004666C0 );
    int DeleteRight( unsigned int )                                               zCall( 0x004667C0 );
    int Delete( unsigned int, unsigned long )                                     zCall( 0x004668D0 );
    zSTRING Deleted( unsigned int, unsigned long ) const                          zCall( 0x004669E0 );
    int Delete( zSTRING const&, zTSTR_KIND )                                      zCall( 0x00466B20 );
    zSTRING Deleted( zSTRING const&, zTSTR_KIND ) const                           zCall( 0x00466D10 );
    zSTRING Copied( unsigned int, unsigned long ) const                           zCall( 0x00466FA0 );
    int Copy( zSTRING const&, zTSTR_KIND const& )                                 zCall( 0x00467100 );
    int Copy( unsigned int, unsigned long )                                       zCall( 0x00466DF0 );
    zSTRING Copied( zSTRING const&, zTSTR_KIND const& ) const                     zCall( 0x00467380 );
    void TrimLeft( char )                                                         zCall( 0x00467460 );
    void TrimRight( char )                                                        zCall( 0x004675A0 );
    int Search( int, char const*, unsigned int ) const                            zCall( 0x00467750 );
    int SearchRev( zSTRING const&, unsigned int ) const                           zCall( 0x00467850 );
    bool __cdecl Sprintf( char const*, ... )                                      zCall( 0x00467A90 );
    int Search( zSTRING const&, unsigned int ) const                              zCall( 0x00489C00 );
    long ToInt() const                                                            zCall( 0x0057E2F0 );
    float ToFloat() const                                                         zCall( 0x0057E310 );
    int Search( char const*, unsigned int ) const                                 zCall( 0x0057E330 );
    void Init()                                                                   zCall( 0x00737C50 );
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

} // namespace Gothic_I_Classic

#endif // __ZSTRING_H__VER0__