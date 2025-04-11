#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <math.h>
#include <cstdlib>
#include <string>
#include <optional>

template <typename T>
struct singleAllocator {
    char* memory_block;
    std::size_t capacity;
    std::size_t usedBytes = 0;

    using value_type = T;
    using pointer = T *;
    using const_pointer = const T *;
    using reference = T &;

    ////copy constructor
    singleAllocator(const singleAllocator& allocator){
        this->capacity = allocator.capacity;
        this->usedBytes = allocator.usedBytes;
        this->memory_block = static_cast<char*>(std::malloc(this->capacity * sizeof(T)));

//        std::cout << __PRETTY_FUNCTION__ << std::endl;
//        std::cout << "invoked copy with {" << capacity * sizeof(T) << "} bytes" << std::endl;
    }

    template <typename U>
    struct rebind{
        using other = singleAllocator<U>;
    };

    ////rebind constructor
    template <typename U>
    singleAllocator(const singleAllocator<U> other){
                this->capacity = other.capacity;
                this->usedBytes = other.usedBytes;
                this->memory_block = static_cast<char*>(std::malloc(capacity * sizeof(U)));

//                std::cout << __PRETTY_FUNCTION__ << std::endl;
//                std::cout << "invoked rebind with {" << capacity * sizeof(U) << "} bytes" << std::endl;
             }

    ////normal constructor
    singleAllocator(const std::size_t capacity)
    : capacity(capacity){
//        std::cout << __PRETTY_FUNCTION__ << std::endl;

        memory_block = static_cast<char*>(std::malloc(capacity * sizeof(T)));

        if(!memory_block){
            printf("bad alloc 1");
            throw std::bad_alloc();
        }

//        std::cout << "Allocated " << capacity * sizeof(T) << " bytes once.\n";
    }

    singleAllocator()
            : capacity(0){
    }

    ~singleAllocator(){
//        printf(__PRETTY_FUNCTION__ );
        std::free(memory_block);

//        std::cout << "Freed " << capacity * sizeof(T) << " bytes.\n";
    }

    T *allocate(size_t n) {
        std::size_t requiredBytes = n * sizeof(T);

        if (usedBytes + requiredBytes > capacity * sizeof(T)){
            printf("bad alloc 2");
            throw std::bad_alloc();
        }

        T *ptr = reinterpret_cast<T *>(memory_block + usedBytes);
        usedBytes += requiredBytes;


//        std::cout << "Reused " << requiredBytes << " bytes (total used: " << usedBytes << ").\n";

        return ptr;
    }

    void deallocate(T *p, size_t n) {
    }

    template <typename... Args>
    void construct(T* p, Args&&... args) {
        new (p) T(std::forward<Args>(args)...);
    }

    // Destroy an object
    void destroy(T* p) {
        p->~T();
    }
};

struct Element{
    Element *nextElement;
    int value;
};

class Container{
    Element *firstElement;
    singleAllocator<Element> allocator;
    bool isUsingAllocator;

public:
    Container(const singleAllocator<Element> &allocator)
    :firstElement(NULL),
    allocator(allocator){
        isUsingAllocator = true;
    }

    Container()
    :firstElement(NULL)
    {
        isUsingAllocator = false;
    }

    ~Container(){
        Clear();
    }

    void Print(){
        Element *currentElement = firstElement;

        std::string result;
        if(currentElement->value){
            while(currentElement != nullptr){
                result += std::to_string(currentElement->value) + ", ";
                currentElement = currentElement->nextElement;
            }
        std::cout << result << std::endl;
        }
    }

    bool IsEmpty(){
        return not bool(firstElement);
    }

    void PushBack(int value){
        Element *newElement;

        if(isUsingAllocator){
            newElement = allocator.allocate(1);
            allocator.construct(newElement);
        }
        else
            newElement = new Element();

        newElement->value = value;
        newElement->nextElement = nullptr;

        if (this->IsEmpty()){
            firstElement = newElement;
        }

        else{
            Element *currentElement = firstElement;

            while(currentElement->nextElement != nullptr)
                currentElement = currentElement->nextElement;

            currentElement->nextElement = newElement;
        }
    }

    void Clear(){
        while(firstElement){
            Element *temp = firstElement;
            firstElement = firstElement->nextElement;

            if(isUsingAllocator){
                allocator.destroy(temp);
                allocator.deallocate(temp, 1);
            }
        }
    }
};

int main(int, char **) {
    //Шаг 1
    auto mapNoAllocator = std::map<
            int,
            int,
            std::less<int>>{};

    //Шаг 2
    for (int i = 0; i < 10; i++){
        int result = 1;

        for (int j = 1; j <=
                        i; j++)
            result *= j;

        mapNoAllocator[i] = result;
    }
    singleAllocator<std::pair<const int, int>> allocator(10);
//    Шаг 3
    auto mapWithAllocator = std::map<
            int,
            int,
            std::less<int>,
            singleAllocator<std::pair<const int, int>>
    >(std::less<int>(), allocator);

    //Шаг 4
    for (int i = 0; i < 10; i++){
        int result = 1;

        for (int j = 1; j <= i; j++)
            result *= j;

        std::cout << result << std::endl;

        mapWithAllocator[i] = (result);
    }

    //Шаг 5
    Container container;
    for (int i = 0; i < 10; i++){
        int result = 1;

        for (int j = 1; j <=i; j++)
            result *= j;

        container.PushBack(result);
    }

    container.Print();

    singleAllocator<Element> elementAllocator(10);

    Container containerAllocated(elementAllocator);

    for (int i = 0; i < 10; i++){
        int result = 1;

        for (int j = 1; j <=i; j++)
            result *= j;

        containerAllocated.PushBack(result);
    }

    containerAllocated.Print();

    return 0;
}