# Wybory

## ZADANIE

Rozważmy zbiór P={p(0), p(1), ..., p(n-1)} składający się z n społeczności lokalnych, dla których ustalona jest relacja bezpośredniego sąsiedztwa. Ze zbioru P wybieramy k różnych elementów, które będą stanowiły punkty startowe kampanii wyborczych k kandydatów q(0), q(1), ..., q(k-1). Dalej proces realizacji kampanii wyborczych przebiega w turach tak, że:

 - tura 0: każdy z kandydatów q(j) dla 0<=j<=k-1 zakłada w punkcie startowym swojej kampanii sztab wyborczy,

 - ...

 - tura i, krok I: każdy z kandydatów z każdego sztabu wyborczego zlokalizowanego w dowolnej społeczności p(j) dla 0<=j<=n-1, odwiedza wszystkie społeczności bezpośrednio sąsiednie z w/w elementem zbioru P, gdzie zakłada swoje komitety wyborcze, pod warunkiem, że nie ma w nich już własnych sztabów wyborczych, bądź sztabów wyborczych innych kandydatów,

 - tura i, krok II: w każdej społeczności p(j) dla 0<=j<=n-1, dla której założony jest komitet wyborczy co najmniej jednego kandydata odbywają się prawybory, w których zwycięża ten kandydat, którego liczba sztabów wyborczych w społecznościach bezpośrednio sąsiednich (stan z początku i-tej tury) ze społecznością p(j) jest:

 -- wariant A: najmniejsza (w przypadku remisu wygrywa kandydat o większej wartości indeksu l dla q(l)),

 -- wariant B: największa (w przypadku remisu wygrywa kandydat o mniejszej wartości indeksu l dla q(l)).

 - tura i, krok III: zwycięstwo w prawyborach w danej społeczności uprawnia kandydata do założenia sztabu wyborczego w miejsce komitetu wyborczego,

 - ...

i kończy się z chwilą, gdy każda następna tura realizacji kampanii wyborczych nie zmienia ustalonej wcześniej postaci przypisania sztabów wyborczych do elementów rozważanego zbioru P społeczności lokalnych.

Ustal finansowanie kosztów kampanii wyborczej, w zależności od przyjętego wariantu rozstrzygania prawyborów (wariant A albo wariant B), dla każdego z k kandydatów, jeżeli koszty kampanii wyborczej mierzymy ostateczną liczbą założonych sztabów wyborczych w obrębie rozważanego zbioru społeczności lokalnych P.

## WEJŚCIE

Kolejno:

 - liczba naturalna reprezentująca liczbę n społeczności lokalnych, znak nowej linii (kod ASCII 10),

 - ciąg m wierszy postaci liczba naturalna x znak odstępu (kod ASCII 32) liczba naturalna y znak nowego wiersza, zakończony wierszem specjalnym postaci -1 znak odstępu -1 znak nowej linii, z których każdy właściwy wiersz definiuje bezpośrednie sąsiedztwo społeczności lokalnych indeksowanych kolejno liczbami x i y (uwaga! sąsiedztwo definiowane jest jednokrotnie, tj. jeżeli krawędzi (x,y) tworzy sąsiedztwo, to krawędź (y,x) do sąsiedztwa nie należy),

 - liczba naturalna opisująca liczbę k kandydatów, znak nowej linii,

 - ciąg k wierszy postaci liczba naturalna z znak nowej linii, gdzie liczba z zawarta w i-tym wierszu reprezentuje indeks punktu startowego (społeczności lokalnej) każdego kolejnego kandydata począwszy od kandydata q(0).

 

## WYJŚCIE

Ciąg k wierszy postaci liczba naturalna a znak odstępu liczba naturalna b znak nowej linii, z których każdy reprezentuje kolejno koszt kampanii wyborczej w wariancie A (wartość a) i w wariancie B (wartość b) każdego kolejnego kandydata począwszy od kandydata q(0).

Dodatkowo: wiersz zawierający liczbę kontrolną równą liczbie znaków właściwych wczytanych z wejścia (znak właściwy to każdy znak niebędący znakiem białym, tj. znak odstępu, znak nowej linii, znak tabulacji, oraz znakiem końca pliku, tj. EOF).

 

## OGRANICZENIA

Liczby kolejno społeczności n jak i kandydatów k, zawarte w przedziale [1,10^5]. Rozmiar m relacji sąsiedztwa społeczności lokalnych nie większy niż 10^7.

## PRZYKŁAD 1

wejście:

3


0 1


1 2


0 2


-1 -1


2


0


1

wyjście:

1 2


2 1


14

 

/* KOMENTARZ DO ROZWIĄZANIA


Przebieg algorytmu:


  tura 0: stan sztabów wyborczych w społecznościach


    p(0) – sztab wyborczy kandydata 0


    p(1) – sztab wyborczy kandydata 1


    p(2) – brak 


  tura 1, krok 1: stan komitetów wyborczych w społecznościach


    p(0) – brak


    p(1) – brak


    p(2) – komitety wyborcze kandydatów 0 i 1


  tura 1, krok 2: wynik prawyborów w społecznościach


    p(0) – brak


    p(1) – brak


    p(2) – wariant A: wygrywa kandydat 1


         - wariant B: wygrywa kandydat 0 


  tura 1, krok 3: stan sztabów wyborczych w społecznościach


    p(0) – sztab wyborczy kandydata 0


    p(1) – sztab wyborczy kandydata 1


    p(2) – wariant A: sztab wyborczy kandydata 1


         - wariant B: sztab wyborczy kandydata 0


Koniec algorytmu.


Koszt kampanii wyborczej:


  kandydat 0 – wariant A: 1


             - warrant B: 2


  kandydat 1 – wariant A: 2


             - warrant B: 1


Dodatkowo z wejścia wczytano łącznie 14 znaków właściwych. */

 

## PRZYKŁAD 2

wejście:

6


1 0


2 1


3 0


3 1


3 2


4 2


4 3


5 0


5 2


-1 -1


3


0


1


5

wyjście:

1 3


2 2


3 1


27

## PRZYKŁAD 3

wejście:

20


3 0


5 1


6 1


7 4


7 5


8 4


10 3


10 9


11 5


11 8


12 4


12 5


12 6


12 10


13 1


13 3


13 5


14 1


14 6


14 7


15 12


15 13


15 14


16 4


16 8


16 9


16 13


17 0


17 2


17 5


17 7


17 15


18 5


18 7


19 3


19 4


19 7


19 10


19 13


19 14


-1 -1


10


3


2


19


5


15


14


4


8


17


11
wyjście:

1 5


1 1


2 2


2 4


2 1


3 2


2 2


3 1


3 1


1 1


146