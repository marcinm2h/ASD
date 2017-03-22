#include <stdio.h>
#define gc getchar
//ASCII char codes:
//32 = whitespace
//10 = new line

int main() {
    register char c; /* register -> przechowywanie zmiennej w rejestrze procesora
                        znacznie szybsze niż RAM - brak adresu - nie można zrobić pointera */

    // while (!feof(stdin)) {
    while ((c = gc()) != EOF) {
        printf("char code: %d", c);
    }
    
    printf("EOF");
    
    return 0;
}
