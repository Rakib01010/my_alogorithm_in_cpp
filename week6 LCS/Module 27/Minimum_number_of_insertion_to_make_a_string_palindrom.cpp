//https://www.geeksforgeeks.org/minimum-insertions-to-form-a-palindrome-dp-28/
// A Naive recursive program to find minimum 
// number insertions needed to make a string 
// palindrome 
#include<bits/stdc++.h> 
using namespace std; 


// Recursive function to find 
// minimum number of insertions 
int findMinInsertions(char str[], int l, int h) 
{ 
	// Base Cases 
	if (l > h) return INT_MAX; 
	if (l == h) return 0; 
	if (l == h - 1) return (str[l] == str[h])? 0 : 1; 

	// Check if the first and last characters are 
	// same. On the basis of the comparison result, 
	// decide which subproblem(s) to call 
	return (str[l] == str[h])? 
					findMinInsertions(str, l + 1, h - 1): 
					(min(findMinInsertions(str, l, h - 1), 
					findMinInsertions(str, l + 1, h)) + 1); 
} 

// Driver code 
int main() 
{ 
	char str[] = "geeks"; 
	cout << findMinInsertions(str, 0, strlen(str) - 1); 
	return 0; 
} 

// sdf
//3


//                 abcde
//             /          |      
//            /           |        
//            bcde         abcd       bcd  <- case 3 is discarded as str[l] != str[h]
//        /   |   \       /   |   
//       /    |    \     /    |    
//      cde   bcd  cd   bcd abc bc
//    / | \  / | \ /|\ / | 
// de cd d cd bc c………………….