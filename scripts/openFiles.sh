#!/bin/bash
vim -p src/Git.hpp src/pch.hpp src/main.cpp \
    "+vs src/Git.cpp | tabn" \
    "+vs src/pch.cpp | tabn" \
    "+tabmove 0"
