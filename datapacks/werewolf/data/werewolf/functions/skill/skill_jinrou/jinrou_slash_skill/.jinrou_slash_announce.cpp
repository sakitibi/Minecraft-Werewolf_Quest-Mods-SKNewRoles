#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

// Simulate the Minecraft commands
void sendTitle(const std::string& player, const std::string& actionbarText) {
    std::cout << "Sending actionbar title to " << player << ": " << actionbarText << std::endl;
}

int main() {
    // Example values, replace with actual logic to get entities and positions
    std::string entity = "@s"; // Example value
    std::string targetPlayer = "@a"; // Example value

    // Simulate the predicates for looking at players with specific tags
    std::unordered_map<int, bool> canSeePlayer;
    for (int i = 1; i <= 12; ++i) {
        canSeePlayer[i] = true; // Assume can see all players initially
    }

    // Loop through possible target tags and send title if predicate is met
    for (int i = 1; i <= 12; ++i) {
        if (canSeePlayer[i]) {
            std::string actionbarText = "";
            actionbarText += targetPlayer + "[tag=" + std::to_string(i) + "] を切り裂く (右クリック)";
            sendTitle(entity, actionbarText);
        }
    }

    return 0;
}
