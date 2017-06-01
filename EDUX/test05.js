import BinaryHeap from '@tyriar/binary-heap';
BinaryHeap.prototype.delmin = BinaryHeap.prototype.extractMinimum;
BinaryHeap.prototype.min = BinaryHeap.prototype.findMinimum;
BinaryHeap.prototype.print = function() {
  console.log(this.list.map(el=>el.key));
};

const INSERT = (H, val) => {
  H.insert(val);
  return H;
};
const DELMIN = (H) => {
  H.delmin();
  return H;
};
const MIN = (H) => {
  H.min();
  return H;
};


const H = new BinaryHeap();
H.buildHeap([11,6,12,1,14,7,18,2,0,13]);


MIN(H);
DELMIN(H);
DELMIN(INSERT(H, MIN(H)));
DELMIN(INSERT(H,8));
DELMIN(INSERT(H,3));
H.print();