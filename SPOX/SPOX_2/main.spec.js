const createNode = ({ left = null, right = null, val } = {}, options = {}) => Object.assign({ left, right, val }, options);
const Root = createNode({}, { __name: 'ROOT' });

const PATH_KEY_MAP = {
    L: 'left',
    R: 'right'
};

const addNode = ({ val, pathString }) => {
    if (!pathString) {
        Root.val = val;
        return;
    }
    //pathString = LLLRR...
    const path = pathString.split('').map((pathKey) => PATH_KEY_MAP[pathKey]);

    let currentNode = Root;
    path.forEach((key, idx) => {
        if (!currentNode[key]) {
            const node = createNode();
            currentNode[key] = node;
        }
        currentNode = currentNode[key];
        if (idx === (path.length - 1)) {
            currentNode.val = val;
        }
    });
};

const getLongestWord = () => {
    let longestWord = '';
    const traverse = ({ node = Root, word = Root.val } = {}) => {
        if (node.left) {
            traverse({ node: node.left, word: word + (node.left.val || '') });
        }
        if (node.right) {
            traverse({ node: node.right, word: word + (node.right.val || '') });
        }
        //leaf
        if (!node.left && !node.right) {
            if (word.length > longestWord.length) { //tu powinno być porónanie stringów (compareTo)
                longestWord = word;
            }
        }
    };
    traverse();
    return longestWord.split("").reverse().join(""); //reverse word - root -> leaf to leaf -> root
}