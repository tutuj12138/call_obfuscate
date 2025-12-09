# call_obfuscate
## Function call confusion, using C++20
## Use

```
#include "call_obf.hpp"


// 测试函数
void test(int a, int b)
{
	CALL(int (*)(
		_In_z_ _Printf_format_string_ char const* const _Format,
		...), printf)(SecutyString("%d + %d = %d\n"), a, b, a + b);
}

REGISTER_FUNCTION(test)
REGISTER_FUNCTION(printf)
REGISTER_FUNCTION(system)

// 使用示例
int main()
{

	try {


		CALL(void(*)(int, int), test)(1, 2);

		CALL(int (*)(
			_In_z_ _Printf_format_string_ char const* const _Format,
			...), printf)(SecutyString("%d\r\n"), CALL_IN_MODULE(int(*)(), kernel32.dll, GetCurrentProcessId)());


		CALL_IN_MODULE(int(*)(HWND, LPCSTR, LPCSTR, UINT), user32.dll, MessageBoxA)(nullptr,
			SecutyString("Hello from secure call!"),
			SecutyString("Test"), MB_OK);

		CALL_IN_MODULE(int(*)(HWND, LPCWSTR, LPCWSTR, UINT), user32.dll, MessageBoxW)(nullptr,
			SecutyWString(L"Hello from secure call! -- WChar"),
			SecutyWString(L"Test -- WChar"), MB_OK);

	}
	catch (const std::exception& e)
	{
		std::cerr << SecutyString("Error: ") << e.what() << std::endl;
	}

	CALL(int (*)(char const*), system)(SecutyString("pause"));
	return 0;
}

```
## Usage effect
![alt text](img/image.png)

## v12.4
* Function calls and SecurityString implement the new control flow flattening function.

## to be implemented
* Supports wide characters
