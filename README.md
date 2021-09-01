# GitPrompt

# Table of Contents
* [Install](#install)
* [Update](#update)

# Install
```bash
git clone git@github.com:Dosx001/GitPrompt.git
cd GitPrompt
g++ -O3 Git.cpp -o Git; mv Git ~
vim ~/.bashrc
```
Then put "\$(~/Git)" anywhere inside of PS1.
```bash
export PS1="\u@\h \$(~/Git)\[\e[00m\]\n\W\\$ "
```

# Update
```bash
cd GitPrompt
git pull
g++ -O3 Git.cpp -o Git; mv Git ~
```
