#include "tubes.h"

void createList(listMovie &Lm) {
    first(Lm) = NULL;
    last(Lm) = NULL;
}

adrMovie createMovie(string judul, string genre, string sutradara, int tahunRilis) {
    adrMovie p = new elmMovie;
    info(p).Judul = judul;
    info(p).Genre = genre;
    info(p).Sutradara = sutradara;
    info(p).TahunRilis = tahunRilis;
    next(p) = NULL;
    prev(p) = NULL;
    child(p) = NULL;
    return p;
}

adrPenonton createPenonton(string nama, int umur) {
    adrPenonton p = new elmPenonton;
    info(p).Nama = nama;
    info(p).Umur = umur;
    next(p) = NULL;
    return p;
}

void insertFirstMovie(listMovie &Lm, adrMovie p) {
    if (first(Lm) == NULL) {
        first(Lm) = p;
        last(Lm) = p;
    } else {
        next(p) = first(Lm);
        prev(first(Lm)) = p;
        first(Lm) = p;
    }
}

void insertLastMovie(listMovie &Lm, adrMovie p) {
    if (first(Lm) == NULL) {
        first(Lm) = p;
        last(Lm) = p;
    } else {
        prev(p) = last(Lm);
        next(last(Lm)) = p;
        last(Lm) = p;
    }
}

adrMovie findMovie(listMovie Lm, string judul) {
    adrMovie p = first(Lm);
    while (p != NULL) {
        if (info(p).Judul == judul) {
            return p;
        }
        p = next(p);
    }
    return NULL;
}

void deleteMovie(listMovie &Lm, string judul) {
    adrMovie p = findMovie(Lm, judul);
    if (p == NULL) {
        cout << "Film tidak ditemukan.\n";
        return;
    }
    while (child(p) != NULL) {
        adrPenonton temp = child(p);
        child(p) = next(child(p));
        delete temp;
    }

    if (p == first(Lm)) {
        first(Lm) = next(p);
        if (first(Lm)) {
            prev(first(Lm)) = NULL;
        } else {
            last(Lm) = NULL;
        }
    } else if (p == last(Lm)) {
        last(Lm) = prev(p);
        next(last(Lm)) = NULL;
    } else {
        next(prev(p)) = next(p);
        prev(next(p)) = prev(p);
    }
    delete p;
    cout << "Film berhasil dihapus.\n";
}

void insertChild(adrMovie parent, adrPenonton child) {
    if (child(parent) == NULL) {
        child(parent) = child;
    } else {
        adrPenonton q = child(parent);
        while (next(q) != NULL) {
            q = next(q);
        }
        next(q) = child;
    }
}

void deleteChild(adrMovie parent, string nama) {
    if (child(parent) == NULL) {
        cout << "Tidak ada penonton pada film ini.\n";
        return;
    }

    adrPenonton p = child(parent);
    if (info(p).Nama == nama) {
        child(parent) = next(p);
        delete p;
    } else {
        adrPenonton q = NULL;
        while (p != NULL && info(p).Nama != nama) {
            q = p;
            p = next(p);
        }
        if (p == NULL) {
            cout << "Penonton tidak ditemukan.\n";
            return;
        }
        next(q) = next(p);
        delete p;
    }
    cout << "Penonton berhasil dihapus.\n";
}

void showAll(listMovie Lm) {
    if (first(Lm) == NULL) {
        cout << "Tidak ada film.\n";
        return;
    }

    adrMovie p = first(Lm);
    while (p != NULL) {
        cout << "Film: " << info(p).Judul << " | Genre: " << info(p).Genre << endl;
        cout << "Penonton:\n";
        adrPenonton q = child(p);
        while (q != NULL) {
            cout << "- " << info(q).Nama << ", Umur: " << info(q).Umur << endl;
            q = next(q);
        }
        cout << "--------------------\n";
        p = next(p);
    }
}

int countPenonton(adrMovie parent) {
    int count = 0;
    adrPenonton p = child(parent);
    while (p != NULL) {
        count++;
        p = next(p);
    }
    return count;
}

adrPenonton searchPenonton(adrMovie parent, string nama) {
    adrPenonton p = child(parent);
    while (p != NULL) {
        if (info(p).Nama == nama) {
            return p;
        }
        p = next(p);
    }
    return NULL;
}

void updateMovie(listMovie &Lm, string judul, string newJudul, string newGenre, string newSutradara, int newTahunRilis) {
    adrMovie p = findMovie(Lm, judul);
    if (p == NULL) {
        cout << "Film tidak ditemukan.\n";
        return;
    }

    if (!newJudul.empty()) {
        info(p).Judul = newJudul;
    }
    if (!newGenre.empty()) {
        info(p).Genre = newGenre;
    }
    if (!newSutradara.empty()) {
        info(p).Sutradara = newSutradara;
    }
    if (newTahunRilis != 0) {
        info(p).TahunRilis = newTahunRilis;
    }
    cout << "Film berhasil diperbarui.\n";
}
