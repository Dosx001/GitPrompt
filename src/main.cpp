#include "Git.hpp"
#include <thread>

int main() {
    Git* it = new Git();
    if (it -> start()) {
        std::thread th1(&Git::stash, it);
        std::thread th2(&Git::log, it);
        std::thread th3(&Git::status, it);
        std::thread th4(&Git::merge, it);
        std::thread th5(&Git::branch, it);
        th1.join();
        th2.join();
        th3.join();
        th4.join();
        th5.join();
    }
    else std::cout << "\n\033";
    return 0;
}
