#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void hanoi_tower( int disknumber, int from, int to )
{
  int turn = ( 1 << disknumber ) - 1, step = 1, tmp, tmp2;
  from = 0;
  to = 1;

  if( disknumber % 2 == 0 )
    to = 2;
  else
    step++;

  while( turn-- ){
      for( tmp = turn, tmp2 = 0; tmp & 1; tmp2++, tmp >>= 1);

      if( tmp2 % 2 == 1 )
          cout << to + 1 << " -> " << from + 1 << endl;
      else
          cout << from + 1 << " -> " << to + 1 << endl;
      from = (from + step) % 3;
      to = ( to + step ) % 3;
  }
}

int main()
{
 int disk_number;

 cout << "How many disks to move ? :";
 cin >> disk_number;
 hanoi_tower( disk_number , 1 , 2);
}
