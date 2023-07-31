#include <string.h>
#include <conio.h>
#include <iostream> 
#include <stdio.h> 
#include <stdlib.h>  
#include <cstdio> 
#include <cstring>

using namespace std;

int KMPSearch(char *s, char *p) {
	int  n, m;
	int res = -1;
	n = strlen(s);
	m = strlen(p);
    int  i, j = 0, k = -1;
	int  *NewJ;
	NewJ = new int[n];
	NewJ[0] = -1;
	while (j < m - 1)		 	
    {	
			while (k >= 0 && p[j] != p[k])
				k = NewJ[k];
			j++;
			k++;
			if (p[j] == p[k])
				NewJ[j] = NewJ[k];
			else
				NewJ[j] = k;
	}
	i = 0;
	j = 0;
		while (j < m && i < n) 
		{
			while (j >= 0 && s[i] != p[j])
				j = NewJ[j];
			i++;
			j++;
		}
		if (j == m) cout << i - m;
		else cout << -1;
		delete[] NewJ;
	return res;
}

void main()
{
	char s[35], p[80];
	cout << "input s: ";
	gets_s(s, 80);
	cout << "input p: ";
	gets_s(p, 35);
	KMPSearch(s, p);
	_getch();
}
