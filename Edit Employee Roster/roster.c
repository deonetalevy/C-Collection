//Deone'Ta Levy
//Employee Roster: Add new employee to roster

#include <stdio.h>
#include <string.h>

struct record{
    char fname[20];
    char lname[20];
};

int namecmp (struct record eA, struct record eB);

int main() {
    FILE *ifp = fopen("input.txt", "r");
    FILE *ofp = fopen("roster.txt", "w");
    int num_people, i, flag=0;
    struct record new_employee, temp_employee;


    //-Ask the user for the first and last names of the new employee

    printf("What is the first name of the new employee?\n");
    scanf("%s", new_employee.fname);

    printf("What is the last name of the new employee?\n");
    scanf("%s",  new_employee.lname);

    //-Retrieve number of employees from input file

    fscanf(ifp, "%d", &num_people);


    //-Set up a loop for the number of employees
    //-Each time you should do the following:
    //--Read in a name from the input file
    //--Use the provided namecmp function to see if the
    //      new employee should be printed first
    //--Print the old employee to the output file

    for(i = 0; i < num_people; i++){
        fscanf(ifp, "%s", temp_employee.lname);
        fscanf(ifp, "%s", temp_employee.fname);

        namecmp(new_employee, temp_employee);

    //-If the new employee was never printed, print at the end of the file

        if (namecmp(new_employee, temp_employee) < 0 ) {
            fprintf(ofp, "%s %s\n", new_employee.fname, new_employee.lname);
            fprintf(ofp, "%s %s\n", temp_employee.fname, temp_employee.lname);
        }
        else {
            fprintf(ofp, "%s %s\n", temp_employee.fname, temp_employee.lname);

        }

    }

    fclose(ifp);
    fclose(ofp);

    return 0;
}

/* This function takes in two structures of type record.
 * eA = employee A and eB = employee B
 * This function compares the names of the two employee to see which should come first.
 * The function returns -1 if eA comes first, -1 if eB comes first, and 0 if the employees have the same name.
 */
int namecmp (struct record eA, struct record eB) {
    if (strcmp(eA.lname, eB.lname) < 0)
        return -1;
    else if (strcmp(eA.lname, eB.lname) > 0)
        return 1;
    else {
        if (strcmp(eA.fname, eB.fname) < 0)
            return -1;
        else if (strcmp(eA.fname, eB.fname) > 0)
            return 1;
        else
            return 0;
    }
}
