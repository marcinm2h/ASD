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
inline void get_next_number(int input_char);

int main() {

    /* register -> przechowywanie zmiennej w rejestrze procesora
    znacznie szybsze niż RAM - brak adresu - nie można zrobić pointera */
    register int input_char;
    while ((input_char = gc()) != EOF) {
        get_next_number(input_char);
        // printf("current_number: %d", current_number);
    }
    
    return 0;
}

inline void get_next_number(int input_char) {
    if (input_char >= '0' && input_char <= '9')
    {
        current_number = (current_number << 1) + (current_number << 3) + (input_char - '0'); // == current_number * 10 + (c - '0')
        printf("current_number: %d", current_number);
    }
    else if (input_char == '\n')
    {
        //TODO: do testów lokalnych - do usunięcia później
    }
    else
    { 
        current_number = 0;
    }
}