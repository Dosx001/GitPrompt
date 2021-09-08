#include <iostream>

class Git {
    private:
        const int max = 128;
        bool gates[4] = {true, true, true, true};
    public:
        bool start();
        void stash();
        void log();
        void status();
        void merge();
        void branch();
    private:
        void color(char* stream);
        void print(char* stream, int i, char a);
};
