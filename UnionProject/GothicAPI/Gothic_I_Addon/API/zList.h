// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZLIST_H__VER1__
#define __ZLIST_H__VER1__

#include "zContainer.h"
#include "zObject.h"

namespace Gothic_I_Addon {

  template <class T>
  class zCPQueue {
  public:
    T* array;
    int numAlloc;
    int numInArray;
    int(*Compare)(T ele1, T ele2);
    int allow_double_entrys;

    zCPQueue() {
      numInArray = 0;
      numAlloc = 0;
      array = 0;
      allow_double_entrys = TRUE;
    }

    zCPQueue( int startSize ) {
      numInArray = 0;
      numAlloc = startSize;
      array = new T[startSize];
      allow_double_entrys = TRUE;
    }

    zCPQueue( const zCPQueue<T>& array2 ) {
      numInArray = 0;
      numAlloc = 0;
      array = 0;
      AllocDelta( array2.GetNumInList() );
      numInArray = array2.numInArray;
      if( numInArray > 0 )
        memcpy( array, array2.array, sizeof( T ) * numInArray );
      allow_double_entrys = TRUE;
    }

    ~zCPQueue() {
      delete[] array;
      array = 0;
    }

    void SetAllowDouble( int allow ) {
      allow_double_entrys = allow;
    }

    void SetCompare( int(*Cmp)(T ele1, T ele2) ) {
      Compare = Cmp;
    }

    void AllocDelta( const int numDelta ) {
      T* newArray = new T[numAlloc + numDelta];
      if( numInArray > 0 )
        memcpy( newArray, array, sizeof( T ) * numInArray );
      delete[] array;
      array = newArray;
      numAlloc += numDelta;
    }

    void AllocAbs( const int size ) {
      if( numAlloc > size )
        return;
      AllocDelta( size - numAlloc );
    }

    void ShrinkToFit() {
      if( numInArray == 0 ) {
        DeleteList();
        return;
      }
      if( numAlloc > numInArray ) {
        T* newArray = new T[numInArray];
        memcpy( newArray, array, sizeof( T ) * numInArray );
        delete[] array;
        array = newArray;
        numAlloc = numInArray;
      }
    }

    void operator = ( const zCPQueue<T>& array2 ) {
      DeleteList();
      AllocDelta( array2.GetNumInList() );
      numInArray = array2.numInArray;
      if( numInArray > 0 )
        memcpy( array, array2.array, sizeof( T ) * numInArray );
    }

    T& operator [] ( int nr ) {
      return array[nr];
    }

    T operator [] ( int nr ) const {
      return array[nr];
    }

    T& GetSafe( int nr ) const {
      if( nr < 0 )
        nr = 0;
      else if( nr >= numInArray )
        nr = numInArray - 1;
      return array[nr];
    }

    void InsertEnd( const T& ins ) {
      if( numAlloc < numInArray + 1 ) {
        if( numAlloc == 0 )
          AllocDelta( 16 );
        else
          AllocDelta( numAlloc / 2 );
      }
      array[numInArray++] = ins;
    }

    int Insert( const T& ins ) {
      if( numAlloc < numInArray + 1 ) {
        if( numAlloc == 0 )
          AllocDelta( 16 );
        else
          AllocDelta( numAlloc / 2 );
      }
      int ind_low = 0;
      int ind_high = numInArray;
      int index = ind_low + (ind_low + ind_high) / 2;
      int erg;
      do {
        if( ind_high <= ind_low ) {
          if( index >= numInArray ) {
            array[index] = ins;
            numInArray++;
            return TRUE;
          }
          else {
            erg = Compare( ins, array[index] );
            if( erg > 0 ) index++;
            if( (erg == 0) && (!allow_double_entrys) ) return FALSE;
          }
          memmove( &array[index + 1], &array[index], sizeof( T ) * (numInArray - index) );
          array[index] = ins;
          numInArray++;
          return TRUE;
        }
        erg = Compare( ins, array[index] );
        if( erg > 0 )
          ind_low = index + 1;
        else
          ind_high = index - 1;
        index = ind_low + (ind_high - ind_low) / 2;
      }
      while( TRUE );
      return FALSE;
    }

    void Remove( const T& rem ) {
      if( numInArray == 0 )
        return;
      for( int i = 0; i < numInArray; i++ ) {
        if( array[i] == rem ) {
          numInArray--;
          if( i != numInArray )
            array[i] = array[numInArray];
          return;
        }
      }
    }

    void RemoveOrder( const T& rem ) {
      for( int i = 0; i < numInArray; i++ ) {
        if( array[i] == rem ) {
          if( i != numInArray - 1 )
            for( int j = i; j < numInArray; j++ )
              array[j] = array[j + 1];
          numInArray--;
          return;
        }
      }
    }

    void DeleteList() {
      delete[] array;
      array = 0;
      numAlloc = 0;
      numInArray = 0;
    }

