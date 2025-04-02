#include <iostream>
#include <string>

void damagePlayer(int playerTag) {
    std::cout << "Damaging player with tag: " << playerTag << " by 0.01 fall damage" << std::endl;
}

void applySwordEffect() {
    std::cout << "Applying sword effect" << std::endl;
}

void processDoubleKillerMainSlash6() {
    damagePlayer(6);
    applySwordEffect();
}

int main() {
    processDoubleKillerMainSlash6();
    return 0;
}
