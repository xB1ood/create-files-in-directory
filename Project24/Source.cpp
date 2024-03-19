#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <windows.h>

using namespace std;

class File {
	bool dirExists(const std::string& dirName_in)
	{
		DWORD ftyp = GetFileAttributesA(dirName_in.c_str());
		if (ftyp == INVALID_FILE_ATTRIBUTES)
			return false;  //something is wrong with your path!

		if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
			return true;   // this is a directory!

		return false;    // this is not a directory!
	}

	string rand_word(int size) {

		string word;


		for (int i = 0; i < size; i++) {
			word.push_back(char(rand() % 25 + 97));
		}

		return word;
	}

public:

	void file_create() {

		srand(time(0));

		string directory;
		fstream file;
		int size_word,count;
		do {
			cout << "Enter directory(use \\\\ to separate): ";
			cin >> directory;
			if (dirExists(directory) == false) {
				cout << endl << "     Invalid directory" << endl << endl;
				system("pause");
				system("cls");
			}
		} while (dirExists(directory) == false);

		cout << "Enter amount of files: ";
		cin >> count;
		cout << "Enter file name size: ";
		cin >> size_word;
		
		for(int i = 0; i < count; i++){

			string name = "\\" + rand_word(size_word);

			file.open(directory + name, ios::out);

			file.close();
		}
	}
};


int main() {

	File action;
	action.file_create();

}