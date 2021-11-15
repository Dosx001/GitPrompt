#include "Git.hpp"

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    Git* it = new Git();
    if (it -> start()) {
        std::thread th1(&Git::log, it);
        std::thread th2(&Git::status, it);
        std::thread th3(&Git::merge, it);
        std::thread th4(&Git::branch, it);
        std::thread th5(&Git::stash, it);
        th1.join();
        th2.join();
        th3.join();
        th4.join();
        th5.join();
    }
    return 0;
}
