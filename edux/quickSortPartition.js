//Do obliczenia w teście
const ANSWER = {
    wysokosc_drzewa_wywolan_rekurencyjnych_quicksort: -1,
    liczba_wykonan_partition: 0,
    liczba_wykonan_quicksort_partition: 0
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

const swap = (E = [], pos1, pos2) => {
    if (pos1 !== pos2) {
        const temp = E[pos1];
        E[pos1] = E[pos2];
        E[pos2] = temp;
    }
};

const partition = (E = []) => {
    addAnswer({ liczba_wykonan_partition: '+1' });
    let l = -1;
    let r = 0;
    let n = size(E);

    while (r < (n-1)) {
        if (E[r] < E[n-1]) {
            if (r > l+1) {
                swap(E, r, l+1);
            }
            l += 1;
        }
        r += 1;
    }

    if ((l+1) < (n-1)) {
        swap(E, l+1, n-1);
    }

    return l+1;
};

const quickSortPartition = (E = [], poziomRekurencji = 0) => {
    addAnswer({
        liczba_wykonan_quicksort_partition: '+1'
    });

    // if(ANSWER.liczba_wykonan_quicksort_partition === 2) {
    //     addAnswer({ argument_2_wywolania_quicksort: [...E] });
    // }

    const n = size(E);
    const m = partition(E);

    if (m > 1) {
        quickSortPartition(E.slice(0, m), poziomRekurencji +1);
    }

    if ((n-m-1) > 1) {
        quickSortPartition(E.slice(m), , poziomRekurencji +1);
    }

    

    if (poziomRekurencji > ANSWER.wysokosc_drzewa_wywolan_rekurencyjnych_quicksort) {
        addAnswer({ wysokosc_drzewa_wywolan_rekurencyjnych_quicksort: poziomRekurencji });
    }

    return E;
};

const input = [13,19,18,14,9,0,6,15,3,17,12];
const output = quickSortPartition([ ...input ]);

console.log(ANSWER);
