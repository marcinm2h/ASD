//Do obliczenia w teście
const ANSWER = {
    max_dlugosc_kolejki_Q: 0,
    ostateczna_dlugosc_kolejki_Q: 0
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

const { QueueConstruct, IN, EMPTY, FIRST, OUT, PRINT } = require('./Queue.js');


const input = [7,1,11,0,4,13,5,12,16,19,2,8];
const Q = QueueConstruct(input);

//Przepisać wszystkie operacje na kolejce z edux
OUT(IN(Q,FIRST(Q)));
IN(OUT(Q),17);
IN(OUT(Q),11);
OUT(IN(Q,5));
IN(Q,FIRST(Q));
IN(OUT(Q),16);

addAnswer({
    max_dlugosc_kolejki_Q: Q.getMaxQueueLen(),
    ostateczna_dlugosc_kolejki_Q: Q.length()
});

console.log(ANSWER);