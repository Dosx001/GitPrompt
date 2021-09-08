#!/bin/bash
vim -p src/Git.hpp src/Git.hpp \
    "+vs src/Git.cpp | tabn" \
    "+vs src/main.cpp | tabmove 0"
