#include <iostream>
#include <string>
#include <list>

using namespace std;

class Song {
private:
    string title;
    Song* next;

public:
    Song(string title) : title(title), next(nullptr) {}

    string getTitle() const {
        return title;
    }

    Song* getNext() const {
        return next;
    }

    void setNext(Song* song) {
        next = song;
    }
};

class Iterator {
public:
    virtual bool hasNext() const = 0;
    virtual void next() = 0;
    virtual Song* getCurrent() = 0;
};

class SongIterator : public Iterator {
private:
    Song* currentSong;

public:
    SongIterator(Song* firstSong) : currentSong(firstSong) {}

    bool hasNext() const override {
        return currentSong != nullptr;
    }

    void next() override {
        if (hasNext()) {
            currentSong = currentSong->getNext();
        }
    }

    Song* getCurrent() override {
        return currentSong;
    }
};

class PlayList {
private:
    Song* firstSong;
    SongIterator it;

public:
    PlayList() : firstSong(nullptr), it(firstSong) {}

    void addSong(Song* song) 
    {
        if (!firstSong) 
        {
            firstSong = song;
            it = SongIterator(firstSong);
        } 
        else 
        {
            Song* current = firstSong;
            while (current->getNext() != nullptr) {
                current = current->getNext();
            }
            current->setNext(song);
        }
    }

    void removeSong(Song* song) {
        if (!firstSong) {
            return;
        }

        if (firstSong == song) 
        {
            firstSong = firstSong->getNext();
            delete song;
            it = SongIterator(firstSong);
            return;
        }

        Song* current = firstSong;
        while (current->getNext() != nullptr && current->getNext() != song) 
        {
            current = current->getNext();
        }

        if (current->getNext() == song) 
        {
            current->setNext(song->getNext());
            delete song;
            it = SongIterator(firstSong);
        }
    }

    void allSongs()
    {
        Iterator* iterator = createIterator();

        cout << "Playlist Songs:" << endl;
        while (iterator->hasNext()) 
        {
            Song* currentSong = iterator->getCurrent();
            if (currentSong) {
                cout << "Song: " << currentSong->getTitle() << endl;
            }
            iterator->next();
        }
        delete iterator;
    }

    Iterator* createIterator() {
        return new SongIterator(firstSong);
    }
};

int main() {
    PlayList playlist;

    Song* song1 = new Song("Tou phir aao");
    Song* song2 = new Song("Tare bin");
    Song* song3 = new Song("Issue");

    playlist.addSong(song1);
    playlist.addSong(song2);
    playlist.addSong(song3);

    playlist.allSongs();

    playlist.removeSong(song2);

    cout<<"Updated Playlist: " << endl;
    playlist.allSongs();

    return 0;
}
