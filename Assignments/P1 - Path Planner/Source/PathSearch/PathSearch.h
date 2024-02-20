#include "../platform.h" // This file will make exporting DLL symbols simpler for students.
#include "../Framework/TileSystem/TileMap.h"
using namespace std;
namespace ufl_cap4053
{
	namespace searches
	{
		class PathSearch
		{
			struct point
			{
				int x;
				int y;
			};

		// CLASS DECLARATION GOES HERE
			public:
				

				DLLEXPORT PathSearch(); // EX: DLLEXPORT required for public methods - see platform.h
				DLLEXPORT ~PathSearch();
				DLLEXPORT void load(TileMap* _TileMap);
				DLLEXPORT void initialize(int startRow, int startCol, int goalRow, int goalCol);
				DLLEXPORT void update(long timeslice);
				DLLEXPORT void shutdown();
				DLLEXPORT void unload();
				DLLEXPORT bool const isDone(); 
				DLLEXPORT vector<Tile const*> const getSolution();
		private: 
			TileMap* TileMapPtr;
			vector<Tile const*> Solution;
			bool Done;
			point start;
			point goal;
		};
	}
}  // close namespace ufl_cap4053::searches
