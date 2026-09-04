#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

char lines[MAX_LINES][MAX_LENGTH];
int lineCount = 0;

void insertLine(int position)
{
    int i;

    if (lineCount >= MAX_LINES)
    {
        printf("Document is full.\n");
        return;
    }

    if (position < 1 || position > lineCount + 1)
    {
        printf("Invalid line number.\n");
        return;
    }

    for (i = lineCount; i >= position; i--)
    {
        strcpy(lines[i], lines[i - 1]);
    }

    printf("Enter text: ");
    getchar();
    fgets(lines[position - 1], MAX_LENGTH, stdin);

    lines[position - 1][strcspn(lines[position - 1], "\n")] = '\0';

    lineCount++;

    printf("Line inserted successfully.\n");
}

void deleteLine(int position)
{
    int i;

    if (lineCount == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    if (position < 1 || position > lineCount)
    {
        printf("Invalid line number.\n");
        return;
    }

    for (i = position - 1; i < lineCount - 1; i++)
    {
        strcpy(lines[i], lines[i + 1]);
    }

    lineCount--;

    printf("Line deleted successfully.\n");
}

void displayDocument()
{
    int i;

    if (lineCount == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    printf("\n----- DOCUMENT -----\n");

    for (i = 0; i < lineCount; i++)
    {
        printf("%d: %s\n", i + 1, lines[i]);
    }

    printf("--------------------\n");
}

void searchDocument()
{
    char word[MAX_LENGTH];
    int i;
    int found = 0;

    printf("Enter word or phrase to search: ");
    getchar();
    fgets(word, MAX_LENGTH, stdin);

    word[strcspn(word, "\n")] = '\0';

    for (i = 0; i < lineCount; i++)
    {
        if (strstr(lines[i], word) != NULL)
        {
            printf("Found at line %d: %s\n", i + 1, lines[i]);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Word or phrase not found.\n");
    }
}

void showHelp()
{
    printf("\n===== LINE EDITOR COMMANDS =====\n");
    printf("insert <line>  - Insert a new line\n");
    printf("delete <line>  - Delete a line\n");
    printf("display        - Display document\n");
    printf("search         - Search for a word or phrase\n");
    printf("help           - Show commands\n");
    printf("quit           - Exit editor\n");
}

int main()
{
    char command[20];
    int position;

    printf("===== SIMPLE LINE EDITOR =====\n");
    printf("Type 'help' to see commands.\n");

    while (1)
    {
        printf("\n> ");
        scanf("%s", command);

        if (strcmp(command, "insert") == 0)
        {
            scanf("%d", &position);
            insertLine(position);
        }
        else if (strcmp(command, "delete") == 0)
        {
            scanf("%d", &position);
            deleteLine(position);
        }
        else if (strcmp(command, "display") == 0)
        {
            displayDocument();
        }
        else if (strcmp(command, "search") == 0)
        {
            searchDocument();
        }
        else if (strcmp(command, "help") == 0)
        {
            showHelp();
        }
        else if (strcmp(command, "quit") == 0)
        {
            printf("Exiting editor...\n");
            break;
        }
        else
        {
            printf("Unknown command. Type 'help'.\n");
        }
    }

    return 0;
}