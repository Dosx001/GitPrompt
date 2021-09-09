#!/bin/bash
if [[ ! -e FILE ]]; then
    touch time.txt
fi
for i in {0..202}; do
    date "+%N" >> time.txt
    ~/./GitPrompt.exe
    date "+%N" >> time.txt
    done
