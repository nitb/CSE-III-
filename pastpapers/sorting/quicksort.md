#Quick Sort

You might have learnt a lot about quicksort sort. The problem is you have to keep track of the revision tour.
Trust me this is supposed to be your last tour on quicksort sort.
I will be using C++ to code/design my algorithm.

#####Quicksort is also called sorting by randomization

Quicksort divides the list of numbers into low and high piles respectively. Suppose you choose any `p` from the list of numbers. It will be divided as the numbers greater than p and other pile where numbers are less than pile p.
This method is called `partitioning.`

Basically everything is done if you solve this partitioning problem.

Toooo eaassyy?? Yup, its easy and cooooll  :)


         quicksort(item_type s[],int low, int high){
           int p;          /*Partitioning position index*/
           if (high-1 > 0){
             p = partition(s,low,high);
             quicksort(s,low,p-1);
             quicksort(s,p+1,high);
           }
     }

We can partition the array in one linear scan for a particular pivot element by maintaining three section of the array: less than pivot(to the left of the firsthigh), greater than or equal to the pivot (between firsthigh and i), and unexplored(to right of i), as implemented below:

        int partition (item type s[], int low, int high){
            int i;
            int p;      // Pivot element index
            int firsthigh;    //divider position for the index.

            p = high;
            firsthigh = 1;
            for (int i = low; i < high; i++){
              if (s[i] < s[p]){
                swap(&s[i],&s[firsthigh]);
                firsthigh++;
              }
            }
            swap(&s[p],&s[firsthigh]);
            return firsthigh;
    }
