#include "Unity/src/unity.h"
#include <stddef.h>
#include "../libft.h"
#define GREEN "\x1b[32m"
#define RED   "\x1b[31m"
#define RESET "\x1b[0m"

void setUp(void) {}
void tearDown(void) {}

//ft_strlen tests

void strlen_test1(void) {
    TEST_ASSERT_EQUAL_UINT32(0, ft_strlen(""));
}

void strlen_test2(void) {
    TEST_ASSERT_EQUAL_UINT32(5, ft_strlen("Hello"));
}

void strlen_test3(void) {
    TEST_ASSERT_EQUAL_UINT32(11, ft_strlen("Hello World"));
}

//ft_atoi tests

void atoi_test1(void) {
    TEST_ASSERT_EQUAL_UINT32(5, ft_atoi("5"));
}

void atoi_test2(void) {
    TEST_ASSERT_EQUAL_UINT32(10000, ft_atoi("10000"));
}

void atoi_test3(void) {
    TEST_ASSERT_EQUAL_UINT32(-100000000, ft_atoi("-100000000"));
}

void atoi_test4(void) {
    TEST_ASSERT_EQUAL_UINT32(12312312, ft_atoi("12312312"));
}

void atoi_test5(void) {
    TEST_ASSERT_EQUAL_UINT32(0, ft_atoi("asdasdasdadasd"));
}

void atoi_test6(void) {
    TEST_ASSERT_EQUAL_UINT32(0, ft_atoi("+-+-----123123"));
}

//ft_bzero tests

void bzero_test1(void) {
    char str[6] = "Hello";
    char expected[6] = {0, 0, 0, 'l', 'o', '\0'};

    ft_bzero(str, 3);

    TEST_ASSERT_EQUAL_MEMORY(expected, str, 6);  // compares byte-by-byte
}

//ft_bzero tests

void bzero_test2(void) {
    char str[1] = "H";
    char expected[2] = {0, '\0'};

    ft_bzero(str, 1);

    TEST_ASSERT_EQUAL_MEMORY(expected, str, 1);  // compares byte-by-byte
}

void bzero_test3(void) {
    ft_bzero(NULL, 0);
    TEST_PASS_MESSAGE("ft_bzero(NULL, 0) did not crash");
}

int main(void) {
    printf(GREEN "===Running ft_strlen tests===\n" RESET);
    UNITY_BEGIN();

    RUN_TEST(strlen_test1);
    RUN_TEST(strlen_test2);
    RUN_TEST(strlen_test3);

    printf(GREEN "===Running ft_atoi tests===\n" RESET);
    UNITY_BEGIN();

    RUN_TEST(atoi_test1);
    RUN_TEST(atoi_test2);
    RUN_TEST(atoi_test3);
    RUN_TEST(atoi_test4);
    RUN_TEST(atoi_test5);
    RUN_TEST(atoi_test6);
    
    printf(GREEN "===Running ft_bzero tests===\n" RESET);
    RUN_TEST(bzero_test1);
    RUN_TEST(bzero_test2);
    RUN_TEST(bzero_test3);

    int result = UNITY_END();
    if (result == 0)
        printf(GREEN "All tests passed!\n" RESET);
    else
        printf(RED "Some tests failed.\n" RESET);

    return result;
}
