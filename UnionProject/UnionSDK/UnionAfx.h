// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License
// Minimal supported VC: 2010

#ifndef __UNION_H__
#define __UNION_H__

#pragma warning(push)
#pragma warning(disable:4251)
#pragma warning(disable:4005)
#pragma warning(disable:6258)

#pragma comment(lib, "shw32.lib")
#pragma comment(lib, "vdfs32g.lib")

#define ASTAPI __declspec(dllimport)
#include "utils/Macro.h"
#include "utils/Types.h"
#include "array/Array.h"
#include "string/String.h"
#include "thread/Thread.h"
#include "message/Message.h"
#include "map/Map.h"
#include "rowString/Document.h"
#include "options/Options.h"
#include "timer/Timer.h"
#include "crc32/Crc32.h"
#include "console/Console.h"
#include "hook/Hook.h"
#include "union/Union.h"
#include "vdfs/Vdfs.h"

#pragma warning(pop)

#endif // __UNION_H__