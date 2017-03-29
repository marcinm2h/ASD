#include <stdio.h>
#define EOL (10)
#define gc getchar_unlocked

unsigned int is_eol = 0;

int current_number = 0;
int previous_number = 0;

int max = 0;
int min = 0;

int sum = 0;
int read_chars = 0;
int max_length = 0;

int current_sum = 0;
int current_max_length = 0;

int eq_val = 0;
int eq_sum = 0;
int eq_len = 0;

inline int get_next_number();
inline int algorithm(int current_number);

int main()
{
    while (!is_eol)
    {
        current_number = get_next_number();
        algorithm(current_number);

        if (current_max_length > max_length)
        {
            max_length = current_max_length;
            sum = current_sum;
        }
    }

    printf("Sum: %d read_chars: %d max_length: %d current_max_length: %d\n", sum, read_chars, max_length, current_max_length);
    // printf("%d %d\n%d", max_length, sum, read_chars);
    return 0;
}

inline int get_next_number()
{
    register int input_char;
    current_number = 0;
    while (!is_eol && (input_char = gc()) != ' ')
    {
        if (input_char == EOL)
        {
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
    if (current_number > previous_number)
    {
        //rosnący
        if (current_number > max)
        {
            max = current_number;
            current_sum += current_number;
            current_max_length += 1;
        }
        else
        {
            //odwrócenie trendu -> porównać z poprzednią długością ciągu
            if (current_max_length > max_length)
            {
                sum = current_sum;
                max_length = current_max_length;
            }
            //nowy ciąg
            min = (eq_val < previous_number) ? eq_val : previous_number;
            max = (eq_val > current_number) ? eq_val : current_number;
            current_sum = (eq_sum > 0) ? (current_number + eq_sum) : (min + max);
            current_max_length = (eq_len > 0) ? (1 + eq_len) : 2;

            eq_val = 0;
            eq_sum = 0;
            eq_len = 0;
        }
    }
    else if (current_number < previous_number)
    {
        //malejący
        if (current_number < min)
        {
            min = current_number;
            current_sum += current_number;
            current_max_length += 1;
        }
        else
        {
            //odwrócenie trendu -> porównać z poprzednią długością ciągu
            if (current_max_length > max_length)
            {
                sum = current_sum;
                max_length = current_max_length;
            }
            //nowy ciąg
            min = (eq_val < current_number) ? eq_val : current_number;
            max = (eq_val > previous_number) ? eq_val : previous_number;
            current_sum = (eq_sum > 0) ? (current_number + eq_sum) : (min + max);
            current_max_length = (eq_len > 0) ? (1 + eq_len) : 2;

            eq_val = 0;
            eq_sum = 0;
            eq_len = 0;
        }
    }
    else
    {
        // prev == curr
        eq_val = current_number;
        eq_sum += current_number;
        eq_len += 1;

        current_sum += current_number;
        current_max_length += 1;
    }

    previous_number = current_number;
}