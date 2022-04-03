// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License
// Minimal supported VC: 2010

#ifndef __UNION_CMD_H__
#define __UNION_CMD_H__

namespace Common {

  typedef uint32 CPID;
  typedef void( __stdcall* iofunc )( class CCmd& );
  
  typedef enum : byte {
    CMD_BLACK,
    CMD_BLUE,
    CMD_GREEN,
    CMD_CYAN,
    CMD_RED,
    CMD_PURPLE,
    CMD_YELLOW,
    CMD_WHITE,
    CMD_INTENSITY,
    CMD_INT = CMD_INTENSITY,

    CMD_BLACK_INT  = CMD_BLACK  | CMD_INT,
    CMD_BLUE_INT   = CMD_BLUE   | CMD_INT,
    CMD_GREEN_INT  = CMD_GREEN  | CMD_INT,
    CMD_CYAN_INT   = CMD_CYAN   | CMD_INT,
    CMD_RED_INT    = CMD_RED    | CMD_INT,
    CMD_PURPLE_INT = CMD_PURPLE | CMD_INT,
    CMD_YELLOW_INT = CMD_YELLOW | CMD_INT,
    CMD_WHITE_INT  = CMD_WHITE  | CMD_INT,

    CMD_RESET = CMD_INTENSITY
  }
  ECmdColorID;

  struct Col16 {
    union {
      struct {
        byte front;
        byte back;
      };
      short color;
    };

    Col16() {
      front = CMD_WHITE;
      back = CMD_BLACK;
    }

    Col16( const byte& fnt, const byte& bck = CMD_BLACK ) {
      front = fnt;
      back = bck;
    };
  };

  class ASTAPI CCmd {
    bool32 bHasHandle;
    static HANDLE  hConsole;
    static uint32  ulRef;
  protected:
    virtual CCmd& Write( const wchar_t* str, const uint& length );
  public:
    static void Show();
    static void Hide();
    static void Release();
    static void Clear();
    static HANDLE GetHandle();
    CCmd( bool32 shwCsl = False );
    CCmd& Print( const CStringA& str, const CPID& cp = ANSI_CODEPAGE_CYRILLIC );
    CCmd& Print( const CStringW& str );
    CCmd& Print( const text str, const CPID& cp = ANSI_CODEPAGE_CYRILLIC );
    CCmd& Print( const wtext str );
    CCmd& operator << ( const CStringA& str );
    CCmd& operator << ( const CStringW& str );
    CCmd& operator << ( const text str );
    CCmd& operator << ( const wtext str );
    CCmd& operator << ( const int32& val );
    CCmd& operator << ( const uint32& val );
    CCmd& operator << ( const long32& val );
    CCmd& operator << ( const ulong32& val );
    CCmd& operator << ( const int64& val );
    CCmd& operator << ( const uint64& val );
    CCmd& operator << ( const real32& val );
    CCmd& operator << ( const real64& val );
    CCmd& operator << ( const Col16& col );
    CCmd& operator << ( const ECmdColorID& col );
    CCmd& operator << ( iofunc fnc );
    ~CCmd();
  };

  class ASTAPI CLogger : public CCmd {
    string fileName;
    bool nextLine;
    FILE* file;
    void PrintTime();
  public:
    CLogger( string file );
    virtual CCmd& Write( const wchar_t* str, const uint& length );
    virtual ~CLogger();
  };

  ASTAPI void __stdcall endl( CCmd& );
  ASTAPI void __stdcall tab( CCmd& );

  extern ASTAPI CCmd cmd;
}
// namespace Common

#endif // __UNION_CMD_H__