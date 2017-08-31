//Do obliczenia w teście
const ANSWER = {
    liczba_porownan: 0,
    kolejne_indexy_M: [],
    m: 0
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


const binSearch = (E = [], x = 0) => {
    let l = 0;
    let r = E.length -1;
    let m = (l + r)/2;
        m = Math.floor(m);
        addAnswer({ kolejne_indexy_M: ANSWER.kolejne_indexy_M.concat(m) });

    while (addAnswer({ liczba_porownan: '+1' }) && E[m] !== x) {
        if (addAnswer({ liczba_porownan: '+1' }) && E[m] < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
        m = (l + r)/2;
        m = Math.floor(m);
        addAnswer({ kolejne_indexy_M: ANSWER.kolejne_indexy_M.concat(m) });
    }

    addAnswer({ m });
    return m;
};

const input = [2,3,6,8,10,11,12,13,15,17,19];
const output = binSearch(input, 15);

console.log(ANSWER);
