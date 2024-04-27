#include <cstdint>
#include <iterator>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>
std::unordered_map<char, std::uint32_t>getFreqTableFrom(std::string message);
std::string decryptMessage( std::string message, std::string freqLang ){
    std::string decrypt="";
    auto freq = getFreqTableFrom(message);
    std::vector<std::pair<char, uint32_t>> freqV(freq.begin(),freq.end());
    std::sort(freqV.begin(),freqV.end(),[](auto& a,auto &b){
        return  a.second>b.second;
    });
    for (auto c : message) {
        const bool esMinuscula = (c >= 'a' && c <= 'z');
        auto it = std::find_if(freqV.begin(),freqV.end(),[&c](auto&el){
                // std::cout<<el.first;
                return towupper(c)==el.first;
        });
        if (it==freqV.end())
        {
            decrypt+=c;
            continue;
        }
        auto pos = std::distance(freqV.begin(),it);        
        decrypt += ((esMinuscula)?tolower(freqLang[pos]):freqLang[pos]);
    }
    return  decrypt;
}
std::unordered_map<char, std::uint32_t>getFreqTableFrom(std::string message){
    std::unordered_map<char, std::uint32_t> freq{};
    for (int i = 'Z'; i >= 'A'; --i)
    {
        char c = i;
        freq[c]=0;
    }
    for (char c : message) {
        char cM = toupper(c);
        if (freq.find(cM)==freq.end())
        {
            continue;
        }
        freq[cM]++;
    }
    return  freq;
}


