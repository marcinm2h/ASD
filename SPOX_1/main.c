#include <stdio.h>
#define EOL (10)
#define gc getchar_unlocked

unsigned int is_eol = 0;

int current_number = 0;
int previous_number = 0;

int read_chars = 0;
int sum = 0;
int max_length = 0;

int current_sum = 0;
int current_length = 0;

int eq_len = 0;
int eq_val = 0;

int is_asc = 0;
int is_desc = 0;
int is_eq = 0;
int is_start = 1;


inline int get_next_number();
inline int algorithm(int current_number);

int main()
{
    while (!is_eol)
    {
        current_number = get_next_number();
        algorithm(current_number);

        if (current_length > max_length)
        {
            max_length = current_length;
            sum = current_sum;
        }
    }

    // printf("Sum: %d read_chars: %d max_length: %d current_length: %d\n", sum, read_chars, max_length, current_length);
    printf("%d %d\n%d", max_length, sum, read_chars);
    return 0;
}

inline int get_next_number()
{
    register int input_char;
    current_number = 0;
    while (!is_eol && (input_char = gc()) != ' ')
    {
        if (input_char == EOL) {
            is_eol = 1;
        }
        if (input_char >= '0' && input_char <= '9')
        {
            read_chars += 1;
            current_number = (current_number << 1) + (current_number << 3) + (input_char - '0');
        }
    }
    return current_number;
}

inline int algorithm(int current_number)
{
    if (is_start)
    {
        current_length += 1;
        current_sum += current_number;
        is_start = 0;
    }
    else
    {
        if (current_number < previous_number)
        {
            if (is_desc)
            {
                current_length += 1;
                current_sum += current_number;
            }
            else if (is_asc)
            {
                //zmiana trendu z + na -
                if (current_length > max_length)
                {
                    //aktualny ciąg jest najdłuższy
                    max_length = current_length;
                    sum = current_sum;
                }
                //nowy ciąg
                current_length = 0;
                current_sum = 0;
                if (is_eq && eq_len)
                {
                    current_length = eq_len;
                    current_sum = (eq_len * eq_val);
                    eq_len = 0;
                    eq_val = 0;
                }
                if (!is_eq)
                {
                    //dodać poprzednią
                    current_length = 1;
                    current_sum = previous_number;
                    //zerowanie eq
                    eq_len = 0;
                    eq_val = 0;
                }
                current_length += 1;
                current_sum += current_number;
            }
            else
            {
                //prev is_eq
                current_length += 1;
                current_sum += current_number;
            }
            //określenie trendu
            is_desc = 1;
            is_asc = 0;
            is_eq = 0;
        }
        else if (current_number > previous_number)
        {
            if (is_asc)
            {
                current_length += 1;
                current_sum += current_number;
            }
            else if (is_desc)
            {
                //zmiana trendu z - na +
                if (current_length > max_length)
                {
                    //aktualny ciąg jest najdłuższy
                    max_length = current_length;
                    sum = current_sum;
                }
                //nowy ciąg
                current_length = 0;
                current_sum = 0;
                if (is_eq && eq_len)
                {
                    current_length = eq_len;
                    current_sum = (eq_len * eq_val);
                    eq_len = 0;
                    eq_val = 0;
                }
                if (!is_eq)
                {
                    //dodać poprzednią
                    current_length = 1;
                    current_sum = previous_number;
                    //zerowanie eq
                    eq_len = 0;
                    eq_val = 0;
                }
                current_length += 1;
                current_sum += current_number;
            }
            else
            {
                //prev is_eq
                current_length += 1;
                current_sum += current_number;
            }
            //określenie trendu
            is_desc = 0;
            is_asc = 1;
            is_eq = 0;
        }
        else
        {
            if (eq_len == 0)
            {
                eq_len = 1;
                eq_val = current_number;
            }
            eq_len += 1;
            //trend boczny
            current_length += 1;
            current_sum += current_number;
            //current_number == previous_number
            is_eq = 1;

        }
    }

    // printf("\ncurrent_number: %d, current_sum: %d, current_length: %d, is_asc: %d, is_desc: %d, is_eq: %d\n", current_number, current_sum, current_length, is_asc, is_desc, is_eq);
    previous_number = current_number;
}
