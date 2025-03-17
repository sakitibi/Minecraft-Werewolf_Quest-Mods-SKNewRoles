#include <iostream>
#include <string>
#include <vector>

class Player {
public:
    int tag;
    bool lookingAtPlayer;

    Player(int tag, bool lookingAtPlayer) : tag(tag), lookingAtPlayer(lookingAtPlayer) {}

    void titleActionbar(const std::string& message) {
        std::cout << "Actionbar: " << message << std::endl;
    }
};

// Mimic the predicate functions
bool look_at_players(const Player& player) {
    return player.lookingAtPlayer;
}

bool look_at_player_n(const Player& player, int n) {
    return player.tag == n;
}

int main() {
    std::vector<Player> players;
    for (int i = 1; i <= 12; ++i) {
        players.emplace_back(i, true); // Assume all players are being looked at
    }

    for (const auto& player : players) {
        if (look_at_players(player)) {
            std::string message = "を護る (右クリック)";
            std::cout << "Player " << player.tag << " is looking at a player." << std::endl;
            player.titleActionbar("Player " + std::to_string(player.tag) + message);
        }
    }

    return 0;
}
