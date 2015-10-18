//  pUnitTest.h
//  A simple unit test class

#ifndef __PSTRING_UTEST__
#define __PSTRING_UTEST__

#include <cstdio>

#define _UTest_VERSION "1.0.0"

const static char * __ut_pstr = "pass";
const static char * __ut_fstr = "fail";

class UTest {
    unsigned long int _pass_count = 0;
    unsigned long int _fail_count = 0;
    bool _summary_flag = false;

    const char * _test_str = nullptr;

    UTest( UTest & );                   // no copy constructor
    UTest operator = ( UTest & );       // no assignment operator
    UTest(){}                           // no default constructor
public:
    static const char * version() { return _UTest_VERSION; }

    UTest( const char * );
    void init ( const char * );
    bool summary ( bool flag ) { return _summary_flag = flag; }
    bool summary ( ) { return _summary_flag; }
    unsigned long int pass_count() const { return _pass_count; }
    unsigned long int fail_count() const { return _fail_count; }
    void test ( const char * description, const int flag );
    void report() const;
};

#endif /* defined(__PSTRING_UTEST__) */
