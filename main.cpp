#include <iostream>
#include "klasy_i_funkcje.h"


int main()
{
    string name;
    string surname; 
    float weight;
    float height; 
    int age; 
    char Sex;
    std::string index; 
    int year;
    sex sex_;
    string company;
    string position;
    float salary;
    float experience;
    
    cin >> name;
    Major myCourse(name);

    for(int i = 0; i < 10; i++){
        cin >> name >> surname >> weight >> height >> age >> Sex >> index >> year;
        if(Sex == 'M')
            sex_ = M;
        else
            sex_ = K;
        Student myStudent(name, surname, weight, height, age, sex_, index, year);
        myCourse.addStudent(myStudent);
    }
    
    cin >> year;
    
    myCourse.dispTopThree(year);
    
    for(int i = 0; i < 2; i++){
        std::cin >> name >> surname >> weight >> height >> age >> Sex 
        >> company >> position >> salary >> experience;
        if(Sex == 'M')
            sex_ = M;
        else
            sex_ = K;
        Worker myEmployee(name, surname, weight, height, age, sex_, company, position, salary, experience);
        std::cout << myEmployee.topension();
        if(i == 0) std::cout << " ";
    }
    
    return 0;
}