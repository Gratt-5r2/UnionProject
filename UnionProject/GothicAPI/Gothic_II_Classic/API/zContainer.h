// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __ZCONTAINER_H__VER2__
#define __ZCONTAINER_H__VER2__

#include "zMemory_Generic.h"

namespace Gothic_II_Classic {
  extern zCMallocGeneric* zmalloc;

  const int zARRAY_START_ALLOC = 16;

  inline int zArraySortDefaultCompare( const void* ele1, const void* ele2 ) zCall( 0x0054EA80 );

  template <class T>
  class zCArray {
  public:
    T* parray;
    int numAlloc;
    int numInArray;

    zCArray() {
      numInArray = 0;
      numAlloc = 0;
      parray = 0;
    }

    zCArray( const int startSize ) {
      numInArray = 0;
      numAlloc = startSize;
      parray = 0;
      if( startSize > 0 )
        parray = new T[startSize];
    }

    zCArray( const zCArray<T>& array2 ) {
      numInArray = 0;
      numAlloc = 0;
      parray = 0;
      AllocDelta( array2.GetNumInList() );
      numInArray = array2.numInArray;
      for( int i = 0; i < array2.GetNumInList(); i++ )
        parray[i] = array2.parray[i];
    }

    ~zCArray() {
      delete[] parray;
      parray = 0;
    }

    T* GetArray() const {
      return parray;
    }

    void ZeroFill() {
      if( parray )
        memset( parray, 0, sizeof( T ) * numAlloc );
    }

    void AllocDelta( const int numDelta ) {
      if( numDelta <= 0 ) return;
      T* newArray = new T[numAlloc + numDelta];
      if( numInArray > 0 )
        for( int i = 0; i < numInArray; i++ )
          newArray[i] = parray[i];
      delete[] parray;
      parray = newArray;
      numAlloc += numDelta;
    }

    void AllocAbs( const int size ) {
      if( numAlloc >= size )
        return;
      AllocDelta( size - numAlloc );
    }

    void MarkNumAllocUsed() {
      numInArray = numAlloc;
    }

    void ShrinkToFit() {
      if( numInArray <= 0 ) {
        DeleteList();
        return;
      }
      if( numAlloc > numInArray ) {
        T* newArray = new T[numInArray];
        for( int i = 0; i < numInArray; i++ )
          newArray[i] = parray[i];
        delete[] parray;
        parray = newArray;
        numAlloc = numInArray;
      }
    }

    void operator = ( const zCArray<T>& array2 ) {
      EmptyList();
      AllocAbs( array2.GetNumInList() );
      numInArray = array2.numInArray;
      for( int i = 0; i < array2.GetNumInList(); i++ )
        parray[i] = array2.parray[i];
    }

    const T& operator [] ( const int nr ) const {
      return parray[nr];
    }

    T& operator [] ( const int nr ) {
      return parray[nr];
    }

    T& GetSafe( int nr ) const {
      if( nr < 0 )
        nr = 0;
      else if( nr >= numInArray )
        nr = numInArray - 1;
      return parray[nr];
    }

    void InsertEnd( const T& ins ) {
      if( numAlloc < numInArray + 1 ) {
        if( numAlloc < zARRAY_START_ALLOC )
          AllocDelta( zARRAY_START_ALLOC );
        else
          AllocDelta( numAlloc / 2 );
      }
      parray[numInArray++] = ins;
    }

    void InsertFront( const T& ins ) {
      InsertAtPos( ins, 0 );
    }

    void Insert( const T& ins ) {
      InsertEnd( ins );
    }

    void InsertAtPos( const T& ins, int pos ) {
      if( numAlloc < numInArray + 1 ) {
        if( numAlloc < zARRAY_START_ALLOC )
          AllocDelta( zARRAY_START_ALLOC );
        else
          AllocDelta( numAlloc / 2 );
      }
      memmove( &parray[pos + 1], &parray[pos], sizeof( T ) * (numInArray - pos) );
      parray[pos] = ins;
      numInArray++;
    }

    void Remove( const T& rem ) {
      if( numInArray == 0 )
        return;
      for( int i = 0; i < numInArray; i++ ) {
        if( parray[i] == rem ) {
          numInArray--;
          if( i != numInArray )
            parray[i] = parray[numInArray];
          return;
        }
      }
    }

    void RemoveIndex( const int index ) {
      if( numInArray <= 0 )
        return;
      numInArray--;
      if( index != numInArray )
        parray[index] = parray[numInArray];
    }

