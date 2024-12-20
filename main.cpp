#include "tubes.h"
#include <iostream>

using namespace std;

void menu() {
    cout << "                         __\n";
    cout << "                   _.--\"\"  |\n";
    cout << "    .----.     _.-'   |/\\| |.--.\n";
    cout << "    |jrei|__.-'   _________|  |_)  _______________\n";
    cout << "    |  .-\"\"-.\"\"\"\"\" ___,    `----'\"))   __   .-\"\"-.\"\"\"\"--._\n";
    cout << "    '-' ,--. `    |tic|   .---.       |:.| ' ,--. `      _`.\n";
    cout << "     ( (    ) ) __|tac|__ \\\\|// _..--  \\/ ( (    ) )--._\".-.\";\n";
    cout << "      . `--' ;\\__________________..--------. `--' ;--------'\n";
    cout << "       `-..-'                               `-..-'\n";
    cout << "\n===== Menu Film dan Penonton =====\n";
    cout << "1. Tambah Film\n";
    cout << "2. Tambah Penonton ke Film\n";
    cout << "3. Tampilkan Semua Data\n";
    cout << "4. Hapus Film\n";
    cout << "5. Hapus Penonton dari Film\n";
    cout << "6. Hitung Total Penonton di Film Tertentu\n";
    cout << "7. Perbarui Data Film\n";
    cout << "8. Cari Penonton di Film\n";
    cout << "0. Keluar\n";
    cout << "Pilih: ";
}

