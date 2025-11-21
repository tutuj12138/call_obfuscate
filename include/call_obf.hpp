//                              ,--,      ,--,                                          
//                           ,---.'|   ,---.'|          ,----..                         
//   ,----..     ,---,       |   | :   |   | :         /   /   \      ,---,.     ,---,. 
//  /   /   \   '  .' \      :   : |   :   : |        /   .     :   ,'  .'  \  ,'  .' | 
// |   :     : /  ;    '.    |   ' :   |   ' :       .   /   ;.  \,---.' .' |,---.'   | 
// .   |  ;. /:  :       \   ;   ; '   ;   ; '      .   ;   /  ` ;|   |  |: ||   |   .' 
// .   ; /--` :  |   /\   \  '   | |__ '   | |__    ;   |  ; \ ; |:   :  :  /:   :  :   
// ;   | ;    |  :  ' ;.   : |   | :.'||   | :.'|   |   :  | ; | ':   |    ; :   |  |-, 
// |   : |    |  |  ;/  \   \'   :    ;'   :    ;   .   |  ' ' ' :|   :     \|   :  ;/| 
// .   | '___ '  :  | \  \ ,'|   |  ./ |   |  ./    '   ;  \; /  ||   |   . ||   |   .' 
// '   ; : .'||  |  '  '--'  ;   : ;   ;   : ;    ___\   \  ',  / '   :  '; |'   :  '   
// '   | '/  :|  :  :        |   ,/    |   ,/  .'  .`|;   :    /  |   |  | ; |   |  |   
// |   :    / |  | ,'        '---'     '---'.'  .'   : \   \ .'   |   :   /  |   :  \   
//  \   \ .'  `--''                      ,---, '   .'   `---`     |   | ,'   |   | ,'   
//   `---`                               ;   |  .'                `----'     `----'     
//                                       `---'                                          
#pragma once
#include <windows.h>
#include <string>
#include <random>
#include <chrono>
#include <map>
#include <array>
#include <iostream>
#include <cstring>

#pragma warning(disable:4244)
#pragma warning(disable:4838)
#pragma warning(disable:4267)
#pragma warning(disable:4309)
#pragma warning(disable:4305)

#define _XOR_KEY_ 0x78

#define CryptCall(FuncType, FuncAddr) \
    [this]() -> auto { \
        using MemberFuncPtr = FuncType;   \
        /* 安全类型转换：使用memcpy替代union */ \
        MemberFuncPtr original_ptr = FuncAddr; \
        \
        uint64_t func_address_int; \
        static_assert(sizeof(MemberFuncPtr) <= sizeof(uint64_t), \
                      "成员函数指针太大，无法用uint64_t表示"); \
        std::memcpy(&func_address_int, &original_ptr, sizeof(original_ptr)); \
        \
        /* 加密解密过程 */ \
        uint64_t decrypted_int = Crypt(func_address_int).decrypt_value(); \
        \
        MemberFuncPtr restored_ptr; \
        std::memcpy(&restored_ptr, &decrypted_int, sizeof(restored_ptr)); \
        \
        /* 返回一个接受参数的可调用对象 */ \
        return [this, restored_ptr](auto&&... args) -> void* { \
            return (this->*restored_ptr)(std::forward<decltype(args)>(args)...); \
        }; \
    }()

