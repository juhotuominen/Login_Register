#include<iostream>
#include<fstream>
#include<string>

std::string name, inName, registerName, choice, password, inPassword, registerPassword;

//Function for encrypting users password before saving it into txt file
std::string encryption(std::string epassword) {
	int i = 0;
	while (i < epassword.length()) {
		epassword[i] = epassword[i] + 2;
		++i;
	}
	return epassword;
}

//Function for decrypting users password from txt file before comparing to input password
std::string decryption(std::string epassword) {
	int i = 0;
	while (i < epassword.length()) {
		epassword[i] = epassword[i] - 2;
		++i;
	}
	return epassword;
}

//register function
int reg() {
	std::ofstream reg_data("register.txt");
	if (!reg_data.is_open()) {
		std::cout << "Failed to open file\n";
		return 0;
	}
	std::cout << "\n\n\n" << "New Username: ";
	std::getline(std::cin, registerName);
	std::cout << "New Password: ";
	std::getline(std::cin, registerPassword);

	registerPassword = encryption(registerPassword);

	reg_data << registerName;
	reg_data << "\n";
	reg_data << registerPassword;
	reg_data.close();

	std::cout << "\n...\n\n" << "Registration done.\n";
}


//login function
int login() {
	while (1) {
		std::ifstream log_data("register.txt");
		if (!log_data.is_open()) {
			std::cout << "Failed to open file";
			return 0;
		}
		std::getline(log_data, name, '\n');
		std::getline(log_data, password, '\n');

		log_data.close();
			password = decryption(password);

			std::cout << "\n\n\n"
				<< "Enter Username: ";
			std::getline(std::cin, inName);
			std::cout << "Enter Password: ";
			std::getline(std::cin, inPassword);

			if (inName == name && inPassword == password) {
				std::cout << "\n\nLogin Succesful\n\n" << "Welcome, " << inName << "\n";
				break;
			}
			else {
				std::cout << "\nLogin failed!";
			}
	}
	std::cout << "Your secret files are here" << "\n\n\n\n\n";
}



int main() {

	while (1) {
		std::cout << "\nHello!\n" << "Do you want to (Register / Exit / Login) ? ";
		std::getline(std::cin, choice);

		if (choice == "exit") {
			return 0;
		}

		if (choice == "register") {
			reg();
		}

		if (choice == "login") {
			login();
		}
	}
	return 0;
}