#!/bin/bash

GREEN='\033[0;32m'
YELLOW='\033[0;33m'
RESET='\033[0m'

# Test case 1: Missing arguments
echo -e "${YELLOW}Test 1: Missing arguments${RESET}"
echo "./replacement file"
./replacement file
echo -e "${GREEN}OK${RESET}"

# Test case 2: Too many arguments
echo -e "${YELLOW}Test 2: Too many arguments${RESET}"
echo "./replacement file hello hi hi hi"
./replacement file file hello hi hi hi
echo -e "${GREEN}OK${RESET}"

# Test case 3: File not found
echo -e "${YELLOW}Test 3: File not found${RESET}"
echo "./replacement non_existent_file hello hi"
./replacement non_existent_file hello hi
echo -e "${GREEN}OK${RESET}"

# Test case 4: Invalid file (permission denied)
echo -e "${YELLOW}Test 4: Invalid file (permission denied)${RESET}"
echo "./replacement invalid_file hello hi"
./replacement invalid_file hello hi
echo -e "${GREEN}OK${RESET}"

# Test case 5: Empty file argument
echo -e "${YELLOW}Test 5: Empty file argument${RESET}"
echo "./replacement \"\" hello hi"
./replacement "" hello hi
echo -e "${GREEN}OK${RESET}"

# Test case 6: Empty quotes
echo -e "${YELLOW}Test 6: Empty quotes${RESET}"
echo "./replacement file \"\" \"\""
./replacement file "" ""
echo -e "${GREEN}OK${RESET}"

# Test case 7: No replacement needed
echo -e "${YELLOW}Test 7: No replacement needed${RESET}"
echo "./replacement file quick brown"
./replacement file quick brown
echo -e "${GREEN}OK${RESET}"

# Test case 8: Empty file (inside)
echo -e "${YELLOW}Test 8: Empty file (inside)${RESET}"
echo "./replacement empty_file k g"
./replacement empty_file k g
echo -e "${GREEN}OK${RESET}"