#define CALL(FuncType, func_name) \
    [&]() -> auto { \
        constexpr CompileTimeStringEncrypt<sizeof(#func_name)> encrypted_##func(#func_name); \
        return call<FuncType>(encrypted_##func.decrypt()); \
    }()

#define CALL_IN_MODULE(FuncType, module_name, func_name) \
	[&]() -> auto { \
        constexpr CompileTimeStringEncrypt<sizeof(#func_name)> encrypted_##func(#func_name); \
        constexpr CompileTimeStringEncrypt<sizeof(#module_name)> encrypted_##md(#module_name); \
        return call_in_module<FuncType>(encrypted_##md.decrypt(), encrypted_##func.decrypt()); \
    }()

#define REGISTER_FUNCTION(func) \
    namespace { \
        static const CompileTimeStringEncrypt<sizeof(#func)> encrypted_str_##func(#func); \
        \
        struct Register_##func { \
            Register_##func() { \
				reinterpret_cast<void(*)(const char*, size_t, void*)> (\
				Crypt(reinterpret_cast<uint64_t>(FunctionRegistry::register_function_encrypted)).decrypt_value())( \
                    encrypted_str_##func.getEncryptedData(), \
                    encrypted_str_##func.getEncryptedSize() - 1, \
                    (void*)func); \
            } \
        } register_instance_##func; \
    }

#define SecutyString(str) \
[&]() -> auto { \
        constexpr CompileTimeStringEncrypt<sizeof(##str)> encrypted_str(##str); \
        return encrypted_str.decrypt(); \
    }().c_str()


class Crypt {
private:
	uint64_t encrypted_value_;

	static constexpr uint64_t COMPILE_TIME_KEY = 0x9E3779B97F4A7C15ULL;
	uint64_t runtime_key_;

	uint8_t perm_table[64];
	uint8_t reverse_perm[64];

	FORCEINLINE void generate_permutation_tables()
	{
		uint8_t indices[64];
		for (int i = 0; i < 64; ++i)
		{
			indices[i] = i;
		}

		// 使用当前时间作为种子进行随机洗牌
		auto seed = std::chrono::high_resolution_clock::now()
			.time_since_epoch().count();
		std::mt19937 gen(static_cast<unsigned int>(seed));

		// Fisher-Yates洗牌算法生成随机排列
		for (int i = 63; i > 0; --i)
		{
			std::uniform_int_distribution<int> dist(0, i);
			int j = dist(gen);
			std::swap(indices[i], indices[j]);
		}

		// 复制到置换表
		for (int i = 0; i < 64; ++i)
		{
			perm_table[i] = indices[i];
		}

		// 生成逆置换表
		for (int i = 0; i < 64; ++i)
		{
			reverse_perm[perm_table[i]] = i;
		}
	}

	// 初始化运行时密钥
	FORCEINLINE void init_runtime_key()
	{
		auto seed = std::chrono::high_resolution_clock::now()
			.time_since_epoch().count();
		std::mt19937_64 gen(static_cast<unsigned int>(seed));
		runtime_key_ = gen();
	}

	// 基础加密函数（XTEA算法修正）
	FORCEINLINE uint64_t xtea_encrypt(uint64_t value, uint64_t key) const
	{
		uint32_t v0 = static_cast<uint32_t>(value);
		uint32_t v1 = static_cast<uint32_t>(value >> 32);
		uint32_t sum = 0;
		const uint32_t delta = 0x9E3779B9;

		// 将64位密钥拆分为4个32位部分
		uint32_t k[4] =
		{
			static_cast<uint32_t>(key),
			static_cast<uint32_t>(key >> 32),
			static_cast<uint32_t>(key) ^ 0x9E3779B9,
			static_cast<uint32_t>(key >> 32) ^ 0x9E3779B9
		};

		for (int i = 0; i < 32; ++i)
		{
			v0 += ((v1 << 4 ^ v1 >> 5) + v1) ^ (sum + k[sum & 3]);
			sum += delta;
			v1 += ((v0 << 4 ^ v0 >> 5) + v0) ^ (sum + k[sum >> 11 & 3]);
		}

		return (static_cast<uint64_t>(v1) << 32) | v0;
	}

	// 基础解密函数
	FORCEINLINE uint64_t xtea_decrypt(uint64_t value, uint64_t key) const
	{
		uint32_t v0 = static_cast<uint32_t>(value);
		uint32_t v1 = static_cast<uint32_t>(value >> 32);
		uint32_t sum = 0xC6EF3720; // delta * 32
		const uint32_t delta = 0x9E3779B9;

		// 将64位密钥拆分为4个32位部分
		uint32_t k[4] =
		{
			static_cast<uint32_t>(key),
			static_cast<uint32_t>(key >> 32),
			static_cast<uint32_t>(key) ^ 0x9E3779B9,
			static_cast<uint32_t>(key >> 32) ^ 0x9E3779B9
		};

		for (int i = 0; i < 32; ++i)
		{
			v1 -= ((v0 << 4 ^ v0 >> 5) + v0) ^ (sum + k[sum >> 11 & 3]);
			sum -= delta;
			v0 -= ((v1 << 4 ^ v1 >> 5) + v1) ^ (sum + k[sum & 3]);
		}

		return (static_cast<uint64_t>(v1) << 32) | v0;
	}

	// 位重排列加密
	FORCEINLINE uint64_t bit_permutation(uint64_t x) const
	{
		uint64_t result = 0;
		for (int i = 0; i < 64; ++i)
		{
			if (x & (1ULL << i))
			{
				result |= (1ULL << perm_table[i]);
			}
		}
		return result;
	}

	// 位重排列解密
	FORCEINLINE uint64_t bit_permutation_reverse(uint64_t x) const
	{
		uint64_t result = 0;
		for (int i = 0; i < 64; ++i)
		{
			if (x & (1ULL << i))
			{
				result |= (1ULL << reverse_perm[i]);
			}
		}
		return result;
	}

public:
	// 构造函数
	explicit Crypt(uint64_t value = 0)
	{
		generate_permutation_tables();  // 生成固定的随机置换表
		init_runtime_key();
		encrypted_value_ = encrypt_value(value);
	}

	// 拷贝构造函数 - 确保置换表也被复制
	Crypt(const Crypt& other)
		: encrypted_value_(other.encrypted_value_), runtime_key_(other.runtime_key_)
	{
		// 复制置换表
		std::copy(std::begin(other.perm_table), std::end(other.perm_table), perm_table);
		std::copy(std::begin(other.reverse_perm), std::end(other.reverse_perm), reverse_perm);
	}

	// 赋值操作符
	Crypt& operator=(const Crypt& other)
	{
		if (this != &other)
		{
			encrypted_value_ = other.encrypted_value_;
			runtime_key_ = other.runtime_key_;
			// 复制置换表
			std::copy(std::begin(other.perm_table), std::end(other.perm_table), perm_table);
			std::copy(std::begin(other.reverse_perm), std::end(other.reverse_perm), reverse_perm);
		}
		return *this;
	}

	Crypt& operator=(uint64_t value)
	{
		encrypted_value_ = encrypt_value(value);
		return *this;
	}

	// 加密值
	FORCEINLINE uint64_t encrypt_value(uint64_t value)
	{
		// 第一层：基础XTEA加密
		uint64_t layer1 = xtea_encrypt(value, COMPILE_TIME_KEY);

		// 第二层：位重排列
		uint64_t layer2 = bit_permutation(layer1);

		// 第三层：运行时密钥加密
		uint64_t layer3 = xtea_encrypt(layer2, runtime_key_);

		// 第四层：最终位操作
		uint64_t final_value = layer3 ^ COMPILE_TIME_KEY;
		final_value = (final_value >> 13) | (final_value << (64 - 13)); // 循环右移13位

		return final_value;
	}

	// 解密值
	FORCEINLINE uint64_t decrypt_value() const
	{
		// 反转第四层
		uint64_t layer3 = (encrypted_value_ << 13) | (encrypted_value_ >> (64 - 13));
		layer3 ^= COMPILE_TIME_KEY;

		// 反转第三层
		uint64_t layer2 = xtea_decrypt(layer3, runtime_key_);

		// 反转第二层
		uint64_t layer1 = bit_permutation_reverse(layer2);

		// 反转第一层
		uint64_t original_value = xtea_decrypt(layer1, COMPILE_TIME_KEY);

		return original_value;
	}

	// 获取加密后的值
	FORCEINLINE uint64_t get_encrypted() const
	{
		return encrypted_value_;
	}

	// 设置新值
	FORCEINLINE void set_value(uint64_t value)
	{
		encrypted_value_ = encrypt_value(value);
	}

	// 操作符重载
	FORCEINLINE operator uint64_t() const
	{
		return decrypt_value();
	}

	// ... 其他操作符和比较操作符保持不变
	FORCEINLINE Crypt& operator+=(uint64_t other)
	{
		uint64_t current = decrypt_value();
		set_value(current + other);
		return *this;
	}

	FORCEINLINE Crypt& operator-=(uint64_t other)
	{
		uint64_t current = decrypt_value();
		set_value(current - other);
		return *this;
	}

	FORCEINLINE Crypt operator+(uint64_t other) const
	{
		Crypt result(*this);
		result += other;
		return result;
	}

	FORCEINLINE Crypt operator-(uint64_t other) const
	{
		Crypt result(*this);
		result -= other;
		return result;
	}

	// 比较操作符
	FORCEINLINE bool operator==(const Crypt& other) const
	{
		return decrypt_value() == other.decrypt_value();
	}

	FORCEINLINE bool operator!=(const Crypt& other) const
	{
		return !(*this == other);
	}

	FORCEINLINE bool operator<(const Crypt& other) const
	{
		return decrypt_value() < other.decrypt_value();
	}

	FORCEINLINE bool operator>(const Crypt& other) const
	{
		return decrypt_value() > other.decrypt_value();
	}

	// 新增：获取置换表信息（用于调试或序列化）
	FORCEINLINE void get_permutation_table(uint8_t* table) const
	{
		std::copy(perm_table, perm_table + 64, table);
	}

	FORCEINLINE void get_reverse_permutation_table(uint8_t* table) const
	{
		std::copy(reverse_perm, reverse_perm + 64, table);
	}
};

template <size_t N>
class CompileTimeStringEncrypt {
private:
	std::array<char, N> encrypted_data_;
	static constexpr char XOR_KEY = _XOR_KEY_; 

public:
	constexpr CompileTimeStringEncrypt(const char(&str)[N])
	{
		for (size_t i = 0; i < N; ++i)
		{
			auto v0 = str[i] ^ (XOR_KEY + i);
			auto v1 = v0 ^ (XOR_KEY * i);
			auto v2 = v1 ^ XOR_KEY;
			encrypted_data_[i] = v2; 
		}
	}

	std::string decrypt() const {
		std::string result;
		result.reserve(N);
		for (size_t i = 0; i < N - 1; ++i)
		{ 
			// 排除null终止符
			auto v2 = encrypted_data_[i] ^ XOR_KEY;
			auto v1 = v2 ^ (XOR_KEY * i);
			auto v0 = v1 ^ (XOR_KEY + i);
			result += v0;
		}
		return result;
	}

	// 获取加密数据指针
	const char* getEncryptedData() const { return encrypted_data_.data(); }

	// 获取加密数据长度
	constexpr size_t getEncryptedSize() const { return N; }
};

std::string runtime_string_encrypt(const std::string& input)
{
	static constexpr char XOR_KEY = _XOR_KEY_;
	std::string output = input;
	for (size_t i = 0; i < input.length(); ++i)
	{
		auto v2 = input[i] ^ XOR_KEY;
		auto v1 = v2 ^ (XOR_KEY * i);
		auto v0 = v1 ^ (XOR_KEY + i);
		output[i] = v0;
	}
	return output;
}

class FunctionRegistry
{
private:
	static std::map<std::string, void*>& get_function_map()
	{
		static std::map<std::string, void*> function_map;
		return function_map;
	}

public:
	static void register_function_encrypted(const char* encrypted_name, size_t encrypted_size, void* function)
	{
		std::string key(encrypted_name, encrypted_size);
		get_function_map()[key] = function;
	}

	static void* get_function(const std::string& name)
	{
		std::string encrypted_name = runtime_string_encrypt(name);
		auto it = get_function_map().find(encrypted_name);
		return (it != get_function_map().end()) ? it->second : nullptr;
	}

	static bool is_function_registered(const std::string& name)
	{
		std::string encrypted_name = runtime_string_encrypt(name);
		return get_function_map().find(encrypted_name) != get_function_map().end();
	}
};

template<typename FuncType>
class CallBuilder {
private:
	std::string func_name_;
	std::string module_name_;
	bool has_module_ = false;
	void* func_ptr_ = nullptr;
	std::unique_ptr<Crypt> crypt_func_ptr_;

private:
	void* get_kernel32_base()
	{
		uint64_t peb = __readgsqword(Crypt(0x60).decrypt_value());
		uint64_t ldr = *(uint64_t*)(peb + Crypt(0x18).decrypt_value());
		uint64_t InMemoryOrderModuleList = *(uint64_t*)(ldr + Crypt(0x20).decrypt_value());
		uint64_t kernelBase = *(uint64_t*)(*(uint64_t*)(*(uint64_t*)(*(uint64_t*)(InMemoryOrderModuleList))) + Crypt(0x20).decrypt_value());
		return reinterpret_cast<void*>(kernelBase);
	}

	void* get_func_by_eat(void* base, const std::string& func_name)
	{
		if (base == nullptr) return nullptr;

		auto dos = reinterpret_cast<PIMAGE_DOS_HEADER>(base);
		if (Crypt(dos->e_magic).decrypt_value() != Crypt(IMAGE_DOS_SIGNATURE).decrypt_value())
			return nullptr;

		auto nt = reinterpret_cast<PIMAGE_NT_HEADERS>(reinterpret_cast<uintptr_t>(base) + dos->e_lfanew);
		if (Crypt(nt->Signature).decrypt_value() != Crypt(IMAGE_NT_SIGNATURE).decrypt_value())
			return nullptr;

		auto& data_dir = nt->OptionalHeader.DataDirectory[Crypt(IMAGE_DIRECTORY_ENTRY_EXPORT).decrypt_value()];
		if (data_dir.VirtualAddress == 0 || data_dir.Size == 0)
			return nullptr;

		auto export_dir = reinterpret_cast<PIMAGE_EXPORT_DIRECTORY>(reinterpret_cast<uintptr_t>(base) + Crypt(data_dir.VirtualAddress).decrypt_value());
		auto name_table = reinterpret_cast<DWORD*>(reinterpret_cast<uintptr_t>(base) + Crypt(export_dir->AddressOfNames).decrypt_value());
		auto func_table = reinterpret_cast<DWORD*>(reinterpret_cast<uintptr_t>(base) + Crypt(export_dir->AddressOfFunctions).decrypt_value());
		auto ord_table = reinterpret_cast<WORD*>(reinterpret_cast<uintptr_t>(base) + Crypt(export_dir->AddressOfNameOrdinals).decrypt_value());

		for (DWORD i = 0; i < export_dir->NumberOfNames; i++)
		{
			auto cur_name = reinterpret_cast<const char*>(reinterpret_cast<uintptr_t>(base) + name_table[i]);
			if (func_name == cur_name)
			{
				DWORD func_rva = func_table[ord_table[i]];

				if (func_rva >= data_dir.VirtualAddress && func_rva < data_dir.VirtualAddress + data_dir.Size)
				{
					return nullptr; // 转发器函数，不支持
				}
				return reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(base) + func_rva);
			}
		}
		return nullptr;
	}

	void* get_module(const std::string& module_name)
	{
		static void* pfnGetModuleHandleA = nullptr;
		static void* pfnLoadLibraryA = nullptr;
		static void* kernel_base = nullptr;

		if (kernel_base == nullptr)
		{
			//kernel_base = get_kernel32_base();
			kernel_base = CryptCall(void* (CallBuilder::*)(), &CallBuilder::get_kernel32_base)();	
			
		}
		if (pfnGetModuleHandleA == nullptr)
		{
			char szpGetModuleHandleA[] = {
			Crypt('G').decrypt_value(),
			Crypt('e').decrypt_value(),
			Crypt('t').decrypt_value(),
			Crypt('M').decrypt_value(),
			Crypt('o').decrypt_value(),
			Crypt('d').decrypt_value(),
			Crypt('u').decrypt_value(),
			Crypt('l').decrypt_value(),
			Crypt('e').decrypt_value(),
			Crypt('H').decrypt_value(),
			Crypt('a').decrypt_value(),
			Crypt('n').decrypt_value(),
			Crypt('d').decrypt_value(),
			Crypt('l').decrypt_value(),
			Crypt('e').decrypt_value(),
			Crypt('A').decrypt_value(),
			Crypt('\0').decrypt_value() };
			//pfnGetModuleHandleA = get_func_by_eat(kernel_base, szpGetModuleHandleA);
			pfnGetModuleHandleA = CryptCall(void* (CallBuilder::*)(void*, const std::string&), &CallBuilder::get_func_by_eat)(kernel_base, szpGetModuleHandleA);
		}
		if (pfnLoadLibraryA == nullptr)
		{
			char szpLoadLibraryA[] = {
				Crypt('L').decrypt_value(),
				Crypt('o').decrypt_value(),
				Crypt('a').decrypt_value(),
				Crypt('d').decrypt_value(),
				Crypt('L').decrypt_value(),
				Crypt('i').decrypt_value(),
				Crypt('b').decrypt_value(),
				Crypt('r').decrypt_value(),
				Crypt('a').decrypt_value(),
				Crypt('r').decrypt_value(),
				Crypt('y').decrypt_value(),
				Crypt('A').decrypt_value(),
				Crypt('\0').decrypt_value() };

			//pfnLoadLibraryA = get_func_by_eat(kernel_base, szpLoadLibraryA);
			pfnLoadLibraryA = CryptCall(void* (CallBuilder::*)(void*, const std::string&), &CallBuilder::get_func_by_eat)(kernel_base, szpLoadLibraryA);
		}

		HMODULE module_base = reinterpret_cast<HMODULE(*)(LPCSTR)>(pfnGetModuleHandleA)(module_name.c_str());
		if (module_base == nullptr)
		{
			module_base = reinterpret_cast<HMODULE(*)(LPCSTR)>(pfnLoadLibraryA)(module_name.c_str());
		}
		return module_base;
	}

	std::unique_ptr<Crypt> get_func(const std::string& module_name, const std::string& func_name)
	{
		void* module_base = nullptr;

		if (module_name == SecutyString("current") || module_name.empty())
		{
			void* func_address = FunctionRegistry::get_function(func_name);
			if (func_address != nullptr)
			{
				return std::make_unique<Crypt>(reinterpret_cast<uint64_t>(func_address));
			}

		}
		else
		{
			// DLL模块查找
			module_base = get_module(module_name);
			if (module_base != nullptr)
			{
				void* func_address = get_func_by_eat(module_base, func_name);
				if (func_address != nullptr)
				{
					return std::make_unique<Crypt>(reinterpret_cast<uint64_t>(func_address));
				}
			}
		}
		return nullptr;
	}

public:
	explicit CallBuilder(const std::string& func_name) : func_name_(func_name)
	{
	}

	CallBuilder& in(const std::string& module_name)
	{
		module_name_ = module_name;
		has_module_ = true;
		crypt_func_ptr_ = get_func(module_name_, func_name_);
		return *this;
	}

	template<typename... Args>
	auto operator()(Args&&... args)
	{
		if (!has_module_)
		{
			module_name_ = SecutyString("current");
			has_module_ = true;
			crypt_func_ptr_ = get_func(module_name_, func_name_);
		}

		if (!crypt_func_ptr_)
		{
			throw std::runtime_error(SecutyString("Function '") + func_name_ + SecutyString("' not found in module: ") + module_name_);
		}

		uint64_t func_address = crypt_func_ptr_->decrypt_value();

		if (func_address == 0)
		{
			throw std::runtime_error(("Decrypted function address is null"));
		}

		auto func = reinterpret_cast<FuncType>(func_address);
		return func(std::forward<Args>(args)...);
	}
};

template<typename FuncType>
auto call(const std::string& func_name)
{
	return CallBuilder<FuncType>(func_name);
}

template<typename FuncType>
auto call_in_module(const std::string& module_name, const std::string& func_name)
{
	CallBuilder<FuncType> builder(func_name);
	return std::move(builder.in(module_name));
}


