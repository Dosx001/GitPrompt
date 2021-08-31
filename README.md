# GitPrompt

# Install
```bash
git clone git@github.com:Dosx001/GitPrompt.git
cd GitPrompt
g++ -O3 Git.cpp -o Git; mv Git ~
vim ~/.bashrc
```
Added Git() to your .bashrc.
```bash
Git() {
    if [ -n "$(git branch --show-current 2> /dev/null)" ]
    then                                                                                                                                                                                                                                              |   ~/Git
    fi
}
```
Finally while still inside your .bashrc insert Git() anywhere inside of PS1.
```bash
export PS1="\u@\h \$(Git)\[\e[00m\]\n\W\\$ "
```
