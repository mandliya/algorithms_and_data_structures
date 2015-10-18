/**
 *  A string library for practice
 *  Ravi Mandliya
 */

#include "pstring.h"

using String = algo::String;

String::String( ) {
  _reset();
}

String::String( const char * s ) {
  _copy_str(s);
}

String::String( const String & str ) {
  _copy_str(str);
}

String::String( String && other ) noexcept {
  _reset();
  _str = other._str;
  _str_len = other._str_len;
  other._str = nullptr;
  other._str_len = 0;
  other._reset();
}

String::~String() {
  _reset();
}

void String::_alloc_cstr(size_t sz) {
  if ( _str ) {
    _reset();
  }
  _str_len = ( sz > algo::_PSTRING_MAX_LEN ) ? algo::_PSTRING_MAX_LEN : sz;
  _str = new char[_str_len + 1]();
}

void String::_reset() {
  if ( _str ) {
    delete [] _str;
  }
  _str = nullptr;
  _str_len = 0;
}

void String::_swap( String & other ) {
  std::swap( _str, other._str );
  std::swap( _str_len, other._str_len );
}

const char * String::c_str() const {
  return _str;
}

void String::_copy_str( const char * s ) {
  if ( s ) {
    size_t sz = strnlen( s, algo::_PSTRING_MAX_LEN );
    _alloc_cstr( sz );
    strncpy( _str, s, sz );
  }
}

bool String::_have_value() const {
  if ( _str ) {
    return true;
  }
  return false;
}

size_t String::_char_find( const char & match, size_t pos ) const {
  if ( pos >= _str_len ) {
    return algo::npos;
  }
  for ( size_t i  = 0; _str[i + pos]; ++i ) {
    if ( _str[i] == match ) {
      return i;
    }
  }
  return algo::npos;
}

void String::_char_replace( const char & match_char,
                            const char & replace_char) {
  for ( size_t i = 0; _str[i]; ++i ) {
    if ( _str[i] == match_char ) {
      _str[i] = replace_char;
      return;
    }
  }
}

String & String::operator = ( String other ) {
  _swap(other);
  return *this;
}

String & String::operator += ( const char * s ) {
  if ( s ) {
    size_t len1 = strlen(s);
    if ( len1 < 1 ) {
      return *this;
    }
    size_t new_len = len1 + _str_len;
    new_len = (new_len > algo::_PSTRING_MAX_LEN )  ? algo::_PSTRING_MAX_LEN : new_len;
    char * buf = new char[new_len + 1];
    if (_str_len && _str ) {
      memcpy(buf, _str, _str_len);
    }
    memcpy(buf + _str_len, s, len1);
    _copy_str( buf );
    delete[] buf;
  }
  return * this;
}

String & String::operator += ( const String & s ) {
  operator+=( s.c_str() );
  return * this;
}

const char String::operator [] (const size_t index) const {
  if ( index >= this->length() ) return 0;
  return _str[index];
}

bool String::operator == ( const String & s ) const {
  if ( std::strncmp(this->c_str(), s.c_str(), algo::_PSTRING_MAX_LEN ) == 0 ) {
    return true;
  }
  else return false;
}

bool String::operator != ( const String & s ) const {
  if ( std::strncmp(this->c_str(), s.c_str(), algo::_PSTRING_MAX_LEN ) != 0 ) {
    return true;
  }
  else return false;
}

bool String::operator >= ( const String & s ) const {
  if ( std::strncmp(this->c_str(), s.c_str(), algo::_PSTRING_MAX_LEN ) >= 0 ) {
    return true;
  }
  else return false;
}

bool String::operator <= ( const String & s ) const {
  if ( std::strncmp(this->c_str(), s.c_str(), algo::_PSTRING_MAX_LEN ) <= 0 ) {
    return true;
  }
  else return false;
}

bool String::operator < ( const String & s ) const {
  if ( std::strncmp(this->c_str(), s.c_str(), algo::_PSTRING_MAX_LEN ) < 0 ) {
    return true;
  }
  else return false;
}

bool String::operator > ( const String & s ) const {
  if ( std::strncmp(this->c_str(), s.c_str(), algo::_PSTRING_MAX_LEN ) > 0 ) {
    return true;
  }
  else return false;
}

String::operator const char * () const {
  return this->c_str();
}

String String::lower() const {
  String rs = *this;
  for ( size_t i = 0; rs._str[i]; ++i ) {
    rs._str[i] = tolower(rs._str[i]);
  }
  return rs;
}

String String::upper() const {
  String rs = *this;
  for ( size_t i = 0; rs._str[i]; ++i ) {
    rs._str[i] = toupper(rs._str[i]);
  }
  return rs;
}

const char & String::front() const {
  return _str[0];
}

const char & String::back() const {
  return _str[_str_len - 1];
}

String String::substr( size_t pos, size_t len ) const {
  String rs;
  char * buf;
  if ( len + 1 > algo::_PSTRING_MAX_LEN ||
       ( pos + len ) > algo::_PSTRING_MAX_LEN ) {
    return rs;
  }
  if ( _str_len - pos < len ) {
    return rs;
  }
  if (!_str) {
    return rs;
  }
  buf = new char[ len + 1 ]();
  memcpy( buf, _str + pos, len );
  rs = buf;
  delete[] buf;
  return rs;
}

size_t String::find( const char * s, size_t pos ) const {
  size_t index = algo::npos;
  if ( pos >= _str_len ) {
    return index;
  }
  char * sub = strstr( _str + pos, s );
  if ( sub ) {
    return ( sub - _str );
  }
  return algo::npos;
}

size_t String::find( const String & match, size_t pos ) const {
  return find( match.c_str(), pos);
}

size_t String::find( char c, size_t pos ) const {
  return _char_find(c, pos);
}

String String::replace( size_t pos, size_t len, const char * str ) {
  String res;
  if ( ( pos >= _str_len ) || ( pos + len >= _str_len ) ) {
    return res;
  }
  String s1 = pos > 0 ? substr( 0, pos ) : "" ;
  String s2 = str;
  String s3 = substr( pos + len, _str_len - (pos+len));
  String s4 = s1 + s2 + s3;
  return s4;
}

String String::replace( size_t pos, size_t len, const String & str) {
  return replace(pos, len, str.c_str());
}

int String::compare( const char * str ) const {
  return strncmp( this->c_str(), str, algo::_PSTRING_MAX_LEN );
}

int String::compare( const String & str ) const noexcept {
  return strncmp( this->c_str(), str.c_str(), algo::_PSTRING_MAX_LEN );
}

String algo::operator + ( const String & lhs, const String & rhs ) {
  String ans = lhs;
  ans += rhs;
  return ans;
}

String algo::operator + ( const String & lhs, const char * rhs ) {
  String ans = lhs;
  ans += rhs;
  return ans;
}
