using System.IO;
using System.Text;

class Program
{
    static void Main()
    {
        var commands = new string[]
        {
            // 通常
            "execute if entity @s[team=Kishi] if score @a[tag=1,limit=1] skill_kishi_protected matches 0 run tellraw @s [{\"selector\":\"@a[tag=1]\"},{\"text\":\"を守護した。\"}]",
            "execute if entity @s[team=Kishi] if score @a[tag=1,limit=1] skill_kishi_protected matches 2 run tellraw @s [{\"text\":\"連続で護ることはできない。\"}]",
            "execute if entity @s[team=Kishi] if score @a[tag=1,limit=1] skill_kishi_protected matches 0 run loot replace entity @s weapon.mainhand loot werewolf:skill/kishi_skill/cooltime",
            "execute if entity @s[team=Kishi] if score @a[tag=1,limit=1] skill_kishi_protected matches 0 run scoreboard players set @s skill_kishi_cooltime 1",
            "execute if entity @s[team=Kishi] if score @a[tag=1,limit=1] skill_kishi_protected matches 0 run scoreboard players set @a[tag=1] skill_kishi_protected 1",
            
            // ポンコツ
            "execute if entity @s[team=Ponkotsu] if score @a[tag=1,limit=1] skill_kishi_protected_dummy matches 1 run tellraw @s [{\"selector\":\"@a[tag=1]\"},{\"text\":\"連続で護ることはできない。\"}]",
            "execute if entity @s[team=Ponkotsu] if entity @a[scores={skill_kishi_protected_dummy=1..},tag=player] unless score @a[tag=1,limit=1] skill_kishi_protected_dummy matches 1 run tellraw @s [{\"selector\":\"@a[tag=1]\"},{\"text\":\"あなたは今も誰かを護っている。\"}]",
            "execute if entity @s[team=Ponkotsu] unless entity @a[scores={skill_kishi_protected_dummy=1..},tag=player] if score @a[tag=1,limit=1] skill_kishi_protected_dummy matches 0 run tellraw @s [{\"selector\":\"@a[tag=1]\"},{\"text\":\"を守護した。\"}]",
            "execute if entity @s[team=Ponkotsu] unless entity @a[scores={skill_kishi_protected_dummy=1..},tag=player] if score @a[tag=1,limit=1] skill_kishi_protected_dummy matches 0 run loot replace entity @s weapon.mainhand loot werewolf:skill/kishi_skill/cooltime",
            "execute if entity @s[team=Ponkotsu] unless entity @a[scores={skill_kishi_protected_dummy=1..},tag=player] if score @a[tag=1,limit=1] skill_kishi_protected_dummy matches 0 run scoreboard players set @s skill_kishi_cooltime 1",
            "execute if entity @s[team=Ponkotsu] unless entity @a[scores={skill_kishi_protected_dummy=1..},tag=player] if score @a[tag=1,limit=1] skill_kishi_protected_dummy matches 0 run scoreboard players set @a[tag=1] skill_kishi_protected_dummy 1"
        };

        var output = string.Join("\n", commands);
        File.WriteAllText("kishi1.mcfunction", output);
    }
}
