#include <iostream>

using namespace std;

int main() {
    // Set windmill animation value to 0
    cout << "data modify storage anim: windmill set value 0" << endl;

    // Execute windmill rotation animation
    cout << "execute as @e[type=#animated_java:root,tag=aj.windmill.root] run function animated_java:windmill/animations/rotation/play" << endl;

    // View other settings
    cout << "function werewolf:.settings/view_settings_others" << endl;

    return 0;
}
