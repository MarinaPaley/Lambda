#include <iostream>
#include <functional>

// Это указатель на функцию.
// Функция лежит где-то в памяти. У этого "где-то" есть адрес.
typedef bool (*checker)(const int value);

void outer(checker function_pointer, const std::string& name, const int value);
void outer_function(
	const std::function<bool(const int)>& predicate,
	const std::string& name,
	const int value);


bool is_odd(const int value);
bool is_even(const int value);

int main()
{
	outer(is_odd, "is_odd", 5);
	outer(is_even, "is_even", 42);

	outer([](const int x) { return x % 2 == 1; }, "is odd", 5);

	auto deletor = 2;

	outer_function([&deletor](const int x) { return x % deletor == 1; }, "is odd", 5);

	//outer(nullptr, "is odd", 5);
	//outer_function(nullptr, "is odd", 5);

	return 0;
}

void outer(checker function_pointer, const std::string& name, const int value)
{
	std::cout << name << " "
		<< value << " --> "
		<< std::boolalpha << function_pointer(value)
		<< std::endl;
}

void outer_function(
	const std::function<bool(const int)>& predicate,
	const std::string& name,
	const int value)
{
	std::cout << name << " "
		<< value << " --> "
		<< std::boolalpha << predicate(value)
		<< std::endl;
}

bool is_odd(const int value)
{
	return value % 2 == 1;
}


bool is_even(const int value)
{
	return value % 2 == 0;
}
