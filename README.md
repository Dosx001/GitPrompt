# GitPrompt
I designed GitPrompt to work only on Linux. Keeps GitPrompt simple and fast.
I'm assuming most developers are working on Linux if not come join the fun!
But if there is enough demand I could make a Windows or Mac version.

Fun Fact: I started this project because I was too lazy to type git status.

I originally wrote GitPrompt in Bash. These were literally the first lines of code I wrote.
```bash
gitStatus() {
  echo -e "\e[31m$(git status --short 2> /dev/null | sed ':a;N;$!ba;s/\n/ /g')"
}
```

# Table of Contents
* [Examples](#examples)
  * [Normal Usage](#normal-usage)
  * [Merge Conflict](#merge-conflict)
* [What does GitPrompt do?](#what-does-gitprompt-do)
* [Git Status Color Codes ](#git-status-color-codes)
  * [Normal](#normal)
  * [Merge Conflicts](#merge-conflicts)
* [Install](#install)
  * [Nerd Font](#nerd-font)
* [Setup](#setup)
  * [Bash](#bash)
  * [Zsh](#zsh)
* [Update](#update)

# Examples
## Normal Usage
<img src="https://i.imgur.com/RknJSHG.gif"/>

## Merge Conflict
![](https://i.imgur.com/Jftkd9u.png)

# What does GitPrompt do?
![](https://i.imgur.com/ZLmBlag.png)

# Git Status Color Codes
## Normal
| Status | Color |
|---|---|
| Untracked File | ![](https://i.imgur.com/AQgcrQ4.png)
| Modified File | ![](https://i.imgur.com/3DapgCd.png)
| Staged Modified File | ![](https://i.imgur.com/ArrhovJ.png) |
| Modified Staged Modified File | ![](https://i.imgur.com/wpW2pxi.png) |
| Deleted Staged Modified File | ![](https://i.imgur.com/iybnC7o.png) |
| Deleted File | ![](https://i.imgur.com/FBpDcKy.png) |
| Staged Deleted File | ![](https://i.imgur.com/FTKZq8M.png) |
| New File | ![](https://i.imgur.com/gClsMBJ.png) |
| Modified New File | ![](https://i.imgur.com/0wsqtmF.png) |
| Deleted New File | ![](https://i.imgur.com/HC5WqbA.png) |
| Rename File | ![](https://i.imgur.com/eX1msRP.png) |
| Modified Rename File | ![](https://i.imgur.com/dWyPvjn.png) |
| Deleted Rename File | ![](https://i.imgur.com/gnzkKJI.png) |
## Merge Conflicts
| Status | Color |
|---|---|
| Modified File | ![](https://i.imgur.com/kMg9ny9.png) |
| New File(Self) | ![](https://i.imgur.com/ZQogGmO.png) |
| New File(Them) | ![](https://i.imgur.com/8bVrjfN.png) |
| New File(Both) | ![](https://i.imgur.com/KmvvaX5.png) |
| Deleted File(Self) | ![](https://i.imgur.com/V6CkKXz.png) |
| Deleted File(Them) | ![](https://i.imgur.com/7gojtXH.png) |
| Deleted File(Both) | ![](https://i.imgur.com/8gEo6RW.png) |

# Install
```bash
git clone git@github.com:Dosx001/GitPrompt.git
cd GitPrompt
cmake CMakeLists.txt
make
cp bin/GitPrompt.exe ~
```

## Nerd Font
You might see weird symbols like this one . Just install Nerd Font.
```bash
git clone https://github.com/sgolovine/nerdfont-patcher.git
cd nerdfont-patcher
sudo apt-get install -y software-properties-common
sudo add-apt-repository -y ppa:fontforge/fontforge
sudo apt-get update -y
sudo apt-get install -y fontforge
fontforge -script font-patcher /PATH/TO/YOUR/FAVORITE/FONT/FontName.ttf -c
```
Install your new font and change your terminal font to the new font.

# Setup
## Bash
Just put "\$(~/GitPrompt.exe)" anywhere inside of PS1.
```bash
export PS1="\u@\h \$(~/GitPrompt.exe)\[\e[00m\]\n\W\\$ "
```
My personal bash prompt.
```bash
export PS1="\[\e[92m\]\u@\h \$(~/GitPrompt.exe)\n\[\e[32;44m\] \W \[\e[0;34m\]\[\e[0m\]"
```
## Zsh
Just add these lines inside your .zshrc and you're set.
```zsh
_prompt() {
    ~/GitPrompt.exe
}

autoload -U add-zsh-hook
add-zsh-hook precmd _prompt
```
My personal zsh prompt.
```zsh
_prompt() {
    if [[ -e `git rev-parse --git-dir 2> /dev/null` ]]; then
        echo -n "$fg[green]`whoami`@`cat /proc/sys/kernel/hostname` "
    else
        echo "$fg[green]`whoami`@`cat /proc/sys/kernel/hostname`"
    fi
    ~/GitPrompt.exe
}

autoload -U add-zsh-hook
add-zsh-hook precmd _prompt

autoload -U colors && colors
PROMPT="%{$fg[green]$bg[blue]%} %1d %{$reset_color%}%{$fg[blue]%}%{$reset_color%}"
```
# Update
```bash
cd GitPrompt
git pull
cmake CMakeLists.txt
make
cp bin/GitPrompt.exe ~
```
