const { BSTConstruct, DELETE, INSERT, MEMBER } = require('./BSTree.js');

const T = BSTConstruct([18,15,11,13,17,10,9,5,14,7]);

//przepisać z edux, => zamienić na &&
MEMBER(T,3) && INSERT(T,12);
INSERT(DELETE(T,3),19);
DELETE(T,2);
INSERT(DELETE(T,11),13);
DELETE(T,2);

console.log({ wysokosc_drzewa: T.getHeight(), liczba_wierzcholkow: T.getLength(), T });

// console.log(JSON.stringify(T, undefined, 2));