#include <iostream>

using namespace std;

int _mod(int a, int b) {
  int m = a%b;
  if (m<0) {
    m = (b<0) ? m - b : m + b;
  }
  return m;
}

int _rightmost(int n) {
  int bit = 1;
  if (n%2==0) {
    return bit;
  }
  else {
    while (true) {
      n = n>>1;
      bit++;
      if (n%2==0) {
        break;
      }
    }
  }
  return bit;
}

void toh(int n) {
  int T = 0;
  int count = 0;

  int P;
  if (n%2==0) {
    P=1;
  }
  else if (n%2==1) {
    P=-1;
  }

  int max = (1<<n)-1;


  while (true) {
    cout<<"Move Disk from Tower "<<_mod(T, 3)<<" to Tower "<<_mod((T+P),3)<<endl;
    T = _mod(T+P,3);
    count = count + 1;

    if (count>=max) {
      break;
    }
    else if (_rightmost(count)%2==0) {
      cout<<"Move Disk 1 from Tower "<<_mod((T-P),3)<<" to Tower "<<_mod((T+P),3)<<endl;
    }
    else {
      cout<<"Move Disk 1 from Tower "<<_mod((T+P),3)<<" to Tower "<<_mod((T-P),3)<<endl;
    }
    count = count + 1;
  }
}


// int main() {
//   cout.setf(ios::fixed);
//   clock_t begin = clock();
//
//   int n;
//   cout<<"Please enter the number of disks: ";
//   cin>>n;
//   toh(n);
//
//   clock_t end = clock();
//   double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
//   cout<<"Running Time is: "<<elapsed_secs<<endl;
//
//   return 0;
// }


int main() {
  cout.setf(ios::fixed);

  int n;
  cout<<"Enter the number of disks: ";
  cin>>n;

  int i;
  for(i=1; i<=n;i++)
  {
    clock_t begin = clock();
    toh(i);
    clock_t end = clock();

    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout<<"The number of disks: "<<i<<", Running Time is: "<<elapsed_secs<<endl;
  }

  return 0;
}
