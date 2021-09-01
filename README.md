# GitPrompt

# Table of Contents
* [Install](#install)
* [Color Codes ](#color-codes)
    * [Normal](#normal)
    * [Merge Conflicts](#merge-conflicts)
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

# Update
```bash
cd GitPrompt
git pull
g++ -O3 Git.cpp -o Git; mv Git ~
```
