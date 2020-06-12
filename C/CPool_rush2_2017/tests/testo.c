#include <criterion/criterion.h>

//Both suite name and test name are choosen by user, however, test_name should be explicit
//test name should be explicit coz when it fails, it's name will show off as the failed test
Test(suite_name, test_name)
{
...
}
with // suite_name + test_name unique.

//The list of asserts is here.

//The most used are:

// Passes if Expression is true
cr_assert(Expression, FormatString, ...);

// Passes if Expression is false
cr_assert_not(Expression, FormatString, ...);

// Passes if Actual == Expected
cr_assert_eq(Actual, Expected, FormatString, ...);

// Passes if Actual != Expected
cr_assert_neq(Actual, Expected, FormatString, ...);

