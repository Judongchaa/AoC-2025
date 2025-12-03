#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int has_repetition(char s[]);
char ftoa(int value);
void reverse(char s[]);

int main(void) {

    FILE *input = fopen("puzzle_input", "r");
    int c;
    char s[20];
    int ranges_list[200][2];
    int n_ranges = 0; // variable to iterate over the ranges
    int j = 0; // variable to itera

    while ((c=fgetc(input)) != EOF) {
        if (c == ',' || c == '\n') {
            s[j] = '\0';
            ranges_list[n_ranges++][1] = atof(s);
            j = 0;
        } else if (c == '-') {
            s[j] = '\0';
            ranges_list[n_ranges][0] = atof(s);
            j = 0;
        } else {
            s[j++] = c;
        }
    }

    float value;
    float sum = 0;
    char ascii_number[20];

    for(int i=0; i<n_ranges+1; i++) {
        
        value = ranges_list[i][0];

        while (value<=ranges_list[i][1]){
            char ascii_number[20] = ftoa(value);
            if (has_repetition(ascii_number)) {
                sum += value;
                printf("%f\n", value);
            }   
            value++;
        }
    }

    printf("%f\n", sum);
    
    return 0;
}

int has_repetition(char s[]) {
    int len = strlen(s);
    if ((len%2) == 1) return 0;

    int i = 0;

    while (s[i] == s[i + (len/2)]) {
        i++;
        if (i == (len/2)) return 1;
    }

    return 0;
}

char ftoa(int value) {
    char s[30];
    int resto = 0;
    int i;
    for (i = 0; value>0; i++) {
        resto = value % 10;
        s[i] = resto + '0';
        value = (value-resto)/10;
    }
    s[i] = '\0';

    reverse(s);

    return s;
}

void reverse(char s[]) {
    int len = strlen(s) -1;
    int temp;
    for (int i = 0; i<=len; i++, len--) {
        temp = s[i];
        s[i] = s[len];
        s[len] = temp;
    }
}
