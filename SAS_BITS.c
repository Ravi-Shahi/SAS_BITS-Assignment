#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <unistd.h>
#include<time.h>
//global_variables
//get_time_log
time_t tm;
//is_validate(0=false,1=true)
int i;
int is_validate;
int user_choice;
int invalid_try = 0;
//current_working_directory
char cwd[256];
//legitimate_users_data
char bits_user[5][20] = {"dev_ravi", "frn_raghu", "ods_tarun", "pbt_raushan", "grl_ritika"};
char bits_pass[5][20] = {"hey", "hi", "not", "hola", "adios"};
//user_credentials
char input_username[1][20];
char input_pass[1][20];
//total_numer_of_data
int total_user;
int total_pass;
//log_path
char path[256];
//create_log
void generate_log()
{
    time(&tm);
    FILE *fptr;
    fptr =fopen(strcat(cwd,"\\sas_bits_log.txt"),"a");
    if(fptr ==NULL)
    {
        printf("Log Doesn't exist!");
    }
    fprintf(fptr,"Invalid attempt on: %s",ctime(&tm));
    fprintf(fptr,"Username: %s, Password: %s\n",input_username[0],input_pass[0]);
    fclose(fptr);

}
//user_facility
void user_facility()
{
    printf("Welcome! \n");
    printf("You would like to: \n 1. Check Account Balance \n 2. Transfer Fund \n 3. Update Balance \n");
    printf("Enter your Choice:\n");
    //User_
    scanf("%d", &user_choice);
    switch (user_choice)
    {
    case 1:
        printf("You don't have any balance. Please start Earning.");
        break;
    case 2:
        printf("Told you no money. No Transfer Possible.");
        break;
    case 3:
        printf("Thanks for using Our System. Update of Balance will be done shortly.");
        break;
    default:
        printf("Thank you for your response.Please click \n 1 for Balance Enquiry \n 2 for Transfer Fund \n 3 for Balance Update.");
    }
}
//User_Authentication ----- Checking legitimate username and password.
void validate_cred()
{
    for (i = 0; i < 5; i++)
    {
        if (strcmp(bits_user[i], input_username[0]) == 0 && strcmp(bits_pass[i], input_pass[0]) == 0)
        {
            user_facility();
            is_validate = 1;
            invalid_try = 3;
            break;
        }
        else
        {
            is_validate = 0;
        }
    }
    if (is_validate != 1)
    {
        printf("Invalid Credentials! Please try Again.\n\n");

        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
           generate_log();
        }
    }
}
//user_input
void get_cred()
{
    //user_input_credentials
    if (total_user == total_pass && invalid_try < 3)
    {
        printf("Enter username:\n");
        scanf("%s", input_username[0]);
        printf("Enter password:\n");
        scanf("%s", input_pass[0]);
        invalid_try++;
        validate_cred();
    }
}
//verify_user
void verify_user()
{
    while (invalid_try != 4)
    {
        if (invalid_try < 3) 
        {
            get_cred();
        }
        else
        {
            if(is_validate!=1)
            {
                printf("Account locked. Maximum attempt reached!\nPlease contact your admin.");
            }
            
            invalid_try++;
        }
    }
}

//main_function
void main()
{
    total_user = sizeof(bits_user) / sizeof(bits_user[0]);
    total_pass = sizeof(bits_pass) / sizeof(bits_user[0]);
    verify_user();
    getch();
}
