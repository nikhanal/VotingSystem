#include <stdio.h>
#include <string.h>

typedef struct candidates
{
    int votes;
    char name[100];
    char sign[2];
}candidates;
void welcomeMessage()
{
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  *------------------*\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =                ELECTRONIC                 =");
    printf("\n\t\t\t        =                  VOTING                   =");
    printf("\n\t\t\t        =                 MACHINE                   =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  *------------------*\n");
}
void candidate(int number,candidates something[]){
    int number_of_candidates = number;
    for (int i = 0; i < number_of_candidates; i++)
    {
        printf("\nEnter name of candidate:");
        scanf("%s",something[i].name);
        fseek(stdin, 0, SEEK_END);

        printf("Enter sign of candidate: ");
        scanf("%s",something[i].sign);
    }

}
void display(int number, candidates can[]){
    int x = number;
    printf("You candidates are as follow:\n");
    printf("SN\t\tName\t\tSymbol\n");
    printf("\n/************************************************************/\n");
    for (int j = 0; j < x; j++)
    {
        printf("\n%d\t\t%s\t\t%s\n",j+1,can[j].name, can[j].sign);
    }

}

void vote(candidates vote[], int number_of_candidates){
    int y;
    char symbol[1];
    int num_of = number_of_candidates;
    for (int j = 0; j < num_of; j++)
    {
        vote[j].votes = 0;
    }
    fseek(stdin, 0, SEEK_END);
    printf("\nEnter '1' to continue voting '0' to exit: ");
    scanf("%i",&y);
    fseek(stdin, 0, SEEK_END);

    while (y == 1)
    {
        switch (y)
        {
        case 1:
            fseek(stdin, 0, SEEK_END);
            printf("Enter the symbol of your candidate: ");
            scanf("%s",symbol);
            for (int i = 0; i < num_of; i++)
            {   
                if (strcmp(vote[i].sign,symbol)==0)
                {
                    vote[i].votes++;
                }            
            }
            
        default:
            break;
        }
        fseek(stdin, 0, SEEK_END);
        
        printf("\nEnter '1' to continue voting '0' to exit: ");
        scanf("%i",&y);
        fseek(stdin, 0, SEEK_END);


    }
    
    for (int k = 0; k < num_of; k++)
    {
        printf("\nVote of %s is %i\n",vote[k].name,vote[k].votes);

    }
    
}

int main(){
    int choice;
    int num_of_candidates;
    welcomeMessage();
    printf("Enter number of candidates: ");
    scanf("%i",&num_of_candidates);
    candidates prop[num_of_candidates];
    candidate(num_of_candidates,prop);
    display(num_of_candidates,prop);
    vote(prop, num_of_candidates);
    return 0;
}