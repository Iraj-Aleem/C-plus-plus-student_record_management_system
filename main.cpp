#include <iostream>
#include "students.h"
using namespace std;
#include<graphics.h>


	int main(int argc, char** argv) {
  initwindow( 1300 , 1300 , "Student_Record_Management_System");
    setcolor(BLUE);
	//}
    students s;
   	//GUI gui(s);

    int ex = 0;
    int i, subj_no;
    int option;
    
    char name[20], studentregNumber[100];
    int max = 10;
    float marks[max];
    float mark;
    struct students *root = NULL;
    
	
     rectangle(40,40,1030,370);
     setfillstyle(HATCH_FILL,BLUE);
    floodfill(41,169,BLUE);
    while(1){
	
    cout << "\t\t\t  **************************************************************************************\n ";
    cout << "\t\t\t  **************************************************************************************\n ";
    cout << "\t\t\t  **************************************************************************************\n ";
    cout << "\t\t\t  **************************************************************************************\n ";
    cout << "\t\t\t  **      |       |   |   STUDENT REPORT PROGRAM BY 019,014 2023   |   |      |       **\n ";
    cout << "\t\t\t  **                                                                                  **\n ";
    cout << "\t\t\t  **      To Introduce New Student             ---->          choose  option '1'      **\n ";
    cout << "\t\t\t  **      To Introduce New Mark                ---->          choose  option '2'      **\n ";
    cout << "\t\t\t  **      To Remove Student                    ---->          choose  option '3'      **\n ";
    cout << "\t\t\t  **      To Print a Single Report             ---->          choose  option '4'      **\n ";
    cout << "\t\t\t  **      To Print Report of all Students      ---->          choose  option '5'      **\n ";
    cout << "\t\t\t  **      To Save to a FILE                    ---->          choose  option '6'      **\n ";
    cout << "\t\t\t  **      To Retrieve from a FILE              ---->          choose  option '7'      **\n ";
    cout << "\t\t\t  **      To EXIT                              ---->          choose  option '8'      **\n ";
    cout << "\t\t\t  **                                                                                  **\n ";
    cout << "\t\t\t  **************************************************************************************\n ";
    cout << "\t\t\t  **************************************************************************************\n ";
    cout << "\t\t\t  **************************************************************************************\n ";
    cout << "\t\t\t  **************************************************************************************\n ";
	cout <<"Please	enter	your	choice"<<endl;
	cin >> option;
    cout << endl;



    switch (option) {

        case 1:
            cout << "Enter Student Name: "<<endl;
            cin >> name;
            cout << "Enter Student Number: "<<endl;
            cin >> studentregNumber;
            for (int i = 0; i < max; i++) {
                marks[i] = 0;
            }
            createStudent(name, studentregNumber, marks);
            break;

        case 2:
            cout << "Enter Student Name: "<<endl;
            cin >> name;
            cout << "Enter Subject Number: "<<endl;
            cin >> subj_no;
            cout << "Enter the Marks: "<<endl;
            cin >> mark;
            addingMark(root, name, subj_no, mark);
            break;

        case 3:
            cout << "Enter name to delete: ";
            cin >> name;
            //root = DeleteStudentRecord(root, name);
            balanceBinary(root);
            break;

        case 4:
            cout << "Enter name to print: ";
            cin >> name;
            cout << "Name\tStudent Registration Number\tStudent Marks";
            PrintStudent(root, name);
            break;

        case 5:
            studentsReport(root,marks);
            break;

        case 6:
            //writeFile(name, studentregNumber, marks);
            writeList(root);
            break;

        case 7:
            readFile();
            break;

        case 8:
            	exit(1);
            break;

        default:
            cout << "\n\nEnter Only One of the Option below" << endl;
            	exit(0);
    }
    
}
    getch();
}

