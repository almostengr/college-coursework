#ifndef SORT_H
#define SORT_H
//A generic sorting function.

template<class T>
void sort(T a[], int number_used);
//Precondition: number_used <= declared size of the array a.
//The array elements a[0] through a[number_used - 1] have values.
//Postcondition: The values of a[0] through a[number_used - 1] have
//been rearranged so that a[0] <= a[1] <= ... <= a[number_used - 1].

template<class T>
void swap_values(T& variable1, T& variable2);
//Interchanges the values of variable1 and variable2.

template<class T>
int index_of_smallest(const T a[], int start_index, int number_used);
//Precondition: 0 <= start_index < number_used. Array elements have values.
//Returns the index i such that a[i] is the smallest of the values
//a[start_index], a[star_index + 1], ..., a[number_used - 1].

template<class T>
void sort(T a[], int number_used)
{
    int index_of_next_smallest;
    for (int index = 0; index < number_used - 1; index++)
    {//Place the correct value in a[index]:
        index_of_next_smallest = 
                 index_of_smallest(a, index, number_used);
        swap_values(a[index], a[index_of_next_smallest]);
        //a[0] <= a[1] <=...<= a[index] are the smallest of the original array
        //elements. The rest of the elements are in the remaining positions.
    }
}

template<class T>
void swap_values(T& variable1, T& variable2)
{
    T temp;

    temp = variable1;
    variable1 = variable2;
    variable2 = temp;
}

template<class T>
int index_of_smallest(const T a[], int start_index, int number_used)
{
    T min = a[start_index];
    int index_of_min = start_index;

    for (int index = start_index + 1; index < number_used; index++)
        if (a[index] < min)
        {
            min = a[index];
            index_of_min = index;
            //min is the smallest of a[start_index] through a[index]
        }

    return index_of_min;
}
#endif