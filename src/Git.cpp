#include "Git.hpp"

bool Git::start() {
    char stream[max];
    return fgets(stream, max, popen("git rev-parse --git-dir 2> /dev/null", "r"));
}

void Git::stash() {
    FILE* fp;
    fp = popen("git stash list", "r");
    char stream[max];
    int i = 0;
    while (fgets(stream, max, fp)) i++;
    if (0 < i) std::cout << "\033[35mStashes: " << i;
    gates[0] = 0;
    pclose(fp);
}

void Git::log() {
    char stream[max];
    if (fgets(stream, max, popen("git log -1 --pretty=format:'%s' 2> /dev/null", "r"))) {
        while (gates[0]);
        std::cout << "\033[90m\n" << stream;
    }
    gates[1] = 0;
}

void Git::status() {
    FILE* fp;
    fp = popen("git status -s", "r");
    char stream[max];
    if (fgets(stream, max, fp)) {
        while (gates[1]);
        std::cout << "\n\033";
        do color(stream);
        while (fgets(stream, max, fp));
    }
    gates[2] = 0;
    pclose(fp);
}

void Git::merge() {
    char stream[max];
    if (fgets(stream, max, popen("cat `git rev-parse --show-toplevel`/.git/MERGE_MSG 2> /dev/null", "r"))) {
        char check[14] = {'M', 'e', 'r', 'g', 'e', ' ', 'b', 'r', 'a', 'n', 'c', 'h', ' ', '\''};
        for (int i = 15; i -= 3;) if (stream[i] != check[i]) goto done;
        while (gates[2]);
        std::cout << "\n\033[30;42mMerging\033[32;41m\033[30;41m";
        print(stream, 14, '\'');
        std::cout << "\033[0;31m";
    }
    done: gates[3] = 0;
}

void Git::branch() {
    char stream[max];
    if (fgets(stream, max, popen("git branch --show-current", "r"))) {
        while (gates[3] || gates[2]);
        std::cout << "\n\033[30;41m";
        print(stream, 0, '\n');
        std::cout << "\033[31;44m";
        return;
    }
    fgets(stream, max, popen("git branch -l", "r"));
    while (gates[3] || gates[2]);
    std::cout << "\n\033[30;42mRebasing\033[0;32m\n\033[30;41m";
    print(stream, 23, ')');
    std::cout << "\033[31;44m";
}

void Git::color(char* stream) {
    switch(stream[0]) {
        case '?':
            std::cout << "\033[37m";
            break;
        case ' ':
            switch(stream[1]) {
                case 'M':
                    std::cout << "\033[33m";
                    break;
                case 'D':
                    std::cout << "\033[31m";
            }
            break;
        case 'A':
            switch(stream[1]) {
                case ' ':
                    std::cout << "\033[34m";
                    break;
                case 'A':
                    std::cout << "\033[37;44m";
                    break;
                case 'D':
                    std::cout << "\033[96m";
                    break;
                case 'M':
                    std::cout << "\033[94m";
                    break;
                case 'U':
                    std::cout << "\033[30;44m";
            }
            break;
        case 'D':
            switch(stream[1]) {
                case ' ':
                    std::cout << "\033[91m";
                    break;
                case 'D':
                    std::cout << "\033[37;41m";
                    break;
                case 'U':
                    std::cout << "\033[30;41m";
            }
            break;
        case 'M':
            switch(stream[1]) {
                case ' ':
                    std::cout << "\033[32m";
                    break;
                case 'D':
                    std::cout << "\033[38;5;202m";
                    break;
                case 'M':
                    std::cout << "\033[93m";
            }
            break;
        case 'U':
            switch(stream[1]) {
                case 'A':
                    std::cout << "\033[33;44m";
                    break;
                case 'D':
                    std::cout << "\033[33;41m";
                    break;
                case 'U':
                    std::cout << "\033[30;43m";
            }
            break;
        case 'R':
            switch(stream[1]) {
                case ' ':
                    std::cout << "\033[35m";
                    break;
                case 'D':
                    std::cout << "\033[38;5;201m";
                    break;
                case 'M':
                    std::cout << "\033[38;5;93m";
            }
    }
    print(stream, 3, '\n');
    std::cout << "\033[0m ";
}

void Git::print(char* stream, int i, char a) {
    do {
        std::cout << stream[i];
        i++;
    }
    while (stream[i] != a);
}
