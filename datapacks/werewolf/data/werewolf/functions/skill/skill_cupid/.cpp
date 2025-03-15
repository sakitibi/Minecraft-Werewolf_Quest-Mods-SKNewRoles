#include <iostream>
#include <string>

void chargeCupidArrow() {
    std::cout << "Charging Cupid's arrow" << std::endl;
}

void addHitCupidArrowTag() {
    std::cout << "Adding hit_cupid_arrow tag" << std::endl;
}

void killCupidArrow() {
    std::cout << "Killing Cupid's arrow" << std::endl;
}

void applyCupidArrowDamage() {
    std::cout << "Applying Cupid's arrow damage" << std::endl;
}

void bounceCupidArrow() {
    std::cout << "Bouncing Cupid's arrow" << std::endl;
}

void displayCupidArrowParticles() {
    std::cout << "Displaying Cupid's arrow particles" << std::endl;
}

void processCupidArrow() {
    // チャージ
    chargeCupidArrow();

    // 当たり判定処理
    addHitCupidArrowTag();
    killCupidArrow();
    applyCupidArrowDamage();

    // 壁や床に当たったら消滅
    bounceCupidArrow();

    // パーティクルの表示
    displayCupidArrowParticles();
    displayCupidArrowParticles();
}

int main() {
    processCupidArrow();
    return 0;
}
