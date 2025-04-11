#include <iostream>
#include <cstdint>
#include <vector>
#include <list>

template<typename T>
void print_container(const T &container){
    std::string string;

    for(int i: container)
        string += std::to_string(i) + ".";

    string.pop_back();

    std::cout << string << std::endl;
}

template<typename T,
        typename std::enable_if<
                std::is_same<T, int16_t>::value ||
                std::is_same<T, int8_t>::value ||
                std::is_same<T, int32_t>::value ||
                std::is_same<T, int64_t>::value, int
        >::type = 0>
void print_ip(T value) {
    uint8_t* byte_ptr = reinterpret_cast<uint8_t*>(&value);

    std::string string;

    for (int i = 0; i < sizeof(int16_t); ++i) {
        string += std::to_string(static_cast<int>(byte_ptr[i])) + ".";
    }

    string.pop_back();

    std::cout << string << std::endl;
}

template<typename T,
        typename std::enable_if<std::is_same<T, std::string>::value, int
        >::type = 0>
void print_ip(T value) {

    std::cout << value<< std::endl;
}

//template<typename T>
//auto print_ip(T& container) -> decltype(container.size()){
//
//    std::cout << value<< std::endl;
//}

template<typename T,
        typename std::enable_if<std::is_same<T, std::vector<int>>::value, int
        >::type = 0>
void print_ip(T value) {
    print_container(value);
}

template<typename T,
        typename std::enable_if<std::is_same<T, std::list<int>>::value, int
        >::type = 0>
void print_ip(T value) {
    print_container(value);
}

//template<typename T,
//        typename = typename std::enable_if<
//                std::is_same<typename std::remove_reference<T>::type, std::string>::value
//                , void>::type>
//void print_ip(T value) {
//    uint8_t* byte_ptr = reinterpret_cast<uint8_t*>(&value);
//
//    std::string string;
//
//    for (int i = 0; i < sizeof(int16_t); ++i) {
//        string += std::to_string(static_cast<int>(byte_ptr[i])) + ".";
//    }
//
//    string.pop_back();
//
//    std::cout << string << std::endl;
//}

template <typename T> std::string type_name();

int main() {

    print_ip(int16_t{-1});

    print_ip(std::string{"212"});

    print_ip(std::vector<int>{100,200,300});

    print_ip(std::list<int>{100,200,300});

    return 0;
}