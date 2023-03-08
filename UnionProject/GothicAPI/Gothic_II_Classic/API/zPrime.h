// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZPRIME_H__VER2__
#define __ZPRIME_H__VER2__

namespace Gothic_II_Classic {

  // sizeof 01h
  class zCPrime {
  public:

    zCPrime() {}
    static int IsPrime( unsigned long )             zCall( 0x005BA040 );
    static unsigned short PrimeNo( unsigned short ) zCall( 0x005BA110 );
    static unsigned long NextPrime( unsigned long ) zCall( 0x005BA220 );

    // user API
    #include "zCPrime.inl"
  };

} // namespace Gothic_II_Classic

#endif // __ZPRIME_H__VER2__