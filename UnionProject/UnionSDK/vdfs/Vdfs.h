// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License
// Minimal supported VC: 2010

#ifndef __UNION_VDFS_H__
#define __UNION_VDFS_H__

namespace Vdfs32 {
#define VDFAPI __declspec(dllimport)

#define VDF_VIRTUAL       (1)
#define VDF_PHYSICAL      (2)
#define VDF_PHYSICALFIRST (4)
#define VDF_DEFAULT VDF_VIRTUAL | VDF_PHYSICAL


  // open file and return handle
  VDFAPI long vdf_fopen( char* fullfname, long flags );


  // close file
  VDFAPI long vdf_fclose( long handle );


  // read file to the buffer. return the real readed size in bytes
  VDFAPI long vdf_fread( long handle, char* buffer, long size );


  // move the reading cursor to specified position
  VDFAPI long vdf_fseek( long handle, long pos );


  // get the reading cursor
  VDFAPI long vdf_ftell( long handle );


  // check the file by full name. flags - is prefer file mode - physical 
  // or virtual. if choose both, system will return the highest-priority 
  // flag of the file. or Null if file does not exists.
  VDFAPI long vdf_fexists( char* fullfname, long flags );


  // finds files by relative path. second argument - the
  // found fullname if return value is not false.
  VDFAPI long vdf_searchfile( char* filename, char* fullfilename );


  // return size of file
  VDFAPI long vdf_ffilesize( long handle );


  // for union vdfs this parms unused
  VDFAPI long vdf_initall( long numdisks = None, char* cdid = None, long* cddrives = None, long* disksfound = None );


  // collects a physical files list and returns their count
  VDFAPI long vdf_filelist_physical( char**& list );


  // collects a virtual files list and returns their count
  VDFAPI long vdf_filelist_virtual( char**& list );


  //
  ASTAPI long vdf_regvol( const char* volname );


  // get last system error in VDFS
  VDFAPI long vdf_getlasterror( char* error );


  // get FILE handler of virtual stream
  VDFAPI long vdf_getfilehandle( long handle, long& offset );


  // async copy full ogg data in memory
  VDFAPI long vdf_unpackogg( char* fullname, long flags );


  // clear ogg data from memory
  VDFAPI long vdf_packogg( char* fullname, long flags );


  // import vdf volume
  VDFAPI long vdf_import(char* volname);


  // set allow unzip multi-threading
  VDFAPI long vdf_set_unzip_multithreading(long allow);


  // update physical file list
  VDFAPI long vdf_updatephysicaltable();


  // get vdf name of the file. volumeName sould be null,
  // memory will be allocated in this function
  VDFAPI long vdf_getvolumename( char* fileName, char*& volumeName );


  class VirtualFile {
    long Handler;
    long Flow;
    Common::string Name;

  public:
    VirtualFile();
    VirtualFile( const Common::string& name, const long& flow = VDF_DEFAULT, const Common::uint& index = 0 );
    bool Open( const Common::string name, const long& flow = VDF_DEFAULT, const Common::uint& index = 0 );

  public:
    long Read( char* buff, const long& length );
    long ReadToEnd( char* buff );

    template <class T>
    long Read( T buff, const long& length ) {
      return Read( (char*)buff, length );
    }

    template <class T>
    long ReadToEnd( T& buff ) {
      return ReadToEnd( (char*&)buff );
    }

    long ReadString( Common::string& str );
    long Size();
    long Tell();
    void Seek( const long& pos );
    bool IsVirtual();
    bool IsExists();
    void Close();
    operator bool();
    virtual ~VirtualFile();
  };

  inline VirtualFile::VirtualFile() {
    Handler = Invalid;
  }

  inline VirtualFile::VirtualFile( const Common::string& name, const long& flow, const Common::uint& index ) {
    Handler = Invalid;
    Open( name, flow, index );
  }

  inline bool VirtualFile::Open( Common::string name, const long& flow, const Common::uint& index ) {
    if( index > 0 ) {
      char NameBuffer[1024];
      if( !vdf_searchfile( name.ToChar(), NameBuffer ) )
        return false;

      Common::string Names = NameBuffer;
      Name = Names.GetWord( "|", index );
      if( Name.IsEmpty() )
        return false;

      Flow = vdf_fexists( Name.ToChar(), flow );
      Handler = vdf_fopen( Name.ToChar(), Flow );
    }
    else {
      Name = name;
      Flow = vdf_fexists( Name.ToChar(), flow );
      if( Flow == 0 )
        return false;

      Handler = vdf_fopen( Name.ToChar(), Flow );
    }

    return true;
  }

  inline long VirtualFile::Read( char* buff, const long& length ) {
    return vdf_fread( Handler, buff, length );
  }

  inline long VirtualFile::ReadToEnd( char* buff ) {
    long tell = Tell();
    long size = Size();
    Seek( 0 );
    long readed = vdf_fread( Handler, buff, size );
    Seek( tell );
    return readed;
  }

  inline long VirtualFile::ReadString( Common::string& str ) {
    long tell = Tell();
    long size = Size();
    Seek( 0 );
    char* buff = new char[size];
    long readed = vdf_fread( Handler, buff, size );
    str = Common::string( buff, readed );
    delete [] buff;
    Seek( tell );
    return readed;
  }

  inline long VirtualFile::Size() {
    return vdf_ffilesize( Handler );
  }

  inline long VirtualFile::Tell() {
    return vdf_ftell( Handler );
  }

  inline void VirtualFile::Seek( const long& pos ) {
    vdf_fseek( Handler, pos );
  }

  inline bool VirtualFile::IsVirtual() {
    if( Flow & VDF_PHYSICALFIRST )
      return (Flow & VDF_PHYSICAL) == 0;

    return Flow & VDF_VIRTUAL;
  }

  inline bool VirtualFile::IsExists() {
    return Handler != Invalid;
  }

  inline void VirtualFile::Close() {
    if( Handler != Invalid ) {
      vdf_fclose( Handler );
      Handler = Invalid;
    }
  }

  inline VirtualFile::operator bool() {
    return IsExists();
  }

  inline VirtualFile::~VirtualFile() {
    Close();
  }
}

#endif // __UNION_VDFS_H__