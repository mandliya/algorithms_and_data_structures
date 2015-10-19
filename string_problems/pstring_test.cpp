/*
30 unit tests testing pstring library ( a string library)
 located in include/pstring.cpp
			  include/pstring.h
			  include/pUnitTest.h
			  include/pUnitTest.cpp

*/
#include <cstdio>
#include "pUnitTest.h"
#include "pstring.h"

bool summary_flag = false;
unsigned long int tpass = 0, tfail = 0;

using string = algo::String;

int main(int argc, const char * argv[])
{

    // Versions n things
    printf("String version: %s\n", string::version());
    printf("UTest version: %s\n", UTest::version());

    UTest u("PstringLib");
    u.summary(summary_flag);

    // string
    printf("\nTesting string -----\n");
    u.init("string");

    const char * _ctest = "   \tfoo   \r\n";
    string ttest = _ctest;
    u.test("cstring ctor", ttest.length() == 12);

    string other = std::move(ttest);
    u.test("move ctor", other.length() == 12 && ttest.length() == 0);
    ttest = std::move(other);
    u.test("move assignment", other.length() == 0 && ttest.length() == 12);
    other = ttest;
    u.test("copy assignment", other.length() == 12 && ttest.length() == 12);


    ttest = "this is a string";
    u.test("length is 16", ttest.length() == 16 && ttest.size() == 16);
    u.test("substr", ttest.substr(10, 3) == string("str"));
    u.test("charfind", ttest.find('s') == 3);
    u.test("charfind (not found)", ttest.find('z') == -1);

    string string_upper = ttest.upper();
    string string_lower = string_upper.lower();
    u.test("upper and lower", string_upper == string("THIS IS A STRING") && string_lower == string("this is a string"));

    string x = "foo";
    string y = "bar";
    string z = x + "baz" + y;

    u.test("concat", z.length() == 9 && memcmp(z.c_str(), "foobazbar", 10) == 0);

    x = y = "foo";
    u.test("foo == foo",   (x == y));
    u.test("foo  > foo",  !(x  > y));
    u.test("foo >= foo",   (x >= y));
    u.test("foo  < foo",  !(x  < y));
    u.test("foo <= foo",   (x <= y));

    x = "bar";
    u.test("bar == foo",  !(x == y));
    u.test("bar  > foo",  !(x  > y));
    u.test("bar >= foo",  !(x >= y));
    u.test("bar  < foo",   (x  < y));
    u.test("bar <= foo",   (x <= y));

    u.test("foo == bar",  !(y == x));
    u.test("foo  > bar",   (y  > x));
    u.test("foo >= bar",   (y >= x));
    u.test("foo  < bar",  !(y  < x));
    u.test("foo <= bar",  !(y <= x));

    u.test("subscript x[0]", x[0] == 'b');
    u.test("subscript x[1]", x[1] == 'a');
    u.test("subscript x[2]", x[2] == 'r');
    u.test("subscript terminator x[3]", x[3] == 0);

    x = "this is a big string ###foobarbaz### this is a big string";
    x = x.replace(21, 15, "foo bar baz");
    u.test("replace", x.length() == 53 && memcmp(x.c_str(), "this is a big string foo bar baz this is a big string", 54) == 0);


    tpass += u.pass_count();
    tfail += u.fail_count();
    u.report();

    printf("\nTotals: pass: %ld, fail: %ld\n", tpass, tfail);

    return 0;   // Done. Yay!
}
