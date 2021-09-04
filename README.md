# GitPrompt
Fun Fact: I started this project because I was too lazy to type git status.

I originally wrote GitPrompt in Bash. These were literally the first lines of code I wrote.
```bash
gitStatus() {
  echo -e "\e[31m$(git status --short 2> /dev/null | sed ':a;N;$!ba;s/\n/ /g')"
}
```

# Table of Contents
* [Install](#install)
  * [Update](#update)
  * [Nerd Font](#nerd-font)
* [Color Codes ](#color-codes)
    * [Normal](#normal)
    * [Merge Conflicts](#merge-conflicts)
* [Examples](#examples)
  * [Merge Conflict](#merge-conflict)
  * [Normal Usage](#normal-usage)

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
## Update
```bash
cd GitPrompt
git pull
g++ -O3 Git.cpp -o Git; mv Git ~
```

## Nerd Font
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


# Color Codes
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

# Examples
## Merge Conflict
![](https://i.imgur.com/1fdC6Rz.png)
## Normal Usage
![](https://i.imgur.com/vx2bjOZ.png)
