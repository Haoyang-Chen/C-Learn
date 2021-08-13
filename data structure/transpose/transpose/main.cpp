//
//  main.cpp
//  transpose
//
//  Created by Haoyang Chen on 2021/8/8.
//

#include <iostream>
using namespace std;

int Transpose(int n)
{
  int count=0;
  for(int i=0;i<n-1;i++)
  {
    count++;
    for(int j=i+1;j<n;j++)
    {
      count++;
      count+=3;
    }
      count++;
  }
  count++;
    return count;
}
int main(int argc, const char * argv[]) {
    for (int i=1;i<=5;i++)
    {
        int c=Transpose(i);
        cout<<c<<endl;
    }
    return 0;
}
