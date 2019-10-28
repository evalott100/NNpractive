#include <iostream>
#include <time.h>
#include <string.h>
class category
{
	private:
		char name[30];
		float lowval,highval,midval;
	public:
		category (void){};
		void setname (char*);
		char* get_name (void);
		void setval (float&, float&, float&);
		float get_lowval (void) const;
		float get_midval (void) const;
		float get_highval (void) const;

		float getshare (const float&);
		~category (void){};
};
