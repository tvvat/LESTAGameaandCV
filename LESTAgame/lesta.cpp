#include "lesta.h"
#include<random>
#include <iostream>
namespace Lesta{
	char colorNum[3] = { 'r','y','o' };
	game::game() {

		int countbusycolor[countcolor] = { 0,0,0 };

		for(int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j) {
				if (j%2) {
					if (i % 2)
						field[i][j] = ' ';
					else
						field[i][j] = '@';
					
				}
				else {
					int tmp;
					int busy =0;
					do{
						tmp = rand() % countcolor;
						if (countbusycolor[tmp] == size )
							continue;
						field[i][j] = colorNum[tmp];
						busy = 1;
						countbusycolor[tmp]++;
						
					} while (!busy);
				}
			}
		


	}

	std::ostream& operator <<(std::ostream& out, const game& star) {
			out << "Y O R\n";
			for (int i = 0; i < star.size; ++i){
				for (int j = 0; j < star.size; ++j)
					out << star.field[i][j];
				out << std::endl;
			}
			return out;
	}
	int game::wolk() {



		std::cout << "enter coordinate (0..4) (0..4) (first line) busy then\n";
		std::cout << "enter coordinate (0..4) (0..4) (first line) empty->";
		int i, j;
		int toi, toj;
		if ((getNum(i) > 0) && (getNum(j) > 0) && (i < 5)&&(j< 5) ){
			
			if ((getNum(toi) > 0) && (getNum(toj) > 0) && (toi < 5) && (toj < 5)){

				int sub = abs(i - toi) + abs(j - toj);
				std::cout << sub << "=sub" << std::endl;
				if(sub <2)
					if( (field[toi][toj] == ' ')&&(field[i][j] !='@') && (field[i][j] != ' ')) {
					field[toi][toj] = field[i][j];
					field[i][j] = ' ';
					}
			}
		}
		else
			std::cout << "u wrong repeat\n";

		return 1;
	}
	int game::check() {

		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size -1; ++j) {
				if (!(j % 2)) {
					int tmp = 0;
					if (field[j][i] != field[j + 1][i])
						return 0;
				} 
			}
			

		return 1;
	}


}