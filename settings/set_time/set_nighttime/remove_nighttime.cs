using System;

class Program
{
    static void Main()
    {
        Console.WriteLine("scoreboard players remove #GameManager set_nighttime 1200");
        Console.WriteLine("scoreboard players operation #GameManager set_nighttime_minutes = #GameManager set_nighttime");
        Console.WriteLine("scoreboard players operation #GameManager set_nighttime_minutes /= #GameManager tick_minute");
        Console.WriteLine("function werewolf:.settings/view_settings_others");
    }
}