int main() {
    listMovie Lm;
    createList(Lm);

    adrMovie movie1 = createMovie("Inception", "Sci-Fi", "Christopher Nolan", 2010);
    insertLastMovie(Lm, movie1);
    insertChild(movie1, createPenonton("John Doe", 25));
    insertChild(movie1, createPenonton("Jane Smith", 30));
    insertChild(movie1, createPenonton("Bob Wilson", 28));

    adrMovie movie2 = createMovie("The Dark Knight", "Action", "Christopher Nolan", 2008);
    insertLastMovie(Lm, movie2);
    insertChild(movie2, createPenonton("Alice Brown", 22));
    insertChild(movie2, createPenonton("Charlie Davis", 35));

    adrMovie movie3 = createMovie("Pulp Fiction", "Crime", "Quentin Tarantino", 1994);
    insertLastMovie(Lm, movie3);
    insertChild(movie3, createPenonton("David Miller", 40));
    insertChild(movie3, createPenonton("Eva Wilson", 27));
    insertChild(movie3, createPenonton("Frank Johnson", 33));
    insertChild(movie3, createPenonton("Grace Lee", 29));

    int choice;

    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1: {
                string judul, genre, sutradara;
                int tahunRilis;
                cout << "Masukkan Judul Film: ";
                cin.ignore();
                getline(cin, judul);
                cout << "Masukkan Genre Film: ";
                getline(cin, genre);
                cout << "Masukkan Sutradara Film: ";
                getline(cin, sutradara);
                cout << "Masukkan Tahun Rilis Film: ";
                cin >> tahunRilis;

                adrMovie newMovie = createMovie(judul, genre, sutradara, tahunRilis);
                insertLastMovie(Lm, newMovie);
                cout << "Film berhasil ditambahkan.\n";
                break;
            }
            case 2: {
                string judul, nama;
                int umur;
                cout << "Masukkan Judul Film: ";
                cin.ignore();
                getline(cin, judul);
                adrMovie movie = findMovie(Lm, judul);
                if (movie == NULL) {
                    cout << "Film tidak ditemukan.\n";
                    break;
                }
                cout << "Masukkan Nama Penonton: ";
                getline(cin, nama);
                cout << "Masukkan Umur Penonton: ";
                cin >> umur;

                adrPenonton newPenonton = createPenonton(nama, umur);
                insertChild(movie, newPenonton);
                cout << "Penonton berhasil ditambahkan ke film " << judul << ".\n";
                break;
            }
            case 3:
                showAll(Lm);
                break;
            case 4: {
                string judul;
                cout << "Masukkan Judul Film yang ingin dihapus: ";
                cin.ignore();
                getline(cin, judul);
                deleteMovie(Lm, judul);
                break;
            }
            case 5: {
                string judul, nama;
                cout << "Masukkan Judul Film: ";
                cin.ignore();
                getline(cin, judul);
                adrMovie movie = findMovie(Lm, judul);
                if (movie == NULL) {
                    cout << "Film tidak ditemukan.\n";
                    break;
                }
                cout << "Masukkan Nama Penonton yang ingin dihapus: ";
                getline(cin, nama);
                deleteChild(movie, nama);
                break;
            }
            case 6: {
                string judul;
                cout << "Masukkan Judul Film: ";
                cin.ignore();
                getline(cin, judul);
                adrMovie movie = findMovie(Lm, judul);
                if (movie == NULL) {
                    cout << "Film tidak ditemukan.\n";
                    break;
                }
                int totalPenonton = countPenonton(movie);
                cout << "Total Penonton di Film " << judul << ": " << totalPenonton << endl;
                break;
            }
            case 7: {
                string judul, judulBaru, genreBaru, sutradaraBaru;
                int tahunRilisBaru;
                cout << "Masukkan Judul Film yang ingin diperbarui: ";
                cin.ignore();
                getline(cin, judul);
                adrMovie movie = findMovie(Lm, judul);
                if (movie == NULL) {
                    cout << "Film tidak ditemukan.\n";
                    break;
                }

                cout << "Masukkan Judul Baru (atau tekan Enter untuk tidak mengubah): ";
                getline(cin, judulBaru);
                cout << "Masukkan Genre Baru (atau tekan Enter untuk tidak mengubah): ";
                getline(cin, genreBaru);
                cout << "Masukkan Sutradara Baru (atau tekan Enter untuk tidak mengubah): ";
                getline(cin, sutradaraBaru);
                cout << "Masukkan Tahun Rilis Baru (atau masukkan 0 untuk tidak mengubah): ";
                cin >> tahunRilisBaru;

                updateMovie(Lm, judul, judulBaru, genreBaru, sutradaraBaru, tahunRilisBaru);
                break;
            }
            case 8: {
                string judul, nama;
                cout << "Masukkan Judul Film: ";
                cin.ignore();
                getline(cin, judul);
                adrMovie movie = findMovie(Lm, judul);
                if (movie == NULL) {
                    cout << "Film tidak ditemukan.\n";
                    break;
                }

                cout << "Masukkan Nama Penonton yang ingin dicari: ";
                getline(cin, nama);

                adrPenonton penonton = searchPenonton(movie, nama);
                if (penonton != NULL) {
                    cout << "Penonton ditemukan: " << info(penonton).Nama
                         << ", Umur: " << info(penonton).Umur << endl;
                } else {
                    cout << "Penonton tidak ditemukan.\n";
                }
                break;
            }
            case 0:
                cout << "Keluar dari program.\n";
                cout << "                         __\n";
                cout << "                   _.--\"\"  |\n";
                cout << "    .----.     _.-'   |/\\| |.--.\n";
                cout << "    |jrei|__.-'   _________|  |_)  _______________\n";
                cout << "    |  .-\"\"-.\"\"\"\"\" ___,    `----'\"))   __   .-\"\"-.\"\"\"\"--._\n";
                cout << "    '-' ,--. `    |tic|   .---.       |:.| ' ,--. `      _`.\n";
                cout << "     ( (    ) ) __|tac|__ \\\\|// _..--  \\/ ( (    ) )--._\".-.\";\n";
                cout << "      . `--' ;\\__________________..--------. `--' ;--------'\n";
                cout << "       `-..-'                               `-..-'\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (choice != 0);

    return 0;
}

