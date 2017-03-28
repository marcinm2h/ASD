//Pseudokod

main (array[]) {
    int prev = 0;
    int curr = 0;

    int mono_max = 0; // ustawiać lokalne max/min w pętli
    int mono_min = 0; // aby sprawdzić czy nadal ciąg jest rosnący/malejący
    int is_asc = 0; // jest rosnący
    int is_desc = 0; // jest malejący

    int mono_sum = 0;
    int max_mono_length = 0;
    int read_numbers = 0;

    for (int i = 0; i < array.length; i++) {
        curr = array[i];
        if (curr > prev) {
            //rosnący
        } else if (curr < prev) {
            //malejący
        } else {
            //stały
            if () {
                //tutaj przypadku z  mono_max mono_min
                // i ew ustawienie is_asc = false | is_desc = false
            }
        }
        prev = array[i];
    }
}