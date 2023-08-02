#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class EmployeeInfo {
    public:
        void SetName (string employeeName);             //Mutator
        void SetTitle (string jobTitle);                //Mutator
        void SetWages (double jobWages);                //Mutator
        double GetWages() const;                        //Accessor
        void Print();                                   //Accessor
        
    private:
        string name;
        string title;
        double wages;
};

void EmployeeInfo::SetName(string employeeName){
    name = employeeName;
}

void EmployeeInfo::SetTitle(string jobTitle){
    title = jobTitle;
}

void EmployeeInfo::SetWages(double jobWages){
    wages = jobWages;
}

double EmployeeInfo::GetWages() const{
    return wages;
}

void EmployeeInfo::Print(){
    cout << name << '\t' << '\t' << title << '\t' << '\t' << "$" << wages << " per hour" << endl;
}

int main(){
    
    EmployeeInfo person1;
        person1.SetName("Long NL");
        person1.SetTitle("Product Manager");
        person1.SetWages(100);
    
    EmployeeInfo person2;
        person2.SetName("Noelle Le");
        person2.SetTitle("Comp. Engineer");
        person2.SetWages(75);
        
    EmployeeInfo person3;
        person3.SetName("Han Tran");
        person3.SetTitle("IT Support");
        person3.SetWages(50);

    EmployeeInfo person4;
        person4.SetName("Huy NL");
        person4.SetTitle("Marketing");
        person4.SetWages(25);
    
    EmployeeInfo person5;
        person5.SetName("Tammy Pham");
        person5.SetTitle("A/V Intern");
        person5.SetWages(5);
    
    cout << "Welcome to Employee Database" << endl;
    cout << endl << "This application will track information about employees at a company, ";
    cout << "such as tracking employee's names, job titles, and wages." << endl;
    cout << "This application will also calculate the total amount of wages ";
    cout << "that employees are to be paid for the week." << endl;
    cout << "Here are the options of the application:" << endl << endl;

    for (int i = 0; i < 3; i++){
        if (i == 0){
            cout << i+1 << ". Print list of employees." << endl;
        } else if (i == 1){
            cout << i+1 << ". Calculate total wages." << endl;
        } else {
            cout << i+1 << ". Exit application." << endl;
        }
    }
    
    cout << endl << "Please select one of these options to begin or exit the program:" << endl;
    
    int choiceInteger;
    string choiceString;
    vector<double> hours(5);  
    string hourString;
    vector<double> weeklyPay(5);
    
    for (int j = 0; j < 10000; j++){
        double totalWeekPay = 0;
        cin >> choiceString;
        for (int k = 0; k < 10000; k++){
            choiceInteger = atoi(choiceString.c_str());
            if (choiceInteger == 1){
                cout << endl << "You have selected option 1." << endl;
                cout << endl << "List of Employees:" << endl << endl;
                cout << "Employee 1: "; person1.Print();
                cout << "Employee 2: "; person2.Print();
                cout << "Employee 3: "; person3.Print();
                cout << "Employee 4: "; person4.Print();
                cout << "Employee 5: "; person5.Print();
                cout << endl;
                for (int i = 0; i < 3; i++){
                    if (i == 0){
                        cout << i+1 << ". Print list of employees." << endl;
                    } else if (i == 1){
                        cout << i+1 << ". Calculate total wages." << endl;
                    } else {
                        cout << i+1 << ". Exit application." << endl;
                    }
                }
                cout << endl << "Please select one of these options to continue or exit the program:" << endl;
                break;
                
            } else if (choiceInteger == 2){
                cout << endl << "You have selected option 2." << endl;
                cout << endl << "Please enter the total number of hours worked this weeks for each employee:" << endl << endl;
                
                for (int p = 0; p < 5; p++){
                    cout << "Employee " << p+1 << ": ";
                    cin >> hourString;
                    double hour = std::stod(hourString);
                    
                    while (hour < 0 || hour > 168) {    
                        if (hour < 0){
                            cout << endl << "Invalid input. Please enter the number of hours (greater than or equal to 0): ";
                        } else {
                            cout << endl << "That is more than the total number of hours in a week. Please try again: ";
                        }
                        cin >> hourString;
                        hour = std::stod(hourString);
                    }
                    
                    hours.at(p) = hour;
                }
                
                weeklyPay.at(0) = hours.at(0)*person1.GetWages();
                weeklyPay.at(1) = hours.at(1)*person2.GetWages();
                weeklyPay.at(2) = hours.at(2)*person3.GetWages();
                weeklyPay.at(3) = hours.at(3)*person4.GetWages();
                weeklyPay.at(4) = hours.at(4)*person5.GetWages();
                
                for (int d = 0; d < 5; d++){
                    totalWeekPay += weeklyPay.at(d);
                }
                
                cout << endl << "The total wages for this week is $" << totalWeekPay << endl << endl;
        
                for (int i = 0; i < 3; i++){
                    if (i == 0){
                        cout << i+1 << ". Print list of employees." << endl;
                    } else if (i == 1){
                        cout << i+1 << ". Calculate total wages." << endl;
                    } else {
                        cout << i+1 << ". Exit application." << endl;
                    }
                }
                
                cout << endl << "Please select one of these options to continue or exit the program:" << endl;
                break;
                
            } else if (choiceInteger == 3){
                cout << "You have selected option 3." << endl;
                break;
                
            } else {
                cout << "Invalid input. Please select the available option by entering the option value." << endl;
                cin >> choiceString;
            }
        }
        
        if (choiceInteger == 3){
            cout << endl << "Exiting program..." << endl;
            break;
        }
    }
    return 0;
}