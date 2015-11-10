//Using circular arrays
#include <stdio.h>

#define MAX 10

void addqatbeg ( int *, int, int *, int * ) ;
void addqatend ( int *, int, int *, int * ) ;
int delqatbeg ( int *, int *, int * ) ;
int delqatend ( int *, int *, int * ) ;
void display ( int * ) ;
int count ( int * ) ;

int main( )
{
    int arr[MAX] ;
    int front, rear, i, n ;

//    clrscr( ) ;

    /* initialises data members */

    front = rear = -1 ;
    for ( i = 0 ; i < MAX ; i++ )
        arr[i] = 0 ;

    addqatend ( arr, 17, &front, &rear ) ;
    addqatbeg ( arr, 10, &front, &rear ) ;
    addqatend ( arr, 8, &front, &rear ) ;
    addqatbeg ( arr, -9, &front, &rear ) ;
    addqatend ( arr, 13, &front, &rear ) ;
    addqatbeg ( arr, 28, &front, &rear ) ;
    addqatend ( arr, 14, &front, &rear ) ;
    addqatbeg ( arr, 5, &front, &rear ) ;
    addqatend ( arr, 25, &front, &rear ) ;
    addqatbeg ( arr, 6, &front, &rear ) ;
    addqatend ( arr, 21, &front, &rear ) ;
    addqatbeg ( arr, 11, &front, &rear ) ;

    printf ( "\nElements in a deque: " ) ;
    display ( arr ) ;

    n = count ( arr ) ;
    printf ( "\nTotal number of elements in deque: %d", n ) ;

    i = delqatbeg ( arr, &front, &rear ) ;
    printf ( "\nItem extracted: %d", i ) ;

    i = delqatbeg ( arr, &front, &rear ) ;
    printf ( "\nItem extracted:%d", i ) ;

    i = delqatbeg ( arr, &front, &rear ) ;
    printf ( "\nItem extracted:%d", i ) ;

    i = delqatbeg ( arr, &front, &rear ) ;
    printf ( "\nItem extracted: %d", i ) ;

    printf ( "\nElements in a deque after deletion: " ) ;
    display ( arr ) ;

    addqatend ( arr, 16, &front, &rear ) ;
    addqatend ( arr, 7, &front, &rear ) ;

    printf ( "\nElements in a deque after addition: " ) ;
    display ( arr ) ;

    i = delqatend ( arr, &front, &rear ) ;
    printf ( "\nItem extracted: %d", i ) ;

    i = delqatend ( arr, &front, &rear ) ;
    printf ( "\nItem extracted: %d", i ) ;

    printf ( "\nElements in a deque after deletion: " ) ;
    display ( arr ) ;

    n = count ( arr ) ;
    printf ( "\nTotal number of elements in deque: %d", n ) ;
    return 0;
    //getch( ) ;
}

/* adds an element at the beginning of a deque */
void addqatbeg ( int *arr, int item, int *pfront, int *prear )
{
    int i, k, c ;

    if ( *pfront == 0 && *prear == MAX - 1 )
    {
        printf ( "\nDeque is full.\n" ) ;
        return ;
    }

    if ( *pfront == -1 )
    {
        *pfront = *prear = 0 ;
        arr[*pfront] = item ;
        return ;
    }

    if ( *prear != MAX - 1 )
    {
        c = count ( arr ) ;
        k = *prear + 1 ;
        for ( i = 1 ; i <= c ; i++ )
        {
            arr[k] = arr[k - 1] ;
            k-- ;
        }
        arr[k] = item ;
        *pfront = k ;
        ( *prear )++ ;
    }
    else
    {
        ( *pfront )-- ;
        arr[*pfront] = item ;
    }
}

/* adds an element at the end of a deque */
void addqatend ( int *arr, int item, int *pfront, int *prear )
{
    int i, k ;

    if ( *pfront == 0 && *prear == MAX - 1 )
    {
        printf ( "\nDeque is full.\n" ) ;
        return ;
    }

    if ( *pfront == -1 )
    {
        *prear = *pfront = 0 ;
        arr[*prear] = item ;
        return ;
    }

    if ( *prear == MAX - 1 )
    {
        k = *pfront - 1 ;
        for ( i = *pfront - 1 ; i < *prear ; i++ )
        {
            k = i ;
            if ( k == MAX - 1 )
                arr[k] = 0 ;
            else
                arr[k] = arr[i + 1] ;
        }
        ( *prear )-- ;
        ( *pfront )-- ;
    }
    ( *prear )++ ;
    arr[*prear] = item ;
}

/* removes an element from the *pfront end of deque */
int delqatbeg ( int *arr, int *pfront, int *prear )
{
    int item ;

    if ( *pfront == -1 )
    {
        printf ( "\nDeque is empty.\n" ) ;
        return 0 ;
    }

    item = arr[*pfront] ;
    arr[*pfront] = 0 ;

    if ( *pfront == *prear )
        *pfront = *prear = -1 ;
    else
        ( *pfront )++ ;

    return item ;
}

/* removes an element from the *prear end of the deque */
int delqatend ( int *arr, int *pfront, int *prear )
{
    int item ;

    if ( *pfront == -1 )
    {
        printf ( "\nDeque is empty.\n" ) ;
        return 0 ;
    }

    item = arr[*prear] ;
    arr[*prear] = 0 ;
    ( *prear )-- ;
    if ( *prear == -1 )
        *pfront = -1 ;
    return item ;
}

/* displays elements of a deque */
void display ( int *arr )
{
    int i ;

    printf ( "\n front->" ) ;
    for ( i = 0 ; i < MAX ; i++ )
        printf ( "\t%d", arr[i] ) ;
    printf ( " <-rear" ) ;
}

/* counts the total number of elements in deque */
int count ( int *arr )
{
    int c = 0, i ;

    for ( i = 0 ; i < MAX ; i++ )
    {
        if ( arr[i] != 0 )
            c++ ;
    }
    return c ;
}
