#include<iostream>
#include<vector>
using namespace std;

void pattern(int x) {						//PATTERN FUNCTION TO PRINT STARS

	static int times = x;

	if (x <= 0)								//IF NUMBER OF STARS ARE LESS THAN 0
		return;								//EXIT FUNCTION

	for (int i = x; i > 0; i--)				//FOR LOOP TO PRINT STARS
		cout << "*";
	cout << endl;							//JUMP TO NEXT LINE

	if (x == 1) {
		do {								//DO WHILE LOOP TO PRINT STARS
			for (int j = 1; j <= x; j++)
				cout << "*";
			cout << endl;
			x++;
		} while (x <= times);

		return;								//EXIT FUNCTION
	}//END IF
	pattern(x - 1);
}//END PATTERN FUNCTION

int main() {

	int numberOfStars;						//VARIABLE TO HOLD NUMBER OF STARS

	cout << "Enter a number: \n";
	cin >> numberOfStars;					//ENTER NUMBER OF STARS

	pattern(numberOfStars;					//START PATTERN FUNCTION

	system("pause");
	return 0;
}//END MAIN