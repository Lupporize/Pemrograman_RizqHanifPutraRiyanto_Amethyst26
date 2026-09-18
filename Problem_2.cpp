#include <iostream>
using namespace std;

int main() {
    char pesan[1000];
    cout << "Masukkan pesan (huruf kapital, tanpa spasi): ";
    cin >> pesan;

    //hitung panjang pesan secara manual (tanpa strlen)
    int panjang = 0;
    while (pesan[panjang] != '\0') {
        panjang++;
    }

    char hasil[1000];
    int nilaiSebelumnya = 0; // huruf pertama tidak mengalami pergeseran

    for (int i = 0; i < panjang; i++) {
        int nilaiAsli = pesan[i] - 'A' + 1; //posisi huruf asli di alfabet
        int nilaiBaru = nilaiAsli + nilaiSebelumnya;

        //wrap-around jika hasil melewati Z (26)
        while (nilaiBaru > 26) {
            nilaiBaru = nilaiBaru - 26;
        }
        hasil[i] = (char)(nilaiBaru - 1 + 'A');
         //geseran untuk huruf berikutnya berdasarkan huruf ASLI, bukan hasil sandi
        nilaiSebelumnya = nilaiAsli;
    }

    hasil[panjang] = '\0'; 

    cout << "Pesan tersandi: ";
    for (int i = 0; i < panjang; i++) {
        cout << hasil[i];
    }
    cout << endl;

    return 0;
}