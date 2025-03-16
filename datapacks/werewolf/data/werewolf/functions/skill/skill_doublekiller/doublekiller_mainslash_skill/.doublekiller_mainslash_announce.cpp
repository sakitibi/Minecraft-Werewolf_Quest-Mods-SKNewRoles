using System;

class DoublekillerMainslashAnnounce
{
    static void AnnounceMainslash(int playerTag)
    {
        Console.WriteLine($"Announcing mainslash for player with tag: {playerTag}");
    }

    static void ProcessDoublekillerMainslashAnnounce()
    {
        for (int i = 1; i <= 12; ++i)
        {
            AnnounceMainslash(i);
        }
    }

    static void Main(string[] args)
    {
        ProcessDoublekillerMainslashAnnounce();
    }
}
