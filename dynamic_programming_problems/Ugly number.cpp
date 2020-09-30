# include<iostream>
using namespace std;

int min(int x, int y, int z) {            //find smallest among three numbers
   if(x < y) {
      if(x < z)
         return x;
      else
         return z;
   }else {
      if(y < z)
         return y;
      else
         return z;
   }
}

int getUglyNum(int n) {
   int uglyNum[n];          // To store ugly numbers
   int i2 = 0, i3 = 0, i5 = 0;

   //find next multiple as 1*2, 1*3, 1*5

   int next2mul = 2;
   int next3mul = 3;
   int next5mul = 5;
   int next = 1;              //initially the ugly number is 1

   uglyNum[0] = 1;

   for (int i=1; i<n; i++) {
      next = min(next2mul, next3mul, next5mul);       //find next ugly number
      uglyNum[i] = next;

      if (next == next2mul) {
         i2++;             //increase iterator of ugly numbers whose factor is 2
         next2mul = uglyNum[i2]*2;
      }

      if (next == next3mul) {
         i3++;             //increase iterator of ugly numbers whose factor is 3
         next3mul = uglyNum[i3]*3;
      }

      if (next == next5mul) {
         i5++;              //increase iterator of ugly numbers whose factor is 5
         next5mul = uglyNum[i5]*5;
      }
   }
   return next;        //the nth ugly number
}

int main() {
   int n;
   cout << "Enter term: "; cin >> n;
   cout << n << "th Ugly number is: " << getUglyNum(n) << endl;
} 
