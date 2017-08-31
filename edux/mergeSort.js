//Do obliczenia w teście
const ANSWER = {
    liczba_wywolan_mergesort: 0,
    liczba_wywolan_rekurencyjnych_mergesort: -1,
    wysokosc_drzewa_wywolan_rekurencyjnych_mergesort: 0
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


const size = (E = []) => E.length;

const merge = (E = [], F = []) => { //nie jest to Merge, ale zwraca poprawny wnik
    return ([ ...E, ...F]).sort((x, y) => x - y);
};

const mergeSort = (E = [], poziomRekurencji = 0) => {
    addAnswer({ liczba_wywolan_rekurencyjnych_mergesort: '+1', liczba_wywolan_mergesort: '+1' });
    // if (ANSWER.liczba_wywolan_mergesort === 9) {
    //     addAnswer({ argument_9_wykonania: [...E] })
    // }

    let n = size(E);

    if (n > 1) {
        const half = Math.floor(n/2);
        const left = E.slice(0, half);
        const right = E.slice(half, n);

        if (half > 1) {
            mergeSort(left, poziomRekurencji +1);
        }
        if(n-(half) > 1) {
            mergeSort(right, poziomRekurencji +1);
        }
        E = merge(left, right);
    }

    if (poziomRekurencji > ANSWER.wysokosc_drzewa_wywolan_rekurencyjnych_mergesort) {
        addAnswer({ wysokosc_drzewa_wywolan_rekurencyjnych_mergesort: poziomRekurencji });
    }

    return E;

};

const input = [4,4,5,18,1,11,10,12,2,8,6];
const output = mergeSort(input);

console.log(ANSWER);