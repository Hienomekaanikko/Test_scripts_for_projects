#!/bin/bash
make -C ./philo

PROGRAM="philo/philo"
SUCCESS_TESTS=0
TOTAL_TESTS=0

# test1
./$PROGRAM 10 800 500 500 > outfile

if grep -q "died" outfile; then
    STATUS=1
else
    STATUS=0
    SUCCESS_TESTS=$((SUCCESS_TESTS + 1))
fi

TOTAL_TESTS=$((TOTAL_TESTS + 1))

echo "$SUCCESS_TESTS/$TOTAL_TESTS succeeded."

if (( TOTAL_TESTS - SUCCESS_TESTS == 0 )); then
    echo "CONGRATULATIONS! YOU PASSED ALL TESTS!"
fi

rm outfile

make -C ./philo fclean