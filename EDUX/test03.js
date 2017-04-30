//utils
const options = {};
const increaseLporownan = () => Object.assign(options, { lporownan: (options.lporownan + 1) });

const findMax = (E = []) => Math.max(...E);
const copy = (E = []) => Array.from(E);
const size = (E = []) => E.length;
const swap = (E = [], pos1, pos2) => {
    const { lprzestawien } = options;
    if (pos1 !== pos2) {
        const temp = E[pos1];
        E[pos1] = E[pos2];
        E[pos2] = temp;
        Object.assign(
            options,
            (lprzestawien !== undefined) && { lprzestawien: lprzestawien + 1 }
        );
    }
};
const partition = (E = []) => {
    let l = -1;
    let r = 0;
    let n = size(E);

    while (r < (n-1)) {
        if (E[r] < E[n-1]) {
            if (r > l+1) {
                swap(E, r, l+1);
            }
            l += 1;
        }
        r += 1;
    }

    if ((l+1) < (n-1)) {
        swap(E, l+1, n-1);
    }

    return l+1;
};

//test 02
const insertionSort = (E = []) => {
    Object.assign(options, { iteracjePetliZew: 0, lprzestawien: 0, lporownan: 0 });

    let i = 0;
    let j = 0;

    for (i = 1; i < size(E); i += 1) {
        Object.assign(options, { iteracjePetliZew: options.iteracjePetliZew + 1 });
        j = i;

        while((j > 0) && increaseLporownan() && (E[j-1]>E[j])) {
            swap(E,j-1,j);
            j -= 1;
        }

        console.log(Object.assign({ E: JSON.stringify(E) }, options)); //wykonanie x pierwszych iteracji pętli zewnętrznej zwróci xxx
    }
};

const countingSort = (E = []) => {
    let i;
    let max = findMax(E);
    let Tmp = Array.apply(null, Array(max+1)).map(()=>0);
    let Out = Array.apply(null, Array(size(E))).map(()=>0);

    //zliczanie
    for (i = 0; i < size(E); i++) {
        Tmp[E[i]] = Tmp[E[i]] + 1;
    }
    console.log('(1)zliczanie:', { Tmp: JSON.stringify(Tmp)});

    //sumowanie
    for(i = 1; i < max+1; i++) {
        Tmp[i] = Tmp[i] + Tmp[i-1];
    }
    console.log('(2)sumowanie:', { Tmp: JSON.stringify(Tmp)});

    //wypisanie
    for (i = (size(E) - 1); i >= 0; i--) {
        Out[Tmp[E[i]]-1] = E[i];
        Tmp[E[i]] = Tmp[E[i]]-1;
    }
    console.log('(3)wypisanie:', { Tmp: JSON.stringify(Tmp)});


    Out = copy(E);
};

const quickSortPartition = (E = []) => {
    const n = size(E);
    const m = partition(E);

    if (m > 1) {
        quickSortPartition(E.slice(0, m));
    }

    if ((n-m-1) > 1) {
        quickSortPartition(E.slice(m));
    }

    return E;
};