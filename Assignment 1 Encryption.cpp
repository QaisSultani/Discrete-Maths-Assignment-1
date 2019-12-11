//	-> Encryption By:
//			M Ahmed Tariq (2018231)
//
//	-> Decryption By:
//			M Qais Sultani (2018314)

#include <iostream>
#include <string>
#include <fstream>

using namespace::std;

string Encrypted;				// store all the encrypted text
char Character[66] = {
						'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
						'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
						' ', ',', '.', '\n',
						'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
						'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
						'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
};								// data which will be used for encryption

void EncryptedText(char temp)	// function will store the encrypted text in 'Encrypted' string
{
	Encrypted.push_back(temp);
}

void Encryption(int position, int key)		// function will perform all the encryption steps
{
	int Encrytedposition;
	Encrytedposition = (position + key) % 66;
	EncryptedText(Character[Encrytedposition]);
}

int indexFinder(char temp)					// function will find the index, from the data used for
{											// encryption, of the given character
	int i;
	for (i = 0; i < 66; i++)
	{
		if (Character[i] == temp)
		{
			break;
		}
	}
	return i;
}

int main()
{
	string PlainText;
	int key;
	int index;
	cout << "NOTE: Program Will read the text file name 'Assignment 1_Plaintext.txt' for data to be encrypted." << endl;
	system("pause");
	cout << endl << endl;

	cout << "Enter Key: ";
	cin >> key;
	key = key % 66;
	
	ifstream input_file("Assignment 1_Plaintext.txt");		// opening plian text file and reading text form it
	if (input_file.is_open())
	{
		do
		{
			PlainText = "\0";
			getline(input_file, PlainText);
			/*if (PlainText == "\0")
			{
				count++;
				position = indexFinder('\n');
				Encryption(position, key);
			}
			else
			{
				count = 0;
				for (int i = 0; i < PlainText.length(); i++)
				{
					position = indexFinder(PlainText[i]);
					Encryption(position, key);
				}
				position = indexFinder('\n');
				Encryption(position, key);
			}*/
			if (!input_file.eof() && PlainText == "\0")
			{
				index = indexFinder('\n');
				Encryption(index, key);
			}
			else
			{
				for (int i = 0; i < PlainText.length(); i++)
				{
					index = indexFinder(PlainText[i]);
					Encryption(index, key);
				}
				if (!input_file.eof())
				{
					index = indexFinder('\n');
					Encryption(index, key);
				}
			}
		} while (!input_file.eof());
		input_file.close();
	}
	else
	{
		cout << endl << "'Assignment 1_Plaintext.txt' input_file could not Open!" << endl << endl;
		system("pause");
		return 0;
	}
	cout << endl << endl;

	ofstream output_file;									// creating text file and saving encrypted text in it
	output_file.open("Assignment 1_Encryptedtext.txt");
	output_file << Encrypted;
	cout << Encrypted;
	output_file.close();
	cout << endl << endl << "NOTE: Encrypted Data had been stored in a file name 'Assignment 1_Encryptedtext.txt'." << endl;

}
