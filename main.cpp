#include "Body.h"
#include "Physics.h"
#include "Graphics.h"
#include "Octree.h"
#include <time.h>
#include <stdlib.h>
#include "CL/cl.h"

std::vector<Body> bodyList;
unsigned int NUMBODIES = 2000;

int main(int argc, char* argv[]) {
  if (argc > 1) 
		NUMBODIES = atoi(argv[1]);
  bodyList.resize(NUMBODIES);
  srand((unsigned int)time(NULL));
  graphicsMain();
  
  //  Octree stuff that is not finalized
  /*
  double center[3] = {5.0, 5.0, 5.0};
  double size = 5.0;
  Body a, b, c, d, e, f; 
  a.setRandom(0);
	b.setRandom(1);
  OctNode* root = NULL;
	for (int i = 0; i < NUMBODIES; i++) {
		bodyList[i].setRandom(i);
		insert(root, bodyList[i], center, size);
	}
  */
  return 0;
}
