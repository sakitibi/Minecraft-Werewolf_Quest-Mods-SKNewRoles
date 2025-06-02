#include <iostream>

void score_random() {
    
    std::cout << "[score_random] called" << std::endl;
}

void add_text() {
    
    std::cout << "[add_text] called" << std::endl;
}

int main() {
  for (int i = 0; i < 10; ++i) {
        score_random();
        add_text();
    }
    return 0;
}
