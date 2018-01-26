#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

int _get_disk(int i) {
     int c = 0, x= i+1;
     for (c=0; x%2==0; c++) {
       x/=2;
     }
     return c;
}

int _movs(int i, int d) {
     while (d--!=0) {
       i/=2;
     }
     return (i+1)/2;
}

int _dirc(int d, int n) {
     return 2 - (n+d)%2;
}


void _move(int disk, int src, int dest) {
     //cout<<"Move Disk "<<(disk+1)<<" from Tower "<<(src+1)<<" to Tower "<<(dest+1)<<endl;
}


void execute(int n) {
     int lim = pow(2,n) - 1;
     for (int i=1; i<=lim; i++){
       int disk = _get_disk(i);
       int src = (_movs(i,disk)*_dirc(disk,n))%3;
       int dest= (src + _dirc(disk,n))%3;
       _move(disk, src, dest);
     }
}

int main() {

  int n;
  cout<<"Enter the number of disks: ";
  cin>>n;

  int i;
  for(i=0; i<n;i++)
  {
    clock_t begin = clock();
    execute(i);
    clock_t end = clock();

    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout<<"The number of disks: "<<i<<", Running Time is: "<<elapsed_secs<<endl;
  }

  return 0;
};
