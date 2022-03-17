#include <catch2/catch_all.hpp>
#include "playlist.h"

TEST_CASE("Create Playlist")
{
    Playlist pl("New Playlist", "Author");
    CHECK(pl.get_author() == "Author");
    CHECK(pl.get_name() == "New Playlist");
    Playlist pl2("AAA", "CCC");
    CHECK(pl2.get_author() == "CCC");
    CHECK(pl2.get_name() == "AAA");
}

TEST_CASE("Setters")
{
    SECTION("Set Author")
    {
        Playlist pl("New Playlist", "Author");
        CHECK(pl.get_author() == "Author");
        pl.set_author("Andrew");
        CHECK(pl.get_author() == "Andrew");
        pl.set_author("");
        CHECK(pl.get_author() == "");
    }
    SECTION("Set Name")
    {
        Playlist pl("New Playlist", "Author");
        CHECK(pl.get_name() == "New Playlist");
        pl.set_name("Chill");
        CHECK(pl.get_name() == "Chill");
        pl.set_name("");
        CHECK(pl.get_name() == "");
    }
    SECTION("Set Duration")
    {
        Playlist pl("New Playlist", "Author");
        CHECK(pl.get_duration() == 0);
        pl.set_duration(3);
        CHECK(pl.get_duration() == 3);
        pl.set_duration(5);
        CHECK(pl.get_duration() == 5);
    }
    SECTION("Set Play Type")
    {
        Playlist pl("New Playlist", "Author");
        CHECK(pl.get_play_type() == "Normal");
        pl.set_play_type("User");
        CHECK(pl.get_play_type() == "User");
        pl.set_play_type("Random");
        CHECK(pl.get_play_type() == "Random");
        REQUIRE_THROWS_AS(pl.set_play_type("Other"), std::invalid_argument);
    }
    SECTION("Set Date Created")
    {
        Playlist pl("New Playlist", "Author");
        CHECK(pl.get_date_created() == "");
        pl.set_date_created("17-03-2022");
        CHECK(pl.get_date_created() == "17-03-2022");
        pl.set_date_created("29-03-2023");
        CHECK(pl.get_date_created() == "29-03-2023");
    }
    SECTION("Set Date Modified")
    {
        Playlist pl("New Playlist", "Author");
        CHECK(pl.get_date_modified() == "");
        pl.set_date_modified("10-03-2022");
        CHECK(pl.get_date_modified() == "10-03-2022");
        pl.set_date_modified("19-03-2023");
        CHECK(pl.get_date_modified() == "19-03-2023");
    }
}

TEST_CASE("Song Methods")
{
    SECTION("Song Count")
    {
        Playlist pl("New Playlist", "Author");
        CHECK(pl.song_count() == 0);
    }
}