    void EmptyList() {
      numInArray = 0;
    }

    int IsInList( const T& data ) const {
      if( numInArray == 0 )
        return FALSE;
      return FALSE;
    }

    int GetNumInList() const {
      return numInArray;
    }

    int IsEmpty() const { return (numInArray == 0); }

    // user API
    #include "zCPQueue.inl"
  };

  template <class T>
  class zCListSort {
  public:
    zMEMPOOL_DECLARATION_TEMPLATE( zCListSort, 0x008B9330 )

    int(*Compare)(T* ele1, T* ele2);
    T* data;
    zCListSort* next;

    zCListSort() {
      next = 0;
      data = 0;
    }

    ~zCListSort() {
      if( next ) {
        delete next;
        next = 0;
      }
    }

    void DeleteList() {
      if( next ) {
        delete next;
        next = 0;
      }
    }

    void DeleteListDatas() {
      if( data ) {
        data->Release();
        data = 0;
      }
      if( next ) {
        next->DeleteListDatas();
        delete next;
        next = 0;
      }
    }

    void Replace( T* ins ) {
      data = ins;
    }

    void Insert( T* ins ) {
      zCListSort* newItem = new zCListSort();
      newItem->data = ins;
      newItem->next = next;
      next = newItem;
    }

    void InsertSort( T* ins ) {
      zCListSort* newItem = new zCListSort();
      newItem->data = ins;
      newItem->next = next;
      zCListSort* val = this;
      while( val->next ) {
        if( Compare( ins, val->next->data ) < 0 ) {
          newItem->next = val->next;
          val->next = newItem;
          return;
        }
        val = val->next;
      }
      newItem->next = NULL;
      val->next = newItem;
    }

    void Remove( T* rem ) {
      zCListSort* item = this;
      while( item->next != 0 ) {
        if( item->next->data == rem ) {
          zCListSort* tmp = item->next;
          item->next = item->next->next;
          tmp->next = 0;
          delete tmp;
          return;
        }
        item = item->next;
      }
    }

    T* Get( int nr ) const {
      zCListSort* item = next;
      int c = 0;
      while( item != 0 ) {
        if( c == nr )
          return(item->data);
        item = item->next;
        c++;
      }
      return 0;
    }

    T* operator [] ( int nr ) const {
      return Get( nr );
    }

    zCListSort* GetNextInList() const {
      return next;
    }

    T* GetData() const {
      return data;
    }

    int InList( T* data ) const {
      zCListSort* item = next;
      while( item != 0 ) {
        if( item->data == data )
          return TRUE;
        item = item->next;
      }
      return FALSE;
    }

    int IsInList( T* data ) const {
      zCListSort* item = next;
      while( item != 0 ) {
        if( item->data == data )
          return TRUE;
        item = item->next;
      }
      return FALSE;
    }

    int GetNumInList() const {
      int count = 0;
      zCListSort* item = next;
      while( item != 0 ) {
        count++;
        item = item->next;
      }
      return count;
    }

    void SetCompare( int(*Cmp)(T* ele1, T* ele2) ) {
      Compare = Cmp;
    }

    // user API
    #include "zCListSort.inl"
  };

  template <class T>
  class zCList2 {
  public:
    zMEMPOOL_DECLARATION_TEMPLATE( zCList2, 0x008B9310 )

    int count;
    T* root;

    zCList2() {
      root = 0;
      count = 0;
    }

    void DeleteList() {
      T* item;
      T* help;
      item = root;
      while( item != 0 ) {
        help = item;
        item = item->next;
        delete(help);
      }
      root = 0;
      count = 0;
    }

    void Insert( T* ins ) {
      ins->next = root;
      root = ins;
      count++;
    }

    void Remove( T* rem ) {
      T* item = root;
      if( item == 0 )
        return;
      if( item == rem ) {
        root = item->next;
        count--;
      }
      else {
        while( item->next != 0 ) {
          if( item->next == rem ) {
            item->next = rem->next;
            count--;
            return;
          }
          item = item->next;
        }
      }
    }

    void Delete( T* rem ) {
      T* item = root;
      if( item == 0 ) return;
      if( item == rem ) {
        root = item->next;
        delete(item);
        count--;
      }
      else {
        while( item->next != 0 ) {
          if( item->next == rem ) {
            item->next = rem->next;
            delete(rem);
            count--;
            return;
          }
          item = item->next;
        }
      }
    }

    T* Get( int nr ) const {
      T* item = root;
      int c = 0;
      while( item != 0 ) {
        if( c == nr )
          return(item);
        item = item->next;
        c++;
      }
      return 0;
    }

    int InList( T* ele2 ) const {
      T* item = root;
      while( item != 0 ) {
        if( item == ele2 )
          return TRUE;
        item = item->next;
      }
      return FALSE;
    }

