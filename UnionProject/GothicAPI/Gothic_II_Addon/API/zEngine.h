// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZENGINE_H__VER3__
#define __ZENGINE_H__VER3__

#pragma warning(push)
#pragma warning(disable:4731)
#pragma warning(disable:26495)
#pragma warning(disable:26812)

#ifdef PlaySound
#undef PlaySound
#endif

#ifdef Success
#undef Success
#endif

#if 1
  #define __ZPROTO_B_VER3__
  #include "zPrototypes.h"
  #include "oPrototypes.h"
#endif

// startup
#ifdef __G2A
	#if 1
	  #ifdef __ZPROTO_B_VER3__
		#define __ZINIT_B_VER3__
		#include "zMacro.h"
		#include "zInput_Const.h"
		#include "zTypes.h"
		#include "zSpyTypes.h"
		#include "zMemPool.h"
	  #endif
	#endif
#endif

// data, containers, cache, factory
#if 1
  #ifdef __ZINIT_B_VER3__
    #define __ZCON_B_VER3__
    #include "zString.h"
    #include "zTypes3d.h"
    #include "zTools.h"
    #include "zAlgebra.h"
    #include "zContainer.h"
    #include "zList.h"
    #include "zSparseArray.h"
    #include "zObject.h"
    #include "zError.h"
  #endif
#endif

// input
#if 1
  #ifdef __ZCON_B_VER3__
    #include "zInput_Win32.h"
  #endif
#endif

// z2D views, fonts, fx, etc
#if 1
  #ifdef __ZCON_B_VER3__
    #define __Z2D_B_VER3__
    #include "zview.h"
    #include "zViewObject.h"
    #include "zViewDraw.h"
    #include "zViewFx.h"
    #include "zViewPrint_Font.h"
    #include "zViewPrint.h"
    #include "zViewDialog.h"
    #include "zViewDialogChoice.h"
    #include "zRndD3d.h"
    #include "zFonts.h"
    #include "zConsole.h"
  #endif
#endif

// o2D inventories, dialogs, documents, menu, etc
#if 1
  #ifdef __Z2D_B_VER3__
    #define __O2D_B_VER3__
    #include "oViewDialogInventory.h"
    #include "oViewDialogItem.h"
    #include "oViewDialogItemContainer.h"
    #include "oViewDialogStealContainer.h"
    #include "oViewDialogTrade.h"
    #include "oViewStatusBar.h"
    #include "oDoc.h"
    #include "oDocumentManager.h"
    #include "oHelp.h"
    #include "oInfo.h"
    #include "oInformationManager.h"
    #include "oMenuSavegame.h"
    #include "oViewDocument.h"
    #include "oViewDocumentMap.h"
    #include "oViewProgressbar.h"
    #include "oMenu_Status.h"
    #include "oMenu_Help.h"
  #endif
#endif

// z3D mobs, npcs, zones, worlds, items, etc
#if 1
  #ifdef __ZCON_B_VER3__
    #define __ZWLD_B_VER3__
    #include "zWorld.h"
    #include "oMusicZone.h"
    #include "oNpc.h"
    #include "oWorld.h"
    #include "oMobInter.h"
    #include "oSpawn.h"
    #include "oObjFactory.h"
  #endif
#endif

// sky
#if 1
  #ifdef __ZWLD_B_VER3__
    #define __ZSKY_B_VER3__
    #include "zSky_Outdoor.h"
    #include "oBarrier.h"
  #endif
#endif

// visual, model, pfx, magic
#if 1
  #ifdef __ZWLD_B_VER3__
    #define __ZVIS_B_VER3__
    #include "zLensflare.h"
    #include "zMorphMesh.h"
    #include "zPolyStrip.h"
    #include "zFlash.h"
    #include "zProgMesh.h"
    #include "zVertexTransform.h"
    #include "zPolyPool.h"
    #include "oVisFX.h"
    #include "oVisFx_MultiTarget.h"
    #include "oMagic.h"
    #include "oMagFrontier.h"
    #include "oParticleControl.h"
  #endif
#endif

// ai, physic, portals
#if 1
  #ifdef __ZWLD_B_VER3__
    #define __ZAI_B_VER3__
    #include "zAIPlayer.h"
    #include "zPhysics.h"
    #include "zMoving.h"
    #include "oAIShoot.h"
    #include "oDialog.h"
    #include "oItemReact.h"
    #include "oFocus.h"
    #include "oNpcMessages.h"
    #include "oPortals.h"
    #include "oWaynet.h"
  #endif
#endif

// data system, vdfs
#if 1
  #ifdef __ZCON_B_VER3__
    #define __ZFILE_B_VER3__
    #include "zDisk.h"
    #include "zArchiverGeneric.h"
    #include "zArchiver2.h"
    #include "zDisk_Vdfs.h"
    #include "zFile3d.h"
    #include "zFileCsv.h"
  #endif
#endif

// scripts, gameplay
#if 1
  #ifdef __Z2D_B_VER3__
    #define __ZEXT_B_VER3__
    #include "zParser.h"
    #include "oSvm.h"
    #include "oText.h"
    #include "oMission.h"
    #include "oGuilds.h"
  #endif
#endif


// net
#if 1
  #ifdef __ZWLD_B_VER3__
    #define __ZNET_B_VER3__
    #include "zQueue.h"
    #include "zNet.h"
    #include "zNetManager.h"
    #include "zNetEventMan.h"
    #include "zNetVobControl.h"
    #include "zNetVersion.h"
  #endif
#endif


// system, memory
#if 1
  #ifdef __ZINIT_B_VER3__
    #define __ZHELP_B_VER3__
    #include "zMemory_Win32.h"
    #include "zMemory_Generic.h"
    #include "oSysInfo.h"
  #endif
#endif

// session
#if 1
  #ifdef __ZWLD_B_VER3__
    #define __ZSES_B_VER3__
    #include "zAccount.h"
    #include "oGameManager.h"
    #include "oGame.h"
    #include "oGameInfo.h"
    #include "oPlayerInfo.h"
  #endif
#endif

// triggers, cutscenes
#if 1
  #ifdef __ZWLD_B_VER3__
    #define __ZCS_B_VER3__
    #include "zCCsPool.h"
    #include "oCSPlayer.h"
    #include "oCSManager.h"
    #include "oCsProps.h"
    #include "oCsTrigger.h"
    #include "oTrigger.h"
  #endif
#endif

// render
#if 1
  #ifdef __ZCON_B_VER3__
    #define __ZRND_B_VER3__
    #include "zRndD3d_Init.h"
    #include "zRenderLightContainer.h"
  #endif
#endif

// sound, music
#if 1
  #ifdef __ZCON_B_VER3__
    #define __ZSND_B_VER3__
      #include "zMusicCtrl.h"
      #include "zSndMss.h"
  #endif
#endif

// video
#if 1
  #ifdef __ZCON_B_VER3__
    #define __ZVID_B_VER3__
    #include "oBinkPlayer.h"
  #endif
#endif


// collisions
#if 1
  #ifdef __ZWLD_B_VER3__
    #define __ZCOLL_B_VER3__
    #include "zConvexCollision.h"
    #include "zCollisionObjectMisc.h"
    #include "oCollisionObjectMiscChar.h"
  #endif
#endif

// other
#if 1
  #include "zEigen.h"
  #include "zVobIdentifier.h"
  #include "zPrime.h"
#endif

#include "zGlobal.h"

#pragma warning(pop)

#endif // __ZENGINE_H__VER3__