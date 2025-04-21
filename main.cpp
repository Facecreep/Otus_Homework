#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using double_int_vector = std::vector<std::vector<int>>;

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

double_int_vector Filter(const double_int_vector &twoDVector, int firstByte){
    double_int_vector result;

    std::for_each(twoDVector.begin(), twoDVector.end(), [&result, firstByte](auto vector){
        if (vector[0] == firstByte){
            result.push_back(vector);
        }
    });

    return result;
}

double_int_vector Filter(const double_int_vector &twoDVector, int firstByte, int secondByte){
    double_int_vector result;

    std::for_each(twoDVector.begin(), twoDVector.end(), [&result, firstByte, secondByte](auto vector){
        if (vector[0] == firstByte && vector[1] == secondByte){
            result.push_back(vector);
        }
    });

    return result;
}

double_int_vector FilterAny(const double_int_vector &twoDVector, int firstByte){
    double_int_vector result;

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

std::string ip_to_string(const std::vector<std::string> &ip){
    std::string result;

    std::for_each(ip.begin(), ip.end(), [&result](auto ip_piece){
        result += ip_piece + ".";
    });

    result.pop_back();

    return result;
}

std::string ip_to_string(const std::vector<int> &ip){
    std::string result;

    std::for_each(ip.begin(), ip.end(), [&result](auto ip_piece){
        result += ip_piece + ".";
    });

    result.pop_back();

    return result;
}

void print_full_ip_list(const double_int_vector &twoDVector){
    std::for_each(twoDVector.begin(), twoDVector.end(), [](auto ipList){
        std::cout << ip_to_string(ipList) << std::endl;
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

        if(ipAddress.size() > 4)
            throw std::runtime_error("IP address too long: " + ip_to_string(ipAddress));

        ipPoolString.push_back(split(v.at(0), '.'));
    }

    ipFile.close();

    double_int_vector ipPoolInt;
    std::for_each(ipPoolString.begin(), ipPoolString.end(), [&ipPoolInt](auto ipStringList){
        std::vector<int> ipIntList = {};
        std::for_each(ipStringList.begin(), ipStringList.end(), [&ipIntList, &ipStringList](auto ipString){
            int ip_int = std::stoi(ipString);

            if(ip_int > 255 || ip_int < 0)
                throw std::runtime_error("IP out of range: " + ip_to_string(ipStringList));

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

    print_full_ip_list(Filter(ipPoolInt, 1));
    std::cout << std::endl;
    print_full_ip_list(Filter(ipPoolInt, 46, 70));
    std::cout << std::endl;
    print_full_ip_list(FilterAny(ipPoolInt, 46));
}
