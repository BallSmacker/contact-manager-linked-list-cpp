#include <iostream>
#include <string>
using namespace std;

struct Node {
	string name;
	string phone;
	Node* next;
};

Node* head = NULL;

void addContact() {
	Node* newNode = new Node;
	
	cout << "Enter name: ";
	getline(cin, newNode->name);
	
	cout << "Enter phone: ";
	getline(cin, newNode->phone);
	
	newNode->next = head;
	head = newNode;
	
	cout << "Contact added.\n";
}

void displayContacts() {
	if (head == NULL) {
		cout << "No contacts found.\n";
		return;
	}
	
	Node* temp = head;
	while (temp != NULL) {
		cout << "Name: " << temp->name << endl;
		cout << "Phone: " << temp->phone <<endl;
		cout << "---------------\n";
		temp = temp->next;
	}
}

void searchContacts(){
	if (head == NULL) {
		cout << "No contacts to search.\n";
		return;
	}
	
	string key;
	cout << "Enter name to search: ";
	getline(cin, key);
	
	Node* temp = head;
	while (temp != NULL) {
		if (temp->name == key) {
			cout << "\nContact found:\n";
			cout << "Name: " << temp->name << endl;
			cout << "Phone: " << temp->phone << endl;
			return;
		}
		temp = temp->next;
	}
	
	cout << "Contact not found.\n";
}

void deleteContact() {
	if (head == NULL) {
		cout << "No contacts to delete.\n";
		return;
	}
	
	string key;
	cout << "Enter name to delete: ";
	getline(cin, key);
	
	Node* temp = head;
	Node* prev = NULL;
	
	// if Head needs to be deleted
	if (temp != NULL && temp->name == key)
{
		head = temp->next;
		delete temp;
		cout << "Contact deleted.\n";
		return;
	}
	
	// Search for the node to delete
	while (temp != NULL && temp->name !=key) {
		prev = temp;
		temp = temp->next;
	}
	
	// Not found
	if (temp == NULL) {
		cout << "Contact not found.\n";
		return;
	}
	
	// Unlick and delete
	prev->next = temp->next;
	delete temp;
	cout << "Contact deleted.\n";
}

int main() {
	int choice;
	
	do {
		cout << "\n1. Add Contact\n2. View Contacts\n3. Search Contacts\n4. Delete Contact\n0. Exit\n";
		cout << "Choice: ";
		cin >> choice;
		cin.ignore();
		
		switch (choice) {
			case 1:
				addContact();
				break;
			case 2:
				displayContacts();
				break;
			case 3:
				searchContacts();
				break;
			case 4:
				deleteContact();
				break;
		}	
		
	} while (choice != 0);
	
	return 0;
}
