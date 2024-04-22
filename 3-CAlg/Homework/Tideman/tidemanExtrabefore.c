#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;


// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
bool cycle(int v, bool visited[], bool stack[]);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }


    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");


    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
// Enviar para o ranks a preferencia do voter.
bool vote(int rank, string name, int ranks[])
{
    // TODO


    for(int c = 0; c < candidate_count; c++){

    if(strcmp(name, candidates[c]) == 0){
        if(rank == 0){
            ranks[rank] = c;
            return true;
        }
        for(int c2 = 0; c2 < rank-1; c2++){
             if(c == ranks[c2])
             {
                return false;
             }
            }
    ranks[rank] = c;
    return true;
        }

    }

    return false;
}




// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{

    for(int i = 0; i < candidate_count; i++){
        for(int j = 0; j< candidate_count; j++){
            if(i == j){
                preferences[i][j] = 0;
            }
            else if(i <= j){
                preferences[ranks[i]][ranks[j]] += 1;
            }
        }
    }




    for(int c = 0; c < candidate_count; c++){
        ranks[c] = -1;
    }


//so pra testar
    for(int i = 0; i < candidate_count; i++){
        for(int j = 0; j < candidate_count; j++){
        printf("%i",preferences[i][j]);
        }
        printf("\n");
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)

{
    pair_count = 0;
    for(int i = 0; i < candidate_count; i++){
        for(int j = 0 + i; j < candidate_count; j++){

            if (preferences[i][j] >  preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count += 1;
            }
                else if(preferences[i][j] < preferences[j][i])
                {
                    pairs[pair_count].winner = j;
                    pairs[pair_count].loser = i;
                    pair_count += 1;
                }


        }

    }
    // TODO
        for(int i = 0; i < pair_count; i++){
        printf("%i  ,",pairs[i].winner);
        printf("%i  ,",pairs[i].loser);
        printf("\n");
    }

    printf("%i \n",pair_count);
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{

    // TODO
    int dif;
    int subsw;
    int subsl;

    for(int i = 0; i < pair_count-1; i++){

        for(int j = i + 1; j < pair_count; j++){

            if ((preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner])
            <
            (preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner]))
            {
            subsw = pairs[i].winner;
            subsl = pairs[i].loser;
            pairs[i].winner = pairs[j].winner;
            pairs[i].loser = pairs[j].loser;
            pairs[j].winner = subsw;
            pairs[j].loser = subsl;
            }
        }
       }

   for(int i = 0; i < pair_count; i++){
        printf("%i  ,",pairs[i].winner);
        printf("%i  ,",pairs[i].loser);
        printf("\n");
    }
        return;
    }



// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // Itera sobre cada par
    for (int i = 0; i < pair_count; i++)
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;

        // Bloqueia o par
        locked[winner][loser] = true;

        // Verifica se há ciclo
        bool visited[MAX] = {false};
        bool stack[MAX] = {false};
        if (cycle(winner, visited, stack))
        {
            // Se um ciclo for detectado, desbloqueia o par
            locked[winner][loser] = false;
        }
    }

    //locked[pairs[pair_count - 1].loser][pairs[pair_count - 1].winner] = true;
    //locked[pairs[pair_count - 1].winner][pairs[pair_count - 1].loser] = false;


    //teste print

     for(int i = 0; i < candidate_count; i++){
        for(int j = 0; j < candidate_count; j++){
        printf("%d",locked[i][j]);
        }
        printf("\n");
    }


    return;
}


//Cycle
// Função auxiliar para verificar se há um ciclo a partir de 'v'
bool cycle(int v, bool visited[], bool stack[])
{
    if (!visited[v])
    {
        visited[v] = true;
        stack[v] = true;

        for (int i = 0; i < candidate_count; i++)
        {
            if (locked[v][i] && stack[i])
            {
                return true;
            }
            if (locked[v][i] && cycle(i, visited, stack))
            {
                return true;
            }
        }
    }
    stack[v] = false;
    return false;
}




// Print the winner of the election
void print_winner(void)
{
    int win[candidate_count];
    int cont = 0;
    int teste = 0;
    int minus = 10;

    for(int i = 0; i < candidate_count; i++){
        cont = 0;

        for(int j = 0; j < candidate_count; j++){
            if(locked[i][j] == false){
                cont += 1;
            }

        }


    if(minus > cont){
        minus = cont;
    }

    win[i] = cont;


    }


    for(int i = 0; i < candidate_count; i++){

        if (win[i] == minus){
            printf("%s\n", candidates[i]);
            break;
        }


        }


    // TODO
    return;
}




