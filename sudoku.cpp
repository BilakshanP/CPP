#include <iostream>

#define N 9

void print(int grid[N][N]){
    for(int i{}; i < N; i++){
        for(int j{}; i < N; i++){
            std::cout << grid[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

bool isSafe(int grid[N][N], int row_x, int col_y, int num){
    for(int i{}; i < N; i++){
        if(grid[row_x][i] == num){
            return false;
        }

        else if(grid[i][col_y] == num){
            return false;
        }
    }

    int startRow_X = row_x - row_x % 3,
        startCol_X = col_y - col_y % 3;
    
    for(int i{}; i < 3; i++){
        for(int j{}; j < 3; j++){
            if(grid[i+startRow_X][j+startCol_X] == num){
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int grid[N][N], int row_x, int col_y){
    if((row_x == N-1)&&(col_y == N)){
        return true;
    }

    if(col_y == N){
        row_x++;
        col_y = 0;
    }

    if(grid[row_x][col_y]  != 0){
        return solveSudoku(grid, row_x, col_y + 1);
    }

    for(int num = 1; num < N; num++){
        if(isSafe(grid, row_x, col_y, num)){
            grid[row_x][col_y] = num;

            if(solveSudoku(grid, row_x, col_y + 1)){
                return true;
            }
        }
    }

    return false;
}

int main(){
	int grid[N][N] = {
        {3, 0, 6,   5, 0, 8,   4, 0, 0 },
		{5, 2, 0,   0, 0, 0,   0, 0, 0 },
		{0, 8, 7,   0, 0, 0,   0, 3, 1 },

		{0, 0, 3,   0, 1, 0,   0, 8, 0 },
		{9, 0, 0,   8, 6, 3,   0, 0, 5 },
		{0, 5, 0,   0, 9, 0,   6, 0, 0 },

		{1, 3, 0,   0, 0, 0,   2, 5, 0 },
		{0, 0, 0,   0, 0, 0,   0, 7, 4 },
		{0, 0, 5,   2, 0, 6,   3, 0, 0 }
    };

    if(solveSudoku(grid, 0, 0)){
        print(grid);
    }

    else{
        std::cout << "No solution exists!!" << std::endl;
    }
}

/*
grid = [
	[3, 4, 0, 0, 7, 1, 2, 0, 0],
	[0, 9, 1, 2, 0, 0, 7, 0, 0],
	[0, 0, 6, 3, 0, 0, 0, 0, 1],
	[4, 7, 0, 0, 0, 0, 8, 6, 5],
	[1, 0, 0, 5, 0, 8, 3, 7, 0],
	[0, 0, 0, 0, 6, 4, 0, 0, 0],
	[0, 0, 3, 0, 2, 0, 6, 0, 8],
	[0, 0, 7, 0, 1, 5, 0, 0, 0],
	[2, 0, 4, 6, 0, 3, 9, 1, 7]
	]

# grid = [
# 	[0, 0, 0, 0, 0, 0, 0, 0, 0],
# 	[0, 0, 0, 0, 0, 0, 0, 0, 0],
# 	[0, 0, 0, 0, 0, 0, 0, 0, 0],
# 	[0, 0, 0, 0, 0, 0, 0, 0, 0],
# 	[0, 0, 0, 0, 0, 0, 0, 0, 0],
# 	[0, 0, 0, 0, 0, 0, 0, 0, 0],
# 	[0, 0, 0, 0, 0, 0, 0, 0, 0],
# 	[0, 0, 0, 0, 0, 0, 0, 0, 0],
# 	[0, 0, 0, 0, 0, 0, 0, 0, 0]
# 	]

def s_print():
	global grid

	for i in range(0, 9):
		print("", end = "   ")
		for j in range(0, 9):
			print(grid[i][j], end = " ")
			if j in [2, 5]:
				print("", end = "| ")
		if i in [2, 5]:
			print("\n  -------|-------|-------", end="")
		print()



def possible(y, x, n):
	global grid

	for i in range(0, 9):
		if grid[y][i] == n:
			return False

	for i in range(0, 9):
		if grid[i][x] == n:
			return False

	x0 = (x//3)*3
	y0 = (y//3)*3

	for i in range(0, 3):
		for j in range(0, 3):
			if grid[y0+i][x0+j] == n:
				return False
	return True

def solve():
	global grid

	for y in range(0, 9):
		for x in range(0, 9):
			if grid[y][x] == 0:
				for n in range(1, 10):
					if possible(y, x, n):
						grid[y][x] = n
						solve()
						grid[y][x] = 0
				
				return

	s_print()
	if input("More? ") == "Exit":
		exit()

solve()
*/