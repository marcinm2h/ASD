# PRINTRO0 podciąg monotoniczny i spójny

## ZADANIE

Rozważmy losowy ciąg liczb naturalnych C. Podaj długość oraz sumę elementów najdłuższego możliwego monotonicznego i spójnego zarazem podciągu ciągu C. W przypadku niejednoznaczności odpowiedzi wskaż pierwszy taki ciąg począwszy od lewej strony.

## WEJŚCIE

Wiersz opisujący elementy ciągu C oddzielone znakiem odstępu (kod ASCII 32) zakończony znakiem nowego wiersza (kod ASCII 10).

## WYJŚCIE

Wiersz zakończony znakiem nowej linii, zawierający dwie liczby będące rozwiązaniem postawionego problemu oddzielone znakiem odstępu.
Dodatkowo: wiersz zawierający liczbę kontrolną równą liczbie znaków właściwych wczytanych z wejścia (znak właściwy to każdy znak niebędący znakiem białym, tj. znak odstępu, znak nowej linii, znak tabulacji, oraz znakiem końca pliku, tj. EOF).

## OGRANICZENIA

Długość ciągu C dodatnia i ograniczona przez 10^7, elementy rozważanego ciągu zawarte w przedziale wartości [0,10^9].

## PRZYKŁAD 1

wejście:

8 4 2 3 2

wyjście:

3 14

5

/* KOMENTARZ DO ROZWIĄZANIA
Ciąg wejściowy C składa się z elementów kolejno 8, 4, 2, 3, 2. Poszukiwany podciąg monotoniczny i spójny o maksymalnej długości to 8 4 2.
Ostatecznie długość i suma elementów wskazanego podciągu są równe odpowiednio 3 oraz 14.
Dodatkowo z wejścia wczytano łącznie 5 znaków właściwych. */

## PRZYKŁAD 2

wejście:

1 1 7 3 2 0 0 4 5 5 6 2 1

wyjście:

6 20

13

## PRZYKŁAD 3

wejście:

65 87 47 5 12 74 25 32 78 44 40 77 85 4 29 57 55 79 31 63 84 66 62 41 52 36 82 86 6 98 63 65 14 57 75 14 74 15 41 88 27 75 6 78 98 78 22 77 68 74 92 47 30 44 40 52 70 66 17 60 47 97 34 37 23 69 56 57 3 45 7 76 18 35 24 73 47 77 1 84 92 54 18 98 84 36 66 71 92 13 77 28 75 24 46 67 4 63 82 1

wyjście:

4 253

191