class Queue {
  constructor() {
    this.queue = [];
    this.maxQueueLen = 0;
  }

  static IN(queue, value) {
      queue.in(typeof value === 'object' ? value.queue : value);
      return queue;
  }

  static OUT(queue) {
      queue.out();
      return queue;
  }

  static FIRST(queue) {
      return queue.first();
  }

  static EMPTY(queue) {
      return queue.empty();
  }

  static LENGTH(queue) {
      queue.length();
  }

  static PRINT(queue) {
      queue.print();
  }

  empty() {
      return this.queue.length === 0;
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

  getMaxQueueLen() {
      return this.maxQueueLen;
  }
}

const QueueConstruct = (values = []) => {
    const queue = new Queue();
    values.forEach(value => queue.in(value));
    return queue;
}

const { IN, FIRST, EMPTY, LENGTH, OUT, PRINT } = Queue; //API

//użycie
// const Q = QueueConstruct([1,2,3,4]);
//IN(Q, 6);
module.exports = {
    QueueConstruct,
    IN,
    EMPTY,
    FIRST,
    LENGTH,
    OUT,
    PRINT
};
