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
#include <variant>
#include <utility>
#include <iostream>
#include <cstring>
#include <functional>
#include <type_traits>

#pragma warning(disable:4244)
#pragma warning(disable:4838)
#pragma warning(disable:4267)
#pragma warning(disable:4309)
#pragma warning(disable:4305)
#pragma warning(disable:4715)


#define OBFUSCATE_FLOW(f) \
    [&]() -> decltype((f)()) { \
        do { \
            volatile uint64_t state_var = 0xDEADBEEFDEADBEEF; \
            uint32_t current_state = 0; \
            \
            using ReturnType = decltype((f)()); \
            \
            if constexpr (std::is_same_v<ReturnType, void>) { \
                bool func_executed = false; \
                \
                while (current_state < 128) { \
                    switch (current_state) { \
                    case 0: state_var = 0x123456789ABCDEF; current_state++; break; \
                    case 1: state_var = (state_var << 13) | (state_var >> 51); current_state++; break; \
                    case 2: state_var = state_var ^ 0x5555555555555555; current_state++; break; \
                    case 3: state_var = state_var + 0x10001; current_state++; break; \
                    case 4: state_var = ~state_var; current_state++; break; \
                    case 5: state_var = state_var * 0x9E3779B9; current_state++; break; \
                    case 6: state_var = (state_var << 7) ^ state_var; current_state++; break; \
                    case 7: state_var = state_var - 0x13579BDF; current_state++; break; \
                    case 8: state_var = state_var | 0x2468ACE0; current_state++; break; \
                    case 9: state_var = state_var & 0x3579BDF1; current_state++; break; \
                    case 10: state_var = state_var + 0x468ACE02; current_state++; break; \
                    case 11: state_var = state_var - 0x579BDF13; current_state++; break; \
                    case 12: state_var = state_var ^ 0x68ACE024; current_state++; break; \
                    case 13: state_var = (state_var << 17) | (state_var >> 47); current_state++; break; \
                    case 14: state_var = state_var + 0x79BDF135; current_state++; break; \
                    case 15: state_var = state_var - 0x8ACE0246; current_state++; break; \
                    case 16: state_var = state_var * 0x9BDF1357; current_state++; break; \
                    case 17: state_var = state_var & 0xACE02468; current_state++; break; \
                    case 18: state_var = state_var | 0xBDF13579; current_state++; break; \
                    case 19: state_var = state_var ^ 0xCE02468A; current_state++; break; \
                    case 20: state_var = (state_var << 19) | (state_var >> 45); current_state++; break; \
                    case 21: state_var = state_var + 0xDF13579B; current_state++; break; \
                    case 22: state_var = state_var - 0xE02468AC; current_state++; break; \
                    case 23: state_var = state_var * 0xF13579BD; current_state++; break; \
                    case 24: state_var = state_var & 0x02468ACE; current_state++; break; \
                    case 25: state_var = state_var | 0x13579BDF; current_state++; break; \
                    case 26: state_var = state_var ^ 0x2468ACE0; current_state++; break; \
                    case 27: state_var = (state_var << 23) | (state_var >> 41); current_state++; break; \
                    case 28: state_var = state_var + 0x3579BDF1; current_state++; break; \
                    case 29: state_var = state_var - 0x468ACE02; current_state++; break; \
                    case 30: state_var = state_var * 0x579BDF13; current_state++; break; \
                    case 31: state_var = state_var & 0x68ACE024; current_state++; break; \
                    case 32: state_var = state_var | 0x79BDF135; current_state++; break; \
                    case 33: state_var = state_var ^ 0x8ACE0246; current_state++; break; \
                    case 34: state_var = (state_var << 29) | (state_var >> 35); current_state++; break; \
                    case 35: state_var = state_var + 0x9BDF1357; current_state++; break; \
                    case 36: state_var = state_var - 0xACE02468; current_state++; break; \
                    case 37: state_var = state_var * 0xBDF13579; current_state++; break; \
                    case 38: state_var = state_var & 0xCE02468A; current_state++; break; \
                    case 39: state_var = state_var | 0xDF13579B; current_state++; break; \
                    case 40: state_var = state_var ^ 0xE02468AC; current_state++; break; \
                    case 41: state_var = (state_var << 31) | (state_var >> 33); current_state++; break; \
                    case 42: state_var = state_var + 0xF13579BD; current_state++; break; \
                    case 43: state_var = state_var - 0x02468ACE; current_state++; break; \
                    case 44: state_var = state_var * 0x13579BDF; current_state++; break; \
                    case 45: state_var = state_var & 0x2468ACE0; current_state++; break; \
                    case 46: state_var = state_var | 0x3579BDF1; current_state++; break; \
                    case 47: state_var = state_var ^ 0x468ACE02; current_state++; break; \
                    case 48: state_var = (state_var << 37) | (state_var >> 27); current_state++; break; \
                    case 49: state_var = state_var + 0x579BDF13; current_state++; break; \
                    case 50: { \
                        if (!func_executed) { \
                            (f)(); \
                            func_executed = true; \
                        } \
                        current_state++; \
                        break; \
                    } \
                    case 51:[[fallthrough]]; case 52:[[fallthrough]]; case 53:[[fallthrough]]; case 54:[[fallthrough]]; case 55:[[fallthrough]]; case 56:[[fallthrough]]; case 57:[[fallthrough]]; case 58:[[fallthrough]]; case 59:[[fallthrough]]; \
                    case 60:[[fallthrough]]; case 61:[[fallthrough]]; case 62:[[fallthrough]]; case 63:[[fallthrough]]; case 64:[[fallthrough]]; case 65:[[fallthrough]]; case 66:[[fallthrough]]; case 67:[[fallthrough]]; case 68:[[fallthrough]]; case 69:[[fallthrough]]; \
                    case 70:[[fallthrough]]; case 71:[[fallthrough]]; case 72:[[fallthrough]]; case 73:[[fallthrough]]; case 74:[[fallthrough]]; case 75:[[fallthrough]]; case 76:[[fallthrough]]; case 77:[[fallthrough]]; case 78:[[fallthrough]]; case 79:[[fallthrough]]; \
                    case 80:[[fallthrough]]; case 81:[[fallthrough]]; case 82:[[fallthrough]]; case 83:[[fallthrough]]; case 84:[[fallthrough]]; case 85:[[fallthrough]]; case 86:[[fallthrough]]; case 87:[[fallthrough]]; case 88:[[fallthrough]]; case 89:[[fallthrough]]; \
                    case 90:[[fallthrough]]; case 91:[[fallthrough]]; case 92:[[fallthrough]]; case 93:[[fallthrough]]; case 94:[[fallthrough]]; case 95:[[fallthrough]]; case 96:[[fallthrough]]; case 97:[[fallthrough]]; case 98:[[fallthrough]]; case 99:[[fallthrough]]; \
                    case 100: \
                        state_var = (state_var * current_state) ^ static_cast<unsigned long long>(0xDEADBEEF) * 0xAD56D7AD; \
                        current_state++; \
                        break; \
                    case 101:[[fallthrough]]; case 102:[[fallthrough]]; case 103:[[fallthrough]]; case 104:[[fallthrough]]; case 105:[[fallthrough]]; case 106:[[fallthrough]]; case 107:[[fallthrough]]; case 108:[[fallthrough]]; case 109: [[fallthrough]];\
                    case 110:[[fallthrough]]; case 111:[[fallthrough]]; case 112:[[fallthrough]]; case 113:[[fallthrough]]; case 114:[[fallthrough]]; case 115:[[fallthrough]]; case 116:[[fallthrough]]; case 117:[[fallthrough]]; case 118: [[fallthrough]];case 119:[[fallthrough]]; \
                    case 120:[[fallthrough]]; case 121:[[fallthrough]]; case 122:[[fallthrough]]; case 123:[[fallthrough]]; case 124:[[fallthrough]]; case 125:[[fallthrough]]; case 126: \
                        state_var = (state_var * current_state) ^ 0xDEADBEEF; \
                        current_state++; \
                        break; \
                    case 127: { \
                        state_var = (state_var * current_state) ^ 0xDEADBEEF; \
                        _ReadWriteBarrier(); \
                        return; \
                    } \
                    default: \
                        state_var = state_var + current_state; \
                        current_state++; \
                        break; \
                    } \
                } \
                _ReadWriteBarrier(); \
                return; \
            } else { \
                std::variant<std::monostate, ReturnType> result_storage; \
                bool func_executed = false; \
                \
                while (current_state < 128) { \
                    switch (current_state) { \
                    case 0: state_var = 0x123456789ABCDEF; current_state++; break; \
                    case 1: state_var = (state_var << 13) | (state_var >> 51); current_state++; break; \
                    case 2: state_var = state_var ^ 0x5555555555555555; current_state++; break; \
                    case 3: state_var = state_var + 0x10001; current_state++; break; \
                    case 4: state_var = ~state_var; current_state++; break; \
                    case 5: state_var = state_var * 0x9E3779B9; current_state++; break; \
                    case 6: state_var = (state_var << 7) ^ state_var; current_state++; break; \
                    case 7: state_var = state_var - 0x13579BDF; current_state++; break; \
                    case 8: state_var = state_var | 0x2468ACE0; current_state++; break; \
                    case 9: state_var = state_var & 0x3579BDF1; current_state++; break; \
                    case 10: state_var = state_var + 0x468ACE02; current_state++; break; \
                    case 11: state_var = state_var - 0x579BDF13; current_state++; break; \
                    case 12: state_var = state_var ^ 0x68ACE024; current_state++; break; \
                    case 13: state_var = (state_var << 17) | (state_var >> 47); current_state++; break; \
                    case 14: state_var = state_var + 0x79BDF135; current_state++; break; \
                    case 15: state_var = state_var - 0x8ACE0246; current_state++; break; \
                    case 16: state_var = state_var * 0x9BDF1357; current_state++; break; \
                    case 17: state_var = state_var & 0xACE02468; current_state++; break; \
                    case 18: state_var = state_var | 0xBDF13579; current_state++; break; \
                    case 19: state_var = state_var ^ 0xCE02468A; current_state++; break; \
                    case 20: state_var = (state_var << 19) | (state_var >> 45); current_state++; break; \
                    case 21: state_var = state_var + 0xDF13579B; current_state++; break; \
                    case 22: state_var = state_var - 0xE02468AC; current_state++; break; \
                    case 23: state_var = state_var * 0xF13579BD; current_state++; break; \
                    case 24: state_var = state_var & 0x02468ACE; current_state++; break; \
                    case 25: state_var = state_var | 0x13579BDF; current_state++; break; \
                    case 26: state_var = state_var ^ 0x2468ACE0; current_state++; break; \
                    case 27: state_var = (state_var << 23) | (state_var >> 41); current_state++; break; \
                    case 28: state_var = state_var + 0x3579BDF1; current_state++; break; \
                    case 29: state_var = state_var - 0x468ACE02; current_state++; break; \
                    case 30: state_var = state_var * 0x579BDF13; current_state++; break; \
                    case 31: state_var = state_var & 0x68ACE024; current_state++; break; \
                    case 32: state_var = state_var | 0x79BDF135; current_state++; break; \
                    case 33: state_var = state_var ^ 0x8ACE0246; current_state++; break; \
                    case 34: state_var = (state_var << 29) | (state_var >> 35); current_state++; break; \
                    case 35: state_var = state_var + 0x9BDF1357; current_state++; break; \
                    case 36: state_var = state_var - 0xACE02468; current_state++; break; \
                    case 37: state_var = state_var * 0xBDF13579; current_state++; break; \
                    case 38: state_var = state_var & 0xCE02468A; current_state++; break; \
                    case 39: state_var = state_var | 0xDF13579B; current_state++; break; \
                    case 40: state_var = state_var ^ 0xE02468AC; current_state++; break; \
                    case 41: state_var = (state_var << 31) | (state_var >> 33); current_state++; break; \
                    case 42: state_var = state_var + 0xF13579BD; current_state++; break; \
                    case 43: state_var = state_var - 0x02468ACE; current_state++; break; \
                    case 44: state_var = state_var * 0x13579BDF; current_state++; break; \
                    case 45: state_var = state_var & 0x2468ACE0; current_state++; break; \
                    case 46: state_var = state_var | 0x3579BDF1; current_state++; break; \
                    case 47: state_var = state_var ^ 0x468ACE02; current_state++; break; \
                    case 48: state_var = (state_var << 37) | (state_var >> 27); current_state++; break; \
                    case 49: state_var = state_var + 0x579BDF13; current_state++; break; \
                    case 50: { \
                        if (!func_executed) { \
                            result_storage.template emplace<1>((f)()); \
                            func_executed = true; \
                        } \
                        current_state++; \
                        break; \
                    } \
					case 51:[[fallthrough]]; case 52:[[fallthrough]]; case 53:[[fallthrough]]; case 54:[[fallthrough]]; case 55:[[fallthrough]]; case 56:[[fallthrough]]; case 57:[[fallthrough]]; case 58:[[fallthrough]]; case 59:[[fallthrough]]; \
                    case 60:[[fallthrough]]; case 61:[[fallthrough]]; case 62:[[fallthrough]]; case 63:[[fallthrough]]; case 64:[[fallthrough]]; case 65:[[fallthrough]]; case 66:[[fallthrough]]; case 67:[[fallthrough]]; case 68:[[fallthrough]]; case 69:[[fallthrough]]; \
                    case 70:[[fallthrough]]; case 71:[[fallthrough]]; case 72:[[fallthrough]]; case 73:[[fallthrough]]; case 74:[[fallthrough]]; case 75:[[fallthrough]]; case 76:[[fallthrough]]; case 77:[[fallthrough]]; case 78:[[fallthrough]]; case 79:[[fallthrough]]; \
                    case 80:[[fallthrough]]; case 81:[[fallthrough]]; case 82:[[fallthrough]]; case 83:[[fallthrough]]; case 84:[[fallthrough]]; case 85:[[fallthrough]]; case 86:[[fallthrough]]; case 87:[[fallthrough]]; case 88:[[fallthrough]]; case 89:[[fallthrough]]; \
                    case 90:[[fallthrough]]; case 91:[[fallthrough]]; case 92:[[fallthrough]]; case 93:[[fallthrough]]; case 94:[[fallthrough]]; case 95:[[fallthrough]]; case 96:[[fallthrough]]; case 97:[[fallthrough]]; case 98:[[fallthrough]]; case 99:[[fallthrough]]; \
                    case 100: \
                        state_var = (state_var * current_state) ^ static_cast<unsigned long long>(0xDEADBEEF) * 0xAD56D7AD; \
                        current_state++; \
                        break; \
                    case 101:[[fallthrough]]; case 102:[[fallthrough]]; case 103:[[fallthrough]]; case 104:[[fallthrough]]; case 105:[[fallthrough]]; case 106:[[fallthrough]]; case 107:[[fallthrough]]; case 108:[[fallthrough]]; case 109: [[fallthrough]];\
                    case 110:[[fallthrough]]; case 111:[[fallthrough]]; case 112:[[fallthrough]]; case 113:[[fallthrough]]; case 114:[[fallthrough]]; case 115:[[fallthrough]]; case 116:[[fallthrough]]; case 117:[[fallthrough]]; case 118: [[fallthrough]];case 119:[[fallthrough]]; \
                    case 120:[[fallthrough]]; case 121:[[fallthrough]]; case 122:[[fallthrough]]; case 123:[[fallthrough]]; case 124:[[fallthrough]]; case 125:[[fallthrough]]; case 126: \
                        state_var = (state_var * current_state) ^ 0xDEADBEEF; \
                        current_state++; \
                        break; \
                    case 127: { \
                        state_var = (state_var * current_state) ^ 0xDEADBEEF; \
                        _ReadWriteBarrier(); \
                        if (result_storage.index() == 1) { \
                            return std::move(std::get<1>(result_storage)); \
                        } \
                        break; \
                    } \
                    default: \
                        current_state++; \
                        break; \
                    } \
                } \
                _ReadWriteBarrier(); \
            } \
        } while (false); \
    }()

