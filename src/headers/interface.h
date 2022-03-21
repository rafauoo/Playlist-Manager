#include <bits/stdc++.h>
using namespace std;

class Interface
{
    private:
        int choice;
        Playlist playlist;
    public:
        Interface(Playlist&);
        bool breaks;
        void clear();
        void back();
        void write_menu();
        void input();
        void manage_songs_menu();
        void write_choice();
        void write_playlist();
        void write_manage_songs_menu();
};