
#include <iostream>
#include <fstream>
#include <string>

void foo(int a)
{
    std::cout << "Adresa var a in foo este: " << &a << std::endl;
    std::cout << "Val lui a este " << a << std::endl;
}

void foo_pointer(int* a)
{
	std::cout << "Adresa var a in foo_pointer este: " << a << std::endl;
	std::cout << "Val lui a este " << *a << std::endl;
}

void bad_function(int* ptr)
{
	int temp;
	ptr = &temp;
}

void initUserApp(std::string* user_name)
{
	if (user_name == nullptr)
	{
		std::cout << "Creating user name" << std::endl;
		*user_name = "Taifun20";
	}
	else if (user_name != nullptr)
	{
		std::cout << "User already configured" << std::endl;
	}
}

void reverseString(std::string& input)
{
	std::string res = "";
	for (int i = input.length(); i >= 0; i--)
	{
		res += input[i];
	}
	input = res;
}


int main()
{
	int a = 5;
    //& --> operator addresOf --> ne returneaza adresa variabilei
    std::cout << "Adresa var a in main este: " << &a << std::endl;

	std::string* my_user_ptr = nullptr; // ca putem folosi NULL sau 0
	std::string user;
	my_user_ptr = &user;
	initUserApp(my_user_ptr);
	//const int* my_int = &test;
	//*my_int = 99; nu merge deoarece avem eroare

	int my_array[5] = { 1,2,3,4,5 };
	int* my_iterator = &my_array[0];
	for (int i = 0; i < 5; i++)
	{
		std::cout << *my_iterator << std::endl;
		std::cout << "Adresa spre care pointuie my)iteratir " << my_iterator << std::endl;
		my_iterator++;
	}


    foo(a);
	foo_pointer(&a);
	std::string* food_ptr; // * inseamna pointer
	std::string mancare = "Pizza";
	food_ptr = &mancare; // Am facut ca pointerul nostru sa arate catre adresa lui mancare

	std::cout << "Adresa lui mancare : " << &mancare << std::endl;
	std::cout << "Pointerul mancare : " << food_ptr << std::endl;
	// *food_ptr = este pointerul food_ptr dereferentiat
	std::cout << "Valoarea adresei la care pointuie food_ptr : " << *food_ptr << std::endl;
	std::cout << "Valoarea originala a lui mancare : " << mancare << std::endl;
	*food_ptr = "Shaworma";
	std::cout << "Val lui mancare dupa modificare este " << mancare << std::endl;

	int* test_ptr;
	{
		int var_local = 5;
		// Nu este ok din punct de vedere logic
		// Poate genera comportament nedefinit
		// var_local este "distrusa" dupa ce se termina scope-ul
		// Iar test_ptr ramane agatat de adresa respectiva 
		test_ptr = &var_local;
	}//scope local
	// var_local nu mai exista deoarece este o variabila locala in scope-ul local 
	std::cout << "Val lui test_ptr " << *test_ptr << std::endl;
	*test_ptr = 100;
	std::cout << "Val lui test_ptr " << *test_ptr << std::endl;


	std::string food = "Bergher";
	std::string& my_ref = food;
	std::cout << "My food is " << food << std::endl;
	my_ref = "Ciola";
	std::cout << "My food is " << food << std::endl;

	std::string nex_food = my_ref; //Next food este ciola
	my_ref = "Bergher";
	std::cout << "My food is " << food << std::endl;
	std::cout << "My Next food is " << nex_food << std::endl; 

	reverseString(food);
	std::cout << "My food is " << food << std::endl;

}
















/* int x[10000000], y[10000000];
void CE_PRINT_IMAGE_PIXELS_() {
	//curl ascii.live/forrest
	int a = 1, b = 1;
	int word;
	std::fstream file;
	file.open("D:\\.CPP\\Pattern-Generator-master\\data_.txt");
	while (file >> word)
	{
		x[a++] = word;
		file >> word;
		y[b++] = word;
	}
	int p = 1, q = 1, left = 1, right = 1, flag = 1;
	int k = 1;
	while (p < a)
	{
		left = x[p++];
		right = y[q++];
		if (flag == 1)
		{
			for (int i = 1; i < right; i++)
			{
				std::cout << "   ";
			}
		}
		else
		{
			for (int i = y[q - 2]; i < right; i++)
				std::cout << "   ";
			flag = 0;
		}
		std::cout << "X";
		k = x[p];
		if (k > left)
		{
			std::cout << "\n";
			flag = 1;
		}
		else flag = 0;
	}
}
*/