#!/bin/bash
nvim -p src/Git.hpp src/pch.hpp src/main.cpp \
    "+vs src/Git.cpp | tabn | tabn" \
    "+tabmove 0"
