// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License
// Minimal supported VC: 2010

#ifndef __UNION_OPTION_H__
#define __UNION_OPTION_H__

namespace Common {
  class ASTAPI COption {
    bool32 bIsInit;
    bool32 bIsPhysical;
  public:
    CDocumentA mDocument;
    CString  sConfigName;
    byte blocks[8u];
  public:
    COption();
    COption( CString, bool physical_only = false );
    void Init( CString, bool physical_only = false );
    void Exit();
    void SaveAll();
    bool32 IsInit();
    bool32 IsPhysicalOnly();
    bool32 IsExists( CString sec, CString val = NullStr );
    void32 GetValue( CString sec, CString val );
    void SetValue( CString sec, CString val, HBuffer buf, uint32 size );
    void ChangeValue( CString, CString, CString );
    void Write( const bool&, CString sec, CString val );
    void Write( const byte&, CString sec, CString val );
    void Write( const int32&, CString sec, CString val );
    void Write( const real32&, CString sec, CString val );
    void Write( const CString&, CString sec, CString val );
    void Read( bool&, CString sec, CString val, bool def = false );
    void Read( byte&, CString sec, CString val, byte def = 0 );
    void Read( int32&, CString sec, CString val, int32 def = 0 );
    void Read( real32&, CString sec, CString val, real32 def = 0.0f );
    void Read( CString&, CString sec, CString val, CString def = NullStr );
    ~COption();
  };
} // namespace Common

#endif // __UNION_OPTION_H__