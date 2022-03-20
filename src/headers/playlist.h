#include <bits/stdc++.h>
using namespace std;

class Playlist
{
    private:
        string name, author;
        string date_created;
        string date_modified;
        int duration;
        string play_type;
        vector <string> song_list;
        void set_song_list(vector <string>);
    public:
        Playlist();
        vector <string> get_song_list();
        void set_name(string);
        void set_author(string);
        void set_date_created(string);
        void set_date_modified(string);
        void set_duration(int);
        void set_play_type(string);
        string get_name();
        string get_author();
        string get_date_created();
        string get_date_modified();
        int get_duration();
        string get_song_by_id(int);
        string get_play_type();
        int search_song(string);
        void add_song(string);
        void remove_song(string);
        void rename_song(string, string);
        int song_count();
};