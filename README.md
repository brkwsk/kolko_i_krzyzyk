# Kółko i krzyżyk
###### Prosta gra w kółko i krzyżyk.
 
 Oprócz main.cpp, kod zawarty jest w 3 plikach hpp: Plansza, Przeciwnik i Gra, zawierających definicje klas o odpowiednich nazwach.
 
 Gracz wybiera swój znak, decyduje czy będzie się ruszać pierwszy, a następnie rozgrywa tury na przemian z komputerem. Musi również wybrać typ komputera, z którym będzie grał. Pola wybierane są przez wprowadzenie nazwy wiersza i kolumny.
 
 Gra kończy się w momencie utworzenia linii 3 takich samych znaków lub upłynięcia 9 tur. Po zakończonej grze gracz ma możliwość rozpoczęcia nowej partii.
 
 Komputer typu pro nie potrafi przegrać (zgodnie z moją wiedzą). Komputer normalny gra nieoptymalnie, ale racjonalnie. Przeciwnik chaotyczny gra losowo.
 Zaimplementowana jest częściowa walidacja wprowadzanych danych - wprowadzenie ciągu znaków może wywołać błędy. W wypadku wystąpienia błędu w algorytmie przeciwnika, wywołany zostanie wyjątek.
