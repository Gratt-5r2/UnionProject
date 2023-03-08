// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZSTRING_H__VER3__
#define __ZSTRING_H__VER3__

namespace Gothic_II_Addon {

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
    zMEMPOOL_DECLARATION( zSTRING, 0x008CDC98 )

    // Constructors
    zDefineInheritableCtor( zSTRING ) {}
    void zSTRING_OnInit()                                zCall( 0x00402AF0 );
    void zSTRING_OnInit( char const* vec )               zCall( 0x004010C0 );
    void zSTRING_OnInit( zSTRING const& )                zCall( 0x00416500 );
    void zSTRING_OnInit( int val )                       zCall( 0x00435870 );
    void zSTRING_OnInit( float val, int rad = 3 )        zCall( 0x00435970 );
    void zSTRING_OnInit( double val, int rad = 5 )       zCall( 0x00454680 );
    void zSTRING_OnInit( unsigned long val )             zCall( 0x00461E90 );
    void zSTRING_OnInit( char val )                      zCall( 0x0051AC80 );
    void zSTRING_OnInit( long val )                      zCall( 0x006CFE50 );
    void zSTRING_OnInit( zSTRING const* val )            zCall( 0x007928D0 );
    zSTRING()                                            zInit( zSTRING_OnInit() );
    zSTRING( char const* vec )                           zInit( zSTRING_OnInit( vec ) );
    zSTRING( zSTRING const& val )                        zInit( zSTRING_OnInit( val ) );
    zSTRING( int val )                                   zInit( zSTRING_OnInit( val ) );
    zSTRING( float val, int rad = 3 )                    zInit( zSTRING_OnInit( val, rad ) );
    zSTRING( double val, int rad = 5 )                   zInit( zSTRING_OnInit( val, rad ) );
    zSTRING( unsigned long val )                         zInit( zSTRING_OnInit( val ) );
    zSTRING( char val )                                  zInit( zSTRING_OnInit( val ) );
    zSTRING( long val )                                  zInit( zSTRING_OnInit( val ) );
    zSTRING( zSTRING const* val )                        zInit( zSTRING_OnInit( val ) );
    virtual ~zSTRING()                                   zCall( 0x00401160 );  // scalar:0x00401140 vector:0x0041C760 destructor:0x00401160
    
    char& operator[]( unsigned int index )               zCall( 0x00445A20 );
    zSTRING& operator += ( char const* vec )             zCall( 0x0067A7B0 );
    zSTRING& operator =  ( char const* vec )             zCall( 0x004CFAF0 );
    zSTRING& operator =  ( zSTRING const& val )          zCall( 0x0059CEB0 );
    char* ToChar() const                                 zCall( 0x004639D0 );
    void Clear()                                         zCall( 0x0059D010 );
    bool IsEmpty() const                                 zCall( 0x00674210 );
    zSTRING& Lower()                                     zCall( 0x0046A9F0 );
    zSTRING& Upper()                                     zCall( 0x0046AB00 );
    zSTRING& UpperFirstLowerRest()                       zCall( 0x0046AC10 );

    inline operator const char*() const { return ToChar(); }
    inline int Length() const { return length; }
    inline bool operator == ( const char* other ) const { return ((int(__stdcall*)( const char*, const char* )) * (void**)0x0082E174)( ToChar(), other ) == 0; }
    inline bool operator != ( const char* other ) const { return !operator == ( other ); }
    inline zSTRING& Append( const zSTRING& other ) { Insert( length, other ); }

    zSTRING& Align( zTSTR_ALIGN, int, char )                                      zCall( 0x0046AD60 );
    zSTRING PickWord( unsigned int, zSTRING const&, zSTRING const& ) const        zCall( 0x0046AF80 );
    char const* PickWordPos( unsigned int, zSTRING const&, zSTRING const& ) const zCall( 0x0046B1D0 );
    zSTRING PickWord_Old( int, zSTRING const& ) const                             zCall( 0x0046B340 );
    int Insert( unsigned int, zSTRING const& )                                    zCall( 0x0046B400 );
    zSTRING Inserted( unsigned int, zSTRING const& ) const                        zCall( 0x0046B520 );
    int Overwrite( unsigned int, zSTRING const& )                                 zCall( 0x0046B6A0 );
    zSTRING Overwritten( unsigned int, zSTRING const& ) const                     zCall( 0x0046B890 );
    int DeleteRight( unsigned int )                                               zCall( 0x0046B990 );
    int Delete( unsigned int, unsigned long )                                     zCall( 0x0046BAA0 );
    zSTRING Deleted( unsigned int, unsigned long ) const                          zCall( 0x0046BBB0 );
    int Delete( zSTRING const&, zTSTR_KIND )                                      zCall( 0x0046BCF0 );
    zSTRING Deleted( zSTRING const&, zTSTR_KIND ) const                           zCall( 0x0046BEE0 );
    zSTRING Copied( unsigned int, unsigned long ) const                           zCall( 0x0046C170 );
    int Copy( zSTRING const&, zTSTR_KIND const& )                                 zCall( 0x0046C2D0 );
    int Copy( unsigned int index, unsigned long length )                          zCall( 0x0046BFC0 );
    zSTRING Copied( zSTRING const&, zTSTR_KIND const& ) const                     zCall( 0x0046C550 );
    void TrimLeft( char )                                                         zCall( 0x0046C630 );
    void TrimRight( char )                                                        zCall( 0x0046C770 );
    int Search( int, char const*, unsigned int ) const                            zCall( 0x0046C920 );
    int SearchRev( zSTRING const&, unsigned int ) const                           zCall( 0x0046CA20 );
    bool __cdecl Sprintf( char const*, ... )                                      zCall( 0x0046CC60 );
    int Search( zSTRING const&, unsigned int ) const                              zCall( 0x00492680 );
    float ToFloat() const                                                         zCall( 0x004936C0 );
    long ToInt() const                                                            zCall( 0x0059D0F0 );
    int Search( char const*, unsigned int ) const                                 zCall( 0x0059D110 );
    void Init()                                                                   zCall( 0x006D9B80 );
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

} // namespace Gothic_II_Addon

#endif // __ZSTRING_H__VER3__