    void RemoveOrder( const T& rem ) {
      for( int i = 0; i < numInArray; i++ ) {
        if( parray[i] == rem ) {
          RemoveOrderIndex( i );
          return;
        }
      }
    }

    void RemoveOrderIndex( const int index ) {
      if( index >= numInArray )
        return;
      if( index != numInArray - 1 )
        for( int j = index; j < numInArray - 1; j++ )
          parray[j] = parray[j + 1];
      numInArray--;
    }

    void DeleteList() {
      delete[] parray;
      parray = 0;
      numAlloc = 0;
      numInArray = 0;
    }

    void EmptyList() {
      numInArray = 0;
    }

    int Search( const T& data ) const {
      if( numInArray > 0 )
        for( int i = 0; i < numInArray; i++ )
          if( parray[i] == data )
            return i;
      return -1;
    }

    int IsInList( const T& data ) {
      for( int i = 0; i < numInArray; i++ )
        if( parray[i] == data )
          return TRUE;
      return FALSE;
    }

    int GetNumInList() const {
      return numInArray;
    }

    int GetNum() const {
      return numInArray;
    }

    int IsEmpty() const {
      return numInArray <= 0;
    }

    void InsertArray( const zCArray<T>& other ) {
      AllocAbs( other.GetNumInList() + GetNumInList() );
      for( int i = 0; i < other.GetNumInList(); i++ )
        parray[numInArray++] = other[i];
    }

    int CheckDoubles() {
      for( int i = 0; i < GetNumInList() - 1; i++ ) {
        for( int j = i + 1; j < GetNumInList(); j++ ) {
          if( parray[i] == parray[j] ) {
            return TRUE;
          }
        }
      }
      return FALSE;
    }

    void RemoveDoubles() {
      for( int i = 0; i < GetNumInList() - 1; i++ ) {
        for( int j = i + 1; j < GetNumInList(); j++ ) {
          if( parray[i] == parray[j] ) {
            parray[j] = parray[numInArray - 1];
            numInArray--;
            j--;
          }
        }
      }
      return FALSE;
    }

    void DeleteListDatas() {
      for( int i = 0; i != numInArray; i++ )
        SAFE_DELETE( parray[i] );
      DeleteList();
    }

    // user API
    #include "zCArray.inl"
  };

  template <class T>
  class zCArraySort {
  public:
    T* array;
    int numAlloc;
    int numInArray;
    int(*Compare)(const void* ele1, const void* ele2);

    zCArraySort() {
      numInArray = 0;
      numAlloc = 0;
      array = 0;
      SetCompare( zArraySortDefaultCompare );
    }

    zCArraySort( const int startSize ) {
      numInArray = 0;
      numAlloc = startSize;
      array = 0;
      if( startSize > 0 )
        array = new T()[startSize];
      SetCompare( zArraySortDefaultCompare );
    }

    zCArraySort( const zCArraySort<T>& array2 ) {
      numInArray = 0;
      numAlloc = 0;
      array = 0;
      AllocDelta( array2.GetNumInList() );
      numInArray = array2.numInArray;
      for( int i = 0; i < array2.GetNumInList(); i++ )
        array[i] = array2.array[i];
      SetCompare( array2.Compare );
    }

    ~zCArraySort() {
      delete[] array;
      array = 0;
    }

    T* GetArray() const {
      return array;
    }

    void SetCompare( int(*Cmp)(const void* ele1, const void* ele2) ) {
      Compare = Cmp;
    }

    void AllocDelta( const int numDelta ) {
      if( numDelta <= 0 )
        return;
      T* newArray = new T[numAlloc + numDelta];
      if( numInArray > 0 )
        for( int i = 0; i < numInArray; i++ )
          newArray[i] = array[i];
      delete[] array;
      array = newArray;
      numAlloc += numDelta;
    }

    void AllocAbs( const int size ) {
      if( numAlloc >= size )
        return;
      AllocDelta( size - numAlloc );
    }

    void ShrinkToFit() {
      if( numInArray <= 0 ) {
        DeleteList();
        return;
      }
      if( numAlloc > numInArray ) {
        T* newArray = new T()[numInArray];
        for( int i = 0; i < numInArray; i++ )
          newArray[i] = array[i];
        delete[] array;
        array = newArray;
        numAlloc = numInArray;
      }
    }

