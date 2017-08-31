//Do obliczenia w teście
const ANSWER = {
    liczba_rotacji_pojedynczych_w_lewo: 0,
    liczba_rotacji_pojedynczych_w_prawo: 0,
    liczba_rotacji_podwojnych_prawo_lewo: 0,
    liczba_rotacji_podwojnych_lewo_prawo: 0
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

//https://gist.github.com/viking/2424106 + ES6
class AVLTree {
    constructor(node) {
        this.left = null;
        this.right = null;
        this.node = node;
        this.depth = 1;
        this.elements = [node];
    }

    balance() {

        const ldepth = this.left == null ? 0 : this.left.depth;
        const rdepth = this.right == null ? 0 : this.right.depth;

        if (ldepth > (rdepth + 1)) {
            let __rotationNumber = 0;
            const lldepth = this.left.left == null ? 0 : this.left.left.depth;
            const lrdepth = this.left.right == null ? 0 : this.left.right.depth;

            if (lldepth < lrdepth) {
                this.left.rotateRR();
                __rotationNumber++;
            }
            this.rotateLL();
            __rotationNumber++;

            if (__rotationNumber === 1) {
                addAnswer({ liczba_rotacji_pojedynczych_w_prawo: '+1' });
            } else if (__rotationNumber === 2) {
                addAnswer({ liczba_rotacji_podwojnych_lewo_prawo: '+1' });
            }

        } else if (ldepth + 1 < rdepth) {
            let __rotationNumber = 0;
            const rrdepth = this.right.right == null ? 0 : this.right.right.depth;
            const rldepth = this.right.left == null ? 0 : this.right.left.depth;

            if (rldepth > rrdepth) {
                this.right.rotateLL();
                __rotationNumber++;
            }
            this.rotateRR();
            __rotationNumber++;

            if (__rotationNumber === 1) {
                addAnswer({ liczba_rotacji_pojedynczych_w_lewo: '+1' });
            } else if (__rotationNumber === 2) {
                addAnswer({ liczba_rotacji_podwojnych_prawo_lewo: '+1' });
            }
        }
    }

    rotateLL() {
        const nodeBefore = this.node;
        const elementsBefore = this.elements;
        const rightBefore = this.right;
        this.node = this.left.node;
        this.elements = this.left.elements;
        this.right = this.left;
        this.left = this.left.left;
        this.right.left = this.right.right;
        this.right.right = rightBefore;
        this.right.node = nodeBefore;
        this.right.elements = elementsBefore;
        this.right.updateInNewLocation();
        this.updateInNewLocation();
    }

    rotateRR() {
        const nodeBefore = this.node;
        const elementsBefore = this.elements;
        const leftBefore = this.left;
        this.node = this.right.node;
        this.elements = this.right.elements;
        this.left = this.right;
        this.right = this.right.right;
        this.left.right = this.left.left;
        this.left.left = leftBefore;
        this.left.node = nodeBefore;
        this.left.elements = elementsBefore;
        this.left.updateInNewLocation();
        this.updateInNewLocation();
    }

    updateInNewLocation() {
        this.getDepthFromChildren();
    }

    getDepthFromChildren() {
        this.depth = this.node == null ? 0 : 1;
        if (this.left != null) {
            this.depth = this.left.depth + 1;
        }
        if (this.right != null && this.depth <= this.right.depth) {
            this.depth = this.right.depth + 1;
        }
    }

    compare(node1, node2) {
        const v1 = node1;
        const v2 = node2;
        if (v1 == v2) {
            return 0;
        }
        if (v1 < v2) {
            return -1;
        }
        return 1;
    }

    static INSERT(tree, value) {
        tree.insert(value);

        return tree;
    }

    insert(node) {
        const o = this.compare(node, this.node);
        if (o == 0) {
            this.elements.push(node);
            return false;
        }

        let ret = false;
        if (o == -1) {
            if (this.left == null) {
                this.left = new AVLTree(node);
                ret = true;
            } else {
                ret = this.left.insert(node);
                if (ret) {
                    this.balance();
                }
            }
        } else if (o == 1) {
            if (this.right == null) {
                this.right = new AVLTree(node);
                ret = true;
            } else {
                ret = this.right.insert(node);
                if (ret) {
                    this.balance();
                }
            }
        }

        if (ret) {
            this.getDepthFromChildren();
        }
        return ret; //FIXME: zwróć node?
    }

    findBest(rawValue) {
        const substr = this.node.substr(0, value.length).toLowerCase();
        const value = rawValue.toLowerCase();

        if (value < substr) {
            if (this.left != null) {
                return this.left.findBest(value);
            }
            return [];
        } else if (value > substr) {
            if (this.right != null) {
                return this.right.findBest(value);
            }
            return [];
        }
        return this.elements;
    }

    inOrder(value, currentTree = this) {
        let answer = [];
        const recursion = (value, currentTree) => {
            if (currentTree !== null) {
                if (currentTree.left) {
                    recursion(value, currentTree.left);
                }
                if (currentTree.node !== null) {
                    answer.push(currentTree.node);
                }
                if (currentTree.right) {
                    recursion(value, currentTree.right);
                }
            }
        };
        recursion(value, currentTree);

        return answer;
    }

    preOrder(value, currentTree = this) {
        let answer = [];
        const recursion = (value, currentTree) => {
            if (currentTree !== null) {
                if (currentTree.node !== null) {
                    answer.push(currentTree.node);
                }
                if (currentTree.left) {
                    recursion(value, currentTree.left);
                }
                if (currentTree.right) {
                    recursion(value, currentTree.right);
                }
            }
        };
        recursion(value, currentTree);

        return answer;
    }

    postOrder(value, currentTree = this) {
        let answer = [];
        const recursion = (value, currentTree) => {
            if (currentTree !== null) {
                if (currentTree.left) {
                    recursion(value, currentTree.left);
                }
                if (currentTree.right) {
                    recursion(value, currentTree.right);
                }
                if (currentTree.node !== null) {
                    answer.push(currentTree.node);
                }
            }
        };
        recursion(value, currentTree);

        return answer;
    }

    branchNumber(value, currentTree = this) {
        //liczba wierzchołków wewnętrznych - takich które mają przynajmniej 1 dziecko
        let branchNumber = 0;
        const recursion = (value, currentTree) => {
            if (currentTree !== null) {
                if (currentTree.left || currentTree.right) {
                    branchNumber++;
                }
                if (currentTree.left) {
                    recursion(value, currentTree.left);
                }
                if (currentTree.right) {
                    recursion(value, currentTree.right);
                }
            }
        };
        recursion(value, currentTree);

        return branchNumber;
    }

    leafNumber(value, currentTree = this) {
        //liczba wierzchołków zewnętrznych - takich które mają nie mają dzieci
        let leafNumber = 0;
        const recursion = (value, currentTree) => {
            if (currentTree !== null) {
                if (currentTree.left  === null && currentTree.right === null) {
                    leafNumber++;
                }
                if (currentTree.left) {
                    recursion(value, currentTree.left);
                }
                if (currentTree.right) {
                    recursion(value, currentTree.right);
                }
            }
        };
        recursion(value, currentTree);

        return leafNumber;
    }
}

const { INSERT } = AVLTree;

// użycie:
// const T = new AVLTree(0);
// T.insert(1);
// INSERT(T, 4)

module.exports = {
    ANSWER,
    addAnswer,
    AVLTree,
    INSERT
};