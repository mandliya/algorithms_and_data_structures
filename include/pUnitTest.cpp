//  Unit Test
//  A simple unit test class
//  by Ravi Mandliya
//
#include "pUnitTest.h"

UTest::UTest( const char * _test_str ) {
    init(_test_str);
}

void UTest::init( const char * _tstr ) {
    _test_str = _tstr;
    _pass_count = _fail_count = 0;
}

void UTest::test ( const char * description, const int flag ) {
    const char * pf = nullptr;
    if (flag) {
        pf = __ut_pstr;
        ++_pass_count;
    } else {
        pf = __ut_fstr;
        ++_fail_count;
    }
    if(!_summary_flag) printf("%s: %s -> %s\n", _test_str, description, pf);
}

void UTest::report() const {
    printf("%s: pass: %ld, fail: %ld\n", _test_str, pass_count(), fail_count());
    fflush(stdout);
}