    void operator = ( const zCArraySort<T>& array2 ) {
      EmptyList();
      AllocAbs( array2.GetNumInList() );
      numInArray = array2.numInArray;
      for( int i = 0; i < array2.GetNumInList(); i++ )
        array[i] = array2.array[i];
    }

    const T& operator [] ( const int nr ) const {
      return array[nr];
    }

    T& operator [] ( const int nr ) {
      return array[nr];
    }

    T& GetSafe( int nr ) const {
      if( nr < 0 )
        nr = 0;
      else if( nr >= numInArray )
        nr = numInArray - 1;
      return array[nr];
    }

    T& Get( const int nr ) const {
      return array[nr];
    }

    void InsertEnd( const T& ins ) {
      if( numAlloc < numInArray + 1 ) {
        if( numAlloc < zARRAY_START_ALLOC )
          AllocDelta( zARRAY_START_ALLOC );
        else
          AllocDelta( numAlloc / 2 );
      }
      array[numInArray++] = ins;
    }

    void Insert( const T& ins ) {
      InsertEnd( ins );
    }

    void InsertAtPos( const T& ins, int pos ) {
      if( numAlloc < numInArray + 1 ) {
        if( numAlloc < zARRAY_START_ALLOC )
          AllocDelta( zARRAY_START_ALLOC );
        else
          AllocDelta( numAlloc / 2 );
      }
      memmove( &array[pos + 1], &array[pos], sizeof( T ) * (numInArray - pos) );
      array[pos] = ins;
      numInArray++;
    }

    void InsertSort( const T& ins ) {
      if( numAlloc < numInArray + 1 ) {
        if( numAlloc < zARRAY_START_ALLOC )
          AllocDelta( zARRAY_START_ALLOC );
        else
          AllocDelta( numAlloc / 2 );
      }
      int ind_low = 0;
      int ind_high = numInArray - 1;
      int index = (ind_low + ind_high) / 2;
      int erg;
      do {
        if( ind_high <= ind_low ) {
          if( index >= numInArray ) {
            array[index] = ins;
            numInArray++;
            return;
          }
          else {
            erg = Compare( &ins, &(array[index]) );
            if( erg > 0 ) {
              index++;
            }
          }
          memmove( &array[index + 1], &array[index], sizeof( T ) * (numInArray - index) );
          array[index] = ins;
          numInArray++;
          return;
        }
        erg = Compare( &ins, &array[index] );
        if( erg > 0 )
          ind_low = index + 1;
        else
          ind_high = index - 1;
        index = (ind_low + ind_high) / 2;
      }
      while( TRUE );
    }

    int Search( const T& ins ) const {
      if( numInArray <= 0 )
        return -1;
      int ind_low = 0;
      int ind_high = numInArray - 1;
      int index = (ind_low + ind_high) / 2;
      int erg;
      do {
        erg = Compare( &ins, &array[index] );
        if( ind_high <= ind_low ) {
          if( erg == 0 )
            return index;
          return -1;
        }
        if( erg > 0 )
          ind_low = index + 1;
        else if( erg < 0 )
          ind_high = index - 1;
        else
          return index;
        index = (ind_low + ind_high) / 2;
      }
      while( TRUE );
    }

    void RemoveIndex( const int index ) {
      if( numInArray <= 0 )
        return;
      numInArray--;
      if( index != numInArray )
        array[index] = array[numInArray];
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
      int i = Search( rem );
      if( i != -1 )
        RemoveOrderIndex( i );
    }

    void RemoveOrderIndex( const int index ) {
      if( index >= numInArray )
        return;
      if( index != numInArray - 1 )
        for( int j = index; j < numInArray - 1; j++ )
          array[j] = array[j + 1];
      numInArray--;
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
      int i = Search( data );
      if( i == -1 )
        return FALSE;
      return TRUE;
    }

    void MarkNumAllocUsed() {
      numInArray = numAlloc;
    }

    int GetNumInList() const {
      return numInArray;
    }

    int GetNum() const {
      return numInArray;
    }

    int IsEmpty() const {
      return (numInArray <= 0);
    }

    void QuickSort() {
      qsort( array, GetNumInList(), sizeof( T ), Compare );
    }

    void InsertionSort() {
      insertionsort( array, GetNumInList(), sizeof( T ), Compare, FALSE );
    }

    void BestSort() {
      insertionsort( array, GetNumInList(), sizeof( T ), Compare, TRUE );
    }

