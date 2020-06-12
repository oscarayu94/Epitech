#include <criterion/criterion.h>


Test(asserts,invalid)
{
//	cr_expect(strlen("TEST") == 4, "Expected");
	cr_assert(strlen("TEST") == 4);
}
