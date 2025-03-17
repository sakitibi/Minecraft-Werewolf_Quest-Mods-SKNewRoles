using System;

class Kishi8
{
    static void Main()
    {
        // 通常
        Console.WriteLine("execute if entity @s[team=Kishi] if score @a[tag=8,limit=1] skill_kishi_protected matches 0 run tellraw @s [{\"selector\":\"@a[tag=8]\"},{\"text\":\"を守護した。\"}]");
        Console.WriteLine("execute if entity @s[team=Kishi] if score @a[tag=8,limit=1] skill_kishi_protected matches 2 run tellraw @s [{\"text\":\"連続で護ることはできない。\"}]");
        Console.WriteLine("execute if entity @s[team=Kishi] if score @a[tag=8,limit=1] skill_kishi_protected matches 0 run loot replace entity @s weapon.mainhand loot werewolf:skill/kishi_skill/cooltime");
        Console.WriteLine("execute if entity @s[team=Kishi] if score @a[tag=8,limit=1] skill_kishi_protected matches 0 run scoreboard players set @s skill_kishi_cooltime 1");
        Console.WriteLine("execute if entity @s[team=Kishi] if score @a[tag=8,limit=1] skill_kishi_protected matches 0 run scoreboard players set @a[tag=8] skill_kishi_protected 1");

        // ポンコツ
        Console.WriteLine("execute if entity @s[team=Ponkotsu] if score @a[tag=8,limit=1] skill_kishi_protected_dummy matches 1 run tellraw @s [{\"selector\":\"@a[tag=8]\"},{\"text\":\"連続で護ることはできない。\"}]");
        Console.WriteLine("execute if entity @s[team=Ponkotsu] if entity @a[scores={skill_kishi_protected_dummy=1..},tag=player] unless score @a[tag=8,limit=1] skill_kishi_protected_dummy matches 1 run tellraw @s [{\"selector\":\"@a[tag=8]\"},{\"text\":\"あなたは今も誰かを護っている。\"}]");
        Console.WriteLine("execute if entity @s[team=Ponkotsu] unless entity @a[scores={skill_kishi_protected_dummy=1..},tag=player] if score @a[tag=8,limit=1] skill_kishi_protected_dummy matches 0 run tellraw @s [{\"selector\":\"@a[tag=8]\"},{\"text\":\"を守護した。\"}]");
        Console.WriteLine("execute if entity @s[team=Ponkotsu] unless entity @a[scores={skill_kishi_protected_dummy=1..},tag=player] if score @a[tag=8,limit=1] skill_kishi_protected_dummy matches 0 run loot replace entity @s weapon.mainhand loot werewolf:skill/kishi_skill/cooltime");
        Console.WriteLine("execute if entity @s[team=Ponkotsu] unless entity @a[scores={skill_kishi_protected_dummy=1..},tag=player] if score @a[tag=8,limit=1] skill_kishi_protected_dummy matches 0 run scoreboard players set @s skill_kishi_cooltime 1");
        Console.WriteLine("execute if entity @s[team=Ponkotsu] unless entity @a[scores={skill_kishi_protected_dummy=1..},tag=player] if score @a[tag=8,limit=1] skill_kishi_protected_dummy matches 0 run scoreboard players set @a[tag=8] skill_kishi_protected_dummy 1");
    }
}
