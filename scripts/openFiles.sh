#!/bin/bash
vim -p src/Git.hpp src/pch.hpp src/Git.hpp\
    "+vs src/Git.cpp | tabn" \
    "+vs src/pch.cpp | tabn" \
    "+vs src/main.cpp | tabmove 0"
