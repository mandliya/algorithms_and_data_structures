/**
 *  A string library for practice.
 *  by Ravi Mandliya
 */

#ifndef __ALG_PSTRING_LIB
#define __ALG_PSTRING_LIB

#include <cstdlib>
#include <cstring>
#include <iostream>

namespace algo {

  static int const _PSTRING_MAX_LEN = 65535;
  static const char * _PSTRING_VERSION = "1.0.0";
  static const size_t npos = -1;

  class String {

    char * _str = nullptr;
    size_t _str_len = 0;

    //data allocation and dellocation
    void _alloc_cstr( size_t sz );                      //alloc memory for _str
    void _reset();                                        //for resetting data
    void _swap( String & s );                             //mem function swap.
    void _copy_str( const char * s );             //alloc and copy.


    //private utility functions
    bool _have_value() const;
    size_t _char_find( const char & match , size_t pos = 0) const;
    void _char_replace( const char & match_char,
                                 const char & replace_char );

  public:
    String();                                             //default constructor
    String( const char * c );                             //cstr constructor
    String( const String & s );                           //copy constructor
    String( String && s ) noexcept;                       //move constructor
    ~String();                                            //destructor


    const char * c_str() const;                           //getter
    //operators
    String & operator = ( String s );                     //copy and swap assignmment for move and copy assignment.
    String & operator += ( const String & s );            //concatenation for string
    String & operator += ( const char * s );              //concatenation for literals
    const char operator [] ( const size_t index ) const;  //subscript operator

    //comparison operator
    bool operator == ( const String & s ) const;
    bool operator != ( const String & s ) const;
    bool operator >= ( const String & s ) const;
    bool operator >  ( const String & s ) const;
    bool operator <= ( const String & s ) const;
    bool operator <  ( const String & s ) const;

    // conversion operators
    operator const char * () const;             // c-string type

    //utility methods
    size_t length() const { return _str_len; }
    size_t size() const { return _str_len; }
    String lower() const;
    String upper() const;
    const char & back() const;
    const char & front() const;
    String substr(size_t pos = 0, size_t len = npos) const;
    static const char * version() { return _PSTRING_VERSION; }


    //find and replace utility functions
    size_t find( const String & str, size_t pos = 0) const;
    size_t find( const char * s, size_t pos = 0 ) const;
    size_t find( char c, size_t pos = 0) const;
    String replace( size_t pos, size_t len, const char * str );
    String replace( size_t pos, size_t len, const String & str );

    //compare
    int compare (const String& str) const noexcept;
    int compare (const char * str) const;
  };

  String operator + ( const String & lhs, const String & rhs );
  String operator + ( const String & lhs, const char * rhs );
}

#endif
