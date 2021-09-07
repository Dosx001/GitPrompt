#include <iostream>

class Git {
    private:
        FILE* fp;
        static const int max = 128;
        char stream[max];
    public:
        bool start();
        void stash();
        void log();
        void merge();
        void status();
        void branch();
    private:
        void color(char* stream);
        void print(char* stream, int i, char a);
};
