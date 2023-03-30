#include <iostream>
#include <vector>

using namespace std;

enum sex{K=0,M=1};

class Person
{
    string name_;
    string surname_;
    float weight_;
    float height_;
    int age_;
    protected:
    sex sex_;
    public:
    Person(){};
    Person(string,string,float,float,int,sex);
    float BMI();
    //void typeBMI();
    void display();
    float rage();
    friend class Major;



};
Person::Person(string n, string s, float w, float h, int a, sex x): name_(n), surname_(s), weight_(w), height_(h), age_(a), sex_(x)
{
    //display();
}
float Person::BMI()
{
float bmi=weight_/((height_/100)*(height_/100));
return bmi;
}
/*void Person::typeBMI()
{
    float bmi=BMI();
    if(bmi<=18) cout<<"Niedowaga";
    if(bmi>18 and bmi<=25) cout<<"Prawidlowe";
    if(bmi>25) cout<<"Nadwaga";
}*/
float Person::rage()
{
float b=static_cast<float>(age_);
return b;
}
void Person::display()
{
    string sex_p;
    if(sex_) sex_p="Mezczyzna";
    else sex_p="Kobieta";
    cout<<" Imie: "<<name_<<" "<<" Nazwisko: "<<surname_<<" Waga: "<<weight_<<" Wzrost: "<<height_<<" Wiek: "<<age_<<" Plec: "<<sex_p<<" BMI: "<<BMI()<<endl;
}

class Student: public Person
{
    string index_;
    int year_;
    vector<double> marks_;
    public:
    Student(string, string, float, float, int, sex, string,int);
    double average();
    friend class Major;
    bool operator==(const Student&);
    
   
};

Student::Student(string n, string s, float w, float h, int a, sex x, string i,int y): Person(n,s,w,h,a,x), index_(i),year_(y)
{

for(int i=0;i<5;i++)
    {
        double a;
        cin>>a;
        marks_.push_back(a);
    }
    cout<<index_<<endl;
    cout<<average()<<endl;
}
double Student::average()
{
    double a=0;
    for(int i=0;i<5;i++)
    {
        a+=marks_[i];
    }
    return a/5;
}
bool Student :: operator==(const Student& com){
    if(index_ == com.index_)
        return true;
    else
        return false;
}
class Worker: public Person
{
    string ncompany_;
    string position_;
    float earn_;
    float expirience_;
    public:
    Worker(string, string, float, float, int, sex, string,string,float,float);
    float topension();
    
   
};
Worker::Worker(string n, string s, float w, float h, int a, sex x, string i,string y,float E,float e): Person(n,s,w,h,a,x), ncompany_(i),position_(y),earn_(E),expirience_(e)
{

//cout<<topension()<<endl;

}
float Worker::topension()
{
    float a;
    //static_cast<
    if(sex_) a=65-rage();
    else a=60-rage();
    return a;
}
class Major
{
    string namemajor_;
    vector<vector<Student>> students_;
    int numberofstudents_;
    public :
    Major()=default;
    Major(string);
    ~Major()=default;
        void addStudent(Student);
        void removeStudent(Student);
        void studentsUpdate();
        void sortByGrade(int);
        void dispTopThree(int);

};
Major::Major (string name) : namemajor_(name) {
    numberofstudents_ = 0;
    for(int i = 0; i < 5; i++)
        students_.emplace_back(std::vector<Student>());
}

void Major :: addStudent(Student toAdd){ 
    students_[toAdd.year_ - 1].emplace_back(toAdd);
}

void Major :: removeStudent(Student toRemove){ 
    int position;
    for(int i = 0; i < students_[toRemove.year_ - 1].size(); i++){
        if(students_[toRemove.year_ - 1][i] == toRemove){
            position = i;
            students_[toRemove.year_ - 1].erase(students_[toRemove.year_ - 1].begin() + position);
            break;
        }
    }
}

void Major :: studentsUpdate(){ 
    numberofstudents_ = 0;
    for(int i = 0; i < students_.size(); i++){
        for(int j = 0; j < students_[i].size(); j++){
            numberofstudents_++;
        }
    }
}

void Major :: sortByGrade(int year){ 
    for(int i = 0; i < students_[year - 1].size(); i++){
        int minIndex = i;
        for(int j = i + 1; j < students_[year - 1].size(); j++){
            if(students_[year - 1][j].average() > students_[year - 1][minIndex].average())
                minIndex = j;
        }
        std::swap(students_[year - 1][i], students_[year - 1][minIndex]);
    }
}

void Major :: dispTopThree(int year){
    sortByGrade(year);
    for(int i = 0; i < students_[year - 1].size(); i++){
        if(i == 3) break;
        std::cout 
        << students_[year - 1][i].index_ << " " 
        << students_[year - 1][i].name_ << " "  
        << students_[year - 1][i].surname_ << " ";
    }
}