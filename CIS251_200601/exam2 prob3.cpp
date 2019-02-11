//Kenneth Robinson

#include <iostream>
#include <iomanip>
using namespace std;

const int NUMBER_A = 4;
const int NUMBER_B = 5;

void compute_st_sum(const int grade[][NUMBER_B], double st_sum[]);
void compute_quiz_sum(const int grade[][NUMBER_B], double quiz_sum[]);
void display(const int grade[][NUMBER_B], const double st_sum[], const double quiz_sum[]);

int main( )
{
    int grade[NUMBER_A][NUMBER_B];
    double st_sum[NUMBER_A];
    double quiz_sum[NUMBER_B];

    cout << "I am filling the array grade for you.\n";
    grade[0][0] = 10; grade[0][1] = 10; grade[0][2] = 10; grade[0][3] = 10; grade[0][4] = 5;
    grade[1][0] = 2; grade[1][1] = 0; grade[1][2] = 1; grade[1][3] = 10; grade[1][4] = 5;
    grade[2][0] = 8; grade[2][1] = 6; grade[2][2] = 9; grade[2][3] = 10; grade[2][4] = 5;
    grade[3][0] = 8; grade[3][1] = 4; grade[3][2] = 10; grade[3][3] = 10; grade[3][4] = 5;

    compute_st_sum(grade, st_sum);
    compute_quiz_sum(grade, quiz_sum);
    display(grade, st_sum, quiz_sum);
	system("pause");
    return 0;
}

void compute_st_sum(const int grade[][NUMBER_B], double st_sum[])
{
    for (int st_num = 1; st_num <= NUMBER_A; st_num++)
    {//Process one st_num:
        double sum = 0;
        for (int quiz_num = 1; quiz_num <= NUMBER_B; quiz_num++)
		{
            sum = sum + grade[st_num-1][quiz_num-1];
		}
        //sum contains the sum of the quiz scores for student number 
        //st_num.
       st_sum[st_num-1] = sum; //NUMBER_B;
        //Average for student st_num is the value of st_sum[st_num-1]
    }
} 

void compute_quiz_sum(const int grade[][NUMBER_B], double quiz_sum[])
{
    for (int quiz_num = 1; quiz_num <= NUMBER_B; quiz_num++)
    {//Process one quiz (for all students):
        double sum = 0;
        for (int st_num = 1; st_num <= NUMBER_A; st_num++)
            sum = sum + grade[st_num-1][quiz_num-1];
        //sum contains the sum of all student scores on quiz number
        //quiz_num.
        quiz_sum[quiz_num-1] = sum; ///NUMBER_A;
        //Average for quiz quiz_num is the value of quiz_sum[quiz_num-1]
    }
}

//Uses iostream and iomanip:
void display(const int grade[][NUMBER_B], const double st_sum[] , const double quiz_sum[])
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    cout << setw(10) << "Student"
         << setw(10) << "Row Total"
         << setw(15) << "Quizzes\n";
    for (int st_num = 1; st_num <= NUMBER_A; st_num++)
    {//Display for one st_num:
        cout << setw(10) << st_num 
             << setw(8) << st_sum[st_num-1] << " ";
        for (int quiz_num = 1; quiz_num <= NUMBER_B; quiz_num++)
            cout << setw(5) << grade[st_num-1][quiz_num-1];
        cout << endl;
    }

	 cout << "Column Total =    ";
    for (int quiz_num = 1; quiz_num <= NUMBER_B; quiz_num++)
        cout << setw(6) << quiz_sum[quiz_num-1];
    cout << endl;
	
}