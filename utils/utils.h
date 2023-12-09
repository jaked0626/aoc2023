#ifndef UTILS_H
#define UTILS_H


std::string readFileIntoString(const std::ifstream&);
std::vector<std::string> splitString(const std::string&, char);
void printStringVector(std::vector<std::string>);
void printStringVector(std::vector<std::string>);

template <typename K, typename V>
void initializeMapKeyIfEmpty(std::unordered_map<K, V>&, const K&, const V&);

#endif