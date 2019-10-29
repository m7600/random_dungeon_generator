#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>

#include <MapGenerator.h>

using namespace std;

//GeneralMapInfo constructor---------------------------------------------------------
GeneralMapInfo::GeneralMapInfo()
{
	randrowmax = 80+(rand() %21);
	randcolmax = 80+(rand() %21);

	randrow1 = 40+(rand() %11);
	randrow2a = 20+(rand() %11);
	randrow3a = 20+(rand() %11);

	randcol1a = 20+(rand() %11);
	randcol2a = 20+(rand() %11);
	randcol3a = 40+(rand() %11);
	randcol4a = 60+(rand() %11);
	randcol5a = 60+(rand() %11);

	randrow2b = 60+(rand() %11);
	randrow3b = 60+(rand() %11);

	randcol1b = 20+(rand() %11);
	randcol2b = 20+(rand() %11);
	randcol3b = 40+(rand() %11);
	randcol4b = 60+(rand() %11);
	randcol5b = 60+(rand() %11);

	header = "[header]";
	width = "width=";
	height = "height=";
	tilewidth = "tilewidth=64";
	tileheight = "tileheight=32";
	orientation = "orientation=isometric";
	backgroudcolor = "background_color=0,0,0,255";
	heropos = "hero_pos=6,6";
	music = "music=music/dungeon_theme.ogg";
	tileset = "tileset=tilesetdefs/tileset_dungeon.txt";
	title = "title=New Random Map";

	ofstream mapfile;

	mapfile.open ("outputmap.txt", ofstream::out);
	mapfile << header << endl;
	mapfile << width << randcolmax << endl;
	mapfile << height << randrowmax << endl;
	mapfile << tilewidth << endl;
	mapfile << tileheight << endl;
	mapfile << orientation << endl;
	mapfile << backgroudcolor << endl;
	mapfile << heropos << endl;
	mapfile << music << endl;
	mapfile << tileset << endl;
	mapfile << title << endl;
	mapfile << endl;

    //Tilesets------------------------------------------------------------------
    mapfile << "[tilesets]" << endl;
    mapfile << "tileset=../../../tiled/dungeon/tiled_collision.png,64,32,0,0" << endl;
    mapfile << "tileset=../../../tiled/dungeon/tiled_dungeon.png,64,128,0,0" << endl;
    mapfile << "tileset=../../../tiled/dungeon/set_rules.png,64,32,0,0" << endl;
    mapfile << "tileset=../../../tiled/dungeon/tiled_dungeon_2x2.png,128,64,0,16" << endl;
    mapfile << "tileset=../../../tiled/dungeon/door_left.png,64,128,-16,-8" << endl;
    mapfile << "tileset=../../../tiled/dungeon/door_right.png,64,128,16,-8" << endl;
    mapfile << "tileset=../../../tiled/dungeon/stairs.png,256,256,0,48" << endl;
    mapfile << endl;

    //Background layer---------------------------------------------------
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

    //Close the file
    mapfile.close();
}
//------------------------------------------------------
RestofDungeon::RestofDungeon()
{
	idtopleftcorner = 77;
	idtoprightcorner = 78;
	idbottomleftcorner = 76;
	idbottomrightcorner = 79;

	idtopwall = 65;
	idleftwall = 68;
	idbottomwall = 67;
	idrightwall = 66;

    //Object layer-------------------------------------------------------
	ofstream mapfile;

	mapfile.open ("outputmap.txt", ofstream::app);

    mapfile << "[layer]" << endl;
    mapfile << "type=object" << endl;
    mapfile << "# random size: " << randrowmax << " (height) " << "by " << randcolmax << " (width) "<< endl;
    mapfile << "data=" << endl;

    for (int row = 0; row < randrowmax; row++) {
        for (int col = 0; col < randcolmax; col++) {

	if 
	(
	(row == 1 && col == 1) ||
	(row == 1 && col == randcol1a + 1) ||
	(row == 1 && col == randcol3a + 1) ||
	(row == 1 && col == randcol4a + 1) ||
	(row == randrow2a + 1 && col == 1) ||
	(row == randrow2a + 1 && col == randcol2a + 1) ||
	(row == randrow3a + 1 && col == randcol3a + 1) ||
	(row == randrow3a + 1 && col == randcol5a + 1) ||
	(row == randrow1 + 1 && col == 1) ||
	(row == randrow1 + 1 && col == randcol2b + 1) ||
	(row == randrow1 + 1 && col == randcol3b + 1) ||
	(row == randrow1 + 1 && col == randcol5b + 1) ||
	(row == randrow2b + 1 && col == 1) ||
	(row == randrow2b + 1 && col == randcol1b + 1) ||
	(row == randrow3b + 1 && col == randcol3b + 1) ||
	(row == randrow3b + 1 && col == randcol4b + 1)
	)
	mapfile << idtopleftcorner << ",";

	else if
	(
	(row == 1 && col == randcol1a - 1) ||
	(row == 1 && col == randcol3a - 1) ||
	(row == 1 && col == randcol4a - 1) ||
	(row == 1 && col == randcolmax - 2) ||
	(row == randrow2a + 1 && col == randcol2a - 1) ||
	(row == randrow2a + 1 && col == randcol3a - 1) ||
	(row == randrow3a + 1 && col == randcol5a - 1) ||
	(row == randrow3a + 1 && col == randcolmax - 2) ||
	(row == randrow1 + 1 && col == randcol2b - 1) ||
	(row == randrow1 + 1 && col == randcol3b - 1) ||
	(row == randrow1 + 1 && col == randcol5b - 1) ||
	(row == randrow1 + 1 && col == randcolmax - 2) ||
	(row == randrow2b + 1 && col == randcol1b - 1) ||
	(row == randrow2b + 1 && col == randcol3b - 1) ||
	(row == randrow3b + 1 && col == randcol4b - 1) ||
	(row == randrow3b + 1 && col == randcolmax - 2)
	)
	mapfile << idtoprightcorner << ",";

	else if
	(
	(row == randrow2a - 1 && col == 1) ||
	(row == randrow2a - 1 && col == randcol1a + 1) ||
	(row == randrow3a - 1 && col == randcol3a + 1) ||
	(row == randrow3a - 1 && col == randcol4a + 1) ||
	(row == randrow1 - 1 && col == 1) ||
	(row == randrow1 - 1 && col == randcol2a + 1) ||
	(row == randrow1 - 1 && col == randcol3a + 1) ||
	(row == randrow1 - 1 && col == randcol5a + 1) ||
	(row == randrow2b - 1 && col == 1) ||
	(row == randrow2b - 1 && col == randcol2b + 1) ||
	(row == randrow3b - 1 && col == randcol3b + 1) ||
	(row == randrow3b - 1 && col == randcol5b + 1) ||
	(row == randrowmax - 2 && col == 1) ||
	(row == randrowmax - 2 && col == randcol1b + 1) ||
	(row == randrowmax - 2 && col == randcol3b + 1) ||
	(row == randrowmax - 2 && col == randcol4b + 1)
	)
	mapfile << idbottomleftcorner << ",";

	else if
	(
	(row == randrow2a - 1 && col == randcol1a - 1) ||
	(row == randrow2a - 1 && col == randcol3a - 1) ||
	(row == randrow3a - 1 && col == randcol4a - 1) ||
	(row == randrow3a - 1 && col == randcolmax - 2) ||
	(row == randrow1 - 1 && col == randcol2a - 1) ||
	(row == randrow1 - 1 && col == randcol3a - 1) ||
	(row == randrow1 - 1 && col == randcol5a - 1) ||
	(row == randrow1 - 1 && col == randcolmax - 2) ||
	(row == randrow2b - 1 && col == randcol2b - 1) ||
	(row == randrow2b - 1 && col == randcol3b - 1) ||
	(row == randrow3b - 1 && col == randcol5b - 1) ||
	(row == randrow3b - 1 && col == randcolmax - 2) ||
	(row == randrowmax - 2 && col == randcol1b - 1) ||
	(row == randrowmax - 2 && col == randcol3b - 1) ||
	(row == randrowmax - 2 && col == randcol4b - 1) ||
	(row == randrowmax - 2 && col == randcolmax - 2)
	)
	mapfile << idbottomrightcorner << ",";

	else if 
	(
	(row == 1 && col > 0 && col < randcol1a - 1) ||
	(row == 1 && col > randcol1a && col < randcol3a - 1) ||
	(row == 1 && col > randcol3a && col < randcol4a - 1) ||
	(row == 1 && col > randcol4a && col < randcolmax - 2) ||
	(row == randrow2a + 1 && col > 0 && col < randcol2a - 1) ||
	(row == randrow2a + 1 && col > randcol2a && col < randcol3a - 1) ||
	(row == randrow3a + 1 && col > randcol3a && col < randcol5a - 1) ||
	(row == randrow3a + 1 && col > randcol5a && col < randcolmax - 2) ||
	(row == randrow1 + 1 && col > 0 && col < randcol2b - 1) ||
	(row == randrow1 + 1 && col > randcol2b && col < randcol3b - 1) ||
	(row == randrow1 + 1 && col > randcol3b && col < randcol5b - 1) ||
	(row == randrow1 + 1 && col > randcol5b && col < randcolmax - 2) ||
	(row == randrow2b + 1 && col > 0 && col < randcol1b - 1) ||
	(row == randrow2b + 1 && col > randcol1b && col < randcol3b - 1) ||
	(row == randrow3b + 1 && col > randcol3b && col < randcol4b - 1) ||
	(row == randrow3b + 1 && col > randcol4b && col < randcolmax - 2)
	)
	mapfile << idtopwall << ",";

	else if
	(
	(row > 0 && row < randrow2a - 1 && col == 1) ||
	(row > 0 && row < randrow2a - 1 && col == randcol1a + 1) ||
	(row > 0 && row < randrow3a - 1 && col == randcol3a + 1) ||
	(row > 0 && row < randrow3a - 1 && col == randcol4a + 1) ||
	(row > randrow2a + 1 && row < randrow1 - 1 && col == 1) ||
	(row > randrow2a + 1 && row < randrow1 - 1 && col == randcol2a + 1) ||
	(row > randrow3a + 1 && row < randrow1 - 1 && col == randcol3a + 1) ||
	(row > randrow3a + 1 && row < randrow1 - 1 && col == randcol5a + 1) ||
	(row > randrow1 + 1 && row < randrow2b - 1 && col == 1) ||
	(row > randrow1 + 1 && row < randrow2b - 1 && col == randcol2b + 1) ||
	(row > randrow1 + 1 && row < randrow3b - 1 && col == randcol3b + 1) ||
	(row > randrow1 + 1 && row < randrow3b - 1 && col == randcol5b + 1) ||
	(row > randrow2b + 1 && row < randrowmax - 1 && col == 1) ||
	(row > randrow2b + 1 && row < randrowmax - 1 && col == randcol1b + 1) ||
	(row > randrow3b + 1 && row < randrowmax - 1 && col == randcol3b + 1) ||
	(row > randrow3b + 1 && row < randrowmax - 1 && col == randcol4b + 1)
	)
	mapfile << idleftwall << ",";

	else if
	(
	(row == randrow2a - 1 && col > 0 && col < randcol1a - 1) ||
	(row == randrow2a - 1 && col > randcol1a && col < randcol3a - 1) ||
	(row == randrow3a - 1 && col > randcol3a && col < randcol4a - 1) ||
	(row == randrow3a - 1 && col > randcol4a && col < randcolmax - 2) ||
	(row == randrow1 - 1 && col > 0 && col < randcol2a - 1) ||
	(row == randrow1 - 1 && col > randcol2a && col < randcol3a - 1) ||
	(row == randrow1 - 1 && col > randcol3a && col < randcol5a - 1) ||
	(row == randrow1 - 1 && col > randcol5a && col < randcolmax - 2) ||
	(row == randrow2b - 1 && col > 0 && col < randcol2b - 1) ||
	(row == randrow2b - 1 && col > randcol2b && col < randcol3b - 1) ||
	(row == randrow3b - 1 && col > randcol3b && col < randcol5b - 1) ||
	(row == randrow3b - 1 && col > randcol5b && col < randcolmax - 2) ||
	(row == randrowmax - 2 && col > 0 && col < randcol1b - 1) ||
	(row == randrowmax - 2 && col > randcol1b && col < randcol3b - 1) ||
	(row == randrowmax - 2 && col > randcol3b && col < randcol4b - 1) ||
	(row == randrowmax - 2 && col > randcol4b && col < randcolmax - 2)
	)
	mapfile << idbottomwall << ",";

	else if
	(
	(row > 0 && row < randrow2a - 1 && col == randcol1a - 1) ||
	(row > 0 && row < randrow2a - 1 && col == randcol3a - 1) ||
	(row > 0 && row < randrow3a - 1 && col == randcol4a - 1) ||
	(row > 0 && row < randrow3a - 1 && col == randcolmax - 2) ||
	(row > randrow2a + 1 && row < randrow1 && col == randcol2a - 1) ||
	(row > randrow2a + 1 && row < randrow1 && col == randcol3a - 1) ||
	(row > randrow3a + 1 && row < randrow1 && col == randcol5a - 1) ||
	(row > randrow3a + 1 && row < randrow1 && col == randcolmax - 2) ||
	(row > randrow1 + 1 && row < randrow2b && col == randcol2b - 1) ||
	(row > randrow1 + 1 && row < randrow2b && col == randcol3b - 1) ||
	(row > randrow1 + 1 && row < randrow3b && col == randcol5b - 1) ||
	(row > randrow1 + 1 && row < randrow3b && col == randcolmax - 2) ||
	(row > randrow2b + 1 && row < randrowmax - 1 && col == randcol1b - 1) ||
	(row > randrow2b + 1 && row < randrowmax - 1 && col == randcol3b - 1) ||
	(row > randrow3b + 1 && row < randrowmax - 1 && col == randcol4b - 1) ||
	(row > randrow3b + 1 && row < randrowmax - 1 && col == randcolmax - 2)
	)
	mapfile << idrightwall << ",";


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
