#include <stdio.h>
#define EOL (10)
#define gc getchar_unlocked

int current_number = 0;
unsigned int is_eol = 0;

inline int get_next_number();
inline int get_next_number();

int main()
{
    while (!is_eol)
    {
        current_number = get_next_number();
        printf("Number %d\n", current_number);
        //algorithm(current_number);
    }
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
            current_number = (current_number << 1) + (current_number << 3) + (input_char - '0');
        }
    }
    return current_number;
}

inline int algorithm(int current_number) {

}