    // user API
    #include "zCArraySort.inl"
  };

  template <class T>
  class zCArrayAdapt {
  public:
    T* array;
    int numInArray;

    zCArrayAdapt() {
      numInArray = 0;
      array = 0;
    }

    ~zCArrayAdapt() {
      array = 0;
    }

    T* GetArray() const {
      return array;
    }

    DWORD GetSizeBytes() const {
      return sizeof( T ) * numInArray;
    }

    DWORD SetArray( void* ptr, const int num ) {
      array = (T*)ptr;
      numInArray = num;
      return sizeof( T ) * numInArray;
    }

    void SetNumInArray( const int num ) {
      numInArray = num;
    }

    void EmptyList() {
      numInArray = 0;
    }

    int GetNum() const {
      return numInArray;
    }

    int IsEmpty() const {
      return numInArray <= 0;
    }

    const T& operator [] ( const int nr ) const {
      return array[nr];
    }

    T& operator [] ( const int nr ) {
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
      array[numInArray++] = ins;
    }

    void InsertFront( const T& ins ) {
      InsertAtPos( ins, 0 );
    }

    void Insert( const T& ins ) {
      InsertEnd( ins );
    }

    void InsertAtPos( const T& ins, int pos ) {
      memmove( &array[pos + 1], &array[pos], sizeof( T ) * (numInArray - pos) );
      array[pos] = ins;
      numInArray++;
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

    void RemoveIndex( const int index ) {
      if( numInArray <= 0 )
        return;
      numInArray--;
      if( index != numInArray )
        array[index] = array[numInArray];
    }

    void RemoveOrder( const T& rem ) {
      for( int i = 0; i < numInArray; i++ )
        if( array[i] == rem )
          return RemoveOrderIndex( i );
    }

    void RemoveOrderIndex( const int index ) {
      if( index >= numInArray )
        return;
      if( index != numInArray - 1 )
        for( int j = index; j < numInArray - 1; j++ )
          array[j] = array[j + 1];
      numInArray--;
    }

    int Search( const T& data ) const {
      if( numInArray > 0 )
        for( int i = 0; i < numInArray; i++ )
          if( array[i] == data )
            return i;
      return -1;
    }

    int IsInList( const T& data ) const {
      if( numInArray > 0 )
        for( int i = 0; i < numInArray; i++ )
          if( array[i] == data )
            return TRUE;
      return FALSE;
    }

    // user API
#include "zCArrayAdapt.inl"
  };

  template <class T, int SIZE>
  class zCMatrixStack {
  public:
    int pos;
    T stack[SIZE];

    zCMatrixStack() : pos( 0 ) {
    }

    void Push( const T& m ) {
      if( pos >= SIZE )
        return stack[SIZE - 1];
      stack[pos++] = m;
    }

    T Pop( void ) {
      if( pos < 0 )
        return stack[0];
      return stack[--pos];
    }
  };

  template <class T>
  class zCTree {
  public:
    zMEMPOOL_DECLARATION_TEMPLATE( zCTree, 0x008C5D30 )

    zCTree* parent;
    zCTree* firstChild;
    zCTree* next;
    zCTree* prev;
    T* data;

    void zCTree_OnInit()             zCall( 0x0059C900 );
    zCTree()                         zInit( zCTree_OnInit() );
    ~zCTree()                        zCall( 0x0059C920 );
    void RemoveChild()               zCall( 0x0059D150 );
    zCTree* AddChild( T* item )      zCall( 0x00620EE0 );
    zCTree* AddChild( zCTree* node ) zCall( 0x00600030 );
    int CountNodes()                 zCall( 0x00620F30 );
    void RemoveSubtree()             zCall( 0x005FFE20 );

    void DeleteDataSubtree() {
      if( data ) {
        delete data;
        data = 0;
      }
      zCTree* child = GetFirstChild();
      while( child ) {
        child->DeleteDataSubtree();
        child = child->GetNextChild();
      }
    }

    void DeleteChilds() {
      while( firstChild )
        delete firstChild;
      RemoveChild();
    }

    T** GetPtrToData() const {
      return &data;
    }

    T* GetData() const {
      return data;
    }

    void SetData( T* newData ) {
      data = newData;
    }

    zCTree* GetParent() {
      return parent;
    }

    zCTree* GetFirstChild() {
      return firstChild;
    }

    zCTree* GetNextChild() {
      return next;
    }

    zCTree* GetPrevChild() {
      return prev;
    }

