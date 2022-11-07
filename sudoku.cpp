#include <iostream>

void print(int grid[9][9]){
	for(int i {0}; i < 9; i++){
		std::cout << "   ";

		for(int j {0}; j < 9; j++){
			std::cout << grid[i][j] << " ";

			if((j == 2)||(j == 5)){
				std::cout << "| ";
			}
		}

		if((i == 2)||(i == 5)){
			std::cout << "\n  -------|-------|-------";
		}

		std::cout << "\n";
	}
}

bool valid(int grid[9][9], int col_y, int row_x, int num){
	for(int i {0}; i < 9; i++){
		if((grid[col_y][i] == num)||grid[i][row_x] == num){
			return false;
		}
	}

	int col_y0 {(col_y/3)*3},
		row_x0 {(row_x/3)*3};
	
	for(int i {0}; i < 3; i++){
		for(int j {0}; j < 3; j++){
			if(grid[col_y0+i][row_x0+j] == num){
				return false;
			}
		}
	}

	return true;
}

void solve(int grid[9][9]){
	for(int col_y {0}; col_y < 9; col_y++){
		for(int row_x {0}; row_x < 9; row_x++){
			if(grid[col_y][row_x] == 0){
				for(int num {1}; num < 10; num++){
					if(valid(grid, col_y, row_x, num)){
						grid[col_y][row_x] = num;
						solve(grid);
						grid[col_y][row_x] = 0;
					}
				}

				return;
			}
		}
	}

	print(grid);
	std::cout << "\nProceed? Y/Ctrl^C: ";
	std::cin.get();
}

int main(){
	int grid[9][9] {
		{3, 0, 0,  0, 7, 1,  2, 0, 0},
		{0, 9, 1,  2, 0, 0,  7, 0, 0},
		{0, 0, 6,  3, 0, 0,  0, 0, 1},

		{4, 7, 0,  0, 0, 0,  8, 6, 5},
		{1, 0, 0,  5, 0, 8,  3, 7, 0},
		{0, 0, 0,  0, 6, 4,  0, 0, 0},

		{0, 0, 3,  0, 2, 0,  6, 0, 8},
		{0, 0, 7,  0, 1, 5,  0, 0, 0},
		{2, 0, 4,  6, 0, 3,  9, 1, 7}
	};

	int sumn[9][9] {
		{0, 0, 0,  0, 0, 0,  0, 0, 0},
		{0, 0, 0,  0, 0, 0,  0, 0, 0},
		{0, 0, 0,  0, 0, 0,  0, 0, 0},

		{0, 0, 0,  0, 0, 0,  0, 0, 0},
		{0, 0, 0,  0, 0, 0,  0, 0, 0},
		{0, 0, 0,  0, 0, 0,  0, 0, 0},

		{0, 0, 0,  0, 0, 0,  0, 0, 0},
		{0, 0, 0,  0, 0, 0,  0, 0, 0},
		{0, 0, 0,  0, 0, 0,  0, 0, 0},	
	};

	solve(sumn);

	return 0;
}