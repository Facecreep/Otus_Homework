#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back((str.substr(start, stop - start)));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

std::vector<std::vector<int>> Filter(const std::vector<std::vector<int>> &twoDVector, int firstByte){
    std::vector<std::vector<int>> result;

    std::for_each(twoDVector.begin(), twoDVector.end(), [&result, firstByte](auto vector){
        if (vector[0] == firstByte){
            result.push_back(vector);
        }
    });

    return result;
}

std::vector<std::vector<int>> Filter(const std::vector<std::vector<int>> &twoDVector, int firstByte, int secondByte){
    std::vector<std::vector<int>> result;

    std::for_each(twoDVector.begin(), twoDVector.end(), [&result, firstByte, secondByte](auto vector){
        if (vector[0] == firstByte && vector[1] == secondByte){
            result.push_back(vector);
        }
    });

    return result;
}

std::vector<std::vector<int>> FilterAny(const std::vector<std::vector<int>> &twoDVector, int firstByte){
    std::vector<std::vector<int>> result;

    std::for_each(twoDVector.begin(), twoDVector.end(), [&result, firstByte](auto vector){
        bool success = false;

        for (int i = 0; i < 4; i++){
            if (vector[i] == firstByte){
                success = true;
                break;
            }
        }

        if(success){
            result.push_back(vector);
        }
    });

    return result;
}

void Print(const std::vector<std::vector<int>> &twoDVector){
    std::for_each(twoDVector.begin(), twoDVector.end(), [](auto ipList){
        std::cout << ipList[0] << "." << ipList[1] << "." << ipList[2] << "." << ipList[3] << std::endl;
    });
}

int main(int, char **)
{
    std::vector<std::vector<std::string> > ipPoolString;

    std::ifstream ipFile;
    ipFile.open("..\\DZ2\\ip_filter.tsv");

    for(std::string line; std::getline(ipFile, line); )
    {
        std::vector<std::string> v = split(line, '\t');
        std::vector<std::string> ipAddress = split(v.at(0), '.');
        ipPoolString.push_back(split(v.at(0), '.'));
    }

    ipFile.close();

    std::vector<std::vector<int>> ipPoolInt;
    std::for_each(ipPoolString.begin(), ipPoolString.end(), [&ipPoolInt](auto ipStringList){
        std::vector<int> ipIntList = {};
        std::for_each(ipStringList.begin(), ipStringList.end(), [&ipIntList](auto ipString){
           ipIntList.push_back(std::stoi(ipString));
        });
        ipPoolInt.push_back(ipIntList);
    });

    std::sort(ipPoolInt.begin(), ipPoolInt.end(), [](const std::vector<int> &ipList1, const std::vector<int> &ipList2){
        for (int i = 0; i < 4; i++){
            if (ipList1[i] == ipList2[i]){
                continue;
            }
            return ipList1[i] > ipList2[i];
        }
        return false;
    });

    std::ofstream ipFileSorted;
    ipFileSorted.open("..\\DZ2\\ip_filter_sorted.tsv");
    std::for_each(ipPoolInt.begin(), ipPoolInt.end(), [&ipFileSorted](auto ipList){
        ipFileSorted << ipList[0] << "." << ipList[1] << "." << ipList[2] << "." << ipList[3] << std::endl;
    });
    
    Print(Filter(ipPoolInt, 1));
    std::cout << std::endl;
    Print(Filter(ipPoolInt, 46, 70));
    std::cout << std::endl;
    Print(FilterAny(ipPoolInt, 46));
}
