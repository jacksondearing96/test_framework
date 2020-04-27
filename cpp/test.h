#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

#define COLOUR_RESET "\x1b[0m"
#define GREEN "\x1b[42m"
#define RED "\033[0;31m"

#define FATAL 1

namespace Test
{
	std::string Green(std::string s) 
	{
		return GREEN + s + COLOUR_RESET;
	}

	std::string Red(std::string s)
	{
		return RED + s + COLOUR_RESET;
	}

	void PrintPass(const std::string& description)
	{
		std::cout << Green("PASS:") << " " << description << std::endl;
	}

	template<class T, class Y> 
	void PrintFail(const T& actual, const Y& expected, const std::string& description, const std::string& error_type = "") 
	{
	
            std::cout << Red("FAIL");
	    if (!error_type.empty())
		    std::cout << " (" << error_type << ")";
	    std::cout << std::endl;

            std::cout << "\t" << description << std::endl;
            std::cout << "\tExpected: " << expected << std::endl;
            std::cout << "\tActual: " << actual << std::endl;
	}
	template <class T1, class T2>
	void EXPECT_EQ(const T1& actual, const T2& expected, const std::string& description, bool fatal = false)
    {	
        if (actual == expected) return PrintPass(description);
	PrintFail(actual, expected, description);
	if (fatal) exit(1);
    }

	template <class T>
	void ASSERT_EQ(const T& actual, const T& expected, const std::string& description) {
		EXPECT_EQ(actual, expected, description, FATAL);
	}

	void EXPECT_TRUE(bool actual, const std::string& description, bool fatal = false) 
	{
		if (actual) return PrintPass(description);
		PrintFail(actual, true, description);
		if (fatal) exit(1);
	}

	void ASSERT_TRUE(bool actual, const std::string& description) 
	{
		EXPECT_TRUE(actual, description, FATAL);
	}

	void SizeError(size_t actual, size_t expected, const std::string& description) 
	{
		PrintFail(actual, expected, description, "Vector size error");
	}

	template<class T>
	void VectorElementError(const T& actual, const T& expected, size_t index, const std::string& description)
	{
		PrintFail(actual, expected, description, "Vector element error at index " + std::to_string(index));
	}


	template<class T>
	void EXPECT_VECTOR_EQ(const std::vector<T>& actual, const std::vector<T> expected, const std::string& description) 
	{
		if (actual.size() != expected.size())
			return SizeError(actual.size(), expected.size(), description);


		for (size_t i = 0; i < actual.size(); ++i) 
		{
			if (actual[i] != expected[i])
				return VectorElementError(actual[i], expected[i], i, description);
		}

		PrintPass(description);
	}

}
