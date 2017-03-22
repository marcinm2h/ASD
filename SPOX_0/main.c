#include <stdio.h>
#define gc getchar_unlocked
// #define gc getchar //bezpieczniejsze, ale wolniejsze

// ASCII char codes:
// 32 = whitespace
// 10 = new line
// 48 = 0 (zero - number)
// ...
// 57 = 9 (nine - number)

int current_number = 0;
int sum = 0;
int read_chars_count = 0;
int base = 0;
inline int get_next_number();
inline int get_other_base_digits(int base);
inline void set_base();

int main() {

    set_base();
    while (!feof(stdin))
    {
        current_number = get_next_number();
        sum = sum + current_number;
        current_number = 0;
    }
    // printf("sum: %d\nread_chars_counts: %d\ndigits: %d\nbase: %d\n", sum, read_chars_count, get_other_base_digits(base), base);
    printf("%d\n%d", get_other_base_digits(base), read_chars_count);
    return 0;
}

inline void set_base() {
    register int input_char;
    int is_at_base_start = 0;
    while ((input_char = gc()) != '\n')
    {
        if (input_char >= '0' && input_char <= '9')
        {
            read_chars_count += 1;
            if (is_at_base_start)
            {
                if (input_char >= '0' && input_char <= '9')
                {
                    base = (base << 1) + (base << 3) + (input_char - '0');
                }
            }
        } else if (input_char == ' ')
        {
            is_at_base_start = 1;
        }
    }
}

inline int get_next_number() {
    /* register -> przechowywanie zmiennej w rejestrze procesora
    znacznie szybsze niż RAM - brak adresu - nie można zrobić pointera  - nie można użyć w funkcjach */
    register int input_char = gc();
    while (input_char != EOF && input_char != ' ')
    {
        if (input_char >= '0' && input_char <= '9')
        {
            current_number = (current_number << 1) + (current_number << 3) + (input_char - '0'); // == current_number * 10 + (c - '0')
            read_chars_count += 1;
        }
        input_char = gc();
    }
    return current_number;
}

inline int get_other_base_digits(int base) {
    register unsigned int digit = 1;
    register double number = (double)sum;

    if (base == 0)
    {
        return 0;
    }
    else if (base == 1)
    {
        return 1;
    }
    else
    {
        while (number > base)
        {
            digit += 1;
            number = number / base;
        }
        return digit;
    }
}
