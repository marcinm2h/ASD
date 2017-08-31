//Do obliczenia w teście
const ANSWER = {
    liczba_wykonan_partition: 0,
    wysokosc_drzewa_wykonan_rekurencyjnych_hoare: -1
};

//Dodawanie odpowiedzi: addAnswer({ liczba_wykonan_partition: numer }),
//dla numer === '+1' -> inkrementacja
//zwraca true aby można było używać bezpiecznie w operacjach logicznych
const addAnswer = (answer = {}) => {
    Object.keys(answer).forEach((key) => {
        Object.assign(ANSWER, {
            [key]: (answer[key] === '+1') ? ANSWER[key] + 1 : answer[key]
        });
    });

    return true;
};


const size = (array = []) => array.length;

const swap = (array = [], pos1, pos2) => {
    if (pos1 !== pos2) {
        const temp = array[pos1];
        array[pos1] = array[pos2];
        array[pos2] = temp;
    }
};

const partition = (E = []) => {
    addAnswer({ liczba_wykonan_partition: '+1' });
    if (ANSWER.liczba_wykonan_partition === 1) {
        addAnswer({ argument_1_wykonania_partition: [...E] });
    }

    let l = -1;
    let r = 0;
    let n = size(E);

    while(r<n-1) {
        if (E[r] < E[n-1]) {
            if (r>l+1) {
                swap(E, r, l+1);
            }
            l = l+1;
        }
        r = r+1;
    }

    if (l+1 < n-1) {
        swap(E, l+1, n-1);
    }

    // console.log(E);
    return l + 1;
}

const hoarePartition = (E = [], k) => {
    addAnswer({ wysokosc_drzewa_wykonan_rekurencyjnych_hoare: '+1' });

    let m = 0;
    let tmp = 0;
    let n = size(E);
    m = partition(E); //mutuje E

    if (n-m === k) {
        return m;
    } else {
        if (n-m > k) {
            tmp = m + 1 + hoarePartition(E.slice((m+1), n), k);
        } else {
            tmp = hoarePartition(E.slice(0, m), k-(n-m));
        }
    }

    return tmp;
};


const input = [15,2,4,8,16,10,0,12,17,9,18];
const k = 3;
const output = hoarePartition(input, 2);

console.log(ANSWER);