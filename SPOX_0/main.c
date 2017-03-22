#include <stdio.h>
#define gc getchar_unlocked
// #define gc getchar //bezpieczniejsze, ale wolniejsze

// ASCII char codes:
// 32 = whitespace
// 10 = new line
// 48 = 0 (zero - number)
// ...
// 57 = 9 (nine - number)

unsigned long current_number = 0;
unsigned long sum = 0;
unsigned long read_chars_count = 0;
unsigned long base = 0;

inline unsigned long get_next_number();
inline unsigned long get_other_base_digits(unsigned long base);
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
    register unsigned int input_char;
    register unsigned int is_at_base_start = 0;
    while ((input_char = gc()) != '\n')
    {
        if (input_char >= '0' && input_char <= '9')
        {
            read_chars_count += 1;
            if (is_at_base_start)
            {
                base = (base << 1) + (base << 3) + (input_char - '0');
            }
        } else if (input_char == ' ')
        {
            is_at_base_start = 1;
        }
    }
}

inline unsigned long get_next_number() {
    /* register -> przechowywanie zmiennej w rejestrze procesora
    znacznie szybsze niż RAM - brak adresu - nie można zrobić pointera  - nie można użyć w funkcjach */
    register unsigned int input_char;
    while ((input_char = gc()) != EOF && input_char != ' ')
    {
        if (input_char >= '0' && input_char <= '9')
        {
            current_number = (current_number << 1) + (current_number << 3) + (input_char - '0'); // == current_number * 10 + (c - '0')
            read_chars_count += 1;
        }
    }
    return current_number;
}

inline unsigned long get_other_base_digits(unsigned long base) {
    register unsigned int digit = 1;
    register float number = (float)sum;

    if (base < 2)
    {
        return sum;
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
