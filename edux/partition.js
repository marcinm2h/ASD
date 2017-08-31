//Do obliczenia w teście
const ANSWER = {
    liczba_porownan: 0,
    liczba_przestawien: 0,
    l: 0,
    r: 0,
    E: []
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


const swap = (E = [], pos1, pos2, { l, r } = {}) => {
    if (pos1 !== pos2) {
        const temp = E[pos1];
        E[pos1] = E[pos2];
        E[pos2] = temp;

        addAnswer({
            liczba_przestawien: '+1',
            l: l+1,
            r: r+1,
            E: [...E]
        });
        // console.log(ANSWER);
    }
};

const partition = (E = []) => {
    let l = -1;
    let r = 0;
    let n = E.length;

    while (r < (n-1)) {

        if (addAnswer({ liczba_porownan: '+1'}) && E[r] < E[n-1]) {
            if (r > l+1) {
                swap(E, r, l+1, { l, r });
            }
            l += 1;
        }
        r += 1;
    }

    if ((l+1) < (n-1)) {
        swap(E, l+1, n-1, { l, r });
    }

    console.log(E);

    return l+1;
};

const input = [1,8,11,3,6];
const output = partition(input);
