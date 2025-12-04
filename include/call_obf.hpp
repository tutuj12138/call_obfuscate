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

#define _XOR_KEY_ 0x58

#define CryptCall(FuncType, FuncAddr)                                                                                   \
    [this]() -> auto {                                                                                                  \
        using MemberFuncPtr = FuncType;                                                                                 \
        auto original_ptr = FuncAddr;                                                                                   \
        volatile uint64_t obf_var = 0xDEADBEEFDEADBEEF;                                                                 \
        uint32_t state = 0;                                                                                             \
        bool finished = false;                                                                                          \
        while (!finished) {                                                                                             \
            switch (state) {                                                                                            \
                /* 前50个分支 - 基础操作 */                                                                             \
                case 0: obf_var = obf_var ^ 0x123456789ABCDEF; state++; break;                                          \
                case 1: obf_var = (obf_var << 13) | (obf_var >> 51); state++; break;                                    \
                case 2: obf_var = obf_var + 0x1111111111111111; state++; break;                                         \
                case 3: obf_var = obf_var - 0x2222222222222222; state++; break;                                         \
                case 4: obf_var = obf_var * 0x3333333333333333; state++; break;                                         \
                case 5: obf_var = obf_var & 0x4444444444444444; state++; break;                                         \
                case 6: obf_var = obf_var | 0x5555555555555555; state++; break;                                         \
                case 7: obf_var = ~obf_var; state++; break;                                                             \
                case 8: obf_var = (obf_var << 17) ^ obf_var; state++; break;                                            \
                case 9: obf_var = obf_var + (obf_var >> 5); state++; break;                                             \
                case 10: obf_var = obf_var - (obf_var << 3); state++; break;                                            \
                case 11: obf_var = obf_var * 0x123456789; state++; break;                                               \
                case 12: obf_var = obf_var / 0x1000; state++; break;                                                    \
                case 13: obf_var = obf_var % 0x10000; state++; break;                                                   \
                case 14: obf_var = (obf_var << 7) | (obf_var >> 57); state++; break;                                    \
                case 15: obf_var = obf_var ^ (obf_var << 9); state++; break;                                            \
                case 16: obf_var = obf_var + 0xAAAAAAAA; state++; break;                                                \
                case 17: obf_var = obf_var - 0xBBBBBBBB; state++; break;                                                \
                case 18: obf_var = obf_var * 0xCCCCCCCC; state++; break;                                                \
                case 19: obf_var = obf_var & 0xDDDDDDDD; state++; break;                                                \
                case 20: obf_var = obf_var | 0xEEEEEEEE; state++; break;                                                \
                case 21: obf_var = obf_var ^ 0xFFFFFFFF; state++; break;                                                \
                case 22: obf_var = (obf_var << 11) | (obf_var >> 53); state++; break;                                   \
                case 23: obf_var = obf_var + 0x13579BDF; state++; break;                                                \
                case 24: obf_var = obf_var - 0x2468ACE0; state++; break;                                                \
                case 25: obf_var = obf_var * 0x3579BDF1; state++; break;                                                \
                case 26: obf_var = obf_var & 0x468ACE02; state++; break;                                                \
                case 27: obf_var = obf_var | 0x579BDF13; state++; break;                                                \
                case 28: obf_var = obf_var ^ 0x68ACE024; state++; break;                                                \
                case 29: obf_var = (obf_var << 19) | (obf_var >> 45); state++; break;                                   \
                case 30: obf_var = obf_var + 0x79BDF135; state++; break;                                                \
                case 31: obf_var = obf_var - 0x8ACE0246; state++; break;                                                \
                case 32: obf_var = obf_var * 0x9BDF1357; state++; break;                                                \
                case 33: obf_var = obf_var & 0xACE02468; state++; break;                                                \
                case 34: obf_var = obf_var | 0xBDF13579; state++; break;                                                \
                case 35: obf_var = obf_var ^ 0xCE02468A; state++; break;                                                \
                case 36: obf_var = (obf_var << 23) | (obf_var >> 41); state++; break;                                   \
                case 37: obf_var = obf_var + 0xDF13579B; state++; break;                                                \
                case 38: obf_var = obf_var - 0xE02468AC; state++; break;                                                \
                case 39: obf_var = obf_var * 0xF13579BD; state++; break;                                                \
                case 40: obf_var = obf_var & 0x02468ACE; state++; break;                                                \
                case 41: obf_var = obf_var | 0x13579BDF; state++; break;                                                \
                case 42: obf_var = obf_var ^ 0x2468ACE0; state++; break;                                                \
                case 43: obf_var = (obf_var << 29) | (obf_var >> 35); state++; break;                                   \
                case 44: obf_var = obf_var + 0x3579BDF1; state++; break;                                                \
                case 45: obf_var = obf_var - 0x468ACE02; state++; break;                                                \
                case 46: obf_var = obf_var * 0x579BDF13; state++; break;                                                \
                case 47: obf_var = obf_var & 0x68ACE024; state++; break;                                                \
                case 48: obf_var = obf_var | 0x79BDF135; state++; break;                                                \
                case 49: obf_var = obf_var ^ 0x8ACE0246; state++; break;                                                \
																														\
                /* 中间50个分支 - 复杂操作 */                                                                           \
                case 50: obf_var = (obf_var << 31) ^ (obf_var >> 33); state++; break;                                   \
                case 51: obf_var = obf_var + (obf_var << 2); state++; break;                                            \
                case 52: obf_var = obf_var - (obf_var >> 4); state++; break;                                            \
                case 53: obf_var = obf_var * 0x9E3779B9; state++; break;                                                \
                case 54: obf_var = obf_var ^ 0x6A09E667; state++; break;                                                \
                case 55: obf_var = (obf_var << 5) + obf_var; state++; break;                                            \
                case 56: obf_var = obf_var - (obf_var << 7); state++; break;                                            \
                case 57: obf_var = obf_var * 0xDEADBEEF; state++; break;                                                \
                case 58: obf_var = obf_var ^ 0xCAFEBABE; state++; break;                                                \
                case 59: obf_var = (obf_var << 9) | (obf_var >> 55); state++; break;                                    \
                case 60: obf_var = obf_var + 0xBAADF00D; state++; break;                                                \
                case 61: obf_var = obf_var - 0xFEEDFACE; state++; break;                                                \
                case 62: obf_var = obf_var * 0x1337C0DE; state++; break;                                                \
                case 63: obf_var = obf_var & 0xDEADC0DE; state++; break;                                                \
                case 64: obf_var = obf_var | 0xC0FFEEEE; state++; break;                                                \
                case 65: obf_var = obf_var ^ 0x1CEB00DA; state++; break;                                                \
                case 66: obf_var = (obf_var << 15) | (obf_var >> 49); state++; break;                                   \
                case 67: obf_var = obf_var + 0x0B00B135; state++; break;                                                \
                case 68: obf_var = obf_var - 0x1BADB002; state++; break;                                                \
                case 69: obf_var = obf_var * 0x7FFFFFFF; state++; break;                                                \
                case 70: obf_var = obf_var & 0x80000000; state++; break;                                                \
                case 71: obf_var = obf_var | 0x40000000; state++; break;                                                \
                case 72: obf_var = obf_var ^ 0x20000000; state++; break;                                                \
                case 73: obf_var = (obf_var << 21) | (obf_var >> 43); state++; break;                                   \
                case 74: obf_var = obf_var + 0x10000000; state++; break;                                                \
                case 75: obf_var = obf_var - 0x08000000; state++; break;                                                \
                case 76: obf_var = obf_var * 0x04000000; state++; break;                                                \
                case 77: obf_var = obf_var & 0x02000000; state++; break;                                                \
                case 78: obf_var = obf_var | 0x01000000; state++; break;                                                \
                case 79: obf_var = obf_var ^ 0x00800000; state++; break;                                                \
                case 80: obf_var = (obf_var << 25) | (obf_var >> 39); state++; break;                                   \
                case 81: obf_var = obf_var + 0x00400000; state++; break;                                                \
                case 82: obf_var = obf_var - 0x00200000; state++; break;                                                \
                case 83: obf_var = obf_var * 0x00100000; state++; break;                                                \
                case 84: obf_var = obf_var & 0x00080000; state++; break;                                                \
                case 85: obf_var = obf_var | 0x00040000; state++; break;                                                \
                case 86: obf_var = obf_var ^ 0x00020000; state++; break;                                                \
                case 87: obf_var = (obf_var << 27) | (obf_var >> 37); state++; break;                                   \
                case 88: obf_var = obf_var + 0x00010000; state++; break;                                                \
                case 89: obf_var = obf_var - 0x00008000; state++; break;                                                \
                case 90: obf_var = obf_var * 0x00004000; state++; break;                                                \
                case 91: obf_var = obf_var & 0x00002000; state++; break;                                                \
                case 92: obf_var = obf_var | 0x00001000; state++; break;                                                \
                case 93: obf_var = obf_var ^ 0x00000800; state++; break;                                                \
                case 94: obf_var = (obf_var << 33) | (obf_var >> 31); state++; break;                                   \
                case 95: obf_var = obf_var + 0x00000400; state++; break;                                                \
                case 96: obf_var = obf_var - 0x00000200; state++; break;                                                \
                case 97: obf_var = obf_var * 0x00000100; state++; break;                                                \
                case 98: obf_var = obf_var & 0x00000080; state++; break;                                                \
                case 99: obf_var = obf_var | 0x00000040; state++; break;                                                \
																														\
                /* 最终分支 - 结束循环 */                                                                               \
                case 100:                                                                                               \
                    finished = true;                                                                                    \
                    break;                                                                                              \
																														\
                default:                                                                                                \
                    state = 0; /* 重置状态 */                                                                           \
                    break;                                                                                              \
            }                                                                                                           \
																														\
            /* 防止无限循环 */                                                                                          \
            if (state > 1000) finished = true;                                                                          \
        }                                                                                                               \
																														\
        /* 防止编译器优化 */                                                                                            \
        (void)obf_var;                                                                                                  \
																														\
        /* 返回可调用对象 */                                                                                            \
        return [this, original_ptr](auto&&... args) -> void* {                                                          \
            /* 调用前的平坦化 */                                                                                        \
            volatile uint32_t call_obf = 0x12345678;                                                                    \
            uint32_t call_state = 0;                                                                                    \
            bool call_finished = false;                                                                                 \
																														\
            while (!call_finished) {                                                                                    \
                switch (call_state) {                                                                                   \
                    case 0: call_obf = call_obf ^ 0x11111111; call_state++; break;                                      \
                    case 1: call_obf = (call_obf << 3) | (call_obf >> 29); call_state++; break;                         \
                    case 2: call_obf = call_obf + 0x22222222; call_state++; break;                                      \
                    case 3: call_obf = call_obf - 0x33333333; call_state++; break;                                      \
                    case 4: call_obf = call_obf * 0x44444444; call_state++; break;                                      \
                    case 5: call_obf = call_obf & 0x55555555; call_state++; break;                                      \
                    case 6: call_obf = call_obf | 0x66666666; call_state++; break;                                      \
                    case 7: call_obf = call_obf ^ 0x77777777; call_state++; break;                                      \
                    case 8: call_obf = ~call_obf; call_state++; break;                                                  \
                    case 9: call_obf = (call_obf << 5) ^ call_obf; call_state++; break;                                 \
                    case 10:                                                                                            \
                        call_finished = true;                                                                           \
                        break;                                                                                          \
                    default:                                                                                            \
                        call_state = 0;                                                                                 \
                        break;                                                                                          \
                }                                                                                                       \
            }                                                                                                           \
																														\
            (void)call_obf;                                                                                             \
																														\
            /* 实际函数调用 */                                                                                          \
            return (this->*original_ptr)(std::forward<decltype(args)>(args)...);                                        \
        };                                                                                                              \
    }()