    int GetNumChilds() {
      int num = 0;
      zCTree* child = GetFirstChild();
      while( child != 0 ) {
        num++;
        child = child->GetNextChild();
      }
      return num;
    }

    zCTree* Search( T* item ) {
      if( data == item )
        return this;
      zCTree* child = GetFirstChild();
      while( child != 0 ) {
        zCTree* res = child->Search( item );
        if( res != 0 )
          return res;
        child = child->GetNextChild();
      }
      return NULL;
    }

    int Search( const zCTree* node ) {
      if( this == node )
        return TRUE;
      zCTree* child = GetFirstChild();
      while( child != 0 ) {
        if( child->Search( node ) )
          return TRUE;
        child = child->GetNextChild();
      }
      return FALSE;
    }

    void MoveSubtreeTo( zCTree* destParent ) {
      RemoveSubtree();
      if( destParent )
        destParent->AddChild( this );
      else
        parent = 0;
    }

    // user API
    #include "zCTree.inl"
  };

  template <class T>
  class zList {
  public:
    int(*Compare)(T* ele1, T* ele2);
    int count;
    T* last;
    T* root;

    zList() {
      last = 0;
      root = NULL;
      count = 0;
    }

    void SetCompare( int(*Cmp)(T* ele1, T* ele2) ) {
      Compare = Cmp;
    }

    void Clear() {
      T* ele;
      T* help;
      ele = root;
      while( ele != NULL ) {
        help = ele;
        ele = ele->next;
        delete(help);
      }
      last = NULL;
      root = NULL;
      count = 0;
    }

    void Insert( T* ins ) {
      if( IsIn( ins ) )
        return;
      if( root == NULL )
        last = ins;
      ins->next = root;
      root = ins;
      count++;
    }

    void InsertLast( T* ins ) {
      if( IsIn( ins ) )
        return;
      count++;
      ins->next = NULL;
      if( root == NULL ) {
        last = ins;
        root = ins;
      }
      else {
        last->next = ins;
        ins->next = NULL;
        last = ins;
      }
    }

    int InsertAsNext( T* object, T* ins ) {
      if( IsIn( ins ) )
        return FALSE;
      if( !object || !ins )
        return FALSE;
      ins->next = object->next;
      object->next = ins;
      count++;
      return TRUE;
    }

    int InsertAsPrevious( T* ins, T* object ) {
      if( IsIn( ins ) )
        return FALSE;
      if( (!object) || (!ins) )
        return FALSE;
      if( root == object ) {
        ins->next = root;
        root = ins;
        count++;
        return TRUE;
      }
      T* ele = root;
      while( ele != NULL ) {
        if( ele->next == object ) {
          ins->next = object;
          ele->next = ins;
          count++;
          return TRUE;
        }
        ele = ele->next;
      }
      return FALSE;
    }

    void InsertSort( T* ins ) {
      T* ele;
      if( IsIn( ins ) ) {
        return;
      }
      if( root == NULL || Compare( ins, root ) < 0 ) {
        ins->next = root;
        root = ins;
        count++;
      }
      else {
        ele = root;
        while( ele->next != NULL ) {
          if( Compare( ins, ele->next ) <= 0 ) {
            ins->next = ele->next;
            ele->next = ins;
            count++;
            return;
          }
          ele = ele->next;
        }
        ele->next = ins;
        ins->next = NULL;
        last = ins;
        count++;
      }
    }

    void Remove( T* rem ) {
      T* ele = root;
      if( ele == NULL )
        return;
      if( ele == rem ) {
        root = ele->next;
        if( root == NULL )
          last = NULL;
        count--;
      }
      else {
        while( ele->next != NULL ) {
          if( ele->next == rem ) {
            if( rem->next == NULL )
              last = ele;
            ele->next = rem->next;
            count--;
            return;
          }
          if( ele == ele->next )
            ele->next = NULL;
          else
            ele = ele->next;
        }
      }
    }

    void Delete( T* rem ) {
      T* ele = root;
      if( ele == NULL )
        return;
      if( ele == rem ) {
        root = ele->next;
        if( root == NULL )
          last = NULL;
        delete(ele);
        count--;
      }
      else {
        while( ele->next != NULL ) {
          if( ele->next == rem ) {
            if( rem->next == NULL )
              last = ele;
            ele->next = rem->next;
            delete(rem);
            count--;
            return;
          }
          ele = ele->next;
        }
      }
    }

