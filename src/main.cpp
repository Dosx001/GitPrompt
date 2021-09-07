#include "Git.hpp"

int main() {
    Git it;
    if (it.start()) {
        it.stash();
        it.log();
        it.status();
        it.merge();
        it.branch();
    }
    else std::cout << "\n\033";
    return 0;
}
