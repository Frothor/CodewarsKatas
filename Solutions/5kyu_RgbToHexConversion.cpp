/*
5kyu RGB To Hex Conversion

The rgb function is incomplete. Complete it so that passing in RGB decimal values will result in a hexadecimal representation being returned. Valid decimal values for RGB are 0 - 255. Any values that fall out of that range must be rounded to the closest valid value.

Note: Your answer should always be 6 characters long, the shorthand with 3 will not work here.

The following are examples of expected output values:

rgb(255, 255, 255) # returns FFFFFF
rgb(255, 255, 300) # returns FFFFFF
rgb(0,0,0) # returns 000000
rgb(148, 0, 211) # returns 9400D3
*/


#include <sstream>
#include <iomanip>

class RGBToHex
{
  public:
  static std::string rgb(int r, int g, int b);
};

std::string RGBToHex::rgb(int r, int g, int b)
{
  std::ostringstream oss;
  oss << std::uppercase << std::setfill('0') << std::hex
      << std::setw(2) << (r < 0 ? 0 : r > 255 ? 255 : r)
      << std::setw(2) << (g < 0 ? 0 : g > 255 ? 255 : g)
      << std::setw(2) << (b < 0 ? 0 : b > 255 ? 255 : b);
  return oss.str();
}



/*
Faster solution:

class RGBToHex
{
  public:
  static std::string rgb(int r, int g, int b){
  #define RGB_LEN 6
      r=r<0?0:(r>255?255:r);
      g=g<0?0:(g>255?255:g);
      b=b<0?0:(b>255?255:b);
      int i=(r<<16)|(g<<8)|(b);
      char s[RGB_LEN];
      int p=RGB_LEN;
      while (p-->0){
          char c=i%16;
          s[p]=c+(c<10?'0':'A'-10);
          i/=16;
      }
      return std::string(s,RGB_LEN);
  }
};

Another fast solution:

#include <iostream>
#include <string>
#include <array>

constexpr auto trim(int x)
{
    return x < 0 ? 0
                 : x > 255 ? 255 : x;
}

constexpr auto hexchar(int x) -> char
{
    return x < 10 ? x + '0'
                  : x - 10 + 'A';
}

// we need static string values that can be generated by compiler so
// any std's streams won't work here
constexpr auto hexstr(int x) -> std::array<char, 2>
{
    return {hexchar((x & 0xF0) >> 4), hexchar(x & 0xF)};
} 

template<size_t... I>
constexpr auto make_hexmap(std::index_sequence<I...>)
{
    return std::array<std::array<char, 2>, sizeof...(I)>{hexstr(I)...};
}

// it's clearly harder to understand but making such array we sacrifice not much of the memory
// but get extremely trivial hex formatting which is just referencing correct value
constexpr auto HEX_MAP = make_hexmap(std::make_index_sequence<256>{});

// we want to put result directly into the string so that no unnecessary allocations are made
void peek_from_hex_map(int value, char * out)
{
    const auto elem = HEX_MAP[trim(value)];
    std::copy(std::begin(elem), std::end(elem), out);
}

class RGBToHex
{
  public:
  static std::string rgb(int r, int g, int b)
  {
     std::string out(6, 0);
     peek_from_hex_map(r, &out[0]);
     peek_from_hex_map(g, &out[2]);
     peek_from_hex_map(b, &out[4]);
     return out;
  }
};
*/