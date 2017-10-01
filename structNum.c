#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Cory Klish
//Joshua Pineda

//Comment this struct out to test
typedef struct
{
	int gross;
	int rating;
	char* movie_title;
}Records;

void mergeNum(Records list[], int left, int mid, int right){
	
    int LSize = mid - left + 1;
    int RSize =  right - mid;
 
	/*
    //Temp array dynamic allocation
    Records L[LSize], R[RSize];
	*/
	
	Records* LArr = malloc(sizeof(Records) * LSize);
	Records* RArr = malloc(sizeof(Records) * RSize);
	
	int l; //Left index counter
	int r; //Right index counter
	int m; //Merged index
 
    for (l = 0; l < LSize; l++){
        LArr[l] = list[left + l];
	}
	
    for (r = 0; r < RSize; r++){
        RArr[r] = list[mid + 1 + r];
	}
 
	//Merge subarrays
    l = 0; 
    r = 0; 
    m = left; 
    while (l < LSize && r < RSize){
		
        if (LArr[l].gross <= RArr[r].gross){
			
            list[m] = LArr[l];
            l++;
        }
        else{
			
            list[m] = RArr[r];
            r++;
        }
        m++;
    }
 
    while (l < LSize){
		
        list[m] = LArr[l];
        l++;
        m++;
    }
 
    while (r < RSize){
		
        list[m] = RArr[r];
        r++;
        m++;
    }
}
 
void sortNum(Records list[], int left, int right)
{
    if (left < right){
		
        int mid = left + (right - left) / 2;
 
        sortNum(list, left, mid);
        sortNum(list, mid + 1, right);
 
        mergeNum(list, left, mid, right);
    }
}

void printStructs(Records list[], int numStructs){
	
    int i;
    for (i = 0; i < numStructs; i++){
        printf("%d %d %s\n", list[i].gross, list[i].rating, list[i].movie_title);
	}
}
 
 char* sortType;
 
int main(int argc, char* argv[]){
	
	strcpy(sortType, argv[1]);
	
	Records newall[3];
    
	newall[0].gross = 200;
	newall[0].rating = 5;
	newall[0].movie_title = "The Dark Knight";
	newall[1].gross = 100;
	newall[1].rating = 4;
	newall[1].movie_title = "It";
	newall[2].gross = 150;
	newall[2].rating = 3;
	newall[2].movie_title = "Transformers";
	
    int numStructs = 3;
	
    printf("Beginning Array is: \n");
	printStructs(newall, numStructs);
 
    sortNum(newall, 0, numStructs - 1);
 
    printf("\nSorted array is \n");
    printStructs(newall, numStructs);
    return 0;
}