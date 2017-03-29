//Pseudokod

main (array[]) {
    int prev = 0;
    int curr = 0;

    int max = 0; // ustawiać lokalne max/min w pętli
    int min = 0; // aby sprawdzić czy nadal ciąg jest rosnący/malejący

    int sum = 0;
    int max_length = 0;
    int read_numbers = 0;

    for (int i = 0; i < array.length; i++) {
        curr = array[i];

        if (curr > prev) {
            //rosnący
            if (curr > max) {
                max = curr;
                sum = 0;
            }
            sum += 1;
        } else if (curr < prev) {
            //malejący
            if (curr < min) {
                min = curr;
                sum = 0;
            }
            sum += 1;
        } else {
            if (curr > max) {
                max = curr;
                min = 0;
                sum = 1;
            } else if (curr < min) {
                min = curr;
                max = curr;
                sum = 1;
            } else {
                //curr == max || sum == min
                sum += 1;
            }
        }
        
        prev = array[i];
    }
}