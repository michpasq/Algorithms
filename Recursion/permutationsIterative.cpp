#include <iostream>
#include <string>
#include <stdio.h>

int main()
{
	std::string defaultString = "123";

	int perm=1, digits=defaultString.size();
	for (int i=1;i<=digits;perm*=i++);
	for (int a=0;a<perm;a++)
	{
		std::string avail=defaultString;
		for (int b=digits,div=perm;b>0; b--) 
		{
			div/=b;
			int index = (a/div)%b;
			printf("%c", avail[index] );
			//avail[index]=avail[b-1]; // non-lexigraphic but fast
			avail.erase(index,1) ; // lexigraphically correct
		}
		printf("\n");
	}
	printf("permutations:%d\n",perm);

	return 0;
}