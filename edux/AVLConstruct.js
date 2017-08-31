const { ANSWER, addAnswer, AVLTree, INSERT } = require('./AVLTree.js');
const size = (array = []) => array.length;

//TODO: wypisanie InOrder, PreOrder, PostOrder
//TODO: wypisać koszty w NOTES.md

const AVLConstruct = (E = []) => {
    let i;
    let T = null;

    for (i=0; i<size(E); i++) {
        if (i === 0) {
            T = new AVLTree(E[i]);
        } else {
            INSERT(T, E[i]);
        }
    }
    addAnswer({
        liczba_wierzcholkow_wewnetrznych: T.branchNumber(),
        liczba_wierzcholkow_zewnetrznych: T.leafNumber(),
        wysokosc_drzewa: T.depth,
        pre_order: T.preOrder(),
        in_order: T.inOrder(),
        post_order: T.postOrder()
    });
    return T;
};

const input = [16,1,13,12,9,11,17,7,5,15]; //zmienić
const output = AVLConstruct(input);

console.log(ANSWER);
