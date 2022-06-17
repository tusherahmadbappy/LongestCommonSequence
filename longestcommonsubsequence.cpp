#include<iostream>

using namespace std;

void lcs(char x[],char y[])
{
    int m=strlen(x);
    int n=strlen(y);
    int lcs_table [m+1][n+1];

    for(int i=1;i<=m;i++)
    {
        lcs_table[i][0]=0;
    }
    for(int j=1;j<=n;j++)
    {
        lcs_table[0][j]=0;
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i]==y[j])
            {
                lcs_table[i][j]=lcs_table[i-1][j-1]+1;
            }
            else
            {
                lcs_table[i][j]=max(lcs_table[i-1][j],lcs_table[i][j-1]);
            }
        }
    }

  int index = lcs_table[m][n];
  char lcsAlgo[index + 1];
  lcsAlgo[index] = '\0';


  int i = m, j = n;

  while (i > 0 && j > 0) {
    if (x[i - 1] == y[j - 1]) {
      lcsAlgo[index - 1] = x[i - 1];
      i--;
      j--;
      index--;
    }

    else if (lcs_table[i - 1][j] > lcs_table[i][j - 1])
      i--;
    else
      j--;
  }


  // Printing the sub sequences
  cout << "x : " << x << "\ny : " << y << "\nLCS: " << lcsAlgo << "\n";

}

int main()
{
    char str1[20],str2[20];
    cout<<"Enter the first character: ";
    cin>>str1;

    cout<<"Enter the second characters: ";
    cin>>str2;

    lcs(str1,str2);


}
