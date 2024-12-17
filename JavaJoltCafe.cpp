#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
class Employee
{
private:
    int employeeId;
    string employeeName;
    string employeePosition;
    float basicSalary;
    string employeeType;
    string startDate;
    float hourlyWage;

public:
    Employee() : employeeId(0), employeeName(""), employeePosition(""), basicSalary(0), employeeType(""), startDate("") {}
    int getEmployeeID()
    {
        return employeeId;
    }
    string empType()
    {
        cout << "Enter Employee Type( FullTime , PartTime ):";
        cin >> employeeType;
        return employeeType;
    }
    string getEmpType()
    {
        return employeeType;
    }
    void hourlyWageCalcultion()
    {
        hourlyWage = (basicSalary / 30) / 8;
    }
    float getHourlyWage()
    {
        return hourlyWage;
    }
    float getBasicSalary()
    {
        return basicSalary;
    }
    void setData()
    {

        cout << "Enter employee id:";
        cin >> employeeId;
        cin.ignore();
        cout << "Enter employee name:";
        getline(cin, employeeName);
        // cin.ignore();
        cout << "Enter employee position(FT:Supervisor,Cashier,Barista.PT:Cleaner,KitchenStaff,Waiter/Waitress):";
        cin >> employeePosition;
        cout << "Enter starting date:";
        cin >> startDate;
        if (employeePosition == "Barista")
        {
            basicSalary = 1920;
        }
        else if (employeePosition == "Cashier")
        {
            basicSalary = 1790;
        }
        else if (employeePosition == "Supervisor")
        {
            basicSalary = 2400;
        }
        else if (employeePosition == "Cleaner")
        {
            basicSalary = 1400;
        }
        else if (employeePosition == "Waiter" or employeePosition == "Waitress")
        {
            basicSalary = 1700;
        }
        else if (employeePosition == "KitchenStaff")
        {
            basicSalary = 1850;
        }
        else
        {
            cout << "Invalid Position!";
        }
        // cout<<"Enter employee type:";
        // getline(cin,employeeType);
    }

    void displayData()
{
    cout << left; // Align text to the left
    cout << "--------------------------------------------" << endl;
    cout << setw(25) << "Employee ID:" << employeeId << endl;
    cout << setw(25) << "Employee Name:" << employeeName << endl;
    cout << setw(25) << "Employee Position:" << employeePosition << endl;
    cout << setw(25) << "Starting Date:" << startDate << endl;
    cout << setw(25) << "Employee Basic Salary:" << basicSalary << endl;
}
};
class fulltimeEmployee : public Employee
{
private:
    int leaveDay;
    int overtime;
    int bonusAmount;
    float overtimeFees;
    float netSalary;

public:
    fulltimeEmployee() : leaveDay(0), overtime(0), bonusAmount(0), overtimeFees(0), netSalary(0) {}
    void bonusCalculation()
    {
        if (leaveDay == 0)
        {
            bonusAmount = 300;
        }
        else if (leaveDay == 1)
        {
            bonusAmount = 200;
        }
        else if (leaveDay == 2)
        {
            bonusAmount = 100;
        }
        else
        {
            bonusAmount = 0;
        }
    }
    // void overtimeCalculation()
    // {
    //     overtimeFees = overtime * (2 * getHourlyWage());
    // }

