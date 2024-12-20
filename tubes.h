#ifndef KEPALAFILM_H_INCLUDED
#define KEPALAFILM_H_INCLUDED

#include <iostream>
using namespace std;

#define info(p) (p->info)
#define next(p) (p->next)
#define prev(p) (p->prev)
#define child(p) (p->child)
#define first(L) (L.first)
#define last(L) (L.last)

typedef struct elmMovie *adrMovie;
typedef struct elmPenonton *adrPenonton;

struct movie {
    string Judul;
    string Genre;
    string Sutradara;
    int TahunRilis;
};

struct Penonton {
    string Nama;
    int Umur;
};

struct elmMovie {
    movie info;
    adrMovie next;
    adrMovie prev;
    adrPenonton child;
};

struct elmPenonton {
    Penonton info;
    adrPenonton next;
};

struct listMovie {
    adrMovie first;
    adrMovie last;
};

struct listPenonton {
    adrPenonton first;
};

void createList(listMovie &Lm);
adrMovie createMovie(string judul, string genre, string sutradara, int tahunRilis);
adrPenonton createPenonton(string nama, int umur);
void insertFirstMovie(listMovie &Lm, adrMovie p);
void insertLastMovie(listMovie &Lm, adrMovie p);
adrMovie findMovie(listMovie Lm, string judul);
void deleteMovie(listMovie &Lm, string judul);
void insertChild(adrMovie parent, adrPenonton child);
void deleteChild(adrMovie parent, string nama);
void showAll(listMovie Lm);
int countPenonton(adrMovie parent);
void updateMovie(listMovie &Lm, string judul, string newJudul, string newGenre, string newSutradara, int newTahunRilis);
adrPenonton searchPenonton(adrMovie parent, string nama);

#endif // KEPALAFILM_H_INCLUDED
