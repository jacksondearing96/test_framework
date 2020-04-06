#include "test.h"
#include "class.h"

void testTest() 
{
    Test::EXPECT_EQ(Class::Method(), true, "example test");
}

int main()
{
    testTest();
    return 0;
}