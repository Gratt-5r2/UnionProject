// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License
// Minimal supported VC: 2010

#ifndef __PLUGIN_H__
#define __PLUGIN_H__

#include "..\GothicAPI\zGothicAPI.h"

#ifdef __G1
using namespace Gothic_I_Classic;
#endif

#ifdef __G1A
using namespace Gothic_I_Addon;
#endif

#ifdef __G2
using namespace Gothic_II_Classic;
#endif

#ifdef __G2A
using namespace Gothic_II_Addon;
#endif

#endif // __PLUGIN_H__