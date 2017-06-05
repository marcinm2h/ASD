#include<stdio.h>

static int inputCharacters = 0;
class Miasto;
class Kandydat;

class ListElementTown
{
public:
    Miasto* miasto;
    ListElementTown* nastepnyElementListy;

    ListElementTown(Miasto* m)
    {
        this->miasto = m;
        this->nastepnyElementListy = NULL;
    }

    ListElementTown(Miasto* m, ListElementTown* nastepnyElementListy)
    {
        this->miasto = m;
        this->nastepnyElementListy = nastepnyElementListy;
    }
};

class ListTowns
{
public:
    ListElementTown* pierwszyElementListy;
    int iloscElementow;

    ListTowns()
    {
        pierwszyElementListy = NULL;
        iloscElementow = 0;
    }

    Miasto* get(int elementIterator)
    {
        ListElementTown* tmp = pierwszyElementListy;
        for(int i = 0; i < elementIterator; i++)
            tmp = tmp->nastepnyElementListy;

        return tmp->miasto;
    }

    void add(Miasto* m)
    {
        if(this->pierwszyElementListy == NULL)
            this->pierwszyElementListy = new ListElementTown(m);
        else
            pierwszyElementListy = new ListElementTown(m, pierwszyElementListy);

        iloscElementow++;
    }

    bool contains(Miasto* m)
    {
        ListElementTown* tmp = pierwszyElementListy;
        while(tmp)
        {
            if(m == tmp->miasto)
                return true;

            tmp = tmp->nastepnyElementListy;
        }
        return false;
    }

    void clear()
    {
        pierwszyElementListy = NULL;
        iloscElementow = 0;
    }
};

class ListElementThief
{
public:
    Kandydat* kandydat;
    ListElementThief* nastepnyElementListy;

    ListElementThief(Kandydat* t)
    {
        this->kandydat = t;
        this->nastepnyElementListy = NULL;
    }

    ListElementThief(Kandydat* t, ListElementThief* nastepnyElementListy)
    {
        this->kandydat = t;
        this->nastepnyElementListy = nastepnyElementListy;
    }
};

class ListThiefs
{
public:
    ListElementThief* pierwszyElementListy;
    int iloscElementow;

    ListThiefs()
    {
        pierwszyElementListy = NULL;
        iloscElementow = 0;
    }

    Kandydat* get(int elementIterator)
    {
        ListElementThief* tmp = pierwszyElementListy;
        for(int i = 0; i < elementIterator; i++)
            tmp = tmp->nastepnyElementListy;

        return tmp->kandydat;
    }

    void add(Kandydat* t)
    {
        if(this->pierwszyElementListy == NULL)
            this->pierwszyElementListy = new ListElementThief(t);
        else
        {
            pierwszyElementListy = new ListElementThief(t, pierwszyElementListy);
        }
        iloscElementow++;
    }

    bool contains(Kandydat* t)
    {
        ListElementThief* tmp = pierwszyElementListy;
        while(tmp)
        {
            if(t == tmp->kandydat)
                return true;

            tmp = tmp->nastepnyElementListy;
        }
        return false;
    }

    void clear()
    {
        pierwszyElementListy = NULL;
        iloscElementow = 0;
    }
};
class Miasto
{
public:
    int id;
    Kandydat* kandydatKtoryZalozylSztabWyborczyA;
    Kandydat* kandydatKtoryZalozylSztabWyborczyB;
    Kandydat* zwyciezcaA;
    Kandydat* zwyciezcaB;
    ListThiefs* kandydaciA;
    ListThiefs* kandydaciB;
    ListTowns* miastaSasiedzkie;

    Miasto(int i)
    {
        id = i;
        kandydatKtoryZalozylSztabWyborczyA = NULL;
        kandydatKtoryZalozylSztabWyborczyB = NULL;
        zwyciezcaA = NULL;
        zwyciezcaB = NULL;
        kandydaciA = new ListThiefs();
        kandydaciB = new ListThiefs();
        miastaSasiedzkie = new ListTowns();
    }
};

class Kandydat
{
public:
    int id;
    int tymczasowyLicznikIlosciSztabowKandydataWmiastachSasiedzkichA;
    int tymczasowyLicznikIlosciSztabowKandydataWmiastachSasiedzkichB;
    int kosztKampaniA;
    int kosztKampaniB;

    Kandydat(int indeks)
    {
        this->id = indeks;
        this->tymczasowyLicznikIlosciSztabowKandydataWmiastachSasiedzkichA = 0;
        this->tymczasowyLicznikIlosciSztabowKandydataWmiastachSasiedzkichB = 0;
        this->kosztKampaniA = 0;
        this->kosztKampaniB = 0;
    }
};



