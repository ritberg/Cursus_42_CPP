#!/bin/bash

GREEN='\033[0;32m'
YELLOW='\033[0;33m'
RESET='\033[0m'

# Test case 1: Valid input
echo -e "${YELLOW}Test 1: Valid input${RESET}"
echo "./replacement file hello hi"
./replacement file hello hi
echo -e "${GREEN}OK${RESET}"

# Test case 2: Valid input2
#echo -e "${YELLOW}Test 2: Valid input2${RESET}"
#echo "./replacement file \"we\" buuuu"
#./replacement file "we" buuuu
#echo -e "${GREEN}OK${RESET}"

