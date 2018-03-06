#include "./Book.h"

void LoadData(Book *books){
    books[0].title = "Ha";
    books[0].author = "An";
    books[0].publisher = "Ko";
    books[0].genre = "Ak";
    
    books[1].title = "So";
    books[1].author = "Zi";
    books[1].publisher = "Wn";
    books[1].genre = "BB";

    books[2].title = "IO";
    books[2].author = "Nm";
    books[2].publisher = "Re";
    books[2].genre = "Sj";

    books[3].title = "Sn";
    books[3].author = "Vh";
    books[3].publisher = "We";
    books[3].genre = "CC";

    books[4].title = "FJ";
    books[4].author = "Wj";
    books[4].publisher = "Vn";
    books[4].genre = "Nv";
}
#pragma once