#define CALL(FuncType, func_name)																						\
    [&]() -> auto {																										\
        constexpr CompileTimeStringEncrypt<sizeof(#func_name)> encrypted_##func(#func_name);							\
        return call<FuncType>(encrypted_##func.decrypt());																\
    }()

#define CALL_IN_MODULE(FuncType, module_name, func_name)																\
	[&]() -> auto {																										\
        constexpr CompileTimeStringEncrypt<sizeof(#func_name)> encrypted_##func(#func_name);							\
        constexpr CompileTimeStringEncrypt<sizeof(#module_name)> encrypted_##md(#module_name);							\
        return call_in_module<FuncType>(encrypted_##md.decrypt(), encrypted_##func.decrypt());							\
    }()

#define REGISTER_FUNCTION(func)																							\
    namespace {																											\
        static const CompileTimeStringEncrypt<sizeof(#func)> encrypted_str_##func(#func);								\
        struct Register_##func {																						\
            Register_##func() {																							\
				reinterpret_cast<void(*)(const char*, size_t, void*)> (													\
				Crypt(reinterpret_cast<uint64_t>(FunctionRegistry::register_function_encrypted)).decrypt_value())(		\
                    encrypted_str_##func.getEncryptedData(),															\
                    encrypted_str_##func.getEncryptedSize() - 1,														\
                    (void*)func);																						\
            }																											\
        } register_instance_##func;																						\
    }

#define SecutyString(str)                                                                                              \
[&]() -> const char* {                                                                                                 \
    /* 编译时字符串加密 */                                                                                             \
    constexpr CompileTimeStringEncrypt<sizeof(str)> encrypted_str(str);                                                \
																													   \
    /* 运行时流程平坦化解密 */                                                                                         \
    static thread_local std::string cached_result;                                                                     \
    cached_result.clear();                                                                                             \
																													   \
    /* 流程平坦化状态机 */                                                                                             \
    volatile uint64_t state_var = 0xDEADBEEFDEADBEEF;                                                                  \
    uint32_t current_state = 0;                                                                                        \
    bool finished = false;                                                                                             \
    const char* encrypted_data = encrypted_str.getEncryptedData();                                                     \
    size_t data_size = encrypted_str.getEncryptedSize() - 1; /* 排除null终止符 */                                      \
																													   \
    cached_result.reserve(data_size);                                                                                  \
																													   \
    /* 128个分支的流程平坦化 */                                                                                        \
    while (!finished && current_state < 128) {                                                                         \
        switch (current_state) {                                                                                       \
            /* 前50个分支 - 解密准备阶段 */                                                                            \
            case 0: state_var = 0x123456789ABCDEF; current_state++; break;                                             \
            case 1: state_var = (state_var << 13) | (state_var >> 51); current_state++; break;                         \
            case 2: state_var = state_var ^ 0x5555555555555555; current_state++; break;                                \
            case 3: state_var = state_var + data_size * 0x10001; current_state++; break;                               \
            case 4: state_var = ~state_var; current_state++; break;                                                    \
            case 5: state_var = state_var * 0x9E3779B9; current_state++; break;                                        \
            case 6: state_var = (state_var << 7) ^ state_var; current_state++; break;                                  \
            case 7: state_var = state_var - 0x13579BDF; current_state++; break;                                        \
            case 8: state_var = state_var | 0x2468ACE0; current_state++; break;                                        \
            case 9: state_var = state_var & 0x3579BDF1; current_state++; break;                                        \
            case 10: state_var = state_var + 0x468ACE02; current_state++; break;                                       \
            case 11: state_var = state_var - 0x579BDF13; current_state++; break;                                       \
            case 12: state_var = state_var ^ 0x68ACE024; current_state++; break;                                       \
            case 13: state_var = (state_var << 17) | (state_var >> 47); current_state++; break;                        \
            case 14: state_var = state_var + 0x79BDF135; current_state++; break;                                       \
            case 15: state_var = state_var - 0x8ACE0246; current_state++; break;                                       \
            case 16: state_var = state_var * 0x9BDF1357; current_state++; break;                                       \
            case 17: state_var = state_var & 0xACE02468; current_state++; break;                                       \
            case 18: state_var = state_var | 0xBDF13579; current_state++; break;                                       \
            case 19: state_var = state_var ^ 0xCE02468A; current_state++; break;                                       \
            case 20: state_var = (state_var << 19) | (state_var >> 45); current_state++; break;                        \
            case 21: state_var = state_var + 0xDF13579B; current_state++; break;                                       \
            case 22: state_var = state_var - 0xE02468AC; current_state++; break;                                       \
            case 23: state_var = state_var * 0xF13579BD; current_state++; break;                                       \
            case 24: state_var = state_var & 0x02468ACE; current_state++; break;                                       \
            case 25: state_var = state_var | 0x13579BDF; current_state++; break;                                       \
            case 26: state_var = state_var ^ 0x2468ACE0; current_state++; break;                                       \
            case 27: state_var = (state_var << 23) | (state_var >> 41); current_state++; break;                        \
            case 28: state_var = state_var + 0x3579BDF1; current_state++; break;                                       \
            case 29: state_var = state_var - 0x468ACE02; current_state++; break;                                       \
            case 30: state_var = state_var * 0x579BDF13; current_state++; break;                                       \
            case 31: state_var = state_var & 0x68ACE024; current_state++; break;                                       \
            case 32: state_var = state_var | 0x79BDF135; current_state++; break;                                       \
            case 33: state_var = state_var ^ 0x8ACE0246; current_state++; break;                                       \
            case 34: state_var = (state_var << 29) | (state_var >> 35); current_state++; break;                        \
            case 35: state_var = state_var + 0x9BDF1357; current_state++; break;                                       \
            case 36: state_var = state_var - 0xACE02468; current_state++; break;                                       \
            case 37: state_var = state_var * 0xBDF13579; current_state++; break;                                       \
            case 38: state_var = state_var & 0xCE02468A; current_state++; break;                                       \
            case 39: state_var = state_var | 0xDF13579B; current_state++; break;                                       \
            case 40: state_var = state_var ^ 0xE02468AC; current_state++; break;                                       \
            case 41: state_var = (state_var << 31) | (state_var >> 33); current_state++; break;                        \
            case 42: state_var = state_var + 0xF13579BD; current_state++; break;                                       \
            case 43: state_var = state_var - 0x02468ACE; current_state++; break;                                       \
            case 44: state_var = state_var * 0x13579BDF; current_state++; break;                                       \
            case 45: state_var = state_var & 0x2468ACE0; current_state++; break;                                       \
            case 46: state_var = state_var | 0x3579BDF1; current_state++; break;                                       \
            case 47: state_var = state_var ^ 0x468ACE02; current_state++; break;                                       \
            case 48: state_var = (state_var << 37) | (state_var >> 27); current_state++; break;                        \
            case 49: state_var = state_var + 0x579BDF13; current_state++; break;                                       \
																													   \
            /* 字符串解密阶段 - 50个分支 */                                                                            \
            case 50: {                                                                                                 \
                /* 开始字符串解密 */                                                                                   \
                for (size_t i = 0; i < data_size; ++i) {                                                               \
                    char decrypted_char = encrypted_data[i] ^ _XOR_KEY_;                                               \
                    decrypted_char = decrypted_char ^ (i * _XOR_KEY_);                                                 \
                    decrypted_char = decrypted_char ^ (_XOR_KEY_ + i);                                                 \
                    cached_result += decrypted_char;                                                                   \
                }                                                                                                      \
                current_state++;                                                                                       \
                break;                                                                                                 \
            }                                                                                                          \
																													   \
            /* 中间混淆分支 */                                                                                         \
            case 51: case 52: case 53: case 54: case 55: case 56: case 57: case 58: case 59:                           \
            case 60: case 61: case 62: case 63: case 64: case 65: case 66: case 67: case 68: case 69:                  \
            case 70: case 71: case 72: case 73: case 74: case 75: case 76: case 77: case 78: case 79:                  \
            case 80: case 81: case 82: case 83: case 84: case 85: case 86: case 87: case 88: case 89:                  \
            case 90: case 91: case 92: case 93: case 94: case 95: case 96: case 97: case 98: case 99:                  \
                /* 这些状态执行额外的混淆操作 */                                                                       \
                state_var = (state_var << (current_state % 32)) ^ state_var;                                           \
                state_var = state_var + current_state * 0x10001;                                                       \
                state_var = state_var ^ (cached_result.length() * 0x12345678);                                         \
                current_state++;                                                                                       \
                break;                                                                                                 \
																													   \
            /* 结果后处理阶段 */                                                                                       \
            case 100: {                                                                                                \
                /* 验证解密结果 */                                                                                     \
                if (cached_result.empty()) {                                                                           \
                    cached_result = "DECRYPTION_ERROR";                                                                \
                }                                                                                                      \
                current_state++;                                                                                       \
                break;                                                                                                 \
            }                                                                                                          \
																													   \
            case 101: case 102: case 103: case 104: case 105: case 106: case 107: case 108: case 109:                  \
            case 110: case 111: case 112: case 113: case 114: case 115: case 116: case 117: case 118: case 119:        \
            case 120: case 121: case 122: case 123: case 124: case 125: case 126: case 127:                            \
                /* 最终混淆阶段 */                                                                                     \
                state_var = (state_var * current_state) ^ 0xDEADBEEF;                                                  \
                if (current_state == 127) {                                                                            \
                    finished = true;                                                                                   \
                } else {                                                                                               \
                    current_state++;                                                                                   \
                }                                                                                                      \
                break;                                                                                                 \
																													   \
            default:                                                                                                   \
                current_state = 0;                                                                                     \
                break;                                                                                                 \
        }                                                                                                              \
    }                                                                                                                  \
																													   \
    return cached_result.c_str();                                                                                      \
}()



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
	return [func_name_capture = func_name]() -> CallBuilder<FuncType> {
		constexpr auto generate_state_sequence = []() constexpr {
			std::array<uint16_t, 2048> seq{};
			uint16_t state = 0;
			for (size_t i = 0; i < seq.size(); ++i) {
				seq[i] = state;
				state = (state * 0x9E3779B9 + 0x6A09E667 + (i * 0xDEADBEEF)) & 0x7FF;
				if (state >= 2048) state = 1;
			}
			return seq;
			};

		static constexpr auto state_sequence = generate_state_sequence();

		auto process_states = [func_name_capture]() -> CallBuilder<FuncType> {
			volatile uint64_t obfuscation_var = 0xDEADBEEFDEADBEEF;
			uint32_t current_index = 0;
			bool finished = false;
			CallBuilder<FuncType> result{ func_name_capture };

			obfuscation_var = (obfuscation_var << 13) ^ obfuscation_var;
			obfuscation_var = obfuscation_var * 0x2545F4914F6CDD1D;

			while (!finished && current_index < state_sequence.size()) {
				uint16_t current_state = state_sequence[current_index];

				switch (current_state) {
#define GENERATE_CASE_256(n) \
                    case 0x##n: \
                        obfuscation_var = (obfuscation_var ^ (0x##n##DEADBEEF)) + current_index; \
                        obfuscation_var = (obfuscation_var << 17) | (obfuscation_var >> 47); \
                        obfuscation_var = obfuscation_var * 0x##n##9E3779B9; \
                        current_index++; \
                        break;

					GENERATE_CASE_256(000) GENERATE_CASE_256(001) GENERATE_CASE_256(002) GENERATE_CASE_256(003)
						GENERATE_CASE_256(004) GENERATE_CASE_256(005) GENERATE_CASE_256(006) GENERATE_CASE_256(007)
						GENERATE_CASE_256(008) GENERATE_CASE_256(009) GENERATE_CASE_256(00A) GENERATE_CASE_256(00B)
						GENERATE_CASE_256(00C) GENERATE_CASE_256(00D) GENERATE_CASE_256(00E) GENERATE_CASE_256(00F)
						GENERATE_CASE_256(010) GENERATE_CASE_256(011) GENERATE_CASE_256(012) GENERATE_CASE_256(013)
						GENERATE_CASE_256(014) GENERATE_CASE_256(015) GENERATE_CASE_256(016) GENERATE_CASE_256(017)
						GENERATE_CASE_256(018) GENERATE_CASE_256(019) GENERATE_CASE_256(01A) GENERATE_CASE_256(01B)
						GENERATE_CASE_256(01C) GENERATE_CASE_256(01D) GENERATE_CASE_256(01E) GENERATE_CASE_256(01F)
						GENERATE_CASE_256(020) GENERATE_CASE_256(021) GENERATE_CASE_256(022) GENERATE_CASE_256(023)
						GENERATE_CASE_256(024) GENERATE_CASE_256(025) GENERATE_CASE_256(026) GENERATE_CASE_256(027)
						GENERATE_CASE_256(028) GENERATE_CASE_256(029) GENERATE_CASE_256(02A) GENERATE_CASE_256(02B)
						GENERATE_CASE_256(02C) GENERATE_CASE_256(02D) GENERATE_CASE_256(02E) GENERATE_CASE_256(02F)
						GENERATE_CASE_256(030) GENERATE_CASE_256(031) GENERATE_CASE_256(032) GENERATE_CASE_256(033)
						GENERATE_CASE_256(034) GENERATE_CASE_256(035) GENERATE_CASE_256(036) GENERATE_CASE_256(037)
						GENERATE_CASE_256(038) GENERATE_CASE_256(039) GENERATE_CASE_256(03A) GENERATE_CASE_256(03B)
						GENERATE_CASE_256(03C) GENERATE_CASE_256(03D) GENERATE_CASE_256(03E) GENERATE_CASE_256(03F)
						GENERATE_CASE_256(040) GENERATE_CASE_256(041) GENERATE_CASE_256(042) GENERATE_CASE_256(043)
						GENERATE_CASE_256(044) GENERATE_CASE_256(045) GENERATE_CASE_256(046) GENERATE_CASE_256(047)
						GENERATE_CASE_256(048) GENERATE_CASE_256(049) GENERATE_CASE_256(04A) GENERATE_CASE_256(04B)
						GENERATE_CASE_256(04C) GENERATE_CASE_256(04D) GENERATE_CASE_256(04E) GENERATE_CASE_256(04F)
						GENERATE_CASE_256(050) GENERATE_CASE_256(051) GENERATE_CASE_256(052) GENERATE_CASE_256(053)
						GENERATE_CASE_256(054) GENERATE_CASE_256(055) GENERATE_CASE_256(056) GENERATE_CASE_256(057)
						GENERATE_CASE_256(058) GENERATE_CASE_256(059) GENERATE_CASE_256(05A) GENERATE_CASE_256(05B)
						GENERATE_CASE_256(05C) GENERATE_CASE_256(05D) GENERATE_CASE_256(05E) GENERATE_CASE_256(05F)
						GENERATE_CASE_256(060) GENERATE_CASE_256(061) GENERATE_CASE_256(062) GENERATE_CASE_256(063)
						GENERATE_CASE_256(064) GENERATE_CASE_256(065) GENERATE_CASE_256(066) GENERATE_CASE_256(067)
						GENERATE_CASE_256(068) GENERATE_CASE_256(069) GENERATE_CASE_256(06A) GENERATE_CASE_256(06B)
						GENERATE_CASE_256(06C) GENERATE_CASE_256(06D) GENERATE_CASE_256(06E) GENERATE_CASE_256(06F)
						GENERATE_CASE_256(070) GENERATE_CASE_256(071) GENERATE_CASE_256(072) GENERATE_CASE_256(073)
						GENERATE_CASE_256(074) GENERATE_CASE_256(075) GENERATE_CASE_256(076) GENERATE_CASE_256(077)
						GENERATE_CASE_256(078) GENERATE_CASE_256(079) GENERATE_CASE_256(07A) GENERATE_CASE_256(07B)
						GENERATE_CASE_256(07C) GENERATE_CASE_256(07D) GENERATE_CASE_256(07E) GENERATE_CASE_256(07F)
						GENERATE_CASE_256(080) GENERATE_CASE_256(081) GENERATE_CASE_256(082) GENERATE_CASE_256(083)
						GENERATE_CASE_256(084) GENERATE_CASE_256(085) GENERATE_CASE_256(086) GENERATE_CASE_256(087)
						GENERATE_CASE_256(088) GENERATE_CASE_256(089) GENERATE_CASE_256(08A) GENERATE_CASE_256(08B)
						GENERATE_CASE_256(08C) GENERATE_CASE_256(08D) GENERATE_CASE_256(08E) GENERATE_CASE_256(08F)
						GENERATE_CASE_256(090) GENERATE_CASE_256(091) GENERATE_CASE_256(092) GENERATE_CASE_256(093)
						GENERATE_CASE_256(094) GENERATE_CASE_256(095) GENERATE_CASE_256(096) GENERATE_CASE_256(097)
						GENERATE_CASE_256(098) GENERATE_CASE_256(099) GENERATE_CASE_256(09A) GENERATE_CASE_256(09B)
						GENERATE_CASE_256(09C) GENERATE_CASE_256(09D) GENERATE_CASE_256(09E) GENERATE_CASE_256(09F)
						GENERATE_CASE_256(0A0) GENERATE_CASE_256(0A1) GENERATE_CASE_256(0A2) GENERATE_CASE_256(0A3)
						GENERATE_CASE_256(0A4) GENERATE_CASE_256(0A5) GENERATE_CASE_256(0A6) GENERATE_CASE_256(0A7)
						GENERATE_CASE_256(0A8) GENERATE_CASE_256(0A9) GENERATE_CASE_256(0AA) GENERATE_CASE_256(0AB)
						GENERATE_CASE_256(0AC) GENERATE_CASE_256(0AD) GENERATE_CASE_256(0AE) GENERATE_CASE_256(0AF)
						GENERATE_CASE_256(0B0) GENERATE_CASE_256(0B1) GENERATE_CASE_256(0B2) GENERATE_CASE_256(0B3)
						GENERATE_CASE_256(0B4) GENERATE_CASE_256(0B5) GENERATE_CASE_256(0B6) GENERATE_CASE_256(0B7)
						GENERATE_CASE_256(0B8) GENERATE_CASE_256(0B9) GENERATE_CASE_256(0BA) GENERATE_CASE_256(0BB)
						GENERATE_CASE_256(0BC) GENERATE_CASE_256(0BD) GENERATE_CASE_256(0BE) GENERATE_CASE_256(0BF)
						GENERATE_CASE_256(0C0) GENERATE_CASE_256(0C1) GENERATE_CASE_256(0C2) GENERATE_CASE_256(0C3)
						GENERATE_CASE_256(0C4) GENERATE_CASE_256(0C5) GENERATE_CASE_256(0C6) GENERATE_CASE_256(0C7)
						GENERATE_CASE_256(0C8) GENERATE_CASE_256(0C9) GENERATE_CASE_256(0CA) GENERATE_CASE_256(0CB)
						GENERATE_CASE_256(0CC) GENERATE_CASE_256(0CD) GENERATE_CASE_256(0CE) GENERATE_CASE_256(0CF)
						GENERATE_CASE_256(0D0) GENERATE_CASE_256(0D1) GENERATE_CASE_256(0D2) GENERATE_CASE_256(0D3)
						GENERATE_CASE_256(0D4) GENERATE_CASE_256(0D5) GENERATE_CASE_256(0D6) GENERATE_CASE_256(0D7)
						GENERATE_CASE_256(0D8) GENERATE_CASE_256(0D9) GENERATE_CASE_256(0DA) GENERATE_CASE_256(0DB)
						GENERATE_CASE_256(0DC) GENERATE_CASE_256(0DD) GENERATE_CASE_256(0DE) GENERATE_CASE_256(0DF)
						GENERATE_CASE_256(0E0) GENERATE_CASE_256(0E1) GENERATE_CASE_256(0E2) GENERATE_CASE_256(0E3)
						GENERATE_CASE_256(0E4) GENERATE_CASE_256(0E5) GENERATE_CASE_256(0E6) GENERATE_CASE_256(0E7)
						GENERATE_CASE_256(0E8) GENERATE_CASE_256(0E9) GENERATE_CASE_256(0EA) GENERATE_CASE_256(0EB)
						GENERATE_CASE_256(0EC) GENERATE_CASE_256(0ED) GENERATE_CASE_256(0EE) GENERATE_CASE_256(0EF)
						GENERATE_CASE_256(0F0) GENERATE_CASE_256(0F1) GENERATE_CASE_256(0F2) GENERATE_CASE_256(0F3)
						GENERATE_CASE_256(0F4) GENERATE_CASE_256(0F5) GENERATE_CASE_256(0F6) GENERATE_CASE_256(0F7)
						GENERATE_CASE_256(0F8) GENERATE_CASE_256(0F9) GENERATE_CASE_256(0FA) GENERATE_CASE_256(0FB)
						GENERATE_CASE_256(0FC) GENERATE_CASE_256(0FD) GENERATE_CASE_256(0FE) GENERATE_CASE_256(0FF)

#undef GENERATE_CASE_256
				case 0x100: {
						for (int i = 0; i < 8; i++) {
							obfuscation_var = (obfuscation_var << i) ^ obfuscation_var;
							obfuscation_var = obfuscation_var + (i * 0x123456789ABCDEF);
						}
						current_index++;
						break;
					}

				case 0x101: {
					uint64_t temp = obfuscation_var;
					obfuscation_var = (temp & 0xFFFFFFFF) * ((temp >> 32) & 0xFFFFFFFF);
					obfuscation_var = (obfuscation_var << 32) | (obfuscation_var >> 32);
					current_index++;
					break;
				}
				case 0x200: {
					for (int round = 0; round < 16; round++) {
						uint64_t s0 = ((obfuscation_var >> 7) | (obfuscation_var << 57)) ^
							((obfuscation_var >> 18) | (obfuscation_var << 46)) ^
							(obfuscation_var >> 3);
						uint64_t s1 = ((obfuscation_var >> 17) | (obfuscation_var << 47)) ^
							((obfuscation_var >> 19) | (obfuscation_var << 45)) ^
							(obfuscation_var >> 10);
						obfuscation_var = obfuscation_var + s0 + s1 + round * 0x5A827999;
					}
					current_index++;
					break;
				}

				case 0x300: {
					double inputs[4] = {
						(double)(obfuscation_var & 0xFFFF),
						(double)((obfuscation_var >> 16) & 0xFFFF),
						(double)((obfuscation_var >> 32) & 0xFFFF),
						(double)((obfuscation_var >> 48) & 0xFFFF)
					};

					double weights[4][4] = { {0.1, 0.2, 0.3, 0.4}, {0.5, 0.6, 0.7, 0.8},
										  {0.9, 1.0, 1.1, 1.2}, {1.3, 1.4, 1.5, 1.6} };
					double outputs[4] = { 0 };

					for (int i = 0; i < 4; i++) {
						for (int j = 0; j < 4; j++) {
							outputs[i] += inputs[j] * weights[i][j];
						}
						outputs[i] = outputs[i] > 0 ? outputs[i] : 0;
					}

					obfuscation_var = 0;
					for (int i = 0; i < 4; i++) {
						obfuscation_var |= ((uint64_t)outputs[i] & 0xFFFF) << (i * 16);
					}
					current_index++;
					break;
				}
				case 0x500: {
					finished = true;
					break;
				}
				case 0x7FF: {
					obfuscation_var = obfuscation_var ^ 0xFFFFFFFFFFFFFFFF;
					current_index++;
					if (current_index >= state_sequence.size()) {
						finished = true;
					}
					break;
				}
				default: {
					obfuscation_var = (obfuscation_var + current_state * 0x9E3779B9) ^ 0xDEADBEEF;
					obfuscation_var = (obfuscation_var << (current_state & 0x3F)) |
						(obfuscation_var >> (64 - (current_state & 0x3F)));
					current_index++;
					break;
				}
				}

				if (current_index > 0xFFFF) {
					finished = true;
				}
			}

			return result;
			};

		return process_states();
		}();
}

template<typename FuncType>
auto call_in_module(const std::string& module_name, const std::string& func_name)
{
	return [module_name_capture = module_name, func_name_capture = func_name]() -> CallBuilder<FuncType> {
		auto builder = call<FuncType>(func_name_capture);
		return std::move(builder.in(module_name_capture));
		}();
}


