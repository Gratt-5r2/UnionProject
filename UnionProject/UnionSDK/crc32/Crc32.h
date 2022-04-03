// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License
// Minimal supported VC: 2010

#ifndef __UNION_CRC_32_H__
#define __UNION_CRC_32_H__

namespace Common {
  struct ASTAPI CCRC32 {
    string FileName;
    uint Length;
    uint Crc32;

    CCRC32( HMODULE module );
    CCRC32( string fileName );
    CCRC32( byte* buffer, uint length );
  };

  struct ASTAPI CCRC64 {
    string FileName;
    uint64 Length;
    uint64 Crc64;

    CCRC64( HMODULE module );
    CCRC64( string fileName );
    CCRC64( byte* buffer, uint length );
  };
} // namespace Common

#endif // __UNION_CRC_32_H__