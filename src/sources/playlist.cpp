#include <bits/stdc++.h>
#include "playlist.h"

Playlist::Playlist()
{
    string author = "Author";
    string name = "Name";
    Playlist::set_duration(0);
    Playlist::set_date_created("None");
    Playlist::set_date_modified("None");
    Playlist::set_author(author);
    Playlist::set_name(name);
    Playlist::set_play_type("Normal");
}

string Playlist::get_song_by_id(int id)
{
    return song_list[id];
}

string Playlist::get_date_created()
{
    return date_created;
}

string Playlist::get_date_modified()
{
    return date_modified;
}

int Playlist::get_duration()
{
    return duration;
}

string Playlist::get_play_type()
{
    return play_type;
}

void Playlist::set_song_list(vector <string> new_list)
{
    song_list = new_list;
}

vector <string> Playlist::get_song_list()
{
    return song_list;
}

void Playlist::set_author(string new_author)
{
    author = new_author;
}

void Playlist::set_name(string new_name)
{
    name = new_name;
}

void Playlist::set_date_created(string date)
{
    date_created = date;
}

void Playlist::set_date_modified(string date)
{
    date_modified = date;
}

void Playlist::set_duration(int new_duration)
{
    duration = new_duration;
}

int Playlist::search_song(string search_name)
{
    for (long unsigned int i = 0; i < song_list.size(); i++)
    {
        if (song_list[i] == search_name)
        {
            return i;
        }
    }
    throw std::invalid_argument("404 Song not found!");
}

void Playlist::add_song(string song_name)
{
    song_list.push_back(song_name);
}

void Playlist::remove_song(string song_name)
{
    // Remove song by name
    long unsigned int song_index = search_song(song_name);
    vector <string> new_song_list;
    for (long unsigned int i = 0; i < song_list.size(); i++)
    {
        if (i != song_index) new_song_list.push_back(song_list[i]);
    }
    set_song_list(new_song_list);
}

void Playlist::rename_song(string song_name, string new_song_name)
{
    long unsigned int index = search_song(song_name);
    vector <string> new_song_list;
    for (long unsigned int i = 0; i < song_list.size(); i++)
    {
        if (i != index) new_song_list.push_back(song_list[i]);
        else new_song_list.push_back(new_song_name);
    }
    set_song_list(new_song_list);
}

int Playlist::song_count()
{
    return song_list.size();
}

string Playlist::get_name()
{
    return name;
}

string Playlist::get_author()
{
    return author;
}

void Playlist::set_play_type(string new_play_type)
{
    vector <string> types;
    types.push_back("Random");
    types.push_back("Normal");
    types.push_back("User");
    for (long unsigned int i = 0; i < types.size() + 1; i++)
    {
        if (i == types.size()) throw invalid_argument("Wrong play type!");
        if (types[i] == new_play_type) break;
    }
    play_type = new_play_type;
}