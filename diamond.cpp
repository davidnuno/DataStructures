#include <iostream> 
#include <string>

using namespace std;

void print(unsigned int cnt) {						//FUNCTION TO PRINT OUT STARS

	for (int i = cnt; i > 0; i--) cout << "* ";		//FOR LOOP TO PRINT OUT # OF STARS
	cout << '\n';
}//END PRINT FUNCTION

void center(int maxRow, int row = 0) {				//FUNCTION TO CENTER DIAMOND

	if (row >= maxRow) {							//IF ROW GREATER THAN MAX ROW
		print(row);									//PRINT ROW
	}//END IF
	else {
		cout << string(maxRow - row, ' ');			//TOP HALF OF DIAMOND
		print(row);

		center(maxRow, row + 1);					//RECURSION
		
		cout << string(maxRow - row, ' ');			//BOTOM HALF OF DIAMOND
		print(row);
	}//END ELSE
}//END CENTER FUNCTION

int main() {
	int totalLines;									//TOTAL NUMBER OF LINES

	cout << "Enter total lines: ";					
	cin >> totalLines;								//ENTER THE NUMBER OF LINES
	cout << '\n';
	
	center(totalLines);								
		
	system("pause");
	return 0;
}//END MAIN
