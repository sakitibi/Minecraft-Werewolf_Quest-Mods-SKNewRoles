using System;
using LanguagePack.ja;
using LanguagePack.ru;

public static class LanguageSet
{
    public static string lang = null;
    static void Main()
    {
        if (lang != "ja" && lang != "ru")
        {
            lang = "ja";
            Console.WriteLine("[Storage] sys:lang set to 'ja'");
        }
        else
        {
            Console.WriteLine($"[Storage] sys:lang is already set to '{lang}'");
            lang = "ru";
        }
    }
}