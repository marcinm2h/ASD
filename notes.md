# 01 Wyszukiwanie

## Wyszukiwanie liniowe/sekwencyjne - linear search
Iteracja po wszystkich elementach aż do znalezienia.

> Koszt - liniowy
> W = O(n); A = O(n);


## W ciągu uporządkowanym

### Skoki (modyfikacja liniowego) - jump search
Iteracja co x elementów 

### Alg. poszukiwań binarnych - binary search
Dzielenie ciągu na 2 -> wejście do prawej lub lewej części,
aż do znalezienia elementu. Liczba podziałów = log2 (10)

> Koszt - logarytmiczny
> T = Θ(log n)


## Wyszukiwanie Min i Max
Znalezienie najmniejszego/największego elementu ciągu.

### Min/Max sekwencyjnie/ Min/Max rekurencyjny
- Dwukrotne przeiterowanie się po całym ciągu. Raz znalezienie min, drugi max.
- Dwukrotna iteracja = 2n -2, stąd koszt liniowy -> Θ(2n -2) = Θ(2n),
lub jednokrotne przeiterowanie się po ciągu i ustalenie aktualnych
minimów / maksimów.

> Koszt- liniowy:
> T = Θ(n)


## Drugi co do wielkości element ciągu - Algorytm turniej

> Koszt - liniowy:
> T = Θ(n + [lg n -2]) = Θ(n)


## k-ty co do wielkości element ciągu - Algorytm Hoare

## Algorytm parition
Segregacja elementów tablicy na większe i mniejsze od wybranego (ostatniego) elementu.

> Koszt - liniowy
> T = Θ(n)

## Algorytm Hoare - Quickselect
Rekurencyhny alogrytm wyszukujący k-ty element ciągu.

> Koszt - liniowy
> T = A = O(n)
> W = O(n^2)


# 02 Sortowanie

## Sortowanie przez wybór - selection sort
Dla każdego elementu iteracja po całej tabilcy i zmiana miejsca (swap) jeśli spełnia warunek.
T = n * (n-1) / 2 = O(n^2)

> Koszt:
> T = O(n^2)

## Sortowanie przez wstawianie - insertion sort
Część uporządkowana i nieuporządkowana. Każdy następn element wstawiany do uporządkowanej
przez porównanie go z całą częścią uporządkowaną i wstawienie w odpowiednie miejsce.

> Koszt:
> W = A = O(n^2)
> S = Θ(1)

## Szybkie sortowanie - quicksort (Hoare partition sort)
Użycie algorytmu partition do podziału względem punktu a następnie ta sama procedura dla większych
i mniejszych elementów tablicy aż do jej posortowania.

> Koszt - liniowo-logarytmiczny:
> A = O(n lg n)
> W = O (n^2)

## Scalanie - merge
Algorytm składowy mergesorta - scalanie ciągów. Iteracja po 2 ciągach i wstawianie do nowego ciągu
akrualnie najmniejszej wartości z 2.

> Koszt - liniowy - zależny od 2 scalanych ciągów n i m
>T =  Θ(n+m)

## Sortowanie przez scalanie - merge sort
Podzielenie ciągu na 2 części, posortowanie, scalenie części.

> Koszt - liniowo-logarytmiczny - mierzony liczbą porównań.
> T(n) = Θ(n lg n)

## Sortowanie przez zliczanie - counting sort

> Koszt n – oznacza liczebność zbioru, k – rozpiętość danych (max - min)):
> T = Θ(k+n) 

# 03 Wybrane Struktury danych

## Stos - Stack
{ push, pop, top, empty }
LIFO - Last In - First Out

>Koszt wyszukiwania w stosie: 
> A = O(n)

## Kolejka - Queue
FIFO - First In - First Out
{ in, out, first, empty }

>Koszt wyszukiwania w kolejce: 
> A = O(n)

## Lista - List

## Drzewo - Tree
Szczególny rodzaj grafu.

## Graf - Graph
G = <V, E>
V - Vertex - wierzchołek,
E - Edge - krawędź (V[])

Reprezentowany przez macierz sąsiedztwa, lub tablicę list incyndencji.

## Drzewo Binarnych Poszukiwań (BST) - Binary Search Tree
Drzewo binarne - Node posiada  co najwyżej 2 - Lewe i Prawe dziecko o
określonej kolejnośći. Lewe dziecko < Rodzic < Prawe dziecko.

Np.
```
        3
       / \
      2   8
     /   / \
    1   5  33
```
### BSTConstruct
Algorytm tworzenia drzewa BST przez insert.

> Koszt:
> Liczba przestawień = 0 => mierzony liczbą przestawień = O(1) => można ograniczyć każdą liczbą z góry!
> złożoność czasowa:
> A = O (n logn), W = O(n^2)
> Złożoność pamięciowa:
>   a) rekurencyjnie: S = O(n)
>   b) iteracyjnie: S = O(1)
