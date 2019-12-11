//	-> Encryption By:
//			M Ahmed Tariq (2018231)
//
//	-> Decryption By:
//			M Qais Sultani (2018314)

#include <iostream>
#include <string>
#include <fstream>

using namespace::std;

string Decrypted;						// store all the decrypted text
char Character[66] = {
						'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
						'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
						' ', ',', '.', '\n',
						'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
						'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
						'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
};										// data which will be used for decryption

void DecryptedText(char temp)			// function will store the decrypted text in 'Decrypted' string
{
	Decrypted.push_back(temp);
}

void Decryption(int position, int key)	// function will perform all the decryption steps
{
	int Decryptedposition;
	if (position - key < 0)
	{
		Decryptedposition = 66 + position - key;
	}
	else
	{
		Decryptedposition = (position - key) % 66;
	}
	DecryptedText(Character[Decryptedposition]);
}

int indexFinder(char temp)				// function will find the index, from the data used for
{										// decryption, of the given character
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

int KeyFinder(char temp)
{
	int index = indexFinder(temp);
	int key = index - 3;
	return key;
}

int main()
{
	string EncryptedText;
	string DecryptedText;
	int index;
	int key_counter = 0;
	int key;
	
	cout << "NOTE: Program will read the text file name 'Assignment 1_Encryptedtext.txt' for data to be decrypted." << endl;
	system("pause");
	cout << endl << endl;

	ifstream input_file("Assignment 1_Encryptedtext.txt");		// opening encrypted text file and reading text form it
	if (input_file.is_open())
	{
		do
		{
			EncryptedText = "\0";
			getline(input_file, EncryptedText);
			//cout << EncryptedText;
			if (key_counter == 0)
			{
				key = KeyFinder(EncryptedText[0]);
				key_counter++;
			}
			if (!input_file.eof() && EncryptedText == "\0")
			{
				//cout << "\n";
				index = indexFinder('\n');
				Decryption(index, key);
			}
			else
			{
				for (int i = 0; i < EncryptedText.length(); i++)
				{
					index = indexFinder(EncryptedText[i]);
					Decryption(index, key);
				}
				if (!input_file.eof())
				{
					index = indexFinder('\n');
					Decryption(index, key);
				}
			}
		} while (!input_file.eof());
		input_file.close();
	}
	else
	{
		cout << endl << "'Assignment 1_Encryptedtext.txt' input_file could not Open!" << endl << endl;
		system("pause");
		return 0;
	}

	ofstream output_file;								// creating text file and saving decrypted text in it
	output_file.open("Assignment 1_Decryptedtext.txt");
	output_file << Decrypted;
	output_file << endl << endl << endl << "Key: " << key;
	cout << "Key: " << key << endl << endl;
	cout << Decrypted;
	output_file.close();
	cout << endl << endl << "NOTE: Decrypted Data had been stored in a file name 'Assignment 1_Decryptedtext.txt'." << endl;
}
