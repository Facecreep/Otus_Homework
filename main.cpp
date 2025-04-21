#include <iostream>
#include <cstdint>
#include <vector>
#include <list>
#include <tuple>

template<typename T>
void print_container(const T &container){
    std::string string;

    for(int i: container)
        string += std::to_string(i) + ".";

    string.pop_back();

    std::cout << string << std::endl;
}

template<typename T,
        typename std::enable_if<std::is_integral<T>::value, int
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

template<typename T,
        typename std::enable_if<!std::is_same<T, std::string>::value, int
        >::type = 0>
auto print_ip(const T& container) -> decltype(container.begin(), container.end()){
    print_container(container);
}

//template<typename T,
//        typename std::enable_if<std::is_same<T, std::vector<int>>::value, int
//        >::type = 0>
//void print_ip(T value) {
//    print_container(value);
//}
//
//template<typename T,
//        typename std::enable_if<std::is_same<T, std::list<int>>::value, int
//        >::type = 0>
//void print_ip(T value) {
//    print_container(value);
//}

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

    print_ip( int8_t{-1} );
    print_ip( int16_t{0} );
    print_ip( int32_t{2130706433} );
    print_ip( int64_t{8875824491850138409} );
    print_ip( std::string{"Hello, World!"} );
    print_ip( std::vector<int>{100, 200, 300, 400} );
    print_ip( std::list<short>{400, 300, 200, 100} );
    print_ip( std::make_tuple(123, 456, 789, 0) );

    return 0;
}