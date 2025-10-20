#!/bin/bash

# Go to src and build the library
make -C ../

# Compile the test binary linking with the library
gcc -Wall -Wextra -Werror -I ../ -I Unity/src libft_tests.c Unity/src/unity.c ../libft.a -o tests

# Run the tests
./tests

make -C ../ fclean
rm tests