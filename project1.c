#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15


struct Contact {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
};

void addContact(struct Contact contacts[], int* numContacts);
void viewContacts(struct Contact contacts[], int numContacts);
void searchContact(struct Contact contacts[], int numContacts);

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    int choice;

    do {
        printf("\nPhonebook Management System\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                viewContacts(contacts, numContacts);
                break;
            case 3:
                searchContact(contacts, numContacts);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addContact(struct Contact contacts[], int* numContacts) {
    if (*numContacts >= MAX_CONTACTS) {
        printf("Phonebook is full. Cannot add more contacts.\n");
        return;
    }

    struct Contact newContact;

    printf("Enter name: ");
    scanf(" %[^\n]s", newContact.name);

    printf("Enter phone number: ");
    scanf(" %[^\n]s", newContact.phone);

    contacts[*numContacts] = newContact;
    (*numContacts)++;

    printf("Contact added successfully.\n");
}

void viewContacts(struct Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        printf("Phonebook is empty.\n");
        return;
    }

    printf("Phonebook Contacts:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%d. Name: %s\n   Phone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void searchContact(struct Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        printf("Phonebook is empty. Cannot search for contacts.\n");
        return;
    }

    char searchName[MAX_NAME_LENGTH];
    printf("Enter the name to search: ");
    scanf(" %[^\n]s", searchName);

    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}
