#include <iostream>

using namespace std;

void hanoi (int n, char a, char b, char c) {
  cout<<"call hanoi function"<<"("<<a<<","<<b<<","<<c<<","<<n<<")"<<endl;
  if (n==1) {
    cout<<"Move disk "<<n<<" from "<<a<<" to "<<c<<endl;
  }
  else {
    hanoi(n-1,a,c,b);
    cout<<"Move disk "<<n<<" from "<<a<<" to "<<c<<endl;
    hanoi(n-1,b,a,c);
  }
}


int main() {
  clock_t begin = clock();

  int n;
  cout<<"Please enter the number of disks: ";
  cin>>n;
  hanoi(n,'A','B','C');

  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  cout<<"Running Time is: "<<elapsed_secs<<endl;

  return 0;
}


// int main() {
//   cout.setf(ios::fixed);
//
//   int n;
//   cout<<"Enter the number of disks: ";
//   cin>>n;
//
//   int i;
//   for(i=1; i<=n;i++)
//   {
//     clock_t begin = clock();
//     hanoi(i,'A','B','C');
//     clock_t end = clock();
//
//     double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
//     cout<<"The number of disks: "<<i<<", Running Time is: "<<elapsed_secs<<endl;
//   }
//
//   return 0;
// }
