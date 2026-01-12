#include <stdio.h>
#define ADET 10
// CEYDA UYĞUN
// 2420161055
// https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=OKMhwBMMvB


// Araya Ekleme Siralamasi (Insertion Sort) Algoritmasi
void arayaEklemeSirala(int dizi[], int n) {
    int i, anahtar, j;
    for (i = 1; i < n; i++) {
        anahtar = dizi[i]; // Siradaki elemani elimize aliyoruz
        j = i - 1;

        /* Elimizdeki sayidan buyuk olanlari saga dogru kaydiriyoruz */
        while (j >= 0 && dizi[j] > anahtar) {
            dizi[j + 1] = dizi[j];
            j = j - 1;
        }
        // Bosalan yere anahtar sayiyi yerlestiriyoruz
        dizi[j + 1] = anahtar;
    }
}

// Ikili Arama (Binary Search) - Dongu Kullanarak (Iterative)
int ikiliArama(int liste[], int n, int aranan) {
    int sol = 0;
    int sag = n - 1;

    while (sol <= sag) {
        int orta = sol + (sag - sol) / 2;

        // Aranan bulunduysa indeksini dondur
        if (liste[orta] == aranan)
            return orta;

        // Aranan ortadakinden buyukse sol tarafı ele
        if (liste[orta] < aranan)
            sol = orta + 1;
        // Aranan ortadakinden kucukse sag tarafı ele
        else
            sag = orta - 1;
    }

    // Bulunamazsa -1 dondur
    return -1;
}

int main() {
    int veri[ADET] = {45, 12, 89, 34, 23, 1, 67, 90, 11, 5};
    int i, hedef, sonuc;

    printf("--- SIRALAMA ONCESI ---\n");
    for (i = 0; i < ADET; i++) {
        printf("%d ", veri[i]);
    }
    printf("\n\n");

    // Araya ekleme siralamasini calistir
    arayaEklemeSirala(veri, ADET);

    printf("--- SIRALANDIKTAN SONRA ---\n");
    for (i = 0; i < ADET; i++) {
        printf("%d ", veri[i]);
    }
    printf("\n\n");

    printf("Aramak istediginiz sayi: ");
    scanf("%d", &hedef);

    // Ikili arama fonksiyonunu cagir
    sonuc = ikiliArama(veri, ADET, hedef);

    if (sonuc != -1) {
        printf("Bilgi: %d sayisi dizinin %d. sirasinda bulundu.\n", hedef, sonuc);
    } else {
        printf("Bilgi: %d sayisi maalesef dizide yok.\n", hedef);
    }

    return 0;
}
