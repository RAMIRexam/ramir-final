#ifndef PATH_HPP
#define PATH_HPP

#include "Blob.hpp"
#include "Definitions.hpp"

#include <vector>

using namespace std;

class Path
{
	public:
		Path(Blob * blob, int pathLife = 10);
		~Path();

		void addBlob(Blob *blob);
		Blob *getBlob(int index = 0);
		Blob *getLastBlob();

		int getNrBlobs();
		vector<Blob *> * getBlobVector();

		void setLife(int life);
		bool isAlive();

		void addHeading(Point2f heading);
		Point2f getHeading();


		void addArea(int area);
		int getMeanArea();


		bool isCountedCheck();
		void setCounted(bool counted);		//will be called with true when the blob passes the eeline

		

		//For TRACKING_CC
		int get_staSOL();					//get start side of line
		void set_staSOL(int lineSide);		//set start side of line
				
		int get_curSOL();					//get current side of line
		void set_curSOL(int lineSide);		//set current side of line

		bool processed;						//DEBUG, Used in TRACKING_CC to make shure the path has been processed in some way at the end of the code

	private:
		Point2f headingSum;
		int areaSum;

		vector<Blob *> *blobs;
		Blob *ptrLastBlob;

		int nLife;
		int remainingLife;

		bool isCounted;							//True if the pedestrian has passed the countingline

		int curSOL;								//current Side Of Line, which side of the line the object currently is
		int staSOL;								//start Side Of Line, which side of the line the object was when it was first detected


};

#endif // !PATH_HPP


