
#include "Road.h"

Road::Road()
{
	for(int i =0; i<3; i++)
	{
		Tile beginning(); // how to make the pointer to the next ?? Do we need this??
		Road1.push_back(beginning);
	}
}
Road::Road(int num, Intersection a, Intersection b){

	
	for(int i=0; i<2*num+2; i++){
		
		if(i ==num+1){

			Road1.push_back(a);

		}

		else if (i == num+2)
		{
			Road1.push_back(b);
		}

		else
		{
			Tile temp ();
			Road1.push_back(temp);
		
		}
	}
}