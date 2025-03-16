#include <iostream>
#include <string>
#include <vector>

// Simulate the Minecraft title actionbar command
void titleActionbar(const std::string& selector, int tag) {
    std::cout << "Executing title actionbar for " << selector << " with tag " << tag << std::endl;
    std::cout << "Text: を切り裂く (右クリック)" << std::endl;
}

// Simulate the werewolf:look_at predicate
bool werewolfLookAtPredicate(int tag) {
    // In a real implementation, this would check if the entity is looking at the specified player
    // Here, we just return true for demonstration purposes
    return true;
}

int main() {
    std::vector<int> playerTags = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    for (int tag : playerTags) {
        if (werewolfLookAtPredicate(tag)) {
            titleActionbar("@a", tag);
        }
    }

    return 0;
}
