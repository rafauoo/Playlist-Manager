#include <catch2/catch_all.hpp>
#include "playlist.h"

TEST_CASE("Create Playlist")
{
}

TEST_CASE("Setters and getters")
{
    SECTION("Set Author")
    {
        Playlist pl;
        CHECK(pl.get_author() == "Author");
        pl.set_author("Andrew");
        CHECK(pl.get_author() == "Andrew");
        pl.set_author("");
        CHECK(pl.get_author() == "");
    }
    SECTION("Set Name")
    {
        Playlist pl;
        CHECK(pl.get_name() == "Name");
        pl.set_name("Chill");
        CHECK(pl.get_name() == "Chill");
        pl.set_name("");
        CHECK(pl.get_name() == "");
    }
    SECTION("Set Duration")
    {
        Playlist pl;
        CHECK(pl.get_duration() == 0);
        pl.set_duration(3);
        CHECK(pl.get_duration() == 3);
        pl.set_duration(5);
        CHECK(pl.get_duration() == 5);
    }
    SECTION("Set Play Type")
    {
        Playlist pl;
        CHECK(pl.get_play_type() == "Normal");
        pl.set_play_type("User");
        CHECK(pl.get_play_type() == "User");
        pl.set_play_type("Random");
        CHECK(pl.get_play_type() == "Random");
        REQUIRE_THROWS_AS(pl.set_play_type("Other"), std::invalid_argument);
    }
    SECTION("Set Date Created")
    {
        Playlist pl;
        CHECK(pl.get_date_created() == "None");
        pl.set_date_created("17-03-2022");
        CHECK(pl.get_date_created() == "17-03-2022");
        pl.set_date_created("29-03-2023");
        CHECK(pl.get_date_created() == "29-03-2023");
    }
    SECTION("Set Date Modified")
    {
        Playlist pl;
        CHECK(pl.get_date_modified() == "None");
        pl.set_date_modified("10-03-2022");
        CHECK(pl.get_date_modified() == "10-03-2022");
        pl.set_date_modified("19-03-2023");
        CHECK(pl.get_date_modified() == "19-03-2023");
    }
}

TEST_CASE("Song Methods")
{
    SECTION("Add Song")
    {
        Playlist pl;
        CHECK(pl.song_count() == 0);
        pl.add_song("Song 1");
        CHECK(pl.song_count() == 1);
        pl.add_song("Song 2");
        CHECK(pl.song_count() == 2);
    }
    SECTION("Remove Song and Song Count")
    {
        Playlist pl;
        CHECK(pl.song_count() == 0);
        pl.add_song("Song 1");
        CHECK(pl.song_count() == 1);
        pl.add_song("Song 2");
        CHECK(pl.song_count() == 2);
        pl.remove_song("Song 1");
        CHECK(pl.song_count() == 1);
        pl.remove_song("Song 2");
        CHECK(pl.song_count() == 0);
        REQUIRE_THROWS_AS(pl.remove_song("Song 3"), std::invalid_argument);
    }
    SECTION("Search Song by name")
    {
        Playlist pl;
        pl.add_song("Song 1");
        pl.add_song("Song 2");
        CHECK(pl.search_song("Song 1") == 0);
        CHECK(pl.search_song("Song 2") == 1);
        REQUIRE_THROWS_AS(pl.search_song("Song 3"), std::invalid_argument);
    }
    SECTION("Rename Song")
    {
        Playlist pl;
        pl.add_song("Song 1");
        CHECK(pl.song_count() == 1);
        CHECK(pl.search_song("Song 1") == 0);
        pl.rename_song("Song 1", "Another Song");
        CHECK(pl.search_song("Another Song") == 0);
        REQUIRE_THROWS_AS(pl.rename_song("Song 1", "Another Song"), std::invalid_argument);
    }
    SECTION("Search song by id")
    {
        Playlist pl;
        pl.add_song("Song 1");
        CHECK(pl.song_count() == 1);
        CHECK(pl.get_song_by_id(0) == "Song 1");
        pl.add_song("Song 2");
        CHECK(pl.song_count() == 2);
        CHECK(pl.get_song_by_id(1) == "Song 2");
        pl.add_song("Song 3");
        CHECK(pl.song_count() == 3);
        CHECK(pl.get_song_by_id(2) == "Song 3");
        REQUIRE_THROWS_AS(pl.get_song_by_id(10), std::invalid_argument);
    }
}