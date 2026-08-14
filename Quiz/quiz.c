#include <stdio.h>
#include <string.h>


int main(){

    char questions [][100] = {{"What is the capital of India?"},
                              {"What is the capital of germany?"}, // Questions
                              {"What is the hottest Planet?"},
                              {"Who is the president of India?"},
                              {"In which galaxy do we live?"}};                    
    int NumQues = sizeof(questions) / sizeof(questions[0]); // No of questions to loop through

    char options [][100] = {{"A. Delhi\nB. Phagwara\nC. Amsterdam\nD. Washington D.C.\n "}, 
                            {"A. Iceland\nB. Berlin\nC. Sydney\nD. Bangkok\n"},
                            {"A. Jupiter\nB. Mars\nC. Neptune\nD. Venus\n"},
                            {"A. Narendra Modi\nB. Donald J. Trump\nC. Vladimir Putin\nD. Marco\n "}, // Options
                            {"A. Andromeda\nB. Milky Way\nC. Earth\nD. IC-1301\n"}};

    char AnswerKey[5] =  {'A','B','D','A','B'}; // Answer Key

    int CorrectAnswers = 0;
    int WrongAnswers = 0; // Score and tally
    char UserInput = '\0';

    for (int i = 0; i < NumQues; i++){
        printf("\n %s \n", questions[i]);
        printf("\n%s\n", options[i]);
        printf("Enter Your Answer: "); // Main loop to ask questions till the end
        scanf(" %c", &UserInput);
        while(getchar() != '\n')
        ;

            if(UserInput == AnswerKey[i]){ // Checking for correct answer
                CorrectAnswers++;
            }
            else{
                WrongAnswers++;
            }
    }

    printf("Correct Answers: %d\n", CorrectAnswers);
    printf("Wrong Answers: %d\n", WrongAnswers); // Final Output




    return 0;
}