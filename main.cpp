
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <regex>

#define PRNT_DBG 0

class one_ip {
  uint8_t f1=0, f2=0, f3=0, f4=0;
public:
  one_ip() noexcept :
      f1(0), f2(0), f3(0), f4(0) {
    if(PRNT_DBG) std::cout << "Default Ctor: " << (uint) f1 << "." << (uint) f2 << "." << (uint) f3 << "." << (uint) f4 << std::endl;
  }

  one_ip(const one_ip &other) noexcept :
      f1(other.f1), f2(other.f2), f3(other.f3), f4(other.f4) {
    if(PRNT_DBG) std::cout << "Copy CTor: " << (uint) f1 << "." << (uint) f2 << "." << (uint) f3 << "." << (uint) f4 << " (with " << (uint) other.f1 << "." << (uint) other.f2 << "." << (uint) other.f3 << "." << (uint) other.f4 << ")" << std::endl;
  }

  one_ip& operator=(const one_ip &other) noexcept {
    if(PRNT_DBG) std::cout << "Copy Assignment: " << (uint) f1 << "." << (uint) f2 << "." << (uint) f3 << "." << (uint) f4 << " (with " << (uint) other.f1 << "." << (uint) other.f2 << "." << (uint) other.f3 << "." << (uint) other.f4 << ")" << std::endl;
    if (this == &other) return *this;
    f1 = other.f1;
    f2 = other.f2;
    f3 = other.f3;
    f4 = other.f4;
    return *this;
  }

  one_ip(one_ip &&other) noexcept {
    if(PRNT_DBG) std::cout << "Move CTor: " << (uint)f1 << "." << (uint)f2 << "." << (uint)f3 << "." << (uint)f4 << " (with " << (uint)other.f1 << "." << (uint)other.f2 << "." << (uint)other.f3 << "." << (uint)other.f4 << ")" << std::endl;
    f1 = std::exchange(other.f1, 0);
    f2 = std::exchange(other.f2, 0);
    f3 = std::exchange(other.f3, 0);
    f4 = std::exchange(other.f4, 0);
  }

  one_ip& operator=(one_ip &&other) noexcept {
    if(PRNT_DBG) std::cout << "Move Assignment: " << (uint) f1 << "." << (uint) f2 << "." << (uint) f3 << "." << (uint) f4 << " (with " << (uint) other.f1 << "." << (uint) other.f2 << "." << (uint) other.f3 << "." << (uint) other.f4 << ")" << std::endl;
    if (this != &other) {
      f1 = std::exchange(other.f1, 0);
      f2 = std::exchange(other.f2, 0);
      f3 = std::exchange(other.f3, 0);
      f4 = std::exchange(other.f4, 0);
    }
    return *this;
  }

  one_ip(uint8_t in_f1, uint8_t in_f2, uint8_t in_f3, uint8_t in_f4) noexcept :
      f1(in_f1), f2(in_f2), f3(in_f3), f4(in_f4) {
    if(PRNT_DBG) std::cout << "Regular Ctor: " << (uint) f1 << "." << (uint) f2 << "." << (uint) f3 << "." << (uint) f4 << std::endl;
  }

  one_ip(const std::string &a, const std::string &b, const std::string &c, const std::string &d) {
    f1 = std::stoul(a);
    f2 = std::stoul(b);
    f3 = std::stoul(c);
    f4 = std::stoul(d);
    if(PRNT_DBG) std::cout << "Conversion CTor: " << (uint)f1 << "." << (uint)f2 << "." << (uint)f3 << "." << (uint)f4 << std::endl;
  }

  operator std::string() const {
    return std::to_string((uint) f1) + "." + std::to_string((uint) f2) + "." + std::to_string((uint) f3) + "."
        + std::to_string((uint) f4);
  }

