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
inline void get_next_number();

int main() {
    get_next_number();
    printf("current_number: %d", current_number);
    
    return 0;
}

inline void get_next_number() {
    /* register -> przechowywanie zmiennej w rejestrze procesora
    znacznie szybsze niż RAM - brak adresu - nie można zrobić pointera */
    register int c;
    while ((c = gc()) != 'E') //TODO: for testing - change to EOF later
    {
        if (c >= '0' && c <= '9')
        {
            current_number = current_number * 10 + (c - '0'); //to samo co current_number * 10 + (c - '0')
        }
        else if (c == '\n')
        {
            //TODO: dummy just for testing locally -> remove later
        }
        else
        { 
            current_number = 0;
        }
    }
}