    int GetNumInList() const {
      return count;
    }
  };

  template <class KEY, class VALUE>
  class zTRayTurboValMap {
  public:
    struct zSNode {
      KEY Key;
      VALUE Value;
      unsigned long Hash;
      zSNode* Next;
    };

    zCArray<zSNode*> Nodes;

    int IsEmpty() const {
      return Nodes.GetNum() == 0;
    }

    int IsValidKey( const KEY& key ) const {
      unsigned long hash;
      const zSNode* node = GetNode( key, hash );
      if( node == NULL )
        return FALSE;
      return TRUE;
    }

    int Contains( const VALUE& val ) const {
      return GetIndex( val ) != -1;
    }

    void Clear( void ) {
      RemoveAll();
    }

    const zCArray<zSNode*>& GetData( void ) const {
      return Nodes;
    }

    unsigned long GetHash( const KEY& obj ) {
      return ((unsigned long)(void*)(unsigned long)obj) >> 4;
    }

    zSNode* AccessNode( const KEY& key, unsigned long& hash ) {
      hash = GetHash( key ) % Nodes.GetNum();
      int iIndex = static_cast<int> (hash);
      if( Nodes.IsEmpty() )
        return NULL;
      zSNode* node = Nodes[iIndex];
      while( node != NULL ) {
        if( key == node->Key )
          return node;
        node = node->Next;
      }
      return NULL;
    }

    const zSNode* GetNode( const KEY& key, unsigned long& hash ) const {
      hash = GetHash( key ) % Nodes.GetNum();
      int iIndex = static_cast<int> (hash);
      if( Nodes.IsEmpty() )
        return NULL;
      zSNode* node = Nodes[iIndex];
      while( node != NULL ) {
        if( key == node->Key )
          return node;
        node = node->Next;
      }
      return NULL;
    }

    VALUE& AccessAt( const KEY& key ) {
      unsigned long hash;
      zSNode* node = AccessNode( key, hash );
      if( node != NULL )
        return node->Value;
      node = new zSNode;
      node->Key = key;
      node->Hash = hash;
      node->Next = Nodes[hash];
      Nodes[hash] = node;
      return node->Value;
    }

    const VALUE& GetAt( const KEY& key ) const {
      unsigned long hash;
      const zSNode* node = GetNode( key, hash );
      return node->Value;
    }

    int GetAt( const KEY& key, VALUE& val ) const {
      unsigned long hash;
      const zSNode* node = GetNode( key, hash );
      if( node != NULL ) {
        val = node->Value;
        return TRUE;
      }
      return FALSE;
    }

    void SetAt( const KEY& key, const VALUE& val ) {
      AccessAt( key ) = val;
    }

    int RemoveAt( const KEY& key ) {
      unsigned long hash = GetHash( key ) % Nodes.GetNum();
      int index = (int)hash;
      if( Nodes.IsEmpty() )
        return FALSE;
      zSNode* node = Nodes[index];
      if( key == node->Key ) {
        Nodes[index] = node->Next;
        delete node;
        return TRUE;
      }
      while( node->Next != NULL ) {
        if( key == node->Next->Key ) {
          zSNode* pOldNode = node->Next;
          node->Next = node->Next->Next;
          delete pOldNode;
          return TRUE;
        }
        node = node->Next;
      }

      return FALSE;
    }

    void DeleteAll() {
      for( int i = 0; i < Nodes.GetNum(); i++ ) {
        zSNode* node = Nodes[i];
        zSNode* next = NULL;
        while( node != NULL ) {
          next = node->Next;
          delete node->Value;
          delete node;
          node = next;
        }
      }
      Nodes.EmptyList();
      Init();
    }

    void RemoveAll() {
      for( int i = 0; i < Nodes.GetNum(); i++ ) {
        zSNode* node = Nodes[i];
        zSNode* next = NULL;
        while( node != NULL ) {
          next = node->Next;
          delete node;
          node = next;
        }
      }
      Nodes.EmptyList();
      Init();
    }

    const VALUE& operator [] ( const KEY& key ) const {
      return GetAt( key );
    }

    VALUE& operator [] ( const KEY& key ) {
      return AccessAt( key );
    }

    void Init() {
      InitHashTable( 97 );
    }

    void InitHashTable( unsigned long hashCount ) {
      Nodes.DeleteList();
      Nodes.AllocAbs( hashCount );
      for( unsigned int i = 0; i < hashCount; i++ ) {
        zSNode* dummy = NULL;
        Nodes.Insert( dummy );
      }
    }

    zTRayTurboValMap( const zTRayTurboValMap<KEY, VALUE>& ) {
    }

    zTRayTurboValMap() {
      Init();
    }

    ~zTRayTurboValMap() {
      RemoveAll();
    }
  };

} // namespace Gothic_II_Addon

#endif // __ZLIST_H__VER1__