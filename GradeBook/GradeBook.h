#include <string>
using std::string;

class GradeBook{

public:
    
    GradeBook(string);

    void setCourseName(string);
    int getCourseName();
    void displayMessage();

private:

    string courseName;
    

};
