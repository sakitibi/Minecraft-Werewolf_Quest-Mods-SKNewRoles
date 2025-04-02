#include <iostream>
#include <string>

// Simulate the Minecraft commands
void executeParticle(const std::string& particle, const std::string& position) {
    std::cout << "Executing particle " << particle << " at " << position << std::endl;
}

void playSound(const std::string& sound, const std::string& target, const std::string& position, float volume, float pitch, float minVolume) {
    std::cout << "Playing sound " << sound << " for target " << target << " at " << position << " with volume " << volume << ", pitch " << pitch << ", and min volume " << minVolume << std::endl;
}

void giveEffect(const std::string& target, const std::string& effect, int duration, int amplifier, bool hideParticles) {
    std::cout << "Giving effect " << effect << " to target " << target << " for " << duration << " seconds with amplifier " << amplifier << " and hide particles " << hideParticles << std::endl;
}

void tellRaw(const std::string& player, const std::string& message) {
    std::cout << "Sending tellraw message to " << player << ": " << message << std::endl;
}

int main() {
    // Example values, replace with actual logic to get entities and positions
    std::string entity = "@s"; // Example value
    std::string team = "Asasine"; // Example value

    // Execute particle effect
    executeParticle("minecraft:end_rod", "~ ~0.5 ~");

    // Play sound
    playSound("minecraft:entity.experience_orb.pickup", "@a", "~ ~ ~", 1.0f, 1.0f, 0.0f);

    // Give invisibility effect if the entity is on the Asasine team
    if (team == "Asasine") {
        giveEffect(entity, "minecraft:invisibility", 10, 0, true);
    }

    // Send tellraw message
    tellRaw(entity, "あなたは透明化した。");

    return 0;
}
