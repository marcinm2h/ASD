//Do obliczenia w teście
const ANSWER = {
    tablica_pomocnicza_po_1_petli: [],
    tablica_pomocnicza_po_2_petli: [],
    tablica_pomocnicza_po_3_petli: []
};

//Dodawanie odpowiedzi: addAnswer({ liczba_wykonan_partition: numer }),
//dla numer === '+1' -> inkrementacja
const addAnswer = (answer = {}) => {
    Object.keys(answer).forEach((key) => {
        Object.assign(ANSWER, {
            [key]: (answer[key] === '+1') ? ANSWER[key] + 1 : answer[key]
        });
    });

    return true;
};


const findMax = (E = []) => Math.max(...E);
const size = (E = []) => E.length;
const getEmptyArray = (length, initValue = 0) => '0'.repeat(length).split('').map(()=>initValue);

const countingSort = (E = []) => {
    let i;
    let max = findMax(E);
    let Tmp = getEmptyArray(max+1);
    let Out = getEmptyArray(size(E));

    for (let i = 0; i < size(E); i++) { //(1) zliczanie
        Tmp[E[i]] = Tmp[E[i]] + 1;
        addAnswer({ tablica_pomocnicza_po_1_petli: [ ...Tmp ]});
    }

    for (let i = 1; i < max+1; i++) { //(2) sumowanie
        Tmp[i] = Tmp[i] + Tmp[i-1];
        addAnswer({ tablica_pomocnicza_po_2_petli: [ ...Tmp ]});
    }

    for(let i = size(E)-1; i >= 0; i--) { //(3) wypisanie
        Out[Tmp[E[i]]-1] = E[i];
        Tmp[E[i]] = Tmp[E[i]]-1;
        addAnswer({ tablica_pomocnicza_po_3_petli: [ ...Tmp ]});
    }

    return Out;
};

const input = [4,2,2,0,1,3,2,1,1,1,2];
const output = countingSort(input);

console.log(ANSWER);