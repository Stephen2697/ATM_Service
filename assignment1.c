//Author : Stephen Alger © 2016
//Version 1.0 - Post BETA, Submission & Interview
//Date of Last Major Update 13/11/2016 ~22:30. 
//Minor Modifications Made After Interview & Feedback  - 22/11/2016
//Continuous Assessment 2016 - Programming

/*This program carries out four basic functions of an ATM as specified in the CA assignment pdf. The program is menu driven using print statements and a loop to continuously output this menu to the user. The user's selection at this menu is entered to a variable and the resulting actions are taken as a result of a SWITCH statement. Throughout this code there are many measures taken to validate and error check extensively. If the user enters 1 at the menu they can check they are using the right pin. If the user enters 2 at the menu then they can change their password assuming they do infact have the old pin on hand. If the user enters 3 at the menu then the program will display the number of entries - sorted by incorrect and correct entries. Then finally if the user enters 4 at the main menu then they can confirm to end or continue the program. Otherwise the default aspect of the SWITCH statement will declare an invalid entry.*/

#include <stdio.h>
#define SIZE 4
#define CONTINUE 'C'
#define CONTINUE_small 'c'
#define QUIT 'Q'
#define QUIT_small 'q'

int main()
{
    /*Declaring & Assigning the arrays needed in storing pin*/ 
    int pin[SIZE]={1,2,3,4};
    
    /*Declaring the array needed in the user's guessing of the pin - placed here so it is reset everytime the while statement loops*/
    int pin_guess[SIZE];
       
    /*Declaring the arrays needed in changing pin. Placed here so it is reset everytime the while statement loops*/
    int pin_change1[SIZE];
    int pin_change2[SIZE];
    
    /*Declaring intger used to store the Main Menu User Selection*/
    int User_Input;
    
    /*Declaring the index integer used in transferring the 'pin_change' array to the 'pin' array */ 
    int index;

    /*Declaring the char used in the process of clearing buffer - equivalent to 'flushall' used on other OS*/
    int unwantedChars;
    
    /*Declaring the other integers needed in storing the user's menu selection 
    & monitoring correct and incorrect pin entries */
    int Correct_Entry;
    int Incorrect_Entry;

    /*Assigning the integers*/
    Correct_Entry = Incorrect_Entry = 0;

    /*Declaring character variable which will be used to keep loop running */
    char Loop_ON_OFF = CONTINUE;  
    

    
/*—————————START OF WHILE LOOP——————————*/
    
    
    /* Using a While loop to output the Main Menu to the user until they wish to exit */
    while (Loop_ON_OFF == CONTINUE || Loop_ON_OFF == CONTINUE_small) 
    {
        
        /*Assigning these following Variables & Arrays used in this program - separately assigned here so that they can be reset everytime the while statement loops*/
        
        /*Used in storing the user's menu selection and is used in controlling the switch statement*/
        User_Input=0;
        
        /*Declaring & Assigning new integer variables which are used in PIN change Validation. This is Used specifically in tracking if the newly entered pin is the same as the old */
        int Old_Equal_New=0; 
        
        /*this variable will equal 1 it is true or it will equal 0 if it is false*/
        int Correct_guess=1; 
        
        /*this variable will equal 1 it is true or it will equal 0 if it is false*/
        int New_Pins_Match=1; 
        
        /*this variable will be changed to 1 if there are illegal characters entered in a new pin code*/
        int illegal_entry_checker=0; 
        
        /*will store each number in newly entered pin and this array will be checked for characters with ASCII values outside of the desired range, if it passes these checks its contents will be converted and transferred to the pin_change1[] array*/
        char ASCII_value[SIZE] = {'o','o','o','o'}; 
        
        /*resetting the behind the scenes arrays each time the program runs*/
        for (index=0; index<SIZE; index++)
        {
            pin_guess[index]=0;
            
            pin_change1[index]=0;
            
            pin_change2[index]=0;
            
        } // end for
        
        
        /*Outputting Introduction and Menu to User & Inputting their Selection*/
        printf("\nWelcome to DIT Banking Services!\nSelect How we can help you from the Menu Below,\nUse the Corresponding Number followed by Pressing Enter.\n"); 

        printf("\n1. Enter PIN & Verification\n2. Change PIN\n3. Number of PIN Entries\n4. End program\n\n");

        scanf("%d", &User_Input);
        
        /*Clears buffer preventing issues, Used as a replacement for 'flushall' - as this code is not portable or recommdended for industry code. IE it is not compatible with MacOS*/
        while ((unwantedChars = getchar()) != '\n' && unwantedChars != EOF ); 

        printf("\n");

        /*Triggers compiler warning with MacOS Terminal Compiler due to it being invalid with C99 Standards - however it carries out the desired function*/
        //system("clear");

        
        
        
        /*Switch performs tasks based on User's Menu Selection*/ 
        switch (User_Input)
        {
                
/*—————————START OF CASE 1——————————*/      

            /*pin Verification function*/
            case 1 : 
            {
                printf("Type Each Number of Your PIN,\nand Press Enter after You Have entered Each Number.\n\n");
            
                /*The Following For loop Takes in user's guess at their pin code & stores it*/
                for (index=0; index<SIZE; index++)
                {
                    scanf("%d", &pin_guess[index]);
                       
                } // end for

                /*flush all effect, clears buffer*/
                while ((unwantedChars = getchar()) != '\n' && unwantedChars != EOF ); 
            
                
                /*The For and if statements below Verify that the pin guess entered matches the actual pin code. This method was used to avoid hard coding several conditions in an if statement which is not recommended*/
                for (index=0; index<SIZE; index++)
                {
                    
                    if (pin[index] != pin_guess[index])
                    {
                        Correct_guess = 0;
                        
                        index=SIZE; //ends for loop
                        
                    } // end if
                    
                } // end for
            

                /*code below is executed aslong as the user has entered their Pin correctly*/
                if (Correct_guess ==1) 
                {
                    
                    printf("\n\nYou Have Entered the Correct PIN\n\n");
                    
                    Correct_Entry++;
                    
                    break;
                    

                } // end if
            

                /*Otherwise if PIN was incorrectly entered the followoing code will be executed*/
                else 
                {
         
                    printf("\n\nYou Have Entered the Incorrect PIN\n\n");

                    Incorrect_Entry++;	/*Increments the incorrect entry counter*/

                    printf("You will be Redirected to the Main Menu\n\n");

                    break;
                    

                } // end else

            
                break;

            } // end case 1

/*—————————START OF CASE 2——————————*/  

            /*Change pin function*/
            case 2 :
            {
                
                printf("Type Each Number of Your PIN,\nand Press Enter after You Have entered Each Number.\n\n");

            
                /*Takes in user's guess at their pin code & stores it*/
                for (index=0; index<SIZE; index++)
                {
                    scanf("%d", &pin_guess[index]);
                    
                } // end for

                /*flush all effect, clears buffer*/
                while ((unwantedChars = getchar()) != '\n' && unwantedChars != EOF ); 
                 
            
                /*Code below Verifies that the pin guess entered matches the actual pin code. This method of Combining a For Loop and If Statement was used to avoid hard coding several conditions in an if statement which is not recommended*/
                for (index=0; index<SIZE; index++)
                {
                    
                    if (pin[index] != pin_guess[index])
                    {
                        Correct_guess = 0;
                        
                        index=SIZE; //ends for loop
                        
                    } // end if
                    
                } // end for
            
                
                /*Code executes if the user has entered the correct pin*/
                if (Correct_guess ==1) 
                {

                    printf("\n\nYou Have Entered the Correct PIN\n\n");

                    /*Increment the correct entry counter*/
                    Correct_Entry++; 

                    printf("Type Each Number of Your New PIN,\nand Press Enter after You Have entered Each Number.\n\n");

                    
                    /*validates user's first pin change entry using the ASCII Table - searches for illegal characters*/
                    for (index=0; index<SIZE; index++)
                    {
                        
                        /*Reads the user's number entry as a character NOT int*/
                        scanf("%c", &ASCII_value[index]); 
                        
                        /*clears buffer*/
                        while ((unwantedChars = getchar()) != '\n' && unwantedChars != EOF );

                        
                        /*The following ternary statement is a short hand form of an if-else and I have used it to assign a value to the illegal_entry_checker variable, if the condition is true it changes the pre-assigned value of O to the value 1, if the condition is false nothing happens. For this condition to be true the user must have entered a character with an ASCII value outside of the parameters set. 0 has an ASCII Value of 48 right up to 9 which has an ASCII value of 57. Therefore the user has entered a character outside of the 0-9 range. */
                        
                        illegal_entry_checker = (ASCII_value[index]<48 || ASCII_value[index]>57 )? 1 : illegal_entry_checker;
                        
                    } // end for


                    /*if illegal characters have been used this code gets executed. This method of combining the previous For Loop and this if statement was used to avoid hard coding several conditions in an if statement which is not recommended*/
                    if (illegal_entry_checker==1) 
                    {
                        
                        printf("\nYou have Used Illegal Characters in this New PIN,\nRedirecting to the Main Menu,\nPIN CODE UNCHANGED!\n\n");
                        
                        break;

                    } // end if


                    /*This code executes if there has not been illegal characters used and this code gets executed*/
                    else
                    {

                        /*Loop ASCII Value array into pin_change1*/
                        for (index=0; index<SIZE; index++)
                        {   
                            /*The following code converts ASCII number into regualar Int number... eg: 1 - 0 = 1 - whereas in ASCII values that is 49 - 48 = 1*/
                            ASCII_value[index] -= 48; 
                            
                            /*The following code stores verified new pin in the pin_change1 array*/
                            pin_change1[index] = ASCII_value[index]; 
 
                        } // end for loop
                        

                        /*This For and if work to Check if the old pin is the same as the new one - this method of using a For loop and if statment avoids hard coding too many conditions in a if statement*/
                        for (index=0; index<SIZE; index++)
                        {   
                            
                            /*The following ternary statement assigns the value either 0 or 1 if the condition is true or false respectively. For the condition to be true the */
                            
                            Old_Equal_New += (pin_change1[index]!=pin[index])? 0 : 1;

                        } // end for loop
                        

                        /* if the newly entered pin equals the old pin, this if condition will be triggered as the int variable in the if condition will have been incremented 4 times in the previous ternary statement */
                        if (Old_Equal_New == 4) 
                        {
                            
                            printf("\nYour new PIN is the same as your current PIN, Process Cancelled.\n\n");
                            
                            break;
 
                        } // end if

                        /*Code executes if the previous if statements are not true, therefore there have been no user errors thus far*/
                        else if (illegal_entry_checker != 1 && Old_Equal_New != 4)
                        {
                            
                            printf("\nRe-Enter Your New PIN\n\n");

                            /*Loop the second new pin entry into the pin_change2 array*/
                            for (index=0; index<SIZE; index++)
                            {  
                                scanf("%d", &pin_change2[index]);
                                
                            } // end for loop

                            
                            /*flush all effect, clears buffer*/
                            while ((unwantedChars = getchar()) != '\n' && unwantedChars != EOF); 

                            
                            /*Verfifying that the two newly entered passwords match & take appropriate action to save this pin code*/ 
                            for (index=0; index<SIZE; index++)
                            {
                                
                                if (pin_change1[index] != pin_change2[index])
                                {
                                    New_Pins_Match=0;
                                    
                                    /*Immediately terminates loop as if condition is true at any iteration then the two arrays are not equal*/
                                    index=SIZE; 
                                    
                                } // end if
                                
                            } // end for
                            
                            
                            /*If the two new PIN Codes match the followoing code is executed*/
                            if (New_Pins_Match==1) 
                            {
                                
                                printf("\nYou have changed your PIN Code successfully to: ");

                                
                                /*for loop used to print out & transfer contents of 'pin_change2' array to 'pin' array*/
                                for (index=0; index <SIZE; index++)
                                {
                                    pin[index] = pin_change2[index];

                                    printf("[%d]", pin[index]);
                                    
                                } // end for loop 

                                
                                printf(".\n\n");

                                break;
                                
                            } // end if
                            
                            
                            /* New Pin entries did not match*/
                            else 
                            {
                                printf("\nYour two new PIN entries did not match,\nTry Again From the Main Menu,\nPIN CODE UNCHANGED!\n\n");

                                break;
                            
                            } // end inner else
                            
                            
                            break;

                        } // end else if

                        
                        break;
                        
                    } // end outer else 
                    
                    break;
 
                } // end if
            
            
                /*Otherwise if PIN was incorrectly entered the followoing code will be executed*/
                else 
                {
                    printf("\n\nYou Have entered the Incorrect PIN\n\n");

                    /*Increments the incorrect entry counter*/
                    Incorrect_Entry++;	

                    printf("You will be Redirected to the Main Menu\n\n");

                    break;

                } // end else
            

                break;
            
            }// end case 2 
            
/*—————————START OF CASE 3——————————*/
                
            /*The following case will Display correct entries*/
            case 3 : 
            {
                printf("You Entered your PIN Correctly %d Times and Incorrectly %d Times.\n", Correct_Entry, Incorrect_Entry);
                
                break;

            } // end case 3
                

/*——————————START OF CASE 4—————————*/

            case 4 : // End program
            {
            
                Loop_ON_OFF = CONTINUE;

                printf("Are you sure you want to sign out of this ATM?\nEnter the letter 'Q' to Quit or 'C' to Continue Program.\n\n");

                Loop_ON_OFF = getchar();
                
                /*flush all effect, clears buffer*/
                while ((unwantedChars = getchar()) != '\n' && unwantedChars != EOF ); 

            
                if (Loop_ON_OFF == QUIT || Loop_ON_OFF == QUIT_small)
                {
                    printf("\nYou have Terminated this ATM Interaction\n\n");
                    
                    printf("Thank You for Banking with DIT Bank plc...\nCome Back Another Time to Keep Our Shareholders Happy!\n\n");
                    
                    return 0;
                    
                } // end if
            

                else if (Loop_ON_OFF == CONTINUE || Loop_ON_OFF == CONTINUE_small)
                {
                    printf("\nProcess Cancelled, Continuing Program and Returning to Main Menu\n");
                    
                    break;

                } // end else if

            
                else 
                {
                    printf("\nYou Entered an Unexpected Value, Returning to Main Menu\n");
                    
                    Loop_ON_OFF = CONTINUE ;
                    
                    break;
                } //end else
                
            
                break;

            } // end case 4

/*—————————START OF DEFAULT CASE——————————*/  

            default :
            {
                printf("You Have Made an Invalid Entry... \n");
                
                break;

            } // end default

            break;
                
        } // end switch

    } // end while

    return 0;
    
} //end main
	
	

