#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

//-------------------------------------------------------------------------
class GeneralMapInfo {
	public:
	int randrowmax;
	int randcolmax;

	int randrow1;
	int randrow2a;
	int randrow3a;

	int randcol1a;
	int randcol2a;
	int randcol3a;
	int randcol4a;
	int randcol5a;

	int randrow2b;
	int randrow3b;

	int randcol1b;
	int randcol2b;
	int randcol3b;
	int randcol4b;
	int randcol5b;

	string header;
	string width;
	string height;
	string tilewidth;
	string tileheight;
	string orientation;
	string backgroudcolor;
	string heropos;
	string music;
	string tileset;
	string title;

	GeneralMapInfo ();
};
//-------------------------------------------------------------------------
class RestofDungeon : public GeneralMapInfo {
	public:
	int idtopleftcorner;
	int idtoprightcorner;
	int idbottomleftcorner;
	int idbottomrightcorner;
	int idtopwall;
	int idleftwall;
	int idbottomwall;
	int idrightwall;

	RestofDungeon ();
};

#endif // MAPGENERATOR_H