inline int numDigits(int number)
{
    int digits = 0;
    if (number <= 0) digits = 1;
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

inline void incrementInputCharacters(int var)
{
//    fprintf(stdout, "----> %d, %d <---\n\n", var, numDigits(var));
    inputCharacters += numDigits(var);
}

int main()
{
    int iloscDzialajacychSztabowWyborczychA = 0;
    int iloscDzialajacychSztabowWyborczychB = 0;
    int iloscMiast = 0;
    int iloscKandydatow = 0;
    // wczytujemy ilosc miast
    fscanf(stdin, "%d", &iloscMiast);
    incrementInputCharacters(iloscMiast);
    // tworzymy tablice z miastami
    Miasto* miasta[iloscMiast];
    for(int i = 0; i < iloscMiast; i++)
    {
        // uzupelniamy ja pustymi miastami
        miasta[i] = new Miasto(i);
    }
    int miasto_1;
    int miasto_2;
    // wczytujemy po kolei po 2 id miast ktore sa sasiadami
    fscanf(stdin, "%d", &miasto_1);
    fscanf(stdin, "%d", &miasto_2);
    incrementInputCharacters(miasto_1);
    incrementInputCharacters(miasto_2);
    // lista tych miast konczy sie dwoma id miast -1
    while(miasto_1 != -1 && miasto_2 != -1)
    {
        // graf ma byc nie skierowany, czyli jak sasiad X wie o sasiedzie Y to Y tez musi wiedziec o X
        // dlatego dodajemy informacje o sasiedze do obu miast
        miasta[miasto_1]->miastaSasiedzkie->add(miasta[miasto_2]);
        miasta[miasto_2]->miastaSasiedzkie->add(miasta[miasto_1]);
        fscanf(stdin, "%d", &miasto_1);
        fscanf(stdin, "%d", &miasto_2);
        incrementInputCharacters(miasto_1);
        incrementInputCharacters(miasto_2);
    }
    // wczytujemy ilosc kandydatow
    fscanf(stdin, "%d", &iloscKandydatow);
    incrementInputCharacters(iloscKandydatow);
    // tworzymy tablice z kandydatkami
    Kandydat* kandydaci[iloscKandydatow];
    for(int i = 0; i < iloscKandydatow; i++)
    {
        // uzupelniamy ja kandydatami ktorzy znaja swoje id
        kandydaci[i] = new Kandydat(i);
    }
    // wczytujemy sztaby poczatkowe kandydatow
    int idSztabuStartowegoKandydata;
    for(int i = 0; i < iloscKandydatow; i++)
    {
        // zalozenie jest takie, ze kazdy kandydat ma wlasne miasto,
        // wiec nie trzeba sprawdzac czy aby 2 nie jest naraz w tym samym miescie startowym
        fscanf(stdin, "%d", &idSztabuStartowegoKandydata);
        incrementInputCharacters(idSztabuStartowegoKandydata);
        // dla algorytmu z zasada A i zasada B przypisujemy, ze ten kandydat juz wygral w tym miescie wybory
        miasta[idSztabuStartowegoKandydata]->kandydatKtoryZalozylSztabWyborczyA = kandydaci[i];
        // naliczany koszt kampani wyborczej
        kandydaci[i]->kosztKampaniA++;
        // dodajemy +1 do ilosci dzialajacych sztabow wyborczych
        iloscDzialajacychSztabowWyborczychA++;

        // tutaj to samo co wyzej tylko dla algorytmu 'B'
        miasta[idSztabuStartowegoKandydata]->kandydatKtoryZalozylSztabWyborczyB = kandydaci[i];
        kandydaci[i]->kosztKampaniB++;
        iloscDzialajacychSztabowWyborczychB++;
    }
    /*
teraz dochodzimy do samego mielenia danych:
w celu szybszych obliczen zrobimy sobie liste pomocnicza 'miastaWktorychTrzebaPrzeprowadzicPrawybory'
zalozenia:
mamy milion wierzcholkow grafu [miast]
kazdy wierzcholek ma polaczenie z tysiacami innych wierzcholkow [innymi miastami]
mamy kilkuset kandydatow ktorzy maja ustalone miasta startowe
*/
    ListTowns* miastaWktorychTrzebaPrzeprowadzicPrawybory = new ListTowns();
    // [PĘTLA GŁÓWNA] do poki nie we wszystkich miastach sa sztaby wyborcze
    while(iloscDzialajacychSztabowWyborczychA != iloscMiast && iloscDzialajacychSztabowWyborczychB != iloscMiast)
    {
        // co obrot petli (ture) czyscimy liste pomocnicza
        miastaWktorychTrzebaPrzeprowadzicPrawybory->clear();
        // [PĘTLA 1]
        for(int i = 0; i < iloscMiast; i++)
        {
            // dla kazdego miasta ..
            if(miasta[i]->kandydatKtoryZalozylSztabWyborczyA != NULL && miasta[i]->kandydatKtoryZalozylSztabWyborczyB != NULL)
            {
                // .. w ktorym jest sztab wyborczy [X kandydata]
                // [PĘTLA 1.1]
                for(int i2 = 0; i2 < miasta[i]->miastaSasiedzkie->iloscElementow; i2++)
                {
                    // dla kazdego miasta sasiedniego ..
                    if(miasta[i]->miastaSasiedzkie->get(i2)->kandydatKtoryZalozylSztabWyborczyA == NULL && miasta[i]->miastaSasiedzkie->get(i2)->kandydatKtoryZalozylSztabWyborczyB == NULL)
                    {
                        // .. w ktorym nie ma sztabu wyborczego

                        // wszystko jest w 'ifach', bo wiele innych miast moze byc sasiadem w ktorym jest juz sztab wyborczy,
                        // a lista kandydatow i miast w ktorych maja byc wybor ma byc bez powtorzen
                        if(!(miasta[i]->miastaSasiedzkie->get(i2)->kandydaciA->contains(miasta[i]->kandydatKtoryZalozylSztabWyborczyA)))
                        {
                            // dodaj do listy kandydatow A o ile jeszcze na niej nie jest
                            miasta[i]->miastaSasiedzkie->get(i2)->kandydaciA->add(miasta[i]->kandydatKtoryZalozylSztabWyborczyA);
                        }
                        if(!(miasta[i]->miastaSasiedzkie->get(i2)->kandydaciB->contains(miasta[i]->kandydatKtoryZalozylSztabWyborczyB)))
                        {
                            // dodaj do listy kandydatow B o ile jeszcze na niej nie jest
                            miasta[i]->miastaSasiedzkie->get(i2)->kandydaciB->add(miasta[i]->kandydatKtoryZalozylSztabWyborczyB);
                        }
                        if(!(miastaWktorychTrzebaPrzeprowadzicPrawybory->contains(miasta[i]->miastaSasiedzkie->get(i2))))
                        {
                            // dodaj miasto sasiedzkie do listy miast w ktorych trzeba przeprowadzic prawybory w tej turze
                            miastaWktorychTrzebaPrzeprowadzicPrawybory->add(miasta[i]->miastaSasiedzkie->get(i2));
                        }
                    }
                }
            }
        }

        // koniec 'for' ktory generowal liste miast w ktorych trzeba przeprowadzic prawybory i dodawal w tych miastach kandydatow
        ListElementTown* elementPoczatkowy = miastaWktorychTrzebaPrzeprowadzicPrawybory->pierwszyElementListy;
        int loopsCounter = miastaWktorychTrzebaPrzeprowadzicPrawybory->iloscElementow;
        // teraz trzeba przeprowadzic prawybory i ustalic ktory kandydat wygral w danym miescie
        // przy czym jego wygrana nie moze wplywac na obliczenia innych wygranych (na to moze wplywac dopiero w nastepnej 'turze' algorytmu)
        // dlatego wynik prawyborow zapisujemy do zmiennych 'zwyciezcaA' i 'zwyciezcaB'
        // [PĘTLA 2]
        for(int i = 0; i < loopsCounter; i++)
        {
            Miasto* aktualneMiasto = elementPoczatkowy->miasto;
            Kandydat* tmpKandydat = NULL;
            // z dziwnych powodow trzymamy ilosc 'sztabow wyborczych w miastach sasiednich' w kandydatach,
            // wiec trzeba to co obrot petli czyscic w kazdym kandydacie
            for(int x = 0; x < iloscKandydatow; x++)
            {
                kandydaci[x]->tymczasowyLicznikIlosciSztabowKandydataWmiastachSasiedzkichA = 0;
                kandydaci[x]->tymczasowyLicznikIlosciSztabowKandydataWmiastachSasiedzkichB = 0;
            }
            int loopsCounter_2 = aktualneMiasto->miastaSasiedzkie->iloscElementow;
            ListElementTown* petlaPoSasiadach = aktualneMiasto->miastaSasiedzkie->pierwszyElementListy;
            // teraz dodajemy w tych kandydatach liczbe przechowujaca w ilu miastach sasiedzkich [dla 'aktualneMiasto'] jest sztab danego kandydata
            for(int ii = 0; ii < loopsCounter_2; ii++)
            {
                Miasto* tmpMiasto = petlaPoSasiadach->miasto;
                if(tmpMiasto->kandydatKtoryZalozylSztabWyborczyA != NULL)
                {
                    tmpMiasto->kandydatKtoryZalozylSztabWyborczyA->tymczasowyLicznikIlosciSztabowKandydataWmiastachSasiedzkichA++;
                    tmpMiasto->kandydatKtoryZalozylSztabWyborczyB->tymczasowyLicznikIlosciSztabowKandydataWmiastachSasiedzkichB++;
                }
                petlaPoSasiadach = petlaPoSasiadach->nastepnyElementListy;
            }
            // teraz sprawdzamy ktory kandydat ma najwiecej sztabow wyborczych w sasiadujacych miastach
            Kandydat* zwyciezcaA = aktualneMiasto->kandydaciA->get(0);
            Kandydat* zwyciezcaB = aktualneMiasto->kandydaciB->get(0);

            // dla A
            loopsCounter_2 = aktualneMiasto->kandydaciA->iloscElementow;
            for(int i2 = 1; i2 < loopsCounter_2; i2++)
            {
                tmpKandydat = aktualneMiasto->kandydaciA->get(i2);
                if((zwyciezcaA->tymczasowyLicznikIlosciSztabowKandydataWmiastachSasiedzkichA > tmpKandydat->tymczasowyLicznikIlosciSztabowKandydataWmiastachSasiedzkichA) || (zwyciezcaA->tymczasowyLicznikIlosciSztabowKandydataWmiastachSasiedzkichA == tmpKandydat->tymczasowyLicznikIlosciSztabowKandydataWmiastachSasiedzkichA && zwyciezcaA->id < tmpKandydat->id))
                    zwyciezcaA = tmpKandydat;
            }
            aktualneMiasto->zwyciezcaA = zwyciezcaA;

            fprintf(stdout, "%d", zwyciezcaA->id);
            aktualneMiasto->kandydaciA->clear();
            // dla B
            loopsCounter_2 = aktualneMiasto->kandydaciB->iloscElementow;
            for(int i2 = 1; i2 < loopsCounter_2; i2++)
            {
                tmpKandydat = aktualneMiasto->kandydaciB->get(i2);
                if((zwyciezcaB->tymczasowyLicznikIlosciSztabowKandydataWmiastachSasiedzkichB < tmpKandydat->tymczasowyLicznikIlosciSztabowKandydataWmiastachSasiedzkichB) || (zwyciezcaB->tymczasowyLicznikIlosciSztabowKandydataWmiastachSasiedzkichB == tmpKandydat->tymczasowyLicznikIlosciSztabowKandydataWmiastachSasiedzkichB && zwyciezcaB->id > tmpKandydat->id))
                    zwyciezcaB = tmpKandydat;
            }
            aktualneMiasto->zwyciezcaB = zwyciezcaB;
            fprintf(stdout, ", %d\n\n", zwyciezcaB->id);
            aktualneMiasto->kandydaciB->clear();
            elementPoczatkowy = elementPoczatkowy->nastepnyElementListy;
        }
        elementPoczatkowy = miastaWktorychTrzebaPrzeprowadzicPrawybory->pierwszyElementListy;
        loopsCounter = miastaWktorychTrzebaPrzeprowadzicPrawybory->iloscElementow;
        // znamy juz zwyciezcow, teraz trzeba ich zwycieztwa w prawyborach przepisac na zalozone sztaby, aby w kolejnej 'turze' mogli zakladac kolejne sztaby
        // [PĘTLA 3]
        for(int i = 0; i < loopsCounter; i++)
        {
            Miasto* tmpMiasto = elementPoczatkowy->miasto;
            tmpMiasto->kandydatKtoryZalozylSztabWyborczyA = tmpMiasto->zwyciezcaA;
            tmpMiasto->kandydatKtoryZalozylSztabWyborczyB = tmpMiasto->zwyciezcaB;
            tmpMiasto->kandydatKtoryZalozylSztabWyborczyA->kosztKampaniA++;
            tmpMiasto->kandydatKtoryZalozylSztabWyborczyB->kosztKampaniB++;
            iloscDzialajacychSztabowWyborczychA++;
            iloscDzialajacychSztabowWyborczychB++;
            elementPoczatkowy = elementPoczatkowy->nastepnyElementListy;
        }
    }
    for(int i = 0; i < iloscKandydatow; i++)
    {
        fprintf(stdout, "%d %d\n",kandydaci[i]->kosztKampaniA, kandydaci[i]->kosztKampaniB);
    }
    fprintf(stdout, "%d", inputCharacters);
    return 0;
}