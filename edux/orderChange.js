const InOrder = Symbol.for('InOrder');
const PostOrder = Symbol.for('PostOrder');
const PreOrder = Symbol.for('PreOrder');

//PreOrder <-> PostOrder <-> InOrder
const orderChange = (treeInOrder = [], { inputOrder, outputOrder }) => {
    // program działa tylko dla 7-elementowych list
    // ORDERED_06 - służy jako wzorzec - nie zmieniać!
    const ORDERED_06 = {
        [PreOrder]: [0,1,3,4,2,5,6],
        [InOrder]: [3,1,4,0,5,2,6],
        [PostOrder]: [3,4,1,5,6,2,0]
    };
    const getIndex = (oldIndex) => {
        const naturalIndex = ORDERED_06[inputOrder][oldIndex];
        return ORDERED_06[outputOrder].reduce((result, curr, idx) => {
            return curr === naturalIndex ? idx : result;
        }, 0);
    };
    const newOrderArray = [];
    treeInOrder.forEach((el, idx) => {
        newOrderArray[getIndex(idx)] = el;
    });
    return newOrderArray;
};

const input = [4,3,5,7,2,16,19]; //wierzchołki drzewa w kolejności wejściowej
const inputOrder = InOrder; //kolejność wejściowa
const outputOrder = PostOrder; //kolejność wyjściowa

const output = orderChange([4,3,5,7,2,16,19], { inputOrder, outputOrder });

console.log(output);