#include <iostream>
using namespace std;
class Media {
protected:
    string title, publicationDate, uniqueID, publisher;

public:
    Media(string t,string pd,string id,string pub) {
        title = t; publicationDate = pd; uniqueID = id; publisher = pub;
    }

    virtual void displayInfo() {
        cout << "Title: " << title << "\nPublisher: " << publisher << endl;
    }

    void checkOut() {
        cout << title << " checked out\n";
    }

    void returnItem() {
        cout << title << " returned\n";
    }
};

class Book : public Media {
private:
    string author, ISBN;
    int pages;

public:
    Book(string t,string pd,string id,string pub,string a,string i,int p)
        : Media(t,pd,id,pub) {
        author = a; ISBN = i; pages = p;
    }

    void displayInfo() {
        Media::displayInfo();
        cout << "Author: " << author << "\nPages: " << pages << endl;
    }
};

class DVD : public Media {
private:
    string director, rating;
    int duration;

public:
    DVD(string t,string pd,string id,string pub,string d,int dur,string r)
        : Media(t,pd,id,pub) {
        director = d; duration = dur; rating = r;
    }

    void displayInfo() {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration << endl;
    }
};

class CD : public Media {
private:
    string artist, genre;
    int tracks;

public:
    CD(string t,string pd,string id,string pub,string ar,int tr,string g)
        : Media(t,pd,id,pub) {
        artist = ar; tracks = tr; genre = g;
    }

    void displayInfo() {
        Media::displayInfo();
        cout << "Artist: " << artist << "\nTracks: " << tracks << endl;
    }
};

class Magazine : public Media {
public:
    Magazine(string t,string pd,string id,string pub)
        : Media(t,pd,id,pub) {}

    void displayInfo() {
        Media::displayInfo();
        cout << "Type: Magazine\n";
    }
};

class Library {
public:
    void search(string title) {
        cout << "Searching by title: " << title << endl;
    }

    void search(string title, string author) {
        cout << "Searching by title & author: " << title << ", " << author << endl;
    }

    void search(int year) {
        cout << "Searching by year: " << year << endl;
    }
};

int main() {

    Book b("C++","2020","B1","Pub","Bj","123",500);
    DVD d("Movie","2019","D1","Studio","Ali",120,"PG");
    CD c("Album","2021","C1","Music","Ali",10,"Pop");
    Magazine m("Mag","2022","M1","Press");

    b.displayInfo(); cout << endl;
    d.displayInfo(); cout << endl;
    c.displayInfo(); cout << endl;
    m.displayInfo(); cout << endl;

    b.checkOut();
    b.returnItem();

    Library lib;
    lib.search("C++");
    lib.search("C++","Bj");
    lib.search(2020);

    return 0;
}
