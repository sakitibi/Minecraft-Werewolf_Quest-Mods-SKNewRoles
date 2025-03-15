#include <iostream>
#include <string>

void executeCommand(const std::string& command) {
    std::cout << command << std::endl;
}

void processBounce() {
    // Motion X
    executeCommand("execute as @s[tag=motion_x] store result storage item: motion double 0.001 run data get entity @s Motion[0] 1000");
    executeCommand("execute as @s[tag=motion_x] at @s if data storage item: {motion:0d} run particle heart ~ ~ ~ 0.2 0.2 0.2 0 3 force @a[team=Cupid]");
    executeCommand("execute as @s[tag=motion_x] if data storage item: {motion:0d} run kill @s");

    // Motion Y
    executeCommand("execute as @s[tag=motion_y] store result storage item: motion double 0.001 run data get entity @s Motion[1] 1000");
    executeCommand("execute as @s[tag=motion_y] at @s if data storage item: {motion:0d} run particle heart ~ ~ ~ 0.2 0.2 0.2 0 3 force @a[team=Cupid]");
    executeCommand("execute as @s[tag=motion_y] if data storage item: {motion:0d} run kill @s");

    // Motion Z
    executeCommand("execute as @s[tag=motion_z] store result storage item: motion double 0.001 run data get entity @s Motion[2] 1000");
    executeCommand("execute as @s[tag=motion_z] at @s if data storage item: {motion:0d} run particle heart ~ ~ ~ 0.2 0.2 0.2 0 3 force @a[team=Cupid]");
    executeCommand("execute as @s[tag=motion_z] if data storage item: {motion:0d} run kill @s");

    // Modify entity motion data
    executeCommand("data modify entity @s Item.tag.Motion set from entity @s Motion");
}

int main() {
    processBounce();
    return 0;
}
