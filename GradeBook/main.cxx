#include "GradeBook.h"

int main(){

    GradeBook myGradeBook("CS101 C++ Programing");

    myGradeBook.displayMessage();
    myGradeBook.inputGrades();
    myGradeBook.displayGradeReport();


    return 0;
}