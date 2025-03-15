#include <iostream>
#include <string>

void announceSlash(int playerTag) {
    std::cout << "Announcing slash for player with tag: " << playerTag << std::endl;
}

void processDoubleKillerSubSlashAnnounce() {
    for (int i = 1; i <= 12; ++i) {
        announceSlash(i);
    }
}

int main() {
    processDoubleKillerSubSlashAnnounce();
    return 0;
}
