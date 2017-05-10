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