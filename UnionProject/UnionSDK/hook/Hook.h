// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License
// Supported VC: 2010+

#ifndef __UNION_HOOK_H__
#define __UNION_HOOK_H__
#include <typeinfo>

namespace UnionCore {
  typedef struct ASTAPI _tagUntyped {
    void* data;
    _tagUntyped( untyped_ptr );
    operator void* () const;
  } TInstance;


  enum HookType {
    Hook_Detours,
    Hook_CallPatch,
    Hook_Auto = 0x1000
  };

  struct ASTAPI HookInformation {
    friend const HookInformation& CreateHook( void* from, void* to, const HookType& type );
    HookType Type;
    HANDLE Hook;

    void* GetSourceAddress() const;
    void* GetReturnAddress() const;
    void* GetDestinationAddress() const;
    void Disable() const;
    static const HookInformation& Create( void* from, void* to, const HookType& type );
  protected:
    HookInformation();
  };

  template <typename T>
  struct Hook : public HookInformation {
    T CastToPointer() const {
      Common::uint64 returnAddress = (Common::uint64)GetReturnAddress();
      return *(T*)&returnAddress;
    }

    operator T() const {
      return CastToPointer();
    }
  };

  Common::uint ASTAPI FindEngineAddress( Common::string functionName, Common::string typeAnchor );

  template <typename T>
  static const Hook<T>& CreateHook( TInstance fromAddress, T toAddress, const HookType& type ) {
    return (Hook<T>&)HookInformation::Create( fromAddress, (TInstance)toAddress, type );
  }

#define CreateHookByName( from, to, type ) CreateHook( UnionCore::FindEngineAddress( #from, typeid( to ).name() ), to, type )
#define Hook auto&
#define Base this->*
} // namespace UnionCore

#endif // __UNION_HOOK_H__