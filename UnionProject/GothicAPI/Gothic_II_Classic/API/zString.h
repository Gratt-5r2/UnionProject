// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZSTRING_H__VER2__
#define __ZSTRING_H__VER2__

#define USING_UNION_STRING_METHODS TRUE
#define UNPROTECT_ZSTRING_METHODS  FALSE

namespace Gothic_II_Classic {
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
    zMEMPOOL_DECLARATION( zSTRING, 0x008BF680 )

    // Constructors
    zDefineInheritableCtor( zSTRING ) {}
    void zSTRING_OnInit( char const* )      zCall( 0x004010C0 );
    void zSTRING_OnInit()                   zCall( 0x00402AF0 );
    void zSTRING_OnInit( zSTRING const& )   zCall( 0x00416500 );
    void zSTRING_OnInit( int )              zCall( 0x00435370 );
    void zSTRING_OnInit( float, int )       zCall( 0x00435470 );
    void zSTRING_OnInit( double, int )      zCall( 0x00453F30 );
    void zSTRING_OnInit( unsigned long )    zCall( 0x00461680 );
    void zSTRING_OnInit( char )             zCall( 0x00517EB0 );
    void zSTRING_OnInit( long )             zCall( 0x00673000 );
    void zSTRING_OnInit( zSTRING const* )   zCall( 0x00732E90 );
    zSTRING( char const* vec )              zInit( zSTRING_OnInit( vec ) );
    zSTRING()                               zInit( zSTRING_OnInit() );
    zSTRING( zSTRING const& val )           zInit( zSTRING_OnInit( val ) );
    zSTRING( int val )                      zInit( zSTRING_OnInit( val ) );
    zSTRING( float val, int rad = 3 )       zInit( zSTRING_OnInit( val, rad ) );
    zSTRING( double val, int rad = 5 )      zInit( zSTRING_OnInit( val, rad ) );
    zSTRING( unsigned long val )            zInit( zSTRING_OnInit( val ) );
    zSTRING( char val )                     zInit( zSTRING_OnInit( val ) );
    zSTRING( long val )                     zInit( zSTRING_OnInit( val ) );
    zSTRING( zSTRING const* val )           zInit( zSTRING_OnInit( val ) );
    virtual ~zSTRING()                      zCall( 0x00401160 );
    
    char& operator[]( unsigned int )        zCall( 0x004453F0 );
    zSTRING& operator += ( char const* )    zCall( 0x00673100 );
    zSTRING& operator =  ( char const* )    zCall( 0x004CD590 );
    zSTRING& operator =  ( zSTRING const& ) zCall( 0x00597950 );
    char* ToChar() const                    zCall( 0x004631C0 );
    void Clear()                            zCall( 0x00597AB0 );
    bool IsEmpty() const                    zCall( 0x0078AF30 );
    zSTRING& Lower()                        zCall( 0x00469DC0 );
    zSTRING& Upper()                        zCall( 0x00469ED0 );
    zSTRING& UpperFirstLowerRest()          zCall( 0x00469FE0 );
    
    inline operator const char*() const { return ToChar(); }
    inline int Length() const { return length; }
    inline bool operator == ( const char* other ) const { return ((int(__stdcall*)( const char*, const char* ))*(void**)0x00820174)( ToChar(), other ) == 0; }
    inline bool operator != ( const char* other ) const { return !operator == ( other ); }
    inline zSTRING& Append( const zSTRING& other ) { Insert( length, other ); }

    zSTRING& Align( zTSTR_ALIGN, int, char )                                      zCall( 0x0046A130 );
    zSTRING PickWord( unsigned int, zSTRING const&, zSTRING const& ) const        zCall( 0x0046A350 );
    char const* PickWordPos( unsigned int, zSTRING const&, zSTRING const& ) const zCall( 0x0046A5A0 );
    zSTRING PickWord_Old( int, zSTRING const& ) const                             zCall( 0x0046A710 );
    int Insert( unsigned int, zSTRING const& )                                    zCall( 0x0046A7D0 );
    zSTRING Inserted( unsigned int, zSTRING const& ) const                        zCall( 0x0046A8F0 );
    int Overwrite( unsigned int, zSTRING const& )                                 zCall( 0x0046AA70 );
    zSTRING Overwritten( unsigned int, zSTRING const& ) const                     zCall( 0x0046AC60 );
    int DeleteRight( unsigned int )                                               zCall( 0x0046AD60 );
    int Delete( unsigned int, unsigned long )                                     zCall( 0x0046AE70 );
    zSTRING Deleted( unsigned int, unsigned long ) const                          zCall( 0x0046AF80 );
    int Delete( zSTRING const&, zTSTR_KIND )                                      zCall( 0x0046B0C0 );
    zSTRING Deleted( zSTRING const&, zTSTR_KIND ) const                           zCall( 0x0046B2B0 );
    zSTRING Copied( unsigned int, unsigned long ) const                           zCall( 0x0046B540 );
    int Copy( zSTRING const&, zTSTR_KIND const& )                                 zCall( 0x0046B6A0 );
    int Copy( unsigned int, unsigned long )                                       zCall( 0x0046B390 );
    zSTRING Copied( zSTRING const&, zTSTR_KIND const& ) const                     zCall( 0x0046B920 );
    void TrimLeft( char )                                                         zCall( 0x0046BA00 );
    void TrimRight( char )                                                        zCall( 0x0046BB40 );
    int Search( int, char const*, unsigned int ) const                            zCall( 0x0046BCF0 );
    int SearchRev( zSTRING const&, unsigned int ) const                           zCall( 0x0046BDF0 );
    bool __cdecl Sprintf( char const*, ... )                                      zCall( 0x0046C030 );
    int Search( zSTRING const&, unsigned int ) const                              zCall( 0x00490C70 );
    float ToFloat() const                                                         zCall( 0x00491C90 );
    long ToInt() const                                                            zCall( 0x00597B90 );
    int Search( char const*, unsigned int ) const                                 zCall( 0x00597BB0 );
    void Init()                                                                   zCall( 0x0067CC70 );
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

} // namespace Gothic_II_Classic

#undef USING_UNION_STRING_METHODS
#undef UNPROTECT_ZSTRING_METHODS
#endif // __ZSTRING_H__VER2__