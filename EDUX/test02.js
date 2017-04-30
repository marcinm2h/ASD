const binSearch = (E = [], x = 0) => {
    const kolejneM = [];
    let lporownan = 0;
    let l = 0;
    let r = E.length -1;
    let m = (l + r)/2;
        m = Math.floor(m);
        kolejneM.push(m);

    while ( (() => {
        lporownan += 1;
        return E[m] !== x;
    })() ) {
        if ( (()=> {
            lporownan += 1;
            return E[m] < x;
        })() ) {
            l = m + 1;
        } else {
            r = m - 1;
        }
        m = (l + r)/2;
        m = Math.floor(m);
        kolejneM.push(m);
    }
    return { m, lporownan, kolejneM };
};

const partition = (E = []) => {
    let lporownan = 0;
    let lprzestawien = 0;

    let l = -1;
    let r = 0;
    let n = E.length;

    const swap = (E = [], pos1, pos2) => {
        if (pos1 !== pos2) {
            const temp = E[pos1];
            E[pos1] = E[pos2];
            E[pos2] = temp;
            lprzestawien += 1;
            console.log({ lprzestawien, E: JSON.stringify(E), l: l+1, r: r+1, lporownan }); //l +1, r +1 - w teście oczekiwana jest wartość po wykonaniu pętli (sic!)
        }
    };

    while (r < (n-1)) {
        if ( (() => {
            lporownan += 1;
            return E[r] < E[n-1];
        })() ) {
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
