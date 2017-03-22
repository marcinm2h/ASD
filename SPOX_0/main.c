#include <stdio.h>
#define gc getchar_unlocked
// #define gc getchar //bezpieczniejsze, ale wolniejsze

//ASCII char codes:
//32 = whitespace
//10 = new line
//48 = 0 (zero - number)
//...
//57 = 9 (nine - number)

int current_number = 0;
int sum = 0;
int read_chars_count = 0;
inline int get_next_number();

int main() {

    while (!feof(stdin)) {
        current_number = get_next_number();
        sum = sum + current_number;
        current_number = 0;
    }
    // printf("sum: %d, read_chars_count: %d\n", sum, read_chars_count);
    printf("%d\n%d", sum, read_chars_count);
    return 0;
}

inline int get_next_number() {
    /* register -> przechowywanie zmiennej w rejestrze procesora
    znacznie szybsze niż RAM - brak adresu - nie można zrobić pointera  - nie można użyć w funkcjach */
    register int input_char = gc();
    while (input_char != EOF && input_char != ' ') {
        if (input_char >= '0' && input_char <= '9')
        {
            current_number = (current_number << 1) + (current_number << 3) + (input_char - '0'); // == current_number * 10 + (c - '0')
            read_chars_count += 1;
        }
        input_char = gc();
    }
    return current_number;
}
