#pragma once
#include <iostream>
#define countcolor 3 
namespace Lesta {

	enum color
	{
		yellow = 0,
		red,
		orange,

	};
	class game {
	private:
	


	public:	
		static const int  size = 5;
		char field[size][size];
		game();
		friend std::ostream& operator <<(std::ostream&, const game&);
		int check();
		int wolk();
	};
	template <typename T>
	int getNum(T& a)
	{
		std::cin >> a;
		if ((!std::cin.good())) {

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			return -1;
		}
		return 1;
	}


}