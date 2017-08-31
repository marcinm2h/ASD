//FIXME: Poprawić - nie działa prawidłowo!!!
const { QueueConstruct, IN, EMPTY, FIRST, OUT, PRINT } = require('./Queue.js');

const size = (array = []) => array.length;

const getQueueArray = (length) => {
    let array = (new Array(length)).fill(0);
    array = array.map(() => QueueConstruct());

    return array;
};

const elem_value = (element, i) => {
    return i; //FIXME: nieprawidłowe
};

const radixSort = (E = [], d) => {
    let i, j, k;
    
    const elem = 1; //FIXME: nieprawidłowe
    const Q = getQueueArray(elem);

    for (i = d; i > 0; i= i-1) {
        for (j = 0; j < size(E); j = j+1) {
            IN(Q[elem_value(E[j], i)], E[j]);
        }
        k = 0;
        for (j = 0; j<elem; j = j+1) {
            while (EMPTY(Q[j]) === false) {
                E[k] = FIRST(Q[j]);
                OUT(Q[j]);
                k = k+1;
            }
        }
    }
    console.log(E);
};

const E = [110,759,294,783,863,823,666,550,169,631,454];
const d = 3;
const output = radixSort(E, d);


// const q = getQueueArray(2);

// console.log(q[0]);