const size = (E = []) => E.length;

class Node {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

class BSTree {
    constructor() {
        this.__values = [];
        this.ROOT = null;
    }

    static INSERT(T, value) {
        T.insert(value);
        return T;
    }

    insert(value, parent = this.ROOT) {
        if (!this.__values.includes(value)) {
            this.__values = this.__values.concat(value);
        }
        if (this.ROOT == null) {
            this.ROOT = new Node(value);
        } else {
            if (value < parent.value) {
                if (parent.left) {
                    this.insert(value, parent.left);
                } else {
                    parent.left = new Node(value);
                }
            } else {
                if (parent.right) {
                    this.insert(value, parent.right);
                } else {
                    parent.right = new Node(value);
                }
            }
        }
    }

    static MEMBER(T, value) {
        return T.member(value);
    }

    member(value, currentNode = this.ROOT) { //get
        let member = null;
        const recursion = (value, currentNode) => {
            if (currentNode !== null) {
                if (currentNode.value === value) {
                    member = currentNode;
                } else {
                    if (currentNode.left) {
                        recursion(value, currentNode.left);
                    }
                    if (currentNode.right) {
                        recursion(value, currentNode.right);
                    }
                }
            }
        };
        recursion(value, currentNode);

        return member;
    }

    static DELETE(T, value) {
        T.delete(value);
        return T;
    }

    //https://stackoverflow.com/questions/27812367/binary-search-tree-javascript-implementation-remove-function
    delete(value) {
        if (this.__values.includes(value)) {
            this.__values = this.__values.filter(el => el !== value);
        }
        this.ROOT = this._delete(value, this.ROOT);
    }
    
    _delete(value, node) {
        if (node) {
            if (value < node.value) {
                node.left = this._delete(value, node.left);
            } else if (value > node.value) {
                node.right = this._delete(value, node.right);
            } else if (node.left && node.right) {
                node.value = this.findMinValue(node.right);
                node.right = this._delete(node.value, node.right);
            } else {
                node = node.left || node.right;
            }
        }
        return node;
    }

    findMinValue(node = this.ROOT) {
        if (this.ROOT !== null) {
            while (node.left) {
                node = node.left;
            }
            return node.value;
        }
    }
    
    getHeight(node = this.ROOT) {
        if (!this.isEmpty()) {
            if (node.left === null && node.right === null ) {
                 return 0;
            }

            if (node.left  === null) {
                return 1 + this.getHeight(node.right);
            }

            if (node.right === null) { 
                return 1 + this.getHeight(node.left);
            }

            return 1 + Math.max( this.getHeight( node.left ), this.getHeight( node.right ) );
        }
        return 0;
    }

    getLength() {
        return this.__values.length;
    }

  isEmpty() {
      return this.ROOT === null;
  }

}

const {
    DELETE,
    INSERT,
    MEMBER
} = BSTree;

const BSTConstruct = (E = []) => {
    const T = new BSTree();
    let i;

    for (i = 0; i < size(E); i++) {
        INSERT(T, E[i]);
    }

    return T;
};

//użycie
// const T = BSTConstruct([3, 4, 2, 13, 44]);
//INSERT(T, 6);
module.exports = {
    BSTConstruct,
    BSTree,
    DELETE,
    INSERT,
    MEMBER
};