#include "Data.hpp"


//===============CONSTRUCTOR DESTRUCTOR==================


Data::Data()
{
	upCnt = 0;
	downCnt = 0;

	nImageCnt = 0;
	
	frameBlobs = nullptr;
	images = new vector<Mat *>();
	paths = new vector<Path *>();
}


Data::~Data()
{
	for (unsigned int i = 0; i < images->size(); i++)
	{
		images->at(i);
	}
	delete images;

	for (unsigned int i = 0; i < paths->size(); i++)
	{
		delete paths->at(i);
	}
	delete paths;

	for (unsigned int i = 0; i < frameBlobs->size(); i++)
	{
		delete frameBlobs->at(i);
	}
	delete frameBlobs;
}


//========================================================


void Data::addImage(Mat * img)
{
	images->push_back(img);
}


Mat * Data::getImage(int index)
{
	return images->at(index);
}


Mat * Data::getLastImage()
{
	return images->at(images->size() - 1);
}


void Data::clearImages()
{
	for (unsigned int i = 0; i < images->size(); i++)
	{
		images->at(i)->release();
	}

	images->clear();
}


//======================================================

void Data::addPath(Path * path)
{
	paths->push_back(path);
}

void Data::removeAllPaths() 
{
	delete paths;
	paths = new vector<Path*>;
}


vector<Path*>* Data::getPathVector()
{
	return paths;
}


//===============================================
void Data::setFrameBlobVector(vector<Blob *> * blobVector)
{
	frameBlobs = blobVector;
}

vector<Blob*>* Data::getFrameBlobVector()
{
	return frameBlobs;
}

void Data::clearFrameBlobVector()
{
	frameBlobs->clear();
}
//================================================



