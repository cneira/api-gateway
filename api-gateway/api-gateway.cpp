
#include "Nostromo.h"


int main()
{
	Nostromo* n = new Nostromo();
	
	uclog << U("Starting listener.") << endl;

	n->start_at(U("http://localhost:9090/nostromo/humans/"));
	uclog << U("Terminating JSON listener.") << endl;


	return 0;
}