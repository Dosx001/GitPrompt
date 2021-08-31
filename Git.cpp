#include <iostream>
using namespace std;
int main() {
    const int max_buffer = 128;
    char buffer[max_buffer];
    FILE * status;
    status = popen("git stash list", "r");
    int i = 0;
    while (fgets(buffer, max_buffer, status)) {
        fputs(buffer, status);
        i++;
    }
    if (0 < i) cout << "\033[35mStashes: " << i;
    status = popen("git log -1 --pretty=format:'%s'", "r");
    cout << "\033[90m\n";
    while (fgets(buffer, max_buffer, status)) {
        fputs(buffer, status);
        cout << buffer << '\n';
    }
    status = popen("git status -s", "r");
    while (fgets(buffer, max_buffer, status)) {
        fputs(buffer, status);
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
                        break;
                    default:
                        return 0;
                }
                break;
            case 'A':
                switch(buffer[1]) {
                    case ' ':
                        cout << "\033[34m";
                        break;
                    case 'A':
                        cout << "\033[30;42m";
                        break;
                    case 'D':
                        cout << "\033[96m";
                        break;
                    case 'M':
                        cout << "\033[94m";
                        break;
                    case 'U':
                        cout << "\033[37;42m";
                        break;
                    default:
                        return 0;
                }
                break;
            case 'D':
                switch(buffer[1]) {
                    case ' ':
                        cout << "\033[91m";
                        break;
                    case 'D':
                        cout << "\033[30;41m";
                        break;
                    case 'U':
                        cout << "\033[37;41m";
                        break;
                    default:
                        return 0;
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
                        break;
                    default:
                        return 0;
                }
                break;
            case 'U':
                switch(buffer[1]) {
                    case 'A':
                        cout << "\033[96;42m";
                        break;
                    case 'D':
                        cout << "\e[96;41m";
                        break;
                    case 'U':
                        cout << "\033[30;43m";
                        break;
                    default:
                        return 0;
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
                        break;
                    default:
                        return 0;
                }
                break;
            default:
                return 0;
        }
        i = 3;
        while (buffer[i] != '\n') {
            cout << buffer[i];
            i++;
        }
        cout << "\033[00m ";
    }
    pclose(status);
    return 0;
}