// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License
// Minimal supported VC: 2010

#ifndef __UNION_MAIN_H__
#define __UNION_MAIN_H__

namespace UnionCore {
#define CORE_VERSION 100600
#undef GetSystemDirectory

  enum TEngineHash {
    Hash_G1    = 0x225BA11E,
    Hash_G1A   = 0xBCA27323,
    Hash_G2    = 0xA2EE682C,
    Hash_G2A   = 0x2BCD7E30,
    Hash_G1AL1 = 0x02648DED,
    Hash_G1AL2 = 0xAC7117A1
  };

  enum TSystemLangID {
    Lang_Other,
    Lang_Rus, // russian
    Lang_Eng, // english
    Lang_Deu, // german
    Lang_Pol, // polish
    Lang_Rou, // romanian
    Lang_Ita, // italian
    Lang_Cze, // czech
    Lang_Esp, // spanish
    Lang_Max
  };

  struct ASTAPI TVersion {
    union {
      struct {
        Common::uint64 Micro : 8;
        Common::uint64 Minor : 24;
        Common::uint64 Major : 32;
      };
      Common::uint64 ui64Version;
    };

    TVersion();
    TVersion( const Common::uint32& major, const Common::uint32& minor, const char& micro = 0 );
    Common::string ToString();
    operator Common::uint64();
  };

  class ASTAPI CUnion {
    TVersion UnionVersion;
    Common::uint EngineVersion;
    TSystemLangID SystemLanguage;
    Common::COption UnionOption;
    Common::COption GameOption;
    Common::COption DefaultOption;
    Common::COption SysPackOption;
    Common::uint32 GothicHash;
    Common::bool_t IsInit;
    Common::string CmdLine;
    Common::string GameIni;

  public:
    CUnion();
    void InitGlobal();
    TVersion GetUnionVersion();
    Common::uint GetEngineVersion();
    TSystemLangID GetSystemLanguage();
    Common::COption& GetUnionOption();
    Common::COption& GetGameOption();
    Common::COption& GetDefaultOption();
    Common::COption& GetSysPackOption();
    Common::uint32 GetGothicHash();
    Common::bool_t UnionIsInit();
    const Common::string& GetGameDirectory();
    Common::string GetSystemDirectory( bool full = true );
    Common::string GetCmdLine();
    Common::string GetGameIni();
    int GetLastSaveSlot();
    void DefineCRTVersion( Common::uint32 major, Common::uint32 minor, Common::uint32 build, Common::uint32 rbuild );
    static HMODULE __stdcall LoadLibraryA( LPSTR lpName );
    static HMODULE __stdcall LoadLibraryW( LPWSTR lpName );
    static bool Dx11IsEnabled();
    static HMODULE GetDx11Module();
    static Common::string GetGothicFileName();
    ~CUnion();
  };

  ASTAPI CUnion Union;

  struct TSaveLoadGameInfo {
    // None: -3
    // New game: -2
    // Current: -1
    // Quick: 0
    // Saved: 1-20
    Common::int_t slotID;

    // If a load reason is a world changing,
    // than that parameter is TRUE
    Common::bool_t changeLevel;

    // If a load reason is a world changing or a new game,
    // than that parameter has a world name.
    Common::string worldName;

    // If a load reason is a world changing,
    // than that parameter has a wayPoint name.
    Common::string wayPoint;

    // Save slot name by slot ID
    static Common::string GetSaveSlotName( Common::int_t id ) {
      if( id > 0 )  return "savegame" + Common::string( id );
      if( id == 0 ) return "quicksave";
                    return "current";
    }
  };

  ASTAPI TSaveLoadGameInfo SaveLoadGameInfo;

  template <typename T>
  inline T ZenDef( T G1, T G1A, T G2, T G2A ) {
    switch( Union.GetEngineVersion() ) {
      case Engine_G1:	 return G1;
      case Engine_G1A: return G1A;
      case Engine_G2:	 return G2;
      case Engine_G2A: return G2A;
    };
    return None;
  };
}

#endif // __UNION_MAIN_H__