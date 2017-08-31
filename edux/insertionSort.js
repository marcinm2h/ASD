//Do obliczenia w teście
const ANSWER = {
    iteracje_petli_zewnetrznej: 0,
    liczba_przestawien: 0,
    liczba_porownan: 0
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

        addAnswer({ liczba_przestawien: '+1' });
    }
};

const increaseLporownan = () => Object.assign(options, { lporownan: (options.lporownan + 1) });
const insertionSort = (E = []) => {
    let i = 0;
    let j = 0;

    for (i = 1; i < size(E); i += 1) {
        addAnswer({ iteracje_petli_zewnetrznej: '+1' });
        j = i;

        while((j > 0) && addAnswer({ liczba_porownan: '+1' }) && (E[j-1]>E[j])) {
            swap(E,j-1,j);
            j -= 1;
        }

        if ([4, 5].includes(ANSWER.iteracje_petli_zewnetrznej)) { //Wykonanie pierwszych  x iteracji pętli zewnętrznej
            console.log(Object.assign(ANSWER, { E: [...E] }));
        }
    }

    return E;
};

const input = [3,2,15,17,4,11,16,5,14,9,0];
const output = insertionSort(input);