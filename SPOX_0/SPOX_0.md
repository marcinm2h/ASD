#Suma w systemie pozycyjnym - długość

##ZADANIE
Rozważmy ciąg C złożony z n liczb naturalnych. Wyznacz liczbę znaków sumy elementów ciągu C w ustalonym systemie pozycyjnym o podstawie d.
Uwaga wyjątek! W systemie unarnym (jedynkowy system liczbowy) liczbę 0 reprezentujemy jako słowo puste.

##WEJŚCIE

Wiersz zawierający liczby n i d oddzielone znakiem odstępu (kod ASCII 32) zakończony znakiem nowej linii (kod ASCII 10). Następnie wiersz opisujący elementy ciągu C oddzielone znakiem odstępu.

##WYJŚCIE

Wiersz zakończony znakiem nowej linii, zawierający liczbę naturalną będąca rozwiązaniem zadania.
Dodatkowo: wiersz zawierający liczbę kontrolną równą liczbie znaków właściwych wczytanych z wejścia (znak właściwy to każdy znak niebędący znakiem białym, tj. znak odstępu, znak nowej linii, znak tabulacji, oraz znakiem końca pliku, tj. EOF).

 

##OGRANICZENIA

Długość n ciągu wejściowego zawarta w przedziale od 0 do 10^7. Elementy ciągu C nie większe niż 10^9. Podstawa systemu pozycyjnego d ograniczona odpowiednio przez 1 i 10^9.
 

##PRZYKŁAD 1

wejście:

10 10

0 1 2 3 4 5 6 7 8 9

wyjście:

2

14


/* KOMENTARZ DO ROZWIĄZANIA
Suma elementów ciągu to 0+1+2+3+4+5+6+7+8+9=45. Długość reprezentacji liczby 45 w systemie o podstawie 10 to 2.
Dodatkowo z wejścia wczytano łącznie 14 znaków właściwych. */

##PRZYKŁAD 2

wejście:

10 2

0 1 2 3 4 5 6 7 8 9

wyjście:

6

13
 
##PRZYKŁAD 3

wejście:

100 64

94 39 65 93 40 83 5 100 82 32 80 20 77 89 100 28 36 47 95 32 13 37 79 48 66 50 57 47 29 18 89 26 19 41 5 20 70 4 25 74 51 15 54 17 22 89 34 89 7 84 33 13 68 93 15 85 64 65 94 15 99 67 28 63 59 84 24 22 32 34 72 76 48 37 30 71 10 68 72 33 26 80 98 65 93 42 0 72 17 76 16 70 27 35 46 45 76 64 65 94

wyjście:

3

202
