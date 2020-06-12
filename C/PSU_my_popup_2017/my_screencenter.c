
#include <stdio.h>
#include <string.h>

int main()
{

    struct winsize w; 
    ioctl(0, TIOCGWINSZ, &w); 

    int columns = w.ws_col; 
    int rows = w.ws_row;


    //printf("Lines :  %d\n", rows);
    //printf("Columns ; %d\n", columns);

    char *string = "Hello World";
    int stringLength = strlen(string) / 2;



    printf("%*s\n", columns / 2 + stringLength, string );
    //getchar();                //Pause program

    return 0;
}

//Lines to print after = (lines in console) / 2; // Assuming your text is only 1 line. 
