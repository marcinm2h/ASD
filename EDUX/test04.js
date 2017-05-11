const size = (E = []) => E.length;
const swap = (E = [], pos1, pos2) => {
    if (pos1 !== pos2) {
        const temp = E[pos1];
        E[pos1] = E[pos2];
        E[pos2] = temp;
    }
};

const MinHeap = () => { //root is max
    const heap = [];

    const getRoot = () => heap[0];
    const getParentIndex = (index) => Math.floor((index -1)/2);
    const getLeftChildIndex = (index) => Math.floor(2*index +1);
    const getRightChildIndex = (index) => Math.floor(2*index +2);

    //add last and bubble it up into right spot
    const add = (element) => {
        heap.push(element);
        if (heap.length > 1) {
            //not root
            let currentElementIndex = heap.length - 1;
            let currentElementParentIndex = getParentIndex(currentElementIndex);

            while(heap[currentElementIndex] < heap[currentElementParentIndex]) {
                swap(heap, currentElementIndex, currentElementParentIndex);
                currentElementIndex = currentElementParentIndex;
                currentElementParentIndex =  getParentIndex(currentElementIndex);
            }
        }

    };

    //remove first -- replace it with last added -- bubble new first down
    const removeMin = () => {
        heap[0] = heap[heap.length-1];
        heap.splice(-1,1);
        if (heap.length > 1) {
            let currentElementIndex = 0;
            let currentElementLeftChildIndex = getLeftChildIndex(currentElementIndex);
            let currentElementRightChildIndex = getRightChildIndex(currentElementIndex);
            let smallerChildIndex = (heap[currentElementLeftChildIndex] < heap[currentElementRightChildIndex]) ?
                currentElementLeftChildIndex : currentElementRightChildIndex;

            while(heap[currentElementIndex] > heap[smallerChildIndex]) {
                swap(heap, currentElementIndex, smallerChildIndex);
                currentElementIndex = smallerChildIndex;
                currentElementLeftChildIndex = getLeftChildIndex(currentElementIndex);
                currentElementRightChildIndex = getRightChildIndex(currentElementIndex);
                smallerChildIndex = (heap[currentElementLeftChildIndex] < heap[currentElementRightChildIndex]) ?
                    currentElementLeftChildIndex : currentElementRightChildIndex;
            }

        }
    };

    return {
        _heap: heap,
        removeMin,
        add
    };
};

const heap = Object.create(MinHeap());

//PreOrder <-> PostOrder <-> InOrder
const changeOrder = (treeInOrder = [], fromOrder, toOrder) => {
    const ORDERED_06 = {
        PreOrder: [0,1,3,4,2,5,6],
        InOrder: [3,1,4,0,5,2,6],
        PostOrder: [3,4,1,5,6,2,0]
    };
    const getIndex = (oldIndex) => {
        const naturalIndex = ORDERED_06[fromOrder][oldIndex];
        return ORDERED_06[toOrder].reduce((result, curr, idx) => {
            return curr === naturalIndex ? idx : result;
        }, 0);
    };
    const newOrderArray = [];
    treeInOrder.forEach((el, idx) => {
        newOrderArray[getIndex(idx)] = el;
    });
    return newOrderArray;
};

// changeOrder([15,3,0,10,17,4,7], 'PreOrder', 'InOrder');

//https://github.com/benoitvallon/computer-science-in-javascript/blob/master/data-structures-in-javascript/queue.es6.js
class Queue {
  constructor() {
    this.queue = [];
    this.maxQueueLen = 0;
  }

  static in(queue, value) {
      queue.in(typeof value === 'object' ? value.queue : value);
      return queue;
  }

  static out(queue) {
      queue.out();
      return queue;
  }

  static first(queue) {
      return queue.first();
  }

  static length(queue) {
      queue.length();
  }

  in(value) {
    this.queue.push(value);
    if(this.length() > this.maxQueueLen) {
        this.maxQueueLen = this.length();
    }
  }

  out() {
    return this.queue.shift();
  }

  first() {
    return this.queue[0];
  }

  length() {
    return this.queue.length;
  }

  print() {
    console.log(this.queue.join(' '));
  }
}

const QueueConstruct = (values = []) => {
    const queue = new Queue();
    values.forEach(value => queue.in(value));
    return queue;
}
const { in: IN, first: FIRST, out: OUT } = Queue;

const queue = QueueConstruct([1,2,3,4]);

OUT(IN(queue, FIRST(queue)));
IN(queue, FIRST(queue));
OUT(IN(queue, 9));
FIRST(queue);
OUT(queue);
OUT(IN(queue, FIRST(queue)));

// https://github.com/benoitvallon/computer-science-in-javascript/blob/master/data-structures-in-javascript/graph.es6.js