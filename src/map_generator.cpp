#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "map_generator.h"
using namespace std;

void MapTextFile () {
    // Random number generator for the size of the map, as well as the rows and colums 
    srand((unsigned int)time(0));
    int randrowmax = 80+(rand() %21);
    int randcolmax = 80+(rand() %21);

    int randrow1 = 40+(rand() %11);
    int randrow2a = 20+(rand() %11);
    int randrow3a = 20+(rand() %11);

    int randcol1a = 20+(rand() %11);
    int randcol2a = 20+(rand() %11);
    int randcol3a = 40+(rand() %11);
    int randcol4a = 60+(rand() %11);
    int randcol5a = 60+(rand() %11);

    int randrow2b = 60+(rand() %11);
    int randrow3b = 60+(rand() %11);

    int randcol1b = 20+(rand() %11);
    int randcol2b = 20+(rand() %11);
    int randcol3b = 40+(rand() %11);
    int randcol4b = 60+(rand() %11);
    int randcol5b = 60+(rand() %11);

    //Name of the map's text file
    ofstream mapfile;
    mapfile.open ("outputmap.txt");

    //Header
    mapfile << "[header]" << endl;
    mapfile << "width=" << randcolmax << endl;
    mapfile << "height=" << randrowmax << endl;
    mapfile << "tilewidth=64" << endl;
    mapfile << "tileheight=32" << endl;
    mapfile << "orientation=isometric" << endl;
    mapfile << "background_color=0,0,0,255" << endl;
    mapfile << "hero_pos=6,6" << endl;
    mapfile << "music=music/dungeon_theme.ogg" << endl;
    mapfile << "tileset=tilesetdefs/tileset_dungeon.txt" << endl;
    mapfile << "title=New Random Map" << endl;
    mapfile << endl;

    //Tilesets
    mapfile << "[tilesets]" << endl;
    mapfile << "tileset=../../../tiled/dungeon/tiled_collision.png,64,32,0,0" << endl;
    mapfile << "tileset=../../../tiled/dungeon/tiled_dungeon.png,64,128,0,0" << endl;
    mapfile << "tileset=../../../tiled/dungeon/set_rules.png,64,32,0,0" << endl;
    mapfile << "tileset=../../../tiled/dungeon/tiled_dungeon_2x2.png,128,64,0,16" << endl;
    mapfile << "tileset=../../../tiled/dungeon/door_left.png,64,128,-16,-8" << endl;
    mapfile << "tileset=../../../tiled/dungeon/door_right.png,64,128,16,-8" << endl;
    mapfile << "tileset=../../../tiled/dungeon/stairs.png,256,256,0,48" << endl;
    mapfile << endl;

    //Background layer
    mapfile << "[layer]" << endl;
    mapfile << "type=background" << endl;
    mapfile << "# random size: " << randrowmax << " (height) " << "by " << randcolmax << " (width) "<< endl;
    mapfile << "data=" << endl;

    for (int row = 0; row < randrowmax; row++) {
        for (int col = 0; col < randcolmax; col++) {

        if (row == 0 || row == randrowmax - 1 || col == 0 || col == randcolmax - 1)
            mapfile << 0 << ",";

        else if (
    // Dungeon area A
    (row == randrow1) || // main row
    (row == randrow2a && col < randcol3a) ||
    (row == randrow3a && col > randcol3a) ||

    (row < randrow2a && col == randcol1a) ||
    (row > randrow2a && row < randrow1 && col == randcol2a) ||

    (row < randrow1 && col == randcol3a) || // main col A

    (row < randrow3a && col == randcol4a) ||
    (row > randrow3a && row < randrow1 && col == randcol5a) ||

    // Dungeon area B
    (row == randrow2b && col < randcol3b) ||
    (row == randrow3b && col > randcol3b) ||

    (row > randrow2b && col == randcol1b) ||
    (row < randrow2b && row > randrow1 && col == randcol2b) ||

    (row > randrow1 && col == randcol3b) || // main col B

    (row > randrow3b && col == randcol4b) ||
    (row < randrow3b && row > randrow1 && col == randcol5b)
    )
            mapfile << 0 << ",";

        else
            mapfile << 16+(rand() %4) << ","; //id of the floor tiles: 16-19
	}
        mapfile << endl;
    }
    mapfile << endl;

// Object layer
    mapfile << "[layer]" << endl;
    mapfile << "type=object" << endl;
    mapfile << "# random size: " << randrowmax << " (height) " << "by " << randcolmax << " (width) "<< endl;
    mapfile << "data=" << endl;

        //North corner wall id: 77
        //NE side wall id: 65
        //NW side wall id: 68
        //West corner wall id: 76
        //East corner wall id: 78
        //SE wall id: 66
        //SW wall id: 67
        //South corner wall id: 79

    for (int row = 0; row < randrowmax; row++) {
        for (int col = 0; col < randcolmax; col++) {

        // room 1
        // corners room 1
            if (row == 1 && col == 1)
                mapfile << 77 << ",";
            else if (row == 0 + 1 && col == randcol1a - 1)
                mapfile << 78 << ",";
            else if (row == randrow2a - 1 && col == 1)
                mapfile << 76 << ",";
            else if (row == randrow2a - 1 && col == randcol1a - 1)
                mapfile << 79 << ",";
        // walls room 1
            else if (row == 1 && col > 0 && col < randcol1a - 1) //NE side wall
                mapfile << 65 << ",";
            else if (row > 0 && row < randrow2a - 1 && col == 1) //NW side wall
                mapfile << 68 << ",";
            else if (row == randrow2a - 1 && col > 0 && col < randcol1a - 1) //SW wall
                mapfile << 67 << ",";
            else if (row > 0 && row < randrow2a - 1 && col == randcol1a - 1) //SE wall
                mapfile << 66 << ",";

        // room 2
        // corners room 2
            else if (row == 1 && col == randcol1a + 1)
                mapfile << 77 << ",";
            else if (row == 1 && col == randcol3a - 1)
                mapfile << 78 << ",";
            else if (row == randrow2a - 1 && col == randcol1a + 1)
                mapfile << 76 << ",";
            else if (row == randrow2a - 1 && col == randcol3a - 1)
                mapfile << 79 << ",";
        // walls room 2
            else if (row == 1 && col > randcol1a && col < randcol3a - 1) //NE side wall
                mapfile << 65 << ",";
            else if (row > 0 && row < randrow2a - 1 && col == randcol1a + 1) //NW side wall
                mapfile << 68 << ",";
            else if (row == randrow2a - 1 && col > randcol1a && col < randcol3a - 1) //SW wall
                mapfile << 67 << ",";
            else if (row > 0 && row < randrow2a - 1 && col == randcol3a - 1) //SE wall
                mapfile << 66 << ",";

        // room 3
        // corners room 3
            else if (row == 1 && col == randcol3a + 1)
                mapfile << 77 << ",";
            else if (row == 1 && col == randcol4a - 1)
                mapfile << 78 << ",";
            else if (row == randrow3a - 1 && col == randcol3a + 1)
                mapfile << 76 << ",";
            else if (row == randrow3a - 1 && col == randcol4a - 1)
                mapfile << 79 << ",";
        // walls room 3
            else if (row == 1 && col > randcol3a && col < randcol4a - 1) //NE side wall
                mapfile << 65 << ",";
            else if (row > 0 && row < randrow3a - 1 && col == randcol3a + 1) //NW side wall
                mapfile << 68 << ",";
            else if (row == randrow3a - 1 && col > randcol3a && col < randcol4a - 1) //SW wall
                mapfile << 67 << ",";
            else if (row > 0 && row < randrow3a - 1 && col == randcol4a - 1) //SE wall
                mapfile << 66 << ",";

        // room 4
        // corners room 4
            else if (row == 1 && col == randcol4a + 1)
                mapfile << 77 << ",";
            else if (row == 1 && col == randcolmax - 2)
                mapfile << 78 << ",";
            else if (row == randrow3a - 1 && col == randcol4a + 1)
                mapfile << 76 << ",";
            else if (row == randrow3a - 1 && col == randcolmax - 2)
                mapfile << 79 << ",";
        // walls room 4
            else if (row == 1 && col > randcol4a && col < randcolmax - 2) //NE side wall
                mapfile << 65 << ",";
            else if (row > 0 && row < randrow3a - 1 && col == randcol4a + 1) //NW side wall
                mapfile << 68 << ",";
            else if (row == randrow3a - 1 && col > randcol4a && col < randcolmax - 2) //SW wall
                mapfile << 67 << ",";
            else if (row > 0 && row < randrow3a - 1 && col == randcolmax - 2) //SE wall
                mapfile << 66 << ",";

        // room 5
        // corners room 5
            else if (row == randrow2a + 1 && col == 1)
                mapfile << 77 << ",";
            else if (row == randrow2a + 1 && col == randcol2a - 1)
                mapfile << 78 << ",";
            else if (row == randrow1 - 1 && col == 1)
                mapfile << 76 << ",";
            else if (row == randrow1 - 1 && col == randcol2a - 1)
                mapfile << 79 << ",";
        // walls room 5
            else if (row == randrow2a + 1 && col > 0 && col < randcol2a - 1) //NE side wall
                mapfile << 65 << ",";
            else if (row > randrow2a + 1 && row < randrow1 - 1 && col == 1) //NW side wall
                mapfile << 68 << ",";
            else if (row == randrow1 - 1 && col > 0 && col < randcol2a - 1) //SW wall
                mapfile << 67 << ",";
            else if (row > randrow2a + 1 && row < randrow1 && col == randcol2a - 1) //SE wall
                mapfile << 66 << ",";

        // room 6
        // corners room 6
            else if (row == randrow2a + 1 && col == randcol2a + 1)
                mapfile << 77 << ",";
            else if (row == randrow2a + 1 && col == randcol3a - 1)
                mapfile << 78 << ",";
            else if (row == randrow1 - 1 && col == randcol2a + 1)
                mapfile << 76 << ",";
            else if (row == randrow1 - 1 && col == randcol3a - 1)
                mapfile << 79 << ",";
        // walls room 6
            else if (row == randrow2a + 1 && col > randcol2a && col < randcol3a - 1) //NE side wall
                mapfile << 65 << ",";
            else if (row > randrow2a + 1 && row < randrow1 - 1 && col == randcol2a + 1) //NW side wall
                mapfile << 68 << ",";
            else if (row == randrow1 - 1 && col > randcol2a && col < randcol3a - 1) //SW wall
                mapfile << 67 << ",";
            else if (row > randrow2a + 1 && row < randrow1 && col == randcol3a - 1) //SE wall
                mapfile << 66 << ",";

        // room 7
        // corners room 7
            else if (row == randrow3a + 1 && col == randcol3a + 1)
                mapfile << 77 << ",";
            else if (row == randrow3a + 1 && col == randcol5a - 1)
                mapfile << 78 << ",";
            else if (row == randrow1 - 1 && col == randcol3a + 1)
                mapfile << 76 << ",";
            else if (row == randrow1 - 1 && col == randcol5a - 1)
                mapfile << 79 << ",";
        // walls room 7
            else if (row == randrow3a + 1 && col > randcol3a && col < randcol5a - 1) //NE side wall
                mapfile << 65 << ",";
            else if (row > randrow3a + 1 && row < randrow1 - 1 && col == randcol3a + 1) //NW side wall
                mapfile << 68 << ",";
            else if (row == randrow1 - 1 && col > randcol3a && col < randcol5a - 1) //SW wall
                mapfile << 67 << ",";
            else if (row > randrow3a + 1 && row < randrow1 && col == randcol5a - 1) //SE wall
                mapfile << 66 << ",";

        // room 8
        // corners room 8
            else if (row == randrow3a + 1 && col == randcol5a + 1)
                mapfile << 77 << ",";
            else if (row == randrow3a + 1 && col == randcolmax - 2)
                mapfile << 78 << ",";
            else if (row == randrow1 - 1 && col == randcol5a + 1)
                mapfile << 76 << ",";
            else if (row == randrow1 - 1 && col == randcolmax - 2)
                mapfile << 79 << ",";
        // walls room 8
            else if (row == randrow3a + 1 && col > randcol5a && col < randcolmax - 2) //NE side wall
                mapfile << 65 << ",";
            else if (row > randrow3a + 1 && row < randrow1 - 1 && col == randcol5a + 1) //NW side wall
                mapfile << 68 << ",";
            else if (row == randrow1 - 1 && col > randcol5a && col < randcolmax - 2) //SW wall
                mapfile << 67 << ",";
            else if (row > randrow3a + 1 && row < randrow1 && col == randcolmax - 2) //SE wall
                mapfile << 66 << ",";

        // room 9
        // corners room 9
            else if (row == randrow1 + 1 && col == 1)
                mapfile << 77 << ",";
            else if (row == randrow1 + 1 && col == randcol2b - 1)
                mapfile << 78 << ",";
            else if (row == randrow2b - 1 && col == 1)
                mapfile << 76 << ",";
            else if (row == randrow2b - 1 && col == randcol2b - 1)
                mapfile << 79 << ",";
        // walls room 9
            else if (row == randrow1 + 1 && col > 0 && col < randcol2b - 1) //NE side wall
                mapfile << 65 << ",";
            else if (row > randrow1 + 1 && row < randrow2b - 1 && col == 1) //NW side wall
                mapfile << 68 << ",";
            else if (row == randrow2b - 1 && col > 0 && col < randcol2b - 1) //SW wall
                mapfile << 67 << ",";
            else if (row > randrow1 + 1 && row < randrow2b && col == randcol2b - 1) //SE wall
                mapfile << 66 << ",";

        // room 10
        // corners room 10
            else if (row == randrow1 + 1 && col == randcol2b + 1)
                mapfile << 77 << ",";
            else if (row == randrow1 + 1 && col == randcol3b - 1)
                mapfile << 78 << ",";
            else if (row == randrow2b - 1 && col == randcol2b + 1)
                mapfile << 76 << ",";
            else if (row == randrow2b - 1 && col == randcol3b - 1)
                mapfile << 79 << ",";
        // walls room 10
            else if (row == randrow1 + 1 && col > randcol2b && col < randcol3b - 1) //NE side wall
                mapfile << 65 << ",";
            else if (row > randrow1 + 1 && row < randrow2b - 1 && col == randcol2b + 1) //NW side wall
                mapfile << 68 << ",";
            else if (row == randrow2b - 1 && col > randcol2b && col < randcol3b - 1) //SW wall
                mapfile << 67 << ",";
            else if (row > randrow1 + 1 && row < randrow2b && col == randcol3b - 1) //SE wall
                mapfile << 66 << ",";

        // room 11
        // corners room 11
            else if (row == randrow1 + 1 && col == randcol3b + 1)
                mapfile << 77 << ",";
            else if (row == randrow1 + 1 && col == randcol5b - 1)
                mapfile << 78 << ",";
            else if (row == randrow3b - 1 && col == randcol3b + 1)
                mapfile << 76 << ",";
            else if (row == randrow3b - 1 && col == randcol5b - 1)
                mapfile << 79 << ",";
        // walls room 11
            else if (row == randrow1 + 1 && col > randcol3b && col < randcol5b - 1) //NE side wall
                mapfile << 65 << ",";
            else if (row > randrow1 + 1 && row < randrow3b - 1 && col == randcol3b + 1) //NW side wall
                mapfile << 68 << ",";
            else if (row == randrow3b - 1 && col > randcol3b && col < randcol5b - 1) //SW wall
                mapfile << 67 << ",";
            else if (row > randrow1 + 1 && row < randrow3b && col == randcol5b - 1) //SE wall
                mapfile << 66 << ",";

        // room 12
        // corners room 12
            else if (row == randrow1 + 1 && col == randcol5b + 1)
                mapfile << 77 << ",";
            else if (row == randrow1 + 1 && col == randcolmax - 2)
                mapfile << 78 << ",";
            else if (row == randrow3b - 1 && col == randcol5b + 1)
                mapfile << 76 << ",";
            else if (row == randrow3b - 1 && col == randcolmax - 2)
                mapfile << 79 << ",";
        // walls room 12
            else if (row == randrow1 + 1 && col > randcol5b && col < randcolmax - 2) //NE side wall
                mapfile << 65 << ",";
            else if (row > randrow1 + 1 && row < randrow3b - 1 && col == randcol5b + 1) //NW side wall
                mapfile << 68 << ",";
            else if (row == randrow3b - 1 && col > randcol5b && col < randcolmax - 2) //SW wall
                mapfile << 67 << ",";
            else if (row > randrow1 + 1 && row < randrow3b && col == randcolmax - 2) //SE wall
                mapfile << 66 << ",";

        // room 13
        // corners room 13
            else if (row == randrow2b + 1 && col == 1)
                mapfile << 77 << ",";
            else if (row == randrow2b + 1 && col == randcol1b - 1)
                mapfile << 78 << ",";
            else if (row == randrowmax - 2 && col == 1)
                mapfile << 76 << ",";
            else if (row == randrowmax - 2 && col == randcol1b - 1)
                mapfile << 79 << ",";
        // walls room 13
            else if (row == randrow2b + 1 && col > 0 && col < randcol1b - 1) //NE side wall
                mapfile << 65 << ",";
            else if (row > randrow2b + 1 && row < randrowmax - 1 && col == 1) //NW side wall
                mapfile << 68 << ",";
            else if (row == randrowmax - 2 && col > 0 && col < randcol1b - 1) //SW wall
                mapfile << 67 << ",";
            else if (row > randrow2b + 1 && row < randrowmax - 1 && col == randcol1b - 1) //SE wall
                mapfile << 66 << ",";

        // room 14
        // corners room 14
            else if (row == randrow2b + 1 && col == randcol1b + 1)
                mapfile << 77 << ",";
            else if (row == randrow2b + 1 && col == randcol3b - 1)
                mapfile << 78 << ",";
            else if (row == randrowmax - 2 && col == randcol1b + 1)
                mapfile << 76 << ",";
            else if (row == randrowmax - 2 && col == randcol3b - 1)
                mapfile << 79 << ",";
        // walls room 14
            else if (row == randrow2b + 1 && col > randcol1b && col < randcol3b - 1) //NE side wall
                mapfile << 65 << ",";
            else if (row > randrow2b + 1 && row < randrowmax - 1 && col == randcol1b + 1) //NW side wall
                mapfile << 68 << ",";
            else if (row == randrowmax - 2 && col > randcol1b && col < randcol3b - 1) //SW wall
                mapfile << 67 << ",";
            else if (row > randrow2b + 1 && row < randrowmax - 1 && col == randcol3b - 1) //SE wall
                mapfile << 66 << ",";

        // room 15
        // corners room 15
            else if (row == randrow3b + 1 && col == randcol3b + 1)
                mapfile << 77 << ",";
            else if (row == randrow3b + 1 && col == randcol4b - 1)
                mapfile << 78 << ",";
            else if (row == randrowmax - 2 && col == randcol3b + 1)
                mapfile << 76 << ",";
            else if (row == randrowmax - 2 && col == randcol4b - 1)
                mapfile << 79 << ",";
        // walls room 15
            else if (row == randrow3b + 1 && col > randcol3b && col < randcol4b - 1) //NE side wall
                mapfile << 65 << ",";
            else if (row > randrow3b + 1 && row < randrowmax - 1 && col == randcol3b + 1) //NW side wall
                mapfile << 68 << ",";
            else if (row == randrowmax - 2 && col > randcol3b && col < randcol4b - 1) //SW wall
                mapfile << 67 << ",";
            else if (row > randrow3b + 1 && row < randrowmax - 1 && col == randcol4b - 1) //SE wall
                mapfile << 66 << ",";

        // room 16
        // corners room 16
            else if (row == randrow3b + 1 && col == randcol4b + 1)
                mapfile << 77 << ",";
            else if (row == randrow3b + 1 && col == randcolmax - 2)
                mapfile << 78 << ",";
            else if (row == randrowmax - 2 && col == randcol4b + 1)
                mapfile << 76 << ",";
            else if (row == randrowmax - 2 && col == randcolmax - 2)
                mapfile << 79 << ",";
        // walls room 16
            else if (row == randrow3b + 1 && col > randcol4b && col < randcolmax - 2) //NE side wall
                mapfile << 65 << ",";
            else if (row > randrow3b + 1 && row < randrowmax - 1 && col == randcol4b + 1) //NW side wall
                mapfile << 68 << ",";
            else if (row == randrowmax - 2 && col > randcol4b && col < randcolmax - 2) //SW wall
                mapfile << 67 << ",";
            else if (row > randrow3b + 1 && row < randrowmax - 1 && col == randcolmax - 2) //SE wall
                mapfile << 66 << ",";

            // fill the rest with empty tiles
            else
                mapfile << 0 << ",";
	    }
        mapfile << endl;
        }
    mapfile << endl;

    //Collision layer
    mapfile << "[layer]" << endl;
    mapfile << "type=collision" << endl;
    mapfile << "# random size: " << randrowmax << " (height) " << "by " << randcolmax << " (width) "<< endl;
    mapfile << "data=" << endl;

    for (int row = 0; row < randrowmax; row++) {
        for (int col = 0; col < randcolmax; col++) {
        if (row == 0 || row == randrowmax - 1 || col == 0 || col == randcolmax - 1)
            mapfile << 1 << ",";

        else if (
    // Dungeon area A
//    (row < randrow1 + 2 && row > randrow1 - 3) || // main row
    (row == randrow1) || // main row
    (row == randrow2a && col < randcol3a) ||
    (row == randrow3a && col > randcol3a) ||

    (row < randrow2a && col == randcol1a) ||
    (row > randrow2a && row < randrow1 && col == randcol2a) ||

    (row < randrow1 && col == randcol3a) || // main col A

    (row < randrow3a && col == randcol4a) ||
    (row > randrow3a && row < randrow1 && col == randcol5a) ||

    // Dungeon area B
    (row == randrow2b && col < randcol3b) ||
    (row == randrow3b && col > randcol3b) ||

    (row > randrow2b && col == randcol1b) ||
    (row < randrow2b && row > randrow1 && col == randcol2b) ||

    (row > randrow1 && col == randcol3b) || // main col B

    (row > randrow3b && col == randcol4b) ||
    (row < randrow3b && row > randrow1 && col == randcol5b)
    )
            mapfile << 1 << ",";

        else
            mapfile << 0 << ",";
	}
        mapfile << endl;
    }
    mapfile << endl;

    //Event
    mapfile << "[event]" << endl;
    mapfile << "# Name (example: Wind sound)" << endl;
    mapfile << "type=event" << endl;
    mapfile << "location=0,0,1,1" << endl;
    mapfile << "activate=on_load" << endl;
    mapfile << "soundfx=soundfx/environment/cave_wind_loop.ogg" << endl;
    mapfile << endl;

    //Enemy
    mapfile << "[enemy]" << endl;
    mapfile << "type=enemy" << endl;
    mapfile << "location=5,5,1,1" << endl;
    mapfile << "category=skeleton_mage" << endl;
    mapfile << "direction=7" << endl;
    mapfile << "level=3" << endl;
    mapfile << "number=1" << endl;
    mapfile << "wander_radius=0" << endl;
    mapfile << endl;

    //Close the file
    mapfile.close();
}