    void netSalaryCalculation()
    {
        overtimeFees = overtime * (2 * getHourlyWage());
        float totalSalary;
        totalSalary = getBasicSalary() + overtimeFees + bonusAmount;
        if (leaveDay > 4)
        {
            netSalary = totalSalary - (((totalSalary / 100) * 2) + ((getBasicSalary() / 100) * 1)) - 10;
        }
        else if (leaveDay <= 4)
        {
            netSalary = totalSalary - (((totalSalary / 100) * 2) + 10);
        }
        else
        {
            cout << "Invalid data calculation for net salary!!";
        }
    }
    void setFulltimeData()
    {
        setData();
        cout << "Enter leave day:";
        cin >> leaveDay;
        cout << "Enter overtime:";
        cin >> overtime;
        cout << endl;
        // overtimeCalculation();
        hourlyWageCalcultion();
        bonusCalculation();
        netSalaryCalculation();
    }
    void displayFulltimeData()
    {
        displayData(); 
         cout << left; // Align text to the left
    cout << setw(25) << "Leave Day:" << leaveDay << endl;
    cout << setw(25) << "Overtime:" << overtime << endl;
    cout << setw(25) << "Net Salary:" << netSalary << endl;
    cout << "--------------------------------------------" << endl;
    }
    int getFulltimeEmployeeID()
    {
        return getEmployeeID();
    }
};
class parttimeEmployee : public Employee
{
private:
    int workingHours;
    float parttimeFees;
    float netSalary;

public:
    parttimeEmployee() : workingHours(0), parttimeFees(0), netSalary(0) {}
    void netSalaryCalculation()
    {
        parttimeFees = workingHours * getHourlyWage();
        netSalary = parttimeFees - (((parttimeFees / 100) * 2) + 10);
    }
    void setParttimeData()
    {
        setData();
        cout << "Enter working hours:";
        cin >> workingHours;
        cout << endl;
        hourlyWageCalcultion();
        netSalaryCalculation();
    }
    void displayParttimeData()
    {
        displayData();
        cout << left;
             cout << setw(25) << "Working Hours:" << workingHours << endl;
             cout << setw(25) << "Net Salary:" << netSalary << endl;
             cout << "--------------------------------------------" << endl;
    }
    int getParttimeEmployeeID()
    {
        return getEmployeeID();
    }
};
vector<fulltimeEmployee> ftEmp;
vector<parttimeEmployee> ptEmp;
Employee e;
int main()
{
    int option;
    fulltimeEmployee f;
    parttimeEmployee p;
    do
    {
        cout << "++++++++++++++++++++++++++++++++++" << endl;
        cout << "+++++Employee Payroll Manager+++++" << endl;
        cout << "++++++++++++++++++++++++++++++++++" << endl;
        cout << "1.Insert Employee Data\n2.Update Employee Data\n3.View Full Time Employee Data";
        cout << "\n4.View Part Time Employee Data\n5.View All Data\n6.Exit\nChoose Option:";
        cin >> option;
        switch (option)
        {
        case 1:
        {
            int numofEmp;
            cout << "Enter number of employee to insert:";
            cin >> numofEmp;
            for (int i = 0; i < numofEmp; i++)
            {
                e.empType();
                if (e.getEmpType() == "FullTime")
                {
                    f.setFulltimeData();
                    ftEmp.push_back(f);
                }
                else if (e.getEmpType() == "PartTime")
                {
                    p.setParttimeData();
                    ptEmp.push_back(p);
                }
            }
            break;
        }
        case 2:
        {
            e.empType();
            if (e.getEmpType() == "FullTime")
            {
                int empid;
                cout << "Enter Employee Id to update:";
                cin >> empid;
                for (int i = 0; i < ftEmp.size(); i++)
                {
                    if (empid == f.getFulltimeEmployeeID())
                    {
                        ftEmp[i].setFulltimeData();
                        break;
                    }
                }
            }
            else if (e.getEmpType() == "PartTime")
            {
                int empid;
                cout << "Enter Employee Id to update:";
                cin >> empid;
                for (int i = 0; i < ptEmp.size(); i++)
                {
                    if (empid == p.getParttimeEmployeeID())
                    {
                        ptEmp[i].setParttimeData();
                        break;
                    }
                }
            }
        }
        case 3:
        {
            cout << "+++++Full Time Employee Data+++++\n";
            for (int i = 0; i < ftEmp.size(); i++)
            {
                ftEmp[i].displayFulltimeData();
            }
            break;
        }
        case 4:
        {
            cout << "+++++Part Time Employee Data+++++\n";
            for (int i = 0; i < ptEmp.size(); i++)
            {
                ptEmp[i].displayParttimeData();
            }
            break;
        }
        case 5:
        {
            cout << "++++++++All Employee Data++++++++\n";
            for (int i = 0; i < ftEmp.size(); i++)
            {
                ftEmp[i].displayFulltimeData();
            }
            for (int i = 0; i < ptEmp.size(); i++)
            {
                ptEmp[i].displayParttimeData();
            }
            break;
        }
        case 6:
            break;
        }
    } while (option != 6);
}