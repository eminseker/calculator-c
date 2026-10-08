/*
 * Basit hesap makinesi â€” C Ã¶rneÄŸi.
 *
 * Derleme:  gcc calculator.c -o calculator
 * KullanÄ±m: ./calculator 9 - 4
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HISTORY 100

static char gecmis[MAX_HISTORY][64];
static int gecmis_sayisi = 0;

static void gecmise_ekle(double a, const char *op, double b, double sonuc) {
    if (gecmis_sayisi < MAX_HISTORY) {
        snprintf(gecmis[gecmis_sayisi], sizeof(gecmis[0]),
                 "%.6g %s %.6g = %.6g", a, op, b, sonuc);
        gecmis_sayisi++;
    }
}

static int islem_yap(double a, const char *op, double b, double *sonuc) {
    if (strcmp(op, "+") == 0) {
        *sonuc = a + b;
    } else if (strcmp(op, "-") == 0) {
        *sonuc = a - b;
    } else if (strcmp(op, "*") == 0) {
        *sonuc = a * b;
    } else if (strcmp(op, "/") == 0) {
        if (b == 0.0) {
            fprintf(stderr, "Hata: Sifira bolme\n");
            return 1;
        }
        *sonuc = a / b;
    } else {
        fprintf(stderr, "Hata: Bilinmeyen islem: %s\n", op);
        return 1;
    }
    gecmise_ekle(a, op, b, *sonuc);
    return 0;
}

static void yazdir(double sonuc) {
    if (sonuc == (long long) sonuc) {
        printf("%lld\n", (long long) sonuc);
    } else {
        printf("%g\n", sonuc);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Kullanim: %s <sayi> <islem> <sayi>\n", argv[0]);
        return 1;
    }

    double a = atof(argv[1]);
    double b = atof(argv[3]);
    double sonuc;

    if (islem_yap(a, argv[2], b, &sonuc) != 0) {
        return 1;
    }

    yazdir(sonuc);
    return 0;
}
