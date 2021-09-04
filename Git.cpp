#include <iostream>
using namespace std;
void color(char* buffer);
void print(char* array, int i);

int main() {
    const int max_buffer = 128;
    char buffer[max_buffer];
    if (fgets(buffer, max_buffer, popen("git rev-parse --git-dir 2> /dev/null", "r"))) {
        FILE * status;
        status = popen("git stash list", "r");
        int i = 0;
        while (fgets(buffer, max_buffer, status)) i++;
        if (0 < i) cout << "\033[35mStashes: " << i;
        if (fgets(buffer, max_buffer, popen("git log -1 --pretty=format:'%s' 2> /dev/null", "r")))
            cout << "\033[90m\n" << buffer;
        status = popen("git status -s", "r");
        if (fgets(buffer, max_buffer, status)) {
            cout << "\n\033";
            color(buffer);
            while (fgets(buffer, max_buffer, status)) color(buffer);
        }
        if (fgets(buffer, max_buffer, popen("git branch --show-current", "r"))) {
            cout << "\n\033[30;41m";
            print(buffer, 0);
            cout << "\033[31;44m";
        }
        else cout << "\n\033[30;42mRebasing\033[32;44m\033[0m";
        pclose(status);
    }
    else cout << "\n\033";
    return 0;
}

void color(char* buffer) {
    switch(buffer[0]) {
        case '?':
            cout << "\033[37m";
            break;
        case ' ':
            switch(buffer[1]) {
                case 'M':
                    cout << "\033[33m";
                    break;
                case 'D':
                    cout << "\033[31m";
            }
            break;
        case 'A':
            switch(buffer[1]) {
                case ' ':
                    cout << "\033[34m";
                    break;
                case 'A':
                    cout << "\033[37;44m";
                    break;
                case 'D':
                    cout << "\033[96m";
                    break;
                case 'M':
                    cout << "\033[94m";
                    break;
                case 'U':
                    cout << "\033[30;44m";
            }
            break;
        case 'D':
            switch(buffer[1]) {
                case ' ':
                    cout << "\033[91m";
                    break;
                case 'D':
                    cout << "\033[37;41m";
                    break;
                case 'U':
                    cout << "\033[30;41m";
            }
            break;
        case 'M':
            switch(buffer[1]) {
                case ' ':
                    cout << "\033[32m";
                    break;
                case 'D':
                    cout << "\033[38;5;202m";
                    break;
                case 'M':
                    cout << "\033[93m";
            }
            break;
        case 'U':
            switch(buffer[1]) {
                case 'A':
                    cout << "\033[33;44m";
                    break;
                case 'D':
                    cout << "\033[33;41m";
                    break;
                case 'U':
                    cout << "\033[30;43m";
            }
            break;
        case 'R':
            switch(buffer[1]) {
                case ' ':
                    cout << "\033[35m";
                    break;
                case 'D':
                    cout << "\033[38;5;201m";
                    break;
                case 'M':
                    cout << "\033[38;5;93m";
            }
    }
    print(buffer, 3);
    cout << "\033[00m ";
}

void print(char* array, int i) {
    while (array[i] != '\n') {
        cout << array[i];
        i++;
    }
}
