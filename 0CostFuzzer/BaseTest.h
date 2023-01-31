#include"base64.h"
void man() {
symbolic_str s;
aria2::base64::encode(s.begin(), s.end());
std::cout << s << std::endl;
}