  bool operator==(const one_ip &other) {
    return (f1 == other.f1 && f2 == other.f2 && f3 == other.f3 && f4 == other.f4);
  }
  bool operator!=(const one_ip& other){
    return (f1 != other.f1 || f2 != other.f2 || f3 != other.f3 || f4 != other.f4);
  }
  bool operator<(const one_ip& other)
  {
    if(f1 < other.f1) return true;
    else if(f1 > other.f1) return false;
    else /* (f1 == other.f1) */ {
      if(f2 < other.f2) return true;
      else if(f2 > other.f2) return false;
      else /* (f2 == other.f2) */ {
        if(f3 < other.f3) return true;
        else if(f3 > other.f3) return false;
        else /* (f3 == other.f3) */ {
          if(f4 < other.f4) return true;
          else /* (f4 >= other.f4) */ return false;
        }
      }
    }
  }
  bool operator<=(const one_ip& other)
  {
    if(f1 < other.f1) return true;
    else if(f1 > other.f1) return false;
    else /* (f1 == other.f1) */ {
      if(f2 < other.f2) return true;
      else if(f2 > other.f2) return false;
      else /* (f2 == other.f2) */ {
        if(f3 < other.f3) return true;
        else if(f3 > other.f3) return false;
        else /* (f3 == other.f3) */ {
          if(f4 < other.f4) return true;
          else if(f4 > other.f4) return false;
          else /* (f4 == other.f4) */ return true;
        }
      }
    }
  }
  bool operator>(const one_ip& other)
  {
    if(f1 > other.f1) return true;
    else if(f1 < other.f1) return false;
    else /* (f1 == other.f1) */ {
      if(f2 > other.f2) return true;
      else if(f2 < other.f2) return false;
      else /* (f2 == other.f2) */ {
        if(f3 > other.f3) return true;
        else if(f3 < other.f3) return false;
        else /* (f3 == other.f3) */ {
          if(f4 > other.f4) return true;
          else /* (f4 >= other.f4) */ return false;
        }
      }
    }
  }
  bool operator>=(const one_ip& other)
  {
    if(f1 > other.f1) return true;
    else if(f1 < other.f1) return false;
    else /* (f1 == other.f1) */ {
      if(f2 > other.f2) return true;
      else if(f2 < other.f2) return false;
      else /* (f2 == other.f2) */ {
        if(f3 > other.f3) return true;
        else if(f3 < other.f3) return false;
        else /* (f3 == other.f3) */ {
          if(f4 > other.f4) return true;
          else if(f4 < other.f4) return false;
          else /* (f4 == other.f4) */ return true;
        }
      }
    }
  }

  bool filter(int a=-1, int b=-1, int c=-1, int d=-1) const {
    if((a==f1 || a==-1) && (b==f2 || b==-1) && (c==f3 || c==-1) && (d==f4 || d==-1))
      return true;
    else return false;
  }
  bool filter_any(uint val) const {
    if(val==f1 || val==f2 || val==f3 || val==f4)
      return true;
    else return false;
  }
};

void print_ips(const std::vector<one_ip> &vec){
  for (auto &oip : vec) {
    std::cout << (std::string) oip << "\n";
  }
}

std::vector<one_ip> filter_ips(const std::vector<one_ip> &vec, int a=-1, int b=-1, int c=-1, int d=-1){
  std::vector<one_ip> filtered_ips;
  std::copy_if(vec.begin(), vec.end(),
               std::back_inserter(filtered_ips),
               [=](const one_ip& ip) { return ip.filter(a,b,c,d); });
  if(PRNT_DBG) std::cout << "Before return from filter_ips(...)" << std::endl;
  return filtered_ips;
}

std::vector<one_ip> filter_any_ips(const std::vector<one_ip> &vec, uint val){
  std::vector<one_ip> filtered_ips;
  std::copy_if(vec.begin(), vec.end(),
               std::back_inserter(filtered_ips),
               [=](const one_ip& ip) { return ip.filter_any(val); });
  if(PRNT_DBG) std::cout << "Before return from filter_any_ips(...)" << std::endl;
  return filtered_ips;
}

