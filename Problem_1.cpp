#include <iostream>
using namespace std;

int main() {
    int n, k;
    cout << "Masukkan jumlah astronot (N): ";
    cin >> n;
    cout << "Masukkan nilai awal K: ";
    cin >> k;

    // representasi lingkaran astronot sebagai array (manual, tanpa library)
    int astronot[1000];
    for (int i = 0; i < n; i++) {
        astronot[i] = i + 1;
    }

    int jumlah = n;   // jumlah astronot yang masih tersisa
    int posisi = 0;   // index tempat hitungan berikutnya dimulai

    cout << "\nUrutan astronot yang dieliminasi:\n";

    while (jumlah > 1) {
        // cari index astronot yang akan dieliminasi
        int idxEliminasi = (posisi + k - 1) % jumlah;
        int nomorTereliminasi = astronot[idxEliminasi];

        cout << nomorTereliminasi << " ";

        // hapus astronot dari array: geser semua elemen setelahnya ke kiri
        for (int i = idxEliminasi; i < jumlah - 1; i++) {
            astronot[i] = astronot[i + 1];
        }
        jumlah--;

        // update nilai K sesuai aturan paritas nomor yang dieliminasi
        if (nomorTereliminasi % 2 == 0) {
            k = k + 2;
        } else {
            k = k - 1;
        }
        if (k < 2) {
            k = 2;
        }

        // tentukan posisi mulai hitung untuk ronde berikutnya
        if (jumlah > 0) {
            posisi = idxEliminasi % jumlah;
        }
    }

    cout << "\n\nAstronot terakhir yang bertahan: " << astronot[0] << endl;

    return 0;
}