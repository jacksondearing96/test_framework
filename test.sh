#!/bin/bash

numberOfRandomTests=100;

# Declare colour strings for console output
colourReset='\x1b[0m'
green='\x1b[42m'
red='\033[0;31m'

# Compile c++ programs
g++ expected.cpp -o expectedOutput
g++ main.cpp -o main
g++ randomInput.cpp -o randomInput

failedTests=0

### RUNNING OF TESTS ###
# Loop through every test
for ((i=0;i<$numberOfRandomTests;i++))
do
    
    # Generate the inputs and outputs
    input=$(./randomInput)
    expected=$(echo "$input" | ./expectedOutput)
    actual=$(echo "$input" | ./main)

    # Check if the actual output matches the expected output
    if [ "$actual" != "$expected" ]
    then
        printf "${red}FAIL${colourReset}\n"
        echo "    failed test: $input"
        echo "    expected:    $expected"
        echo "    actual:      $actual"
        let "failedTests++"
    else
        printf "${green}PASS${colourReset} -> $input\n"
    fi
done

# Print a summary of the number of tests passed/failed
echo 
if [ $failedTests -eq 0 ]
then
    printf "${green}ALL TESTS PASS${colourReset}\n"
else
    printf "${red}$failedTests TESTS FAILED${colourReset}\n"
fi

# Clean up the created object files
rm expectedOutput
rm main
rm randomInput