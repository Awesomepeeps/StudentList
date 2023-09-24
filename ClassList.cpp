//  Author: Nikaansh S.
//  Last Editied: 9/24/23
//  This is a program that allows you to add or delete students to a linked list along with being able to print out all students that are currently in the list
    

#include <iostream>
#include <cstring>

using namespace std;

struct node { // This is the struct for a node (or person) on the linked list 
  char *firstName;
  char *lastName;
  float gpa;
  int studentID;
  node *next; // Location of the next person in the list
};

void addStudent(node *&list, int &studentCount);
void deleteStudent(node *&list, int &studentCount);
void printStudent(node *&list, int &studentCount);
void deleteAll(node *&pnt, int &studentCount);

// Takes in input from the user to either add, delete, or print the linked list
int main() {
  int studentCount = 0;
  node *list = NULL; // Pointer to the start of the list
  char *input = new char[10];
  char yn = 'y';
  while (yn == 'y') {
    cout << "What do you want to do (add, delete, or print)?" << endl;
    cin >> input;
    if (strcmp(input, "add") == 0) {
        addStudent(list, studentCount);
    }
    else if (strcmp(input, "delete") == 0) {
        deleteStudent(list, studentCount);
    }
    else if (strcmp(input, "print") == 0) {
        printStudent(list, studentCount);
    }
    cout << "Do you want to contine editing ('y' for yes and 'n' for no)?" << endl;
    cin >> yn;
  }
  deleteAll(list, studentCount);
  delete input;
}

// This creates a new node and adds it to to front of the linked list. This linked list is implimented as a stack, not as a queue. 
// It takes in the location of the first term of the linked list and the address of student count   
void addStudent(node *&pnt, int &studentCount) {
  if (studentCount == 0) { // Seperate scenario if it is the first person being added
    node *tmp = new node;
    tmp->next = NULL; // Sets the next to point to 0x0 or NULL
    tmp->firstName = new char[15];
    tmp->lastName = new char[15];
    cout << "Please enter first name of the student: " << endl;
    cin >> tmp->firstName;
    cout << "Please enter last name of the student: " << endl;
    cin >> tmp->lastName;
    cout << "Please enter the student ID of the student: " << endl;
    cin >> tmp->studentID;
    cout << "Please enter the GPA of the student: " << endl;
    cin >> tmp->gpa;
    pnt = tmp;
    studentCount++;
  }
  else { // Normal scenario for all other cases
    node *tmp = new node;
    tmp->next = NULL;
    tmp->firstName = new char[15];
    tmp->lastName = new char[15];
    cout << "Please enter first name of the student: " << endl;
    cin >> tmp->firstName;
    cout << "Please enter last name of the student: " << endl;
    cin >> tmp->lastName;
    cout << "Please enter the student ID of the student: " << endl;
    cin >> tmp->studentID;
    cout << "Please enter the GPA of the student: " << endl;
    cin >> tmp->gpa;
    tmp->next = pnt;
    pnt = tmp;
    studentCount++;
  }
}

//This is a function that deletes a specific student from the linked list. This one also takes in the location of the list and the address of student count so it can be edited
void deleteStudent(node *&pnt, int &studentCount) {
  int deleter = 0;
  cout << "What is the student ID of the student you want to delete?" << endl;
  cin >> deleter;
  node *finder = pnt;
  node *after = pnt;
  node *before = pnt;
  for (int i = 0; i < studentCount; i++) { // Goes through all the nodes in the linked list
    if (finder->studentID == deleter) { // If current node is the one we are looking for
      if (i != 0) { // Checks if it is not the first term in the linked list
        after = finder->next;
        delete finder->firstName;
        delete finder->lastName;
        delete finder;
        before->next = after;
        studentCount--;
        break; // Breaks out of the loop
      }
      else { // If first term in the linked list
        delete finder->firstName;
        delete finder->lastName;
        after = finder->next;
        delete finder;
        pnt = after;
        studentCount--;
        break;
      }
    }
    else { // Moves pointer to next node
      if (i == 0) { // Only moves finder the first time
        finder = finder->next;
      }
      else { // Moves both finder and before every time after that
        finder = finder->next;
        before = before->next;
      }
    }
  }
}

// This is used to clear all allocated memory after the user quits from the program 
void deleteAll(node *&pnt, int &studentCount) {
  node *current = pnt;
  node *next = pnt;
  for (int i = 0; i < studentCount; i++) {
        next = current->next;
        delete current->firstName;
        delete current->lastName;
        delete current;
        current = next;
  }
}

// This goes through every node on the linked list and prints out their information
void printStudent(node *&pnt, int &studentCount) {
     node *current = pnt;
    for (int i = 0; i < studentCount; i++) {
        cout << "Name: " << current->firstName << " " << current->lastName << ", Student ID: " << current->studentID << ", GPA: " << current->gpa << endl;
        current = current->next;
    }
}