    T* Get( int nr ) {
      T* ele = root;
      int c = 0;
      while( ele != NULL ) {
        c++;
        if( c == nr )
          return(ele);
        ele = ele->next;
      }
      return NULL;
    }
    T* GetLast() {
      return last;
    }

    int IsIn( T* ele2 ) {
      T* ele = root;
      while( ele != NULL ) {
        if( ele == ele2 )
          return TRUE;
        ele = ele->next;
      }
      return FALSE;
    }

    int Count() {
      return count;
    }
  };

  template <class T>
  class zCList {
  public:
    zMEMPOOL_DECLARATION_TEMPLATE( zCList, 0x008C9D18 );

    T* data;
    zCList* next;

    ~zCList()                             zCall( 0x00420A00 );
    void DeleteList()                     zCall( 0x00469B40 );
    void DeleteListDatas()                zCall( 0x0065C480 );
    void Insert( T* ins )                 zCall( 0x0074CCA0 );
    void InsertFront( T* ins )            zCall( 0x0046E8B0 );
    void Remove( T* rem )                 zCall( 0x0074CCF0 );
    T* Get( const int nr ) const          zCall( 0x00420B70 );
    int GetNumInList() const              zCall( 0x00600350 );
    int GetNum() const                    zCall( 0x00600350 );
    T* operator [] ( const int nr ) const zCall( 0x00420B70 );

    zCList() {
      next = 0;
      data = 0;
    }

    void Replace( T* newData ) {
      data = newData;
    }

    zCList* GetNextInList() const {
      return next;
    }

    T* GetData() const {
      return data;
    }

    int IsInList( T* data ) const {
      zCList* item = next;
      while( item != 0 ) {
        if( item->data == data )
          return TRUE;
        item = item->next;
      }
      return FALSE;
    }

    // user API
    #include "zCList.inl"
  };

  template <class T>
  class GETSmallArrayNative {
  public:
    unsigned long Entries;
    unsigned long Used;
    T* Entry;

    void Grow() {
      int delta;
      if( Used >= Entries ) {
        if( Entries > 64 )
          delta = Entries / 4;
        else {
          if( Entries > 8 )
            delta = 16;
          else
            delta = 4;
        }
        Entries += delta;
        T* newEntry = (T*)zmalloc->Realloc( Entry, sizeof( T ) * Entries );
        Entry = newEntry;
      }
    }

    GETSmallArrayNative() {
      Entries = 1;
      Entry = (T*)zmalloc->Malloc( sizeof( T ) * Entries );
      memset( Entry, 0, sizeof( T ) * Entries );
      Used = 0;
    }

    GETSmallArrayNative( int entries ) {
      Entries = entries;
      Entry = (T*)zmalloc->Malloc( sizeof( T ) * Entries );
      memset( Entry, 0, sizeof( T ) * Entries );
      Used = 0;
    }

    GETSmallArrayNative<T>& operator=( GETSmallArrayNative<T>& classItem ) {
      if( Entries == classItem.GetAllocatedEntries() ) {
        Used = classItem.Used;
        memcpy( &Entry[0], &classItem.Entry[0], sizeof( T ) * classItem.Used );
      }
      else {
        Used = classItem.Used;
        zmalloc->Free( Entry );
        Entry = (T*)zmalloc->Malloc( sizeof( T ) * (classItem.Used + 1) );
        memcpy( &Entry[0], &classItem.Entry[0], sizeof( T ) * classItem.Used );
      }
      return *this;
    }

    unsigned long GetAllocatedEntries() {
      return Entries;
    }

    int Reserve( unsigned long entries ) {
      if( entries < Entries )
        return FALSE;
      Entries = entries;
      T* newEntry = (T*)zmalloc->Realloc( Entry, sizeof( T ) * Entries );
      Entry = newEntry;
      return TRUE;
    }

    unsigned long Add( T& item ) {
      Grow();
      Entry[Used] = item;
      Used++;
      return Used - 1;
    }

    void Remove( unsigned long ref ) {
      if( Used == 0 ) {
        return;
      }
      unsigned long i = Used - (ref + 1);
      memmove( &Entry[ref], &Entry[ref + 1], i * sizeof( T ) );
      Used--;
    }

    ~GETSmallArrayNative() {
      zmalloc->Free( Entry );
    }
  };
} // namespace Gothic_II_Classic

#endif // __ZCONTAINER_H__VER2__
