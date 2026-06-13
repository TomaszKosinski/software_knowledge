#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* FormatString(const char* s) {
    int charCnt = 0;
    for (int i = 0; s[i]; i++) {
        if (isalnum((unsigned char)s[i])) {
            charCnt++;
        }
    };

    if (charCnt == 0) {
        char* output = malloc(1);
        if (!output) return NULL;
        output[0] = '\0';
        return output;
    }

    // Rezerwacja pamięci: znaki + spacje + '\0'
    char* output = malloc(charCnt + charCnt/2 + 2);
    if (!output) return NULL;

    // Wyciągnij tylko alnum (cyfry + litery)
    char* chars = malloc(charCnt + 1);
    int k = 0;
    for (int i = 0; s[i]; i++) {
        if (isalnum((unsigned char)s[i])) {
            chars[k++] = s[i];
        }
    };
    chars[k] = '\0';

    // Budowanie wyniku
    int i = 0, pos = 0;
    while (charCnt - i > 4) {
        memcpy(output + pos, chars + i, 3);
        pos += 3;
        output[pos++] = ' ';
        i += 3;
    };

    if (charCnt - i == 4) {
        memcpy(output + pos, chars + i, 2);
        pos += 2;
        output[pos++] = ' ';
        memcpy(output + pos, chars + i + 2, 2);
        pos += 2;
    } else {
        memcpy(output + pos, chars + i, charCnt - i);
        pos += charCnt - i;
    };

    output[pos++] = ';';
    output[pos] = '\0';
    free(chars);
    return output;
};

int main() {
    char* input[] = { "02-219 8 53 24",
        "AAA -CDE- CEF",
        "AAA -CDE- CEF F",
        "AAA -CDE- CEF GH",
        "",
        "1",
        "12",
        "123",
        "1234",
        "12345",
        "123456",
        "1234567",
        "12345678",
        "123456789",
        "1234567890"
    };

    for (int i = 0; i < sizeof(input)/sizeof(char*); ++i)
    {
        char* out = FormatString(input[i]);
        if (out) {
            printf("%s -> %s\n", input[i], out);
            free(out);
        };
    }
    return 0;
};