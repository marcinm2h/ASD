#include <stdio.h>
#define EOL (10)
#define gc getchar_unlocked

unsigned int is_eol = 0;

int current_number = 0;
int previous_number = 0;

int max = 0;
int min = 0;

int read_chars = 0;
int sum = 0;
int max_length = 0;

int current_sum = 0;
int current_length = 0;

int eq_len = 1;
int eq_val = 0;

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
    // printf("\ncurrent_number: %d, previous_number: %d\n", current_number, previous_number);
    if (current_number > previous_number)
    {
        if (current_number > max)
        {
            //rosnący
            min = 0;
            max = current_number;
            current_length += 1;
            current_sum += current_number;
        }
        else
        {
            //zmiana trendu
            if (current_length > max_length)
            {
                max_length = current_length;
                sum = current_sum;
            }

            //nowy ciąg
            min = current_number;
            max = current_number;
            current_sum = current_number;
            current_length = 1;

            //dodać eq do current_length i sum
            if (eq_len > 1)
            {
                //doliczenie długości stałego ciągu
                current_sum += eq_len * eq_val;
                current_length += eq_len;
            }
            else
            {
                //doliczenie poprzendiej liczby przy zmianie trendu
                current_sum += previous_number;
                current_length += 1;
                min = previous_number;
            }

        }
        eq_len = 1;
    }
    else if (current_number < previous_number)
    {
        if (current_number < min)
        {
            //malejący
            max = 0;
            min = current_number;
            current_length += 1;
            current_sum += current_number;
        }
        else
        {
            //zmiana trendu
            if (current_length > max_length)
            {
                max_length = current_length;
                sum = current_sum;
            }

            //nowy ciąg
            min = current_number;
            max = current_number;
            current_sum = current_number;
            current_length = 1;

            //dodać eq do current_length i sum
            if (eq_len)
            {
                //doliczenie długości stałego ciągu
                current_sum += eq_len * eq_val;
                current_length += eq_len;
            }
            else
            {
                //doliczenie poprzendiej liczby przy zmianie trendu
                current_sum += previous_number;
                current_length += 1;
                max = previous_number;
            }
        }
        eq_len = 1;
    }
    else
    {
        //current_number == previous_number
        eq_len += 1;
        eq_val = current_number;
        current_length += 1;
        current_sum += current_number;
    }
    previous_number = current_number;
}