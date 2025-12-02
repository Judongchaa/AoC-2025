#include <stdio.h>
#include <stdlib.h>

int puzzleToInteger(char s[]);

int main(void) {
    char s[10];
    int operations[7000];
    int c, j, lenght = 0;

    int sum = 50;
    int password = 0;

    FILE *puzzle = fopen("puzzle_input",  "r");

    while(((c = fgetc(puzzle)) != EOF)) {
        for (j=0; (c != '\n') && (c != EOF); j++) {
            s[j] = c;
            c = fgetc(puzzle);
        }
        s[j] = '\0';
        operations[lenght++] = puzzleToInteger(s);
    }

    int prev_sum = sum;
    for(int i=0; i<lenght; i++) {
        sum += operations[i];

        if (sum > 99) {
            password += (sum / 100);
        } else if (sum < 0) {
            password += (abs(sum) / 100);
            if (prev_sum != 0) password++;
        }
        if (sum == 0) password++;

        sum = (sum % 100 + 100) % 100;
        prev_sum = sum;
    }

    printf("%d\n", password);
}

int puzzleToInteger(char s[]) {
    if(s[0] == 'L') s[0] = '-';
    if(s[0] == 'R') s[0] = '+';
    int out = atoi(s);

    return out;
}