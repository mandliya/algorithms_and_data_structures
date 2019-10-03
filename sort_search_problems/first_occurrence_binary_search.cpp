/**
 *  Given a sorted array, and a number.
 *  User binary search to find the number, and return the index.If number occurrs multiple times
 *  return the first index. If number does not exist, return -1.
 */

 #include <iostream>
 #include <vector>

 int firstOccurrenceBinarySearch( const std::vector<int> & vec, int key )
 {
   int high = vec.size() - 1;
   int low  = 0;
   int firstOccurrance = -1;
   while ( low <= high ) {
     int mid = (high + low) / 2;
     if ( key < vec[mid] ) {
       high = mid - 1;
     } else if ( key > vec[mid]) {
       low = mid + 1;
     } else {
       firstOccurrance = mid;
       high = mid - 1 ;
     }
   }
   return firstOccurrance;
 }

void printVec( const std::vector<int> & vec)
{
  for ( auto & i : vec ) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

 int main()
 {
   std::vector<int> vec{ 1, 1, 1, 1, 2, 2, 3, 3, 3 };
   std::cout << "Contents of vector:\n";
   printVec(vec);
   std::cout << "First Occurrence of 1 in the vector is at index : "
             << firstOccurrenceBinarySearch(vec, 1) << std::endl;

   return 0;
 }
