#include <stdio.h>
#include <string.h>

int main(){

    // All the variables
    char adjective_1[50] = "";
    char adjective_2[50] = "";
    char adjective_3[50] = "";
    char noun[50] = "";
    char verb[50] = "";

    // All user inputs
    printf("Enter an adjective (description): ");
    fgets(adjective_1, sizeof(adjective_1), stdin);
    adjective_1[strlen(adjective_1) - 1] = '\0';

    printf("Enter a noun (animal of a person): ");
    fgets(noun, sizeof(noun), stdin);
    noun[strlen(noun) - 1] = '\0';

    printf("Enter an adjective (description): ");
    fgets(adjective_2, sizeof(adjective_2), stdin);
    adjective_2[strlen(adjective_2) - 1] = '\0';

    printf("Enter a verb (ending with -ing): ");
    fgets(verb, sizeof(verb), stdin);
    verb[strlen(verb) -1] = '\0';

    printf("Enter an adjective (description): ");
    fgets(adjective_3, sizeof(adjective_3), stdin);
    adjective_3[strlen(adjective_3) - 1] ='\0';

    //Final print statement
    printf("\nToday I went to a %s adoption centre.\nThere I saw %s.\n%s was %s and %s inside the cage.\nEveryone around there was %s. ", adjective_1, noun, noun, adjective_2, verb, adjective_3);


    return 0;

}