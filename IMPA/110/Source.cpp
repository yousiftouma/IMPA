#include <iostream>
#include <string>
using namespace std;
void one();
void two();
void three();
void four();
void five();
void six();
void seven();
void eight();

string indent = "  ";

int main ()
{
	char dummy;
	int M, N;
	cin >> M;
	while (M--)
	{
		cin >> N;
		if (N == 1) one();
		else if (N == 2) two();
		else if (N == 3) three();
		else if (N == 4) four();
		else if (N == 5) five();
		else if (N == 6) six();
		else if (N == 7) seven();
		else eight();
	}

	return 0;
}

void one()
{
	cout << "program sort(input,output);\nvar\n";
	cout << "a : integer;\nbegin\n";
	cout << indent << "readln(a);\n";
	cout << indent << "writeln(a)\n";
	cout << "end.\n";
}

void two()
{
	cout << "program sort(input,output);\nvar\n";
	cout << "a,b : integer;\nbegin\n";
	cout << indent << "readln(a,b);\n";
	cout << indent << "if a < b then\n";
	cout << indent + indent << "writeln(a,b)\n";
	cout << indent << "else\n";
	cout << indent + indent << "writeln(b,a)\n";
	cout << "end.\n";
}

void three()
{
	cout << "program sort(input,output);\nvar\n";
	cout << "a,b,c : integer;\nbegin\n";
	cout << indent << "readln(a,b,c);\n";
	cout << indent << "if a < b then\n";
	cout << indent + indent << "if b < c then\n";
	cout << indent + indent + indent << "writeln(a,b,c)\n";
	cout << indent + indent << "else if a < c then\n";
	cout << indent + indent+indent << "writeln(a,c,b)\n";
	cout << indent + indent << "else\n";
	cout << indent + indent + indent << "writeln(c,a,b)\n";
	cout << indent << "else\n";
	cout << indent + indent << "if a < c then\n";
	cout << indent + indent + indent << "writeln(b,a,c)\n";
	cout << indent + indent << "else if b < c then\n";
	cout << indent + indent + indent << "writeln(b,c,a)\n";
	cout << indent + indent << "else\n";
	cout << indent + indent +indent << "writeln(c,b,a)\n";
	cout << "end.\n";
}
void four()
{
	
}
void five(){}
void six(){}
void seven(){}
void eight(){}