#include "PathSearch.h";
namespace ufl_cap4053
{
	namespace searches
	{
		PathSearch::PathSearch() {
			Solution = vector<Tile const*>();
			Done = false;
		}
		PathSearch::~PathSearch() {
			Solution.clear();
		}

		void PathSearch::load(TileMap* _TileMap) {
			TileMapPtr = _TileMap;
		 }
		 void PathSearch ::initialize(int startRow, int startCol, int goalRow, int goalCol){
			 Solution.clear();
			 Done = false;
			 start = { startRow, startCol };
			 goal = { goalRow, goalCol };

		 }
		 void PathSearch::update(long timeslice) {
			//A* from start to goal 
			Tile* startTile = TileMapPtr->getTile(start.x, start.y);
			Tile* goalTile = TileMapPtr->getTile(goal.x, goal.y);
			
			


			
		 }
		 void PathSearch::shutdown() {
			 Solution.clear();
			 Done = false;
		 }
		 void PathSearch::unload() {
			 Solution.clear();
			 Done = false;
			 TileMapPtr = nullptr;
		 }
		 bool const PathSearch::isDone() {
			return Done;
		 }
		 std::vector<Tile const*> const PathSearch::getSolution() {
			 return Solution;
		 }
	
	}
}  // close namespace ufl_cap4053::searches