#define CryptCall(FuncType, FuncAddr)\
    [this]() -> auto { \
        using MemberFuncPtr = FuncType;   \
        MemberFuncPtr original_ptr = FuncAddr; \
        uint64_t func_address_int; \
        static_assert(sizeof(MemberFuncPtr) <= sizeof(uint64_t), \
                      "成员函数指针太大，无法用uint64_t表示"); \
        std::memcpy(&func_address_int, &original_ptr, sizeof(original_ptr)); \
        uint64_t decrypted_int = Crypt(func_address_int).decrypt_value(); \
        MemberFuncPtr restored_ptr; \
        std::memcpy(&restored_ptr, &decrypted_int, sizeof(restored_ptr)); \
        return [this, restored_ptr](auto&&... args) -> void* { \
            return (this->*restored_ptr)(std::forward<decltype(args)>(args)...); \
        }; \
    }()

#define CALL(FuncType, func_name) \
    []() -> decltype(auto) { \
        static constexpr CompileTimeStringEncrypt<sizeof(#func_name)> encrypted_func(#func_name); \
        return OBFUSCATE_FLOW([]() -> decltype(auto) { \
            return call<FuncType>(encrypted_func.decrypt()); \
        }); \
    }()


#define CALL_IN_MODULE(FuncType, module_name, func_name) \
    []() -> decltype(auto) { \
        static constexpr CompileTimeStringEncrypt<sizeof(#func_name)> encrypted_func(#func_name); \
        static constexpr CompileTimeStringEncrypt<sizeof(#module_name)> encrypted_md(#module_name); \
        return OBFUSCATE_FLOW([]() -> decltype(auto) { \
            return call_in_module<FuncType>(encrypted_md.decrypt(), encrypted_func.decrypt()); \
        }); \
    }()

#define REGISTER_FUNCTION(func) \
    namespace { \
        static const CompileTimeStringEncrypt<sizeof(#func)> encrypted_str_##func(#func); \
        \
        struct Register_##func { \
            Register_##func() { \
                OBFUSCATE_FLOW([&]() -> int { \
                    FunctionRegistry::register_function_encrypted( \
                        encrypted_str_##func.getEncryptedData(), \
                        encrypted_str_##func.getEncryptedSize() - 1, \
                        (void*)func); \
                    return 0; \
                }); \
            } \
        } register_instance_##func; \
    }

#define SecutyString(str) \
    OBFUSCATE_FLOW([&]() -> auto { \
        static constexpr CompileTimeStringEncrypt<sizeof(str)> encrypted_str(str); \
        return encrypted_str.decrypt(); \
    }).c_str()

#define SecutyWString(str) \
	OBFUSCATE_FLOW([&]() -> auto { \
		static constexpr CompileTimeWStringEncrypt<sizeof(##str) / sizeof(wchar_t)> encrypted_str(str); \
		return encrypted_str.decrypt(); \
		}).c_str()



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

		auto seed = std::chrono::high_resolution_clock::now()
			.time_since_epoch().count();
		std::mt19937 gen(static_cast<unsigned int>(seed));

		for (int i = 63; i > 0; --i)
		{
			std::uniform_int_distribution<int> dist(0, i);
			int j = dist(gen);
			std::swap(indices[i], indices[j]);
		}

		for (int i = 0; i < 64; ++i)
		{
			perm_table[i] = indices[i];
		}

		for (int i = 0; i < 64; ++i)
		{
			reverse_perm[perm_table[i]] = i;
		}
	}

	FORCEINLINE void init_runtime_key()
	{
		auto seed = std::chrono::high_resolution_clock::now()
			.time_since_epoch().count();
		std::mt19937_64 gen(static_cast<unsigned int>(seed));
		runtime_key_ = gen();
	}

	FORCEINLINE uint64_t xtea_encrypt(uint64_t value, uint64_t key) const
	{
		uint32_t v0 = static_cast<uint32_t>(value);
		uint32_t v1 = static_cast<uint32_t>(value >> 32);
		uint32_t sum = 0;
		const uint32_t delta = 0x9E3779B9;

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

	FORCEINLINE uint64_t xtea_decrypt(uint64_t value, uint64_t key) const
	{
		uint32_t v0 = static_cast<uint32_t>(value);
		uint32_t v1 = static_cast<uint32_t>(value >> 32);
		uint32_t sum = 0xC6EF3720; // delta * 32
		const uint32_t delta = 0x9E3779B9;

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
	explicit Crypt(uint64_t value = 0)
	{
		generate_permutation_tables();
		init_runtime_key();
		encrypted_value_ = encrypt_value(value);
	}

	Crypt(const Crypt& other)
		: encrypted_value_(other.encrypted_value_), runtime_key_(other.runtime_key_)
	{
		std::copy(std::begin(other.perm_table), std::end(other.perm_table), perm_table);
		std::copy(std::begin(other.reverse_perm), std::end(other.reverse_perm), reverse_perm);
	}

	Crypt& operator=(const Crypt& other)
	{
		if (this != &other)
		{
			encrypted_value_ = other.encrypted_value_;
			runtime_key_ = other.runtime_key_;
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

	FORCEINLINE uint64_t encrypt_value(uint64_t value)
	{
		uint64_t layer1 = xtea_encrypt(value, COMPILE_TIME_KEY);
		uint64_t layer2 = bit_permutation(layer1);
		uint64_t layer3 = xtea_encrypt(layer2, runtime_key_);
		uint64_t final_value = layer3 ^ COMPILE_TIME_KEY;
		final_value = (final_value >> 13) | (final_value << (64 - 13));
		return final_value;
	}

	FORCEINLINE uint64_t decrypt_value() const
	{
		uint64_t layer3 = (encrypted_value_ << 13) | (encrypted_value_ >> (64 - 13));
		layer3 ^= COMPILE_TIME_KEY;
		uint64_t layer2 = xtea_decrypt(layer3, runtime_key_);
		uint64_t layer1 = bit_permutation_reverse(layer2);
		uint64_t original_value = xtea_decrypt(layer1, COMPILE_TIME_KEY);

		return original_value;
	}

	FORCEINLINE uint64_t get_encrypted() const
	{
		return encrypted_value_;
	}

	FORCEINLINE void set_value(uint64_t value)
	{
		encrypted_value_ = encrypt_value(value);
	}

	FORCEINLINE operator uint64_t() const
	{
		return decrypt_value();
	}

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

	FORCEINLINE void get_permutation_table(uint8_t* table) const
	{
		std::copy(perm_table, perm_table + 64, table);
	}

	FORCEINLINE void get_reverse_permutation_table(uint8_t* table) const
	{
		std::copy(reverse_perm, reverse_perm + 64, table);
	}
};



// 窄字符版本
#define _XOR_KEY_ 0x77
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
			auto v2 = encrypted_data_[i] ^ XOR_KEY;
			auto v1 = v2 ^ (XOR_KEY * i);
			auto v0 = v1 ^ (XOR_KEY + i);
			result += v0;
		}
		return result;
	}

	const char* getEncryptedData() const { return encrypted_data_.data(); }
	constexpr size_t getEncryptedSize() const { return N; }
};
// 运行时加密函数 - 窄字符
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


// 宽字符版本
#define _WXOR_KEY_ 0x7234
template <size_t N>
class CompileTimeWStringEncrypt {
private:
	std::array<wchar_t, N> encrypted_data_;
	static constexpr wchar_t WXOR_KEY = _WXOR_KEY_; // 宽字符专用密钥

public:
	constexpr CompileTimeWStringEncrypt(const wchar_t(&str)[N])
	{
		for (size_t i = 0; i < N; ++i)
		{
			auto v0 = str[i] ^ (WXOR_KEY + i);
			auto v1 = v0 ^ (WXOR_KEY * i);
			auto v2 = v1 ^ WXOR_KEY;
			encrypted_data_[i] = v2;
		}
	}

	std::wstring decrypt() const {
		std::wstring result;
		result.reserve(N);
		for (size_t i = 0; i < N - 1; ++i)
		{
			auto v2 = encrypted_data_[i] ^ WXOR_KEY;
			auto v1 = v2 ^ (WXOR_KEY * i);
			auto v0 = v1 ^ (WXOR_KEY + i);
			result += v0;
		}
		return result;
	}

	const wchar_t* getEncryptedData() const { return encrypted_data_.data(); }
	constexpr size_t getEncryptedSize() const { return N; }
};
// 运行时加密函数 - 宽字符
std::wstring runtime_wstring_encrypt(const std::wstring& input)
{
	static constexpr wchar_t WXOR_KEY = _WXOR_KEY_;
	std::wstring output = input;
	for (size_t i = 0; i < input.length(); ++i)
	{
		auto v2 = input[i] ^ WXOR_KEY;
		auto v1 = v2 ^ (WXOR_KEY * i);
		auto v0 = v1 ^ (WXOR_KEY + i);
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