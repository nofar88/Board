#include <string>
#include <iostream>
#include <map>
#include "Direction.hpp"


using namespace std;
namespace ariel {

	class Board{
	private:
		map<unsigned int, map<unsigned int, char>> matrix;
		unsigned int lenr=50;
		unsigned int lenc=50;

		

	public:

	
		


		void post(unsigned int row ,unsigned int column, Direction way ,string s);
	    string read(unsigned int row ,unsigned int column , Direction way , unsigned int len);
	    void show();


	};
	
}