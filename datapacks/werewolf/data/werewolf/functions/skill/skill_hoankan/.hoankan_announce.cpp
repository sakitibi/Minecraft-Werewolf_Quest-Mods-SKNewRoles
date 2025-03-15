#include <iostream>
#include <string>

void announceJudgment(int playerTag) {
    std::cout << "Announcing judgment for player with tag: " << playerTag << std::endl;
}

void processHoankanAnnounce() {
    for (int i = 1; i <= 12; ++i) {
        announceJudgment(i);
    }
}

int main() {
    processHoankanAnnounce();
    return 0;
}
