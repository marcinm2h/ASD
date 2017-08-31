//Do obliczenia w teście
const ANSWER = {
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

const BinaryHeap = require('@tyriar/binary-heap'); //npm install @tyriar/binary-heap

BinaryHeap.prototype.heap = function() {
  return this.list.map(el => el.key);
};

const INSERT = (H, val) => {
  H.insert(val);

  return H;
};

const DELMIN = (H) => {
  H.extractMinimum();
  return H;
};

const MIN = (H) => {
  return H.findMinimum().key;
};

const heapFastConstruct = (array = []) => {
    const H = new BinaryHeap();
    H.buildHeap(array);
    return H;
};


const H = heapFastConstruct([5,13,17,15,1,18,11,3,14,10]);

//przepisać operacje z EDUX
DELMIN(INSERT(H,MIN(H)));
    addAnswer({ kopiec_po_1_oper: H.heap() });
DELMIN(INSERT(H,MIN(H)));
    addAnswer({ kopiec_po_2_oper: H.heap() });
DELMIN(INSERT(H,MIN(H)));
    addAnswer({ kopiec_po_3_oper: H.heap() });
INSERT(H,10);
    addAnswer({ kopiec_po_4_oper: H.heap() });
INSERT(H,MIN(H));
    addAnswer({ kopiec_po_5_oper: H.heap() });


console.log(ANSWER);