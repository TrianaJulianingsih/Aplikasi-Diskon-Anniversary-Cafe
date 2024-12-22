#include <iostream>
using namespace std;

struct Pelanggan {
    char nama[50];
    double totalBelanja;
};

void hitungDiskonIteratif(Pelanggan pelangganList[], int jumlahPelanggan) {
    cout << "Daftar pelanggan yang mendapatkan diskon:\n";
    for (int i = 0; i < jumlahPelanggan; ++i) {
        if (pelangganList[i].totalBelanja > 100000) {
            double totalSetelahDiskon = (pelangganList[i].totalBelanja * 10)/100;
            cout << pelangganList[i].nama << " - Total setelah diskon: Rp " << totalSetelahDiskon << endl;
        }
    }
}

void hitungDiskonRekursif(Pelanggan pelangganList[], int jumlahPelanggan, int index = 0) {
    if (index == jumlahPelanggan) {
        return;
    }

    if (pelangganList[index].totalBelanja > 100000) {
        double totalSetelahDiskon = (pelangganList[index].totalBelanja * 10)/100;  // Use 'index' instead of 'i'
        cout << pelangganList[index].nama << " - Total setelah diskon: Rp " << totalSetelahDiskon << endl;
    }

    hitungDiskonRekursif(pelangganList, jumlahPelanggan, index + 1);
}

int main() {
    int jumlahPelanggan;
    cout << "Masukkan jumlah pelanggan: ";
    cin >> jumlahPelanggan;

    Pelanggan pelangganList[jumlahPelanggan];
    for (int i = 0; i < jumlahPelanggan; ++i) {
        cout << "Masukkan nama pelanggan ke-" << i + 1 << ": ";
        cin >> pelangganList[i].nama;
        cout << "Masukkan total belanja pelanggan ke-" << i + 1 << ": ";
        cin >> pelangganList[i].totalBelanja;
    }
    cout << "\nMenggunakan metode iteratif:\n";
    hitungDiskonIteratif(pelangganList, jumlahPelanggan);

    cout << "\nMenggunakan metode rekursif:\n";
    hitungDiskonRekursif(pelangganList, jumlahPelanggan);

    return 0;
}
