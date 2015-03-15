#include <iostream>
#include <fstream>
#include "Program.h"

using namespace std;

int main()
{
	int i;
	Program p;
	p.setAttribute();
	p.uniformCostSearch();
	fstream out;
	out.open("output.txt", fstream::out);

	out << "-------------solution path vertices [x,y]-------------" << endl << "";
	for(i = 0; i < p.path.size(); i++)
		out << "[" << p.path[i].x <<"," << p.path[i].y << "]" << endl;

	cout << "check output.txt please!" << endl;
	return 0;
}
