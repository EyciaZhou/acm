#include <iostream>
#include <stdio.h>
#include <string.h>

int kait = 0;
int yuan = 1;
int fang = 2;
int hua  = 3;
int douh = 4;

int main() {
    char c;
    int stat = kait;
    bool diyiju = true;
    char juzi[5][1000];
    juzi[4][0] = '\0';
    int p = -1;
    while ((c = getchar()) != EOF) {
        if (c == '(' || c == '[' || c == '{' || c == '\0') {
            if (stat == douh) {
                juzi[0][p + 1] = '\0';
                strcpy(juzi[stat], juzi[0]);
            }
            juzi[0][0] = '\0';
        }
        if (c == '(') {
            stat = yuan;
        }
        if (c == '[') {
            stat = fang;
        }
        if (c == '{') {
            stat = hua;
        }
        if (c == '(' || c == '[' || c == '{') {
            juzi[0][0] = '\0';
            p = -1;
        }
        if (c == ')' || c == ']' || c == '}') {
            juzi[0][p + 1] = '\0';
            strcpy(juzi[stat], juzi[0]);
            juzi[0][0] = '\0';
            stat = kait;
        }
        if (c == ',') {
            if (diyiju) {
                juzi[3][0] = juzi[3][0] - 'a' + 'A';
                diyiju = false;
            } else {
                if (strlen(juzi[4]) > 0) {
                    printf("%s", juzi[4]);
                }
            }
            printf("%s %s %s", juzi[3], juzi[1], juzi[2]);

            fflush(stdout);
            stat = douh;
            p = 0;
            juzi[0][0] = ',';
        }
        if ((c <= 'z' && c >= 'a') || (c == ' ')) {
            p++;
            juzi[0][p] = c;
        }
        if (c <= 'Z' && c >= 'A') {
            p++;
            juzi[0][p] = c - 'A' + 'a';
        }
        if (c == '\n') {
            if (diyiju) {
                juzi[3][0] = juzi[3][0] - 'a' + 'A';
                diyiju = false;
            } else {
                if (strlen(juzi[4]) > 0) {
                    printf("%s", juzi[4]);
                }
            }
            printf("%s %s %s\n", juzi[3], juzi[1], juzi[2]);
            fflush(stdout);
            stat = kait;
            diyiju = true;
            p = -1;
            juzi[0][0] = '\0';
        }
    }
}