int main(int, char const*[]) {
  std::regex pat("^(\\d{1,3}).(\\d{1,3}).(\\d{1,3}).(\\d{1,3})\\s+.*$");
  std::smatch pieces_match;
  std::vector<one_ip> vip;
  try {
    for (std::string line; std::getline(std::cin, line);) {
      if (std::regex_match(line, pieces_match, pat)) {
        vip.emplace_back( pieces_match[1].str(), pieces_match[2].str(), pieces_match[3].str(), pieces_match[4].str() );
        if(PRNT_DBG) std::cout << "\n\nINIT: Vector size=" << vip.size() << "\n      Vector capasity=" << vip.capacity() << std::endl;
      } else {
        std::cerr << "Format error: there is no IP address in the line '" << line << "'\n";
      }

    }

    if(PRNT_DBG) std::cout << "\n\nAFTER INIT: Vector size=" << vip.size() << "\nVector capasity=" << vip.capacity() << std::endl;

    // TODO reverse lexicographically sort
    std::cout << "\n============== raw data input from stdin ==============" << std::endl;

    print_ips(vip);

    if(PRNT_DBG) std::cout << "\n\nBEFORE SORT: Vector size=" << vip.size() << "\nVector capasity=" << vip.capacity() << std::endl;


    std::sort(vip.begin(), vip.end(), [](one_ip &lhs, one_ip &rhs) {
      if(PRNT_DBG) std::cout << "lhs=" << (std::string) lhs << "   rhs=" << (std::string) rhs << std::endl;
      return lhs > rhs;
    });

    std::cout << "\n============== reverse lexicographically sort ==============" << std::endl;
    print_ips(vip);

    if(PRNT_DBG) std::cout << "\n\nAFTER SORT: Vector size=" << vip.size() << "\nVector capasity=" << vip.capacity() << std::endl;

// 222.173.235.246
// 222.130.177.64
// 222.82.198.61
// ...
// 1.70.44.170
// 1.29.168.152
// 1.1.234.8

// TODO filter by first byte and output
// ip = filter(1)

    std::cout << "\n============== filter by first byte and output ==============" << std::endl;
    std::vector<one_ip> fips = filter_ips(vip, 1);
    print_ips(fips);

// 1.231.69.33
// 1.87.203.225
// 1.70.44.170
// 1.29.168.152
// 1.1.234.8

// TODO filter by first and second bytes and output
// ip = filter(46, 70)

    std::cout << "\n============== filter by first and second bytes and output ==============" << std::endl;
    fips = filter_ips(vip, 46, 70);
    print_ips(fips);

// 46.70.225.39
// 46.70.147.26
// 46.70.113.73
// 46.70.29.76

// TODO filter by any byte and output
// ip = filter_any(46)

    std::cout << "\n============== filter by any byte and output ==============" << std::endl;
    fips = filter_any_ips(vip, 46);
    print_ips(fips);

// 186.204.34.46
// 186.46.222.194
// 185.46.87.231
// 185.46.86.132
// 185.46.86.131
// 185.46.86.131
// 185.46.86.22
// 185.46.85.204
// 185.46.85.78
// 68.46.218.208
// 46.251.197.23
// 46.223.254.56
// 46.223.254.56
// 46.182.19.219
// 46.161.63.66
// 46.161.61.51
// 46.161.60.92
// 46.161.60.35
// 46.161.58.202
// 46.161.56.241
// 46.161.56.203
// 46.161.56.174
// 46.161.56.106
// 46.161.56.106
// 46.101.163.119
// 46.101.127.145
// 46.70.225.39
// 46.70.147.26
// 46.70.113.73
// 46.70.29.76
// 46.55.46.98
// 46.49.43.85
// 39.46.86.85
// 5.189.203.46
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
