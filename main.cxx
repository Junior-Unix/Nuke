#include <iostream>
using std::cout;
using std::endl;

#include "GradeBook.h"

int main(){

	GradeBook gradeBook1("CS101 Introduction C++ Programing");
	GradeBook gradeBook2("CS101 C++ Data science");

	cout << "gradeBook1 create for course:" << gradeBook1.getCourseName()
		   << "\ngradeBook2 create for course:" << gradeBook2.getCourseName()
	   		<< endl;


	